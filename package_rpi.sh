#!/usr/bin/env bash
#
# package_rpi.sh — assemble a self-contained Raspberry Pi 5 (aarch64) tarball.
#
# This is the Linux/RPi counterpart to package_app.sh (the macOS .app packager).
# It produces a flat directory tree that mirrors the macOS bundle logically
# (bin/ ~= Contents/MacOS, root ~= Contents/Resources) and tars it up:
#
#   chipmachine-<ver>-rpi5-aarch64/        <- resource root (main.cpp "work_dir")
#   |-- bin/                               <- Environment::getExeDir()
#   |   |-- chipmachine   (GUI)            <- exe/.. contains data/ -> root resolves
#   |   |-- cm            (textmode)
#   |   |-- sunvox.so                      <- dlopen'd from getExeDir()
#   |   |-- ffmpeg        (aarch64 ELF)    <- on PATH via exeDir
#   |   `-- ytdlp/{yt-dlp,_internal/}      <- found at exeDir/ytdlp
#   |-- data/  lua/
#   `-- music/{Console,hvtc,projectay}/
#
# The layout is dictated by main.cpp's resource resolver: getExeDir() reads
# /proc/self/exe (so launch location is irrelevant), the resolver walks exe/..
# looking for data/, and it prepends exeDir + work_dir/bin to PATH so the bundled
# ffmpeg / yt-dlp are found. Run the result with ./bin/chipmachine (or ./bin/cm).
#
# Shared-library runtime deps (GLFW/GLEW/FFTW/ALSA/FFmpeg/X11/Mesa/curl) are NOT
# bundled — they come from apt on the target Pi (see the generated README). For a
# zero-dependency artifact, an AppImage ($ORIGIN RPATH) is the follow-up.
#
# Usage:
#   ./package_rpi.sh                 # build (incremental) + package from builds/release
#   BUILD_DIR=builds/foo ./package_rpi.sh
#   SKIP_BUILD=1 ./package_rpi.sh    # package whatever is already built
set -euo pipefail

SECONDS=0

# Absolute path to the repo root (this script lives there).
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
CM_DIR="${SCRIPT_DIR}"

# Native Pi builds land in builds/release (see rpi/PLAN.md §11). Override with
# BUILD_DIR=... for a different tree (e.g. a cross build's builds/raspberry-release).
BUILD_DIR="${BUILD_DIR:-${CM_DIR}/builds/release}"

SUNVOX_SO="${CM_DIR}/external/musicplayer/src/plugins/sunvoxplugin/sunvox_lib/sunvox.so"

# ---------------------------------------------------------------------------
# Version string (single source of truth: src/version.h) — names the artifact.
# ---------------------------------------------------------------------------
VERSION_H="${CM_DIR}/src/version.h"
[ -f "${VERSION_H}" ] || { echo "CRITICAL: version header not found at ${VERSION_H}"; exit 1; }
VERSION_STR="$(sed -n 's/#define VERSION_STR "\(.*\)"/\1/p' "${VERSION_H}" | tr -d '[:space:]')"
[ -n "${VERSION_STR}" ] || { echo "CRITICAL: could not parse VERSION_STR from ${VERSION_H}"; exit 1; }

PKG_NAME="chipmachine-${VERSION_STR}-rpi5-aarch64"
DIST_DIR="${CM_DIR}/dist"
STAGE="${DIST_DIR}/${PKG_NAME}"
TARBALL="${DIST_DIR}/${PKG_NAME}.tar.gz"

echo "=== Raspberry Pi 5 (aarch64) packaging ==="
echo "Repo:       ${CM_DIR}"
echo "Build dir:  ${BUILD_DIR}"
echo "Version:    ${VERSION_STR}"
echo "Output:     ${TARBALL}"

# ---------------------------------------------------------------------------
# 0. Build chipmachine + cm (incremental) unless SKIP_BUILD=1.
#    Only build when the tree is already CMake-configured — configuring picks the
#    build type/generator, which is the developer's decision, not the packager's
#    (same policy as package_app.sh).
# ---------------------------------------------------------------------------
if [ "${SKIP_BUILD:-0}" = "1" ]; then
    echo "-> SKIP_BUILD=1: packaging existing binaries."
