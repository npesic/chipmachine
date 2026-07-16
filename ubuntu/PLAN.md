# Plan: Build ChipMachine `cm` on Ubuntu Linux

Goal: reach the same milestone as the Raspberry Pi 5 — the text-mode `cm`
executable (and by extension `chipmachine`, `cmtest`, `mksonglist`) compiling and
linking on Ubuntu.

## TL;DR

Ubuntu is **most of the way there already**. Every one of the 12 fixes made for
the Pi was a generic **Linux / glibc / GNU-ld** issue, not an aarch64 one — and
they were largely validated on an x86_64 Debian 12 (Bookworm) host, which is
Ubuntu's immediate cousin (same glibc, same GNU ld, same binutils, same
`objcopy`/`readelf`). So on **Ubuntu x86_64** the expectation is: install deps →
`./build.py build --target native` → a short triage pass → `cm` links.

The only genuinely *new* work vs. the Pi is a small triage of **ISA-gated code
paths that activate on x86_64 but were dormant on aarch64**, plus (on Ubuntu
24.04) a little **newer-GCC strictness**.

No cross-compilation and no toolchain file are needed: on Ubuntu the build is
`--target native` (the host builds for itself), whether that host is x86_64 or
arm64.

## 1. Scope decisions (pick before starting)

| Choice | Options | Recommendation |
| --- | --- | --- |
| Ubuntu release | 22.04 LTS (GCC 11/12) · 24.04 LTS (GCC 13/14) | Target **24.04 LTS**; also smoke-test 22.04. 24.04's newer GCC is the stricter case, so if it's clean, 22.04 is too. |
| Architecture | amd64 (x86_64) · arm64 (aarch64) | **amd64** is the point of this task. Note: **arm64 Ubuntu is essentially the Pi build** already proven — same aarch64 path, just apt instead of the Pi image. |
| Milestone target | `cm` (textmode) first | Same as the Pi: `cm` needs no GL/X11, so it isolates the engine from the GUI. Do `cm` first, then `chipmachine`. |

## 2. What already carries over from the Pi work (no changes needed)

All 12 fixes are architecture-neutral and apply to Ubuntu unchanged:

| # | Fix | Nature | x86_64-relevant? |
| --- | --- | --- | --- |
| 1 | gme `blargg_source.h` → `#include <stdio.h>` before `dprintf` macro | glibc transitive-include | yes |
| 2 | 98fmplayer `leveldata.h` C++ `<atomic>` guard | libstdc++ vs libc++ | yes |
| 3 | protrekkr `ptk_types.h` → unconditional `<stdint.h>` | glibc transitive-include | yes |
| 4 | playerpro `MainDriver.c` unconditional `MADCFReadStreamType` | Apple-guard gap | yes |
| 5 | playerpro `PPStubs.c` `#ifdef _MAC_H` around CoreFoundation | Apple-only include | yes |
| 6 | famitracker `time.hpp` → `#include <unistd.h>` (`usleep`) | glibc transitive-include | yes |
| 7 | furnace `filePlayer.h` → `#include <climits>` (`UINT_MAX`) | glibc transitive-include | yes |
| 8 | apone `exec.h` — hoist `<signal.h>` etc. out of `namespace utils` | ns-scoped system header | yes |
| 9 | root CMake — `--start-group/--end-group` link-rule override | GNU ld single-pass archives | yes |
| 10 | 7 plugins — localize combined-object symbols (`objcopy`) | GNU ld vs ld64 dedup | yes |
| 11 | localize only **strong** hidden syms (`localize_strong_hidden.cmake`) | ELF COMDAT | yes |
| 12 | zxtune wrapper — build+link `devices_aym_dumper` | GNU ld keeps dead code (no `-dead_strip`) | yes |

Because all of these are already committed on the `rpi` branch, an Ubuntu build
from that branch starts with them in place.

## 3. Phase 1 — Provision the build environment

