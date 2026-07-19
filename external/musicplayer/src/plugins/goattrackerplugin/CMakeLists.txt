cmake_minimum_required(VERSION 3.15)
project(cpp-mods.musicplayer.goattrackerplugin)

# GoatTracker v2 .sng (C64 SID tracker, Lasse Oorni) player. Wraps GoatTracker's
# own playback core -- the gplay.c sequencer and the gsid.cpp reSID interface --
# driving the vendored reSID engine directly (no SDL / BME / editor). The .sng
# format loader (gt2_load.c) reproduces GoatTracker's modern GTS3/4/5 parse path
# from memory into the same global song arrays gplay.c consumes.

file(GLOB RESID_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/resid/*.cpp)
# resid/version.cpp only exposes resid_version_string (= the autoconf VERSION
# macro), which nothing in the player uses and which we don't define. Drop it.
list(FILTER RESID_SOURCES EXCLUDE REGEX "version\\.cpp$")

# GoatTracker's engine and reSID export many generic, un-prefixed globals
# (pattern, instr, sid, sidreg, songname, sound_flush, ...) that collide with
# other vendored plugins (e.g. vicepluginbridge's sound_flush/sound_suspend).
# Same fix as mikmodplugin: compile everything with hidden visibility and
# partial-link with `ld -r`, which demotes those private externs to true local
# symbols. Only GoatTrackerPlugin.cpp stays at default visibility so
# musix::GoatTrackerPlugin and goattrackerplugin_register remain exported.
add_library(goattrackerplugin_objs OBJECT
    GoatTrackerPlugin.cpp
    gplay.c
    gsid.cpp
    gt2_load.c
    ${RESID_SOURCES}
    GoatTrackerPlugin.h
    gt2_engine.h
    gcommon.h
    gplay.h
    gsid.h
    gsong.h
    gsound.h)

# Vendored GoatTracker/reSID sources use sprintf(), which the macOS SDK marks
# deprecated. Silence it on the third-party sources only (not our own
# GoatTrackerPlugin.cpp) rather than patch them -- keeps revendoring clean.
set_source_files_properties(gplay.c gsid.cpp gt2_load.c ${RESID_SOURCES} PROPERTIES
    COMPILE_OPTIONS "-Wno-deprecated-declarations")

target_include_directories(goattrackerplugin_objs PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(goattrackerplugin_objs PRIVATE coreutils)

# GoatTracker's two no-op stubs `sound_flush()`/`sound_suspend()` (gt2_load.c)
# have external linkage and collide by name with vicepluginbridge's REAL
# VICE functions of the same names -- with different signatures, at that
# (`void sound_flush(void)` vs VICE's `double sound_flush()`).
#
# The hidden-visibility + `ld -r` localization below hides them on ELF, but that
# is a no-op on Windows COFF, where the final link uses
# --allow-multiple-definition and silently binds ALL callers to whichever
# definition comes first. When GoatTracker's empty stub won, VICE's
# vsync_do_vsync() "flushed" nothing, so no SID samples ever reached the sink and
# psid_play() spun forever: SID playback was silent and hung the audio thread.
#
# Rename them out of the shared namespace so correctness no longer depends on
# the ELF-only localization. Both tokens appear solely as this function's
# declaration/definition/calls within GoatTracker, so a plain -D rename is safe.
target_compile_definitions(goattrackerplugin_objs PRIVATE
    sound_flush=gt_sound_flush
    sound_suspend=gt_sound_suspend)
target_compile_options(goattrackerplugin_objs PRIVATE
    -fvisibility=hidden -fvisibility-inlines-hidden)

# Keep the musix::GoatTrackerPlugin methods + goattrackerplugin_register exported
# -- the host and cmtest reference them directly.
set_source_files_properties(GoatTrackerPlugin.cpp PROPERTIES
    COMPILE_OPTIONS "-fvisibility=default;-fvisibility-inlines-hidden")

set(GT_COMBINED ${CMAKE_CURRENT_BINARY_DIR}/goattrackerplugin_combined.o)
# On ELF/GNU ld, `ld -r` does NOT demote hidden-visibility symbols to local
# (unlike macOS's Mach-O `ld -r`), so this plugin's vendored reSID core still
# clashes with the same core in other plugins (e.g. dmfplugin/furnace) at final
# link. Localize it -- but only the *strong* hidden symbols: localizing weak
# COMDAT entries (C++ template/inline/vtable) breaks COMDAT dedup ("defined in
# discarded section"). See ../localize_strong_hidden.cmake.
if(APPLE)
    set(_LOCALIZE_HIDDEN)
else()
    set(_LOCALIZE_HIDDEN COMMAND ${CMAKE_COMMAND}
        -DOBJ=${GT_COMBINED} -DOBJCOPY=${CMAKE_OBJCOPY} -DREADELF=${CMAKE_READELF}
        -P ${CMAKE_CURRENT_SOURCE_DIR}/../localize_strong_hidden.cmake)
endif()
# On Windows, expanding all object paths onto one `ld -r` command line can exceed
# the ~32 KB CreateProcess limit ("The system cannot execute the specified
# program"). Pass them via a GNU ld @response-file instead. Linux/macOS keep the
# direct expansion.
if(WIN32)
    set(_GT_RSP ${CMAKE_CURRENT_BINARY_DIR}/goattrackerplugin_objs.rsp)
    file(GENERATE OUTPUT ${_GT_RSP}
        CONTENT "$<JOIN:$<TARGET_OBJECTS:goattrackerplugin_objs>,\n>")
    set(_GT_LD_CMD COMMAND ld -r @${_GT_RSP} -o ${GT_COMBINED})
else()
    set(_GT_LD_CMD COMMAND ld -r $<TARGET_OBJECTS:goattrackerplugin_objs> -o ${GT_COMBINED})
endif()
add_custom_command(
    OUTPUT ${GT_COMBINED}
    ${_GT_LD_CMD}
    ${_LOCALIZE_HIDDEN}
    DEPENDS goattrackerplugin_objs $<TARGET_OBJECTS:goattrackerplugin_objs>
    COMMAND_EXPAND_LISTS
    VERBATIM
    COMMENT "Localizing goattrackerplugin symbols (ld -r)")
add_custom_target(goattrackerplugin_combine DEPENDS ${GT_COMBINED})

add_library(goattrackerplugin STATIC ${GT_COMBINED})
add_dependencies(goattrackerplugin goattrackerplugin_combine)
set_target_properties(goattrackerplugin PROPERTIES LINKER_LANGUAGE CXX)

if(NOT WIN32)
    target_link_libraries(goattrackerplugin PRIVATE m)
endif()