elif [ -f "${BUILD_DIR}/CMakeCache.txt" ] || [ -f "${BUILD_DIR}/build.ninja" ]; then
    echo "-> Building chipmachine + cm (incremental)..."
    cmake --build "${BUILD_DIR}" --target chipmachine cm
else
    echo "WARNING: ${BUILD_DIR} is not CMake-configured; packaging whatever binaries exist."
    echo "         Configure first, e.g.:"
    echo "           cmake -B ${BUILD_DIR} -GNinja -DCMAKE_BUILD_TYPE=Release"
fi

# ---------------------------------------------------------------------------
# 1. Pristine staging tree.
# ---------------------------------------------------------------------------
rm -rf "${STAGE}"
mkdir -p "${STAGE}/bin"

# ---------------------------------------------------------------------------
# 2. Binaries. chipmachine is required; cm is required per this build's intent.
#    Verify each is an aarch64 ELF so we never ship a macOS/x86 binary by mistake.
# ---------------------------------------------------------------------------
check_aarch64() {
    # $1 = file, $2 = human label. Hard-fail on wrong arch (a corrupt release is
    # worse than no release).
    local f="$1" label="$2"
    if ! file "$f" | grep -q 'ELF'; then
        echo "CRITICAL: ${label} (${f}) is not an ELF binary — wrong build tree?"; exit 1
    fi
    if ! file "$f" | grep -q 'aarch64'; then
        echo "CRITICAL: ${label} (${f}) is not aarch64 — build it on/for the Pi 5."; exit 1
    fi
}

for tgt in chipmachine cm; do
    src="${BUILD_DIR}/${tgt}"
    [ -f "${src}" ] || { echo "CRITICAL: ${tgt} not found at ${src}. Build it first."; exit 1; }
    check_aarch64 "${src}" "${tgt}"
    echo "-> Bundling binary: ${tgt}"
    cp "${src}" "${STAGE}/bin/${tgt}"
    chmod +x "${STAGE}/bin/${tgt}"
done

# ---------------------------------------------------------------------------
# 3. SunVox engine (aarch64 .so, dlopen'd from getExeDir() at runtime).
# ---------------------------------------------------------------------------
if [ -f "${SUNVOX_SO}" ]; then
    check_aarch64 "${SUNVOX_SO}" "sunvox.so"
    echo "-> Bundling SunVox engine (sunvox.so)"
    cp "${SUNVOX_SO}" "${STAGE}/bin/sunvox.so"
else
    echo "WARNING: sunvox.so not found at ${SUNVOX_SO}. .sunvox playback will fail."
    echo "         See rpi/PLAN.md §12 Finding 5 for how to vendor the aarch64 blob."
fi

# ---------------------------------------------------------------------------
# 4. Helper tools: ffmpeg (aarch64 ELF) + yt-dlp (python zipapp, arch-neutral).
#    main.cpp puts exeDir (bin/) and work_dir/bin on PATH, so both resolve.
# ---------------------------------------------------------------------------
if [ -f "${CM_DIR}/bin/ffmpeg" ]; then
    check_aarch64 "${CM_DIR}/bin/ffmpeg" "bin/ffmpeg"
    echo "-> Bundling ffmpeg"
    cp "${CM_DIR}/bin/ffmpeg" "${STAGE}/bin/ffmpeg"
    chmod +x "${STAGE}/bin/ffmpeg"
else
    echo "WARNING: bin/ffmpeg not found. Streaming/YouTube needs 'apt install ffmpeg' on the Pi."
fi

if [ -d "${CM_DIR}/bin/ytdlp" ]; then
    echo "-> Bundling yt-dlp (onedir)"
    cp -R "${CM_DIR}/bin/ytdlp" "${STAGE}/bin/ytdlp"
    [ -f "${STAGE}/bin/ytdlp/yt-dlp" ] && chmod +x "${STAGE}/bin/ytdlp/yt-dlp"
