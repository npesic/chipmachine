# CMake toolchain file for cross-compiling ChipMachine to the Raspberry Pi 5.
#
# The Pi 5 is a 64-bit aarch64 machine (Broadcom BCM2712, quad Cortex-A76)
# running 64-bit Raspberry Pi OS (Debian Bookworm). This is an ordinary
# Linux/aarch64 target -- it does NOT use the legacy 32-bit ARMv6 "RASPBERRYPI"
# path in the root CMakeLists.txt, and it does NOT use the removed Broadcom
# VideoCore (bcm_host) GL path.
#
# Usage (from another Linux host with an aarch64 cross toolchain installed):
#   sudo apt install crossbuild-essential-arm64      # aarch64-linux-gnu-g++ etc.
#   export RPI_SYSROOT=/path/to/pi-rootfs            # rsync'd from the Pi
#   ./build.py build --target raspberry
# or directly:
#   cmake -B build-rpi -DCMAKE_TOOLCHAIN_FILE=rpi5-aarch64.cmake -DRPI_SYSROOT=...
#
# For a fully native build ON the Pi itself, do NOT use this file -- just build
# normally (./build.py build --target native).

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

# Cross compilers. Override the triple with -DCROSS_PREFIX=... if yours differs
# (e.g. a Bootlin / crosstool-NG toolchain).
if(NOT DEFINED CROSS_PREFIX)
    set(CROSS_PREFIX aarch64-linux-gnu-)
endif()
set(CMAKE_C_COMPILER   ${CROSS_PREFIX}gcc)
set(CMAKE_CXX_COMPILER ${CROSS_PREFIX}g++)

# Cortex-A76 tuning for the Pi 5. On aarch64, -mcpu selects both the base
# architecture and the scheduling model, so no -march/-mfpu/-mfloat-abi is
# needed (those 32-bit ARM flags are exactly what the legacy path got wrong).
set(_RPI5_ARCH_FLAGS "-mcpu=cortex-a76")
set(CMAKE_C_FLAGS_INIT   "${_RPI5_ARCH_FLAGS}")
set(CMAKE_CXX_FLAGS_INIT "${_RPI5_ARCH_FLAGS}")

# Sysroot: a copy of the Pi's root filesystem so the many system/apt libraries
# (ALSA, GLFW, GLEW, X11, FreeType, Boost, FFmpeg, ...) and their headers are
# found for the target rather than the host. Pass via -DRPI_SYSROOT=/path or the
# RPI_SYSROOT env var. Leaving it unset only makes sense inside an aarch64
# container where the target libraries live in the normal locations.
if(DEFINED RPI_SYSROOT)
    set(CMAKE_SYSROOT ${RPI_SYSROOT})
elseif(DEFINED ENV{RPI_SYSROOT})
    set(CMAKE_SYSROOT $ENV{RPI_SYSROOT})
endif()

# Find host-side executables (compilers, tools) on the host, but resolve
# headers/libraries/packages against the target sysroot.
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# pkg-config should look inside the sysroot too (many vendored deps probe it).
if(CMAKE_SYSROOT)
    set(ENV{PKG_CONFIG_DIR} "")
    set(ENV{PKG_CONFIG_SYSROOT_DIR} "${CMAKE_SYSROOT}")
    set(ENV{PKG_CONFIG_LIBDIR}
        "${CMAKE_SYSROOT}/usr/lib/aarch64-linux-gnu/pkgconfig:${CMAKE_SYSROOT}/usr/lib/pkgconfig:${CMAKE_SYSROOT}/usr/share/pkgconfig")
endif()
