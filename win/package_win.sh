#!/usr/bin/env bash
#
# Windows beta packaging — produces a self-contained, double-clickable ZIP.
#
# RUN THIS IN THE MSYS2 **mingw64** SHELL on the Windows build box (the same
# environment chipmachine.exe was built in), NOT in cmd.exe or the plain MSYS
# shell — DLL discovery resolves dependencies against /mingw64/bin, which only
# that environment puts on PATH.
#
# The Windows counterpart of package_app.sh (macOS). Where the .app relies on
# Contents/Resources + install_name_tool, Windows just needs a FLAT folder:
#   - chipmachine.exe links -mwindows (GUI subsystem) so double-click shows no
#     console window (CMakeLists.txt);
#   - on Windows getAppDir()==getExeDir() and that is the last asset search
#     candidate (main.cpp / file.cpp), so data/ lua/ music/ bin/ sitting right
#     next to the exe are found with zero configuration.
#
# Usage:
#   ./win/package_win.sh [BUILD_DIR]
# BUILD_DIR defaults to builds/release inside the repo (where ninja builds
# chipmachine.exe on the Windows box); pass an explicit path to override.
set -euo pipefail
SECONDS=0

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
CHIPMACHINE_DIR="$(cd "${SCRIPT_DIR}/.." && pwd)"
BUILD_DIR="${1:-${CHIPMACHINE_DIR}/builds/release}"

# Staging lives INSIDE the repo under win/dist/ — never as a sibling of the repo.
# A sibling named "ChipMachine" collides with a repo folder named "chipmachine"
# on a case-insensitive Windows filesystem, and the `rm -rf` below would then
# delete the repo itself. Keeping it at a fixed, repo-relative subpath makes the
# target un-ambiguous (and the guard below refuses anything outside win/dist/).
STAGE_NAME="ChipMachine"
DIST_DIR="${CHIPMACHINE_DIR}/win/dist"
STAGE_DIR="${DIST_DIR}/${STAGE_NAME}"
ZIP_OUT="${DIST_DIR}/ChipMachine-win.zip"

# Safety guard: refuse to `rm -rf` anything that is not our dedicated staging
# dir. Belt-and-braces against a future edit reintroducing a path that resolves
# to the repo, a parent, or the CWD. Compares resolved parents because STAGE_DIR
# itself may not exist yet.
safe_rm_stage() {
    local target="$1"
    local parent
    parent="$(cd "$(dirname "${target}")" 2>/dev/null && pwd -P)" || {
        echo "CRITICAL: staging parent does not exist; refusing rm."; exit 1; }
    local resolved="${parent}/$(basename "${target}")"
    local repo; repo="$(cd "${CHIPMACHINE_DIR}" && pwd -P)"
    case "${resolved}" in
        "${repo}/win/dist/"*) : ;;   # the only path we ever delete
        *) echo "CRITICAL: refusing to rm '${resolved}' (not under win/dist/)."; exit 1 ;;
    esac
    # Never delete the repo, an ancestor of it, or the current directory.
    if [ "${resolved}" = "${repo}" ] || [ "${repo#${resolved}/}" != "${repo}" ] \
       || [ "${resolved}" = "$(pwd -P)" ]; then
        echo "CRITICAL: refusing to rm '${resolved}' (repo/ancestor/CWD)."; exit 1
    fi
    rm -rf "${resolved}"
}

EXE_SRC="${BUILD_DIR}/chipmachine.exe"

# --- Version (shared with the macOS packager: src/version.h) -----------------
VERSION_H="${CHIPMACHINE_DIR}/src/version.h"
VERSION_STR="$(sed -n 's/#define VERSION_STR "\(.*\)"/\1/p' "${VERSION_H}" | tr -d '[:space:]')"
[ -n "${VERSION_STR}" ] || { echo "CRITICAL: no VERSION_STR in ${VERSION_H}"; exit 1; }

echo "=== ChipMachine Windows packaging ==="
echo "Repo:    ${CHIPMACHINE_DIR}"
echo "Build:   ${BUILD_DIR}"
echo "Stage:   ${STAGE_DIR}"
echo "Version: ${VERSION_STR}"

# 0. Rebuild (incremental) so the shipped exe matches source — only if the build
#    dir is already CMake-configured; we never choose Release/Debug for the dev.
if [ -f "${BUILD_DIR}/CMakeCache.txt" ]; then
    echo "-> Building chipmachine target (incremental)..."
    cmake --build "${BUILD_DIR}" --target chipmachine
else
    echo "WARNING: ${BUILD_DIR} is not CMake-configured; packaging existing exe."
fi
[ -f "${EXE_SRC}" ] || { echo "CRITICAL: ${EXE_SRC} not found."; exit 1; }

# 1. Pristine staging dir (guarded delete — see safe_rm_stage).
safe_rm_stage "${STAGE_DIR}"
mkdir -p "${STAGE_DIR}"

# 2. The executable.
echo "-> Copying chipmachine.exe..."
cp "${EXE_SRC}" "${STAGE_DIR}/"