else
    echo "WARNING: bin/ytdlp not found. YouTube playback will be unavailable."
fi

# ---------------------------------------------------------------------------
# 5. Resource payloads at the root (this dir IS the resolver's work_dir).
# ---------------------------------------------------------------------------
if [ -d "${CM_DIR}/data" ]; then
    echo "-> Bundling data/"
    cp -R "${CM_DIR}/data" "${STAGE}/data"
else
    echo "CRITICAL: data/ not found at ${CM_DIR}/data — the app cannot start without it."; exit 1
fi

if [ -d "${CM_DIR}/lua" ]; then
    echo "-> Bundling lua/"
    cp -R "${CM_DIR}/lua" "${STAGE}/lua"
else
    echo "WARNING: lua/ not found. Scripting/database features may fail."
fi

# ---------------------------------------------------------------------------
# 6. Bundled music stores (locally-shipped collections with no network fallback:
#    Console/.nsfe, hvtc/.prg, projectay/.ay). Sub-directory hierarchy preserved
#    verbatim — the DB song paths are relative to it.
# ---------------------------------------------------------------------------
mkdir -p "${STAGE}/music"
for store in Console hvtc projectay; do
    src="${CM_DIR}/music/${store}"
    if [ -d "${src}" ]; then
        n="$(find "${src}" -type f | wc -l | tr -d '[:space:]')"
        echo "-> Bundling music/${store}/ (${n} file(s))"
        cp -R "${src}" "${STAGE}/music/${store}"
    else
        echo "WARNING: music/${store} not found — those built-in tracks will be unavailable."
    fi
done

# ---------------------------------------------------------------------------
# 7. README with the target-Pi runtime dependency line.
# ---------------------------------------------------------------------------
cat > "${STAGE}/README.txt" <<EOF
ChipMachine ${VERSION_STR} — Raspberry Pi 5 (64-bit aarch64) build
==================================================================

Run:
    ./bin/chipmachine       # GUI (needs an X/XWayland desktop session)
    ./bin/cm -X             # text-mode player in a terminal

The binary finds its own data/, lua/ and music/ via /proc/self/exe, so you can
launch it from anywhere and you can move this whole folder wherever you like —
just keep bin/ next to data/, lua/ and music/.

Runtime dependencies (shared libraries) are NOT bundled; install them once on a
64-bit Raspberry Pi OS (Bookworm) desktop:

    sudo apt update
    sudo apt install \\
        libglfw3 libglew2.2 libfftw3-single3 libfreetype6 libasound2 \\
        libcurl4 libgl1 libx11-6 libxxf86vm1 libxrandr2 libxi6 \\
        libxinerama1 libxcursor1 ffmpeg python3

Most are already present on a Pi OS *desktop* image (X11, Mesa, FreeType, ALSA,
curl); typically only libglfw3 / libglew2.2 / libfftw3-single3 and the ffmpeg
runtime need adding. The GUI requires a desktop session (Wayland works via
XWayland); a headless SSH shell has no GL context.

Bundled helpers: bin/ffmpeg (aarch64), bin/ytdlp (yt-dlp, needs system python3),
bin/sunvox.so (aarch64 SunVox engine).
EOF
echo "-> Wrote README.txt"

# ---------------------------------------------------------------------------
# 8. Tar it up (tar preserves exec bits and the ytdlp/_internal tree). The
#    archive contains the single top-level ${PKG_NAME}/ directory.
# ---------------------------------------------------------------------------
echo "-> Creating ${TARBALL} ..."
rm -f "${TARBALL}"
tar -czf "${TARBALL}" -C "${DIST_DIR}" "${PKG_NAME}"

SIZE="$(du -sh "${TARBALL}" | cut -f1)"
echo "=== Done: ${TARBALL} (${SIZE}) ==="
printf '=== Total packaging time: %dm %02ds ===\n' $((SECONDS / 60)) $((SECONDS % 60))
echo
echo "Test on the Pi:"
echo "    tar xzf ${PKG_NAME}.tar.gz && ./${PKG_NAME}/bin/chipmachine"
