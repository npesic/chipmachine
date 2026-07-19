cmake_minimum_required(VERSION 3.15)
project(cpp-mods.musicplayer.sunvoxplugin)

set(SUNVOX_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/sunvox_lib)

add_library(sunvoxplugin SunVoxPlugin.cpp SunVoxPlugin.h)

target_include_directories(sunvoxplugin PRIVATE ${SUNVOX_LIB_DIR})

# The SunVox engine is dlopen()ed at runtime, so we only need libdl here, not a
# link-time dependency on the prebuilt shared library.
target_link_libraries(sunvoxplugin PRIVATE coreutils ${CMAKE_DL_LIBS})

# Expose the runtime library path so executables can copy it next to themselves.
# The engine is a prebuilt per-platform binary and must match what the plugin's
# libName() dlopen()s at runtime (sunvox.dll / .dylib / .so). Only the macOS
# build is vendored in this tree, so on other platforms there is nothing to copy
# -- leave SUNVOX_RUNTIME_LIB empty rather than shipping a library the loader
# cannot use (copying sunvox.dylib next to a Windows .exe made LoadLibrary fail
# with error 126, ERROR_MOD_NOT_FOUND). To add a platform, drop the matching
# binary from the official SunVox library distribution into sunvox_lib/.
if(WIN32)
    set(_sunvox_lib ${SUNVOX_LIB_DIR}/sunvox.dll)
elseif(APPLE)
    set(_sunvox_lib ${SUNVOX_LIB_DIR}/sunvox.dylib)
else()
    set(_sunvox_lib ${SUNVOX_LIB_DIR}/sunvox.so)
endif()
if(EXISTS ${_sunvox_lib})
    set(SUNVOX_RUNTIME_LIB ${_sunvox_lib}
        CACHE INTERNAL "SunVox runtime shared library")
else()
    set(SUNVOX_RUNTIME_LIB "" CACHE INTERNAL "SunVox runtime shared library")
endif()