# 3. Recursive DLL discovery.
#
# The exe pulls a large, build-specific DLL closure (libstdc++/libgcc/
# winpthread, OpenSSL, GLFW/freetype, the whole FFmpeg libav* stack, ...). We do
# NOT hard-code it — we walk the real dependency tree of the built exe with
# ntldd and copy every DLL that resolves inside the MinGW prefix. DLLs under
# C:\Windows (system32) are OS-provided (kernel32, opengl32, winmm, ws2_32, ...)
# and must NOT be bundled, so we filter to the mingw prefix only.
MINGW_PREFIX="${MINGW_PREFIX:-/mingw64}"
command -v ntldd >/dev/null 2>&1 || {
    echo "CRITICAL: 'ntldd' not found. Install it:  pacman -S mingw-w64-x86_64-ntldd"
    exit 1
}
echo "-> Resolving DLL dependencies (ntldd -R)..."
# ntldd -R prints lines like "  libFoo.dll => /mingw64/bin/libFoo.dll (0x...)".
# Keep only resolved paths under the mingw prefix; copy each once.
copied=0
while IFS= read -r dll; do
    [ -f "${dll}" ] || continue
    base="$(basename "${dll}")"
    [ -f "${STAGE_DIR}/${base}" ] && continue
    cp "${dll}" "${STAGE_DIR}/"
    copied=$((copied + 1))
    echo "     + ${base}"
done < <(
    ntldd -R "${EXE_SRC}" \
        | sed -n 's/.*=> \(.*\) (0x[0-9a-fA-F]*)/\1/p' \
        | tr '\\' '/' \
        | grep -iE "^${MINGW_PREFIX}/|/mingw64/" \
        | sort -u
)
echo "   Bundled ${copied} DLL(s)."
[ "${copied}" -gt 0 ] || echo "WARNING: no DLLs bundled — is this the mingw64 shell?"

# 4. Runtime assets: data/ and lua/ (asset root == exe dir on Windows).
echo "-> Copying data/ and lua/ ..."
cp -R "${CHIPMACHINE_DIR}/data" "${STAGE_DIR}/"
cp -R "${CHIPMACHINE_DIR}/lua"  "${STAGE_DIR}/"

# 5. Bundled music collections with EMPTY remote sources — these MUST ship or the
#    tunes fail with no network fallback (mirrors package_app.sh 4b/4c/4d).
for coll in "Console:*.nsfe" "hvtc:*.prg" "projectay:*.ay"; do
    dir="${coll%%:*}"; glob="${coll##*:}"
    src="${CHIPMACHINE_DIR}/music/${dir}"
    if [ -d "${src}" ]; then
        n="$(find "${src}" -name "${glob}" | wc -l | tr -d '[:space:]')"
        echo "-> Bundling music/${dir} (${n} ${glob} file(s))..."
        mkdir -p "${STAGE_DIR}/music/${dir}"
        cp -R "${src}/." "${STAGE_DIR}/music/${dir}/"
    else
        echo "CRITICAL: music/${dir} missing — a release must bundle it."; exit 1
    fi
done

# 6. Helper tools (see PLAN.md §27). ffmpeg is called by explicit path bin\
#    ffmpeg.exe; yt-dlp must be the Windows *onedir* build (yt-dlp.exe + _internal).
echo "-> Copying helper tools (bin/)..."
mkdir -p "${STAGE_DIR}/bin"
if [ -f "${CHIPMACHINE_DIR}/bin/ffmpeg.exe" ]; then
    cp "${CHIPMACHINE_DIR}/bin/ffmpeg.exe" "${STAGE_DIR}/bin/"
else
    echo "WARNING: bin/ffmpeg.exe missing — mp3/ogg/flac + streaming will fail."
fi
if [ -d "${CHIPMACHINE_DIR}/bin/ytdlp" ] && [ -f "${CHIPMACHINE_DIR}/bin/ytdlp/yt-dlp.exe" ]; then
    cp -R "${CHIPMACHINE_DIR}/bin/ytdlp" "${STAGE_DIR}/bin/"
else
    echo "WARNING: bin/ytdlp/yt-dlp.exe (Windows onedir) missing — YouTube will fail."
fi

# 7. CA bundle for standalone HTTPS (main.cpp: work_dir/cert.pem -> SSL_CERT_FILE).
CERT_SRC=""
for c in "${MINGW_PREFIX}/etc/ssl/certs/ca-bundle.crt" \
         "${MINGW_PREFIX}/ssl/certs/ca-bundle.crt" \
         "/etc/ssl/certs/ca-bundle.crt"; do
    [ -f "${c}" ] && { CERT_SRC="${c}"; break; }
done
if [ -n "${CERT_SRC}" ]; then
    echo "-> Copying CA bundle (${CERT_SRC}) -> cert.pem ..."
    cp "${CERT_SRC}" "${STAGE_DIR}/cert.pem"
else
    echo "WARNING: no CA bundle found — HTTPS sources may fail."
    echo "         Install with: pacman -S mingw-w64-x86_64-ca-certificates"
fi

# 8. Zip it (the folder itself is the zip root, so it unzips to ChipMachine/).
echo "-> Creating ${ZIP_OUT} ..."
rm -f "${ZIP_OUT}"
( cd "${DIST_DIR}" && zip -r -q "${ZIP_OUT}" "${STAGE_NAME}" )

echo "=== Done: ${ZIP_OUT} ==="
printf '=== Total packaging time: %dm %02ds ===\n' $((SECONDS / 60)) $((SECONDS % 60))
echo "Smoke test: unzip somewhere fresh and double-click ${STAGE_NAME}/chipmachine.exe"
