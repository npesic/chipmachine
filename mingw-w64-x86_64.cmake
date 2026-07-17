# CMake toolchain file for cross-compiling ChipMachine to Windows (x86-64) with
# MinGW-w64 (GCC) from a Linux host.
#
# The Windows port uses MinGW-w64, NOT MSVC: the tree relies on GNU binutils
# (`ld -r` + `objcopy` plugin combining, `--start-group`), GNU inline asm, and
# `__attribute__`/visibility, none of which MSVC implements. MinGW keeps us on
# GCC + GNU ld so the Linux/GCC bring-up carries over.
#
# Two ways to build for Windows:
#   * Native on Windows via MSYS2 -> use `--target native` in the MINGW64 shell
#     (recommended; MSYS2's pacman provides prebuilt deps). This file is NOT used.
#   * Cross from Linux -> `./build.py build --target windows`, which passes this
#     file. NOTE: you must supply MinGW builds of the dependencies (curl, zlib,
#     sqlite3, mpg123, boost, ffmpeg, freetype, fftw, ...) in the find root --
#     e.g. via MXE, apt's mingw-w64 dev packages where available, or a prefix you
#     built yourself. Point CMake at them with -DMINGW_SYSROOT=/path (or the
#     MINGW_SYSROOT env var).
#
# Usage (from a Linux host with a MinGW-w64 cross toolchain installed):
#   sudo apt install mingw-w64            # x86_64-w64-mingw32-g++ etc.
#   export MINGW_SYSROOT=/usr/x86_64-w64-mingw32   # or your dep prefix
#   ./build.py build --target windows

set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

# Cross toolchain prefix. Override with -DCROSS_PREFIX=... if yours differs.
if(NOT DEFINED CROSS_PREFIX)
    set(CROSS_PREFIX x86_64-w64-mingw32-)
endif()
set(CMAKE_C_COMPILER   ${CROSS_PREFIX}gcc)
set(CMAKE_CXX_COMPILER ${CROSS_PREFIX}g++)
set(CMAKE_RC_COMPILER  ${CROSS_PREFIX}windres)

# MinGW defaults to a shared libgcc/libstdc++ (needs the runtime DLLs alongside
# the exe). Link them statically so cm.exe is self-contained; also pull in the
# pthread runtime statically (the code uses std::thread).
set(_MINGW_STATIC "-static-libgcc -static-libstdc++ -static -lpthread")
set(CMAKE_EXE_LINKER_FLAGS_INIT "${_MINGW_STATIC}")

# Find root = where the MinGW headers/import libs and any cross-built deps live.
# Debian's mingw-w64 packages install under /usr/x86_64-w64-mingw32; override
# with -DMINGW_SYSROOT=/path or the MINGW_SYSROOT env var to add a dep prefix.
if(DEFINED MINGW_SYSROOT)
    set(CMAKE_FIND_ROOT_PATH ${MINGW_SYSROOT})
elseif(DEFINED ENV{MINGW_SYSROOT})
    set(CMAKE_FIND_ROOT_PATH $ENV{MINGW_SYSROOT})
else()
    # Derive /usr/<triple> from the prefix (strip the trailing dash).
    string(REGEX REPLACE "-$" "" _MINGW_TRIPLE "${CROSS_PREFIX}")
    set(CMAKE_FIND_ROOT_PATH /usr/${_MINGW_TRIPLE})
endif()

# Host-side tools on the host; headers/libs/packages from the target root.
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# pkg-config should look inside the MinGW root (many vendored deps probe it).
if(CMAKE_FIND_ROOT_PATH)
    set(ENV{PKG_CONFIG_DIR} "")
    set(ENV{PKG_CONFIG_SYSROOT_DIR} "${CMAKE_FIND_ROOT_PATH}")
    set(ENV{PKG_CONFIG_LIBDIR}
        "${CMAKE_FIND_ROOT_PATH}/lib/pkgconfig:${CMAKE_FIND_ROOT_PATH}/share/pkgconfig")
endif()
