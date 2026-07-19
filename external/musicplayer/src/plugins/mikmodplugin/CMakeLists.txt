cmake_minimum_required(VERSION 3.15)
project(cpp-mods.musicplayer.mikmodplugin)

# Vendored slice of libmikmod 3.3.13 (LGPL-2.1+, https://mikmod.sourceforge.net/)
# Just enough to load and render MikMod UNITRK / UNIMOD modules (.uni):
# the player core + software mixer + the UNI loader + the null driver + the
# generic depackers. The OS sound drivers and the other format loaders are
# intentionally omitted (we register only drv_nos and load_uni at runtime).
set(MIKMOD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libmikmod)

set(MIKMOD_SOURCES
    ${MIKMOD_DIR}/playercode/mdriver.c
    ${MIKMOD_DIR}/playercode/mdulaw.c
    ${MIKMOD_DIR}/playercode/mloader.c
    ${MIKMOD_DIR}/playercode/mlutil.c
    ${MIKMOD_DIR}/playercode/mplayer.c
    ${MIKMOD_DIR}/playercode/munitrk.c
    ${MIKMOD_DIR}/playercode/npertab.c
    ${MIKMOD_DIR}/playercode/sloader.c
    ${MIKMOD_DIR}/playercode/virtch.c
    ${MIKMOD_DIR}/playercode/virtch2.c
    ${MIKMOD_DIR}/playercode/virtch_common.c
    ${MIKMOD_DIR}/mmio/mmalloc.c
    ${MIKMOD_DIR}/mmio/mmerror.c
    ${MIKMOD_DIR}/mmio/mmio.c
    ${MIKMOD_DIR}/loaders/load_uni.c
    ${MIKMOD_DIR}/drivers/drv_nos.c
    ${MIKMOD_DIR}/depackers/mmcmp.c
    ${MIKMOD_DIR}/depackers/pp20.c
    ${MIKMOD_DIR}/depackers/s404.c
    ${MIKMOD_DIR}/depackers/xpk.c
    ${MIKMOD_DIR}/posix/strcasecmp.c)

# libmikmod exposes a host of generic, un-prefixed internal helpers
# (getfrequency, getlinearperiod, ...) that collide with other vendored
# trackers (e.g. playerproplugin). Build everything with hidden visibility and
# partial-link with `ld -r`, which demotes the resulting private externs to true
# local symbols. MIKMODAPI is empty unless SYM_VISIBILITY is defined, so hiding
# applies to the whole library; only MikModPlugin.cpp stays at default
# visibility so musix::MikModPlugin and mikmodplugin_register remain exported.
add_library(mikmodplugin_objs OBJECT MikModPlugin.cpp MikModPlugin.h ${MIKMOD_SOURCES})

set_source_files_properties(${MIKMOD_SOURCES} PROPERTIES
    COMPILE_DEFINITIONS "HAVE_CONFIG_H;MIKMOD_STATIC"
    # Vendored libmikmod uses sprintf(), which the macOS SDK marks deprecated.
    # Don't police third-party sources -- silence it here rather than patch them
    # (which would need re-applying on every revendor). Our own MikModPlugin.cpp
    # is not in this list, so it stays strict.
    COMPILE_OPTIONS "-Wno-deprecated-declarations")

target_include_directories(mikmodplugin_objs PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${MIKMOD_DIR}
    ${MIKMOD_DIR}/include)

target_link_libraries(mikmodplugin_objs PRIVATE coreutils)
target_compile_options(mikmodplugin_objs PRIVATE
    -fvisibility=hidden -fvisibility-inlines-hidden)

# Keep the musix::MikModPlugin methods exported -- the host and cmtest reference
# the class directly. Only the vendored libmikmod symbols need hiding.
set_source_files_properties(MikModPlugin.cpp PROPERTIES
    COMPILE_OPTIONS "-fvisibility=default;-fvisibility-inlines-hidden")

set(MIKMOD_COMBINED ${CMAKE_CURRENT_BINARY_DIR}/mikmodplugin_combined.o)
# On ELF/GNU ld, `ld -r` does NOT demote hidden-visibility symbols to local
# (unlike macOS's Mach-O `ld -r`), so libmikmod's cores (getfrequency, ...)
# still clash with the same-named symbols in other plugins at final link.
# Localize them -- but only the *strong* hidden symbols: localizing weak COMDAT
# entries (C++ template/inline/vtable) breaks COMDAT dedup ("defined in
# discarded section"). See ../localize_strong_hidden.cmake.
if(APPLE)
    set(_LOCALIZE_HIDDEN)
else()
    set(_LOCALIZE_HIDDEN COMMAND ${CMAKE_COMMAND}
        -DOBJ=${MIKMOD_COMBINED} -DOBJCOPY=${CMAKE_OBJCOPY} -DREADELF=${CMAKE_READELF}
        -P ${CMAKE_CURRENT_SOURCE_DIR}/../localize_strong_hidden.cmake)
endif()
# On Windows, expanding all object paths onto one `ld -r` command line can exceed
# the ~32 KB CreateProcess limit ("The system cannot execute the specified
# program"). Pass them via a GNU ld @response-file instead. Linux/macOS keep the
# direct expansion.
if(WIN32)
    set(_MIKMOD_RSP ${CMAKE_CURRENT_BINARY_DIR}/mikmodplugin_objs.rsp)
    file(GENERATE OUTPUT ${_MIKMOD_RSP}
        CONTENT "$<JOIN:$<TARGET_OBJECTS:mikmodplugin_objs>,\n>")
    set(_MIKMOD_LD_CMD COMMAND ld -r @${_MIKMOD_RSP} -o ${MIKMOD_COMBINED})
else()
    set(_MIKMOD_LD_CMD COMMAND ld -r $<TARGET_OBJECTS:mikmodplugin_objs> -o ${MIKMOD_COMBINED})
endif()
add_custom_command(
    OUTPUT ${MIKMOD_COMBINED}
    ${_MIKMOD_LD_CMD}
    ${_LOCALIZE_HIDDEN}
    DEPENDS mikmodplugin_objs $<TARGET_OBJECTS:mikmodplugin_objs>
    COMMAND_EXPAND_LISTS
    VERBATIM
    COMMENT "Localizing mikmodplugin symbols (ld -r)")
add_custom_target(mikmodplugin_combine DEPENDS ${MIKMOD_COMBINED})

add_library(mikmodplugin STATIC ${MIKMOD_COMBINED})
add_dependencies(mikmodplugin mikmodplugin_combine)
set_target_properties(mikmodplugin PROPERTIES LINKER_LANGUAGE CXX)

if(NOT WIN32)
    target_link_libraries(mikmodplugin PRIVATE m)
endif()