Install the toolchain and the runtime `-dev` packages the `cm` link needs (these
mirror the Pi's known-good set; Ubuntu shares Debian package names). Library
paths differ only by the multiarch triple (`x86_64-linux-gnu` instead of
`aarch64-linux-gnu`), which CMake/pkg-config resolve automatically.

```sh
sudo apt update
sudo apt install -y \
    build-essential cmake ninja-build git pkg-config ccache \
    libasound2-dev \
    libcurl4-openssl-dev \
    libmpg123-dev \
    zlib1g-dev \
    libavcodec-dev libavformat-dev libavutil-dev libswresample-dev \
    libfreetype-dev \
    libboost-dev \
    libfftw3-dev
```

`libboost-dev` (headers only — zxtune uses header-only Boost, `find_package(Boost
REQUIRED)` with no components) is a configure-time dep for the zxtuneplugin.
`libfftw3-dev` supplies single-precision FFTW (`libfftw3f` + `fftw3.h`) for the
apone `fft`/spectrum module, which is defined unconditionally at generate time.

Note: **`libfreetype-dev` is a configure-time dependency even for `cm`**, not a
GUI-only one — grappix's `CMakeLists.txt` runs `find_package(Freetype REQUIRED)`
and grappix is added to the tree unconditionally, so configure fails without it
regardless of which target you build. (On Ubuntu 22.04 the package may be named
`libfreetype6-dev`.)

CMake version: Ubuntu 22.04 ships **CMake 3.22**, 24.04 ships 3.28. The tree
declares a 3.15 minimum and is kept compatible with it — e.g. the
`add_subdirectory(... SYSTEM)` calls are guarded so 3.22 doesn't misparse the
3.25-only `SYSTEM` keyword. No newer CMake needs to be installed.

For the GUI `chipmachine` target later (NOT needed for the `cm` milestone), add:

```sh
sudo apt install -y \
    libgl1-mesa-dev libglu1-mesa-dev libglew-dev libglfw3-dev \
    libx11-dev libxi-dev libxcursor-dev libxrandr-dev libxinerama-dev
```

## 4. Phase 2 — Native build

```sh
./build.py build --target native            # release, ninja, host arch
# textmode-first, matching the Pi bring-up:
ninja -C builds/release cm
```

`--target native` uses no toolchain file and no `-mcpu` flag; the host compiler
builds for the host. The per-target build-dir logic already gives native its own
`builds/release` tree, distinct from `builds/raspberry-release`.

## 5. Phase 3 — Expected residual triage

The shared Linux issues are already fixed, so most of the tree should compile
straight through. Budget for a small number of the following, **x86_64-specific**
items — the only class the Pi couldn't have surfaced:

1. **ISA-gated code that activates on x86_64.** On aarch64 these took C / NEON /
   generic paths; on x86_64 they may select SSE or an x86 recompiler:
   - `usfplugin` (`lazyusf2/r4300/new_dynarec/`) — a **dynamic recompiler** with
     per-arch assembly. On aarch64 it fell back to the C interpreter (its asm is
     32-bit `linkage_arm.S`, not used on aarch64). On x86_64 it may try the x86
     dynarec. If it fails to build, force the interpreter (the lazyusf2 knob,
     typically a `-DNO_DYNAREC`-style define) — matching the aarch64 behavior.
   - SIMD resamplers/DSP: `openmpt` (`Reverb.cpp`/`EQ.cpp`), `sidplayfp`
     (`SincResampler.cpp`), `minimp3`. These use guarded SSE intrinsics that are
     valid and routinely built on x86_64 Linux — low risk, but first to check if
     an ISA error appears.
   Triage approach: these are the same "read the failing TU, find the `#ifdef`"
   loop used for the Pi. Expect ≤ a handful, if any.

2. **GCC-version drift from the validated GCC 12 — in *both* directions.** The Pi
   was validated on GCC 12; Ubuntu 22.04 ships GCC 11, 24.04 ships GCC 13/14.
   - *Older (22.04 / GCC 11):* lacks features GCC 12 has. Concretely, GCC 11's
     `<stdatomic.h>` does **not** work in C++ (no `_Atomic` in its C++ front end),
     which broke `fmpplugin` via `ppz8.h` — fixed by guarding that redundant
     include to C-only. Watch for similar "GCC 12 accepted it, GCC 11 doesn't."
   - *Newer (24.04 / GCC 13–14):* stricter — more hard errors, tightened headers;
     possible extra one-line "missing include" fixes in the shape of #1/#3/#6/#7.
     GCC 13+ makes C++ `<stdatomic.h>` work, which only helps.

3. **Nothing to *un*-fix.** The stale `RASPBERRYPI`/`RASPBERRY`/bcm_host paths are
   never touched by a native Ubuntu build (same as native Pi), so there is no
   equivalent trap to avoid.

## 6. Phase 4 — Validate the milestone

```sh
./builds/release/cm path/to/song.mod        # textmode player
```

- Confirm it launches the terminal UI, loads a tune, and plays via **ALSA**
  (`libasound`). Ubuntu desktops route ALSA through PipeWire/PulseAudio; the ALSA
  client lib is present, so no code change is needed.
- Spot-check a few formats across engine families (e.g. `.mod` via openmpt, a
  `.sid`, a `.nsf` via gme, a `.vgm`) to shake out any plugin that built but
  misbehaves at runtime.
- `ninja -C builds/release` (full) to confirm `chipmachine`, `cmtest`,
  `mksonglist` also link.

## 7. Phase 5 — Follow-ups (beyond the "cm builds" milestone)

- **SunVox blob is arch-specific.** The post-build step copies
  `sunvox_lib/sunvox.dylib` (a macOS binary) — harmless to the build (a file copy)
  but useless at runtime on Linux. For working SunVox playback, ship the matching
  Linux shared lib (`x86_64` vs `aarch64` `libsunvox.so`). Runtime-only; not a
  build blocker.
- **GUI target `chipmachine`.** Needs the GL/X11/GLFW/FreeType deps from §3 and
  the grappix UNIX path (already the non-Apple, non-`RASPBERRY` branch). Ubuntu
  desktop has full Mesa, so this is more straightforward than on the Pi.
- **Packaging.** A `.deb` (or AppImage) once the binaries run, plus the data/lua
  assets the app loads at runtime.

## 8. Risk summary

| Risk | Likelihood | Impact | Mitigation |
| --- | --- | --- | --- |
| x86_64 dynarec/SIMD path fails to compile (usfplugin, resamplers) | Low–Med | 1 plugin at a time | Fall back to C path via existing config define; same triage loop as the Pi |
| GCC 13/14 stricter headers (24.04) | Low | A few 1-line include fixes | Add the missing `<...>`; identical to fixes #1/#3/#6/#7 |
| A plugin builds but is silent/wrong at runtime | Low | Runtime, not build | Per-family smoke test in Phase 4 |
| SunVox `.dylib` copy | Certain (cosmetic) | Runtime feature only | Provide Linux `libsunvox.so` per arch (Phase 5) |

## 9. Effort estimate

- Phase 1–2 (deps + native build): ~1 sitting.
- Phase 3 (triage): small — the shared-Linux surface is already fixed; expect a
  handful of x86_64/GCC-version items at most, each a familiar one-file fix.
- Phase 4 (validate): short.
- Net: **substantially less than the Pi effort**, since the Pi absorbed all the
  cross-platform (Apple → Linux) and GNU-ld work that Ubuntu inherits for free.
```
