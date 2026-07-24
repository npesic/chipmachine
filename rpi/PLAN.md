# ChipMachine → Raspberry Pi 5: Porting Plan

Goal (from `PROMPT.md`): add the build changes needed to compile the **same**
ChipMachine source into a working executable for the **Raspberry Pi 5**, and
document the tooling/dependency deltas vs. the current Apple Silicon / macOS
build. Deliverable = this detailed plan.

---

## 1. Executive summary

The single most important framing: **a Raspberry Pi 5 is an `aarch64` (ARMv8.2-A,
Cortex-A76) machine running 64-bit Raspberry Pi OS — i.e. a standard 64-bit
Debian/Linux desktop.** So this is *not* an exotic embedded port; it is a
**Linux/aarch64 desktop build**, and the codebase already contains a large amount
of working Linux support:

- Audio already has an ALSA backend (`player_linux.cpp`, selected by the
  `audioplayer` CMake `else()`/`LINUX` branch via `libasound`).
- The GUI layer `grappix` already has a standard-Linux desktop-GL branch
  (`elseif(UNIX)` → `window_pc.cpp` + GLFW3 + GLEW + OpenGL + X11).
- The player engine, all decoder plugins, Lua/sol2, webutils (libcurl), etc. are
  portable C/C++ already built for Linux elsewhere.

**Critical trap to avoid:** the repo has *stale* "Raspberry Pi" plumbing written
for the **original 32-bit ARMv6 Pi (Pi 1/Zero)**, and it is actively wrong for a
Pi 5:

- Root `CMakeLists.txt` `if(RASPBERRYPI)` forces
  `-march=armv6 -mfpu=vfp -mfloat-abi=hard` — a 32-bit ARMv6 target that will not
  even compile for the Pi 5's Cortex-A76/aarch64.
- `grappix/CMakeLists.txt` `elseif(RASPBERRY)` uses `window_pi.cpp` + `eglutil.cpp`
  and links `EGL GLESv2 vcos vchiq_arm bcm_host` — the **legacy Broadcom
  VideoCore userland**, which was **removed on the Pi 5** (Pi 5 uses the
  open-source Mesa **V3D** driver with full desktop OpenGL under KMS/DRM).

So the plan is emphatically: **do NOT set `RASPBERRYPI`/`RASPBERRY`.** Build the
Pi 5 through the *ordinary Linux/UNIX code paths* that already exist, add a small
amount of Apple-code conditionalization, and supply aarch64-Linux dependencies
via `apt`. The "RPi-specific" defines are a distraction inherited from a
different era of Pi.

---

## 2. Platform delta: macOS/Apple Silicon vs. Raspberry Pi 5

Both are 64-bit ARM, so the *CPU architecture* is not the hard part. The deltas
are all **OS / toolchain / dependency** level:

| Concern | macOS / Apple Silicon (current) | Raspberry Pi 5 (target) |
|---|---|---|
| OS | macOS (Tahoe) | Raspberry Pi OS *64-bit* (Debian Bookworm) — must be the 64-bit image |
| CPU/ABI | Apple M-series, `arm64` (Mach-O) | Cortex-A76, `aarch64` (ELF) |
| Compiler | AppleClang | system GCC (or clang) from apt |
| Dep manager | Homebrew (`/opt/homebrew`) | `apt` (system `/usr`), or vendored/source |
| Audio | CoreAudio / AudioToolbox (`player_osx.cpp`) | **ALSA** `libasound` (`player_linux.cpp`) — already present |
| GUI/GL | Cocoa + OpenGL via Apple frameworks | X11/Wayland + **Mesa** desktop GL, GLFW3, GLEW |
| Native UI glue | `NativeDialogs.mm`, `CheckForUpdate.mm` (Obj-C/AppKit) | needs Linux stubs / GTK-portal (see §4) |
| Frameworks | `-framework CoreFoundation IOKit Cocoa AudioToolbox …` | none — drop the whole `APPLE_FRAMEWORKS` list |
| Bundling | `.app` bundle, `MACOSX_BUNDLE`, `package_app.sh` | tarball / `.deb` / AppImage (see §7) |
| FFmpeg | bundled `bin/ffmpeg` (arm64 Mach-O) + `avcodec/...` | aarch64-Linux `ffmpeg` + `libav*-dev` from apt |
| SunVox lib | prebuilt macOS arm64 `.dylib` (dlopen'd) | prebuilt **Linux ARM64** `.so` from SunVox (see §6) |

**Good news:** most of the root `CMakeLists.txt` Apple specifics are already
`if(APPLE)`-guarded (homebrew paths, `CMAKE_OSX_*`, frameworks list, bundle
install). The Linux path largely falls through correctly today.

---

## 3. What already works vs. what must change

**Already Linux-ready (should just build):**
- All decoder plugins (`MUSICPLAYER_PLUGINS`) — portable C/C++ emulator cores.
- ALSA audio backend, grappix desktop-GL/X11 path, Lua/sol2, webutils/libcurl,
  sqlite3, freetype, fft, lhasa/unrar.
- The textmode `cm` target and `cmtest` (both defined `if(NOT WIN32)` / always).

**Must change for Pi 5 (the actual work):**
1. **Objective-C `.mm` files are compiled unconditionally.** Root
   `CMakeLists.txt` `MAIN_FILES` includes `src/CheckForUpdate.mm` and
   `src/NativeDialogs.mm` with no `if(APPLE)` guard — and `MAIN_FILES` is used by
   **all three** targets (`chipmachine`, `cm`, `cmtest`). These are Obj-C/AppKit
   and will not compile on Linux. **This is the #1 blocker.** Fix: move the two
   `.mm` files into an `APPLE`-only source list, and add Linux stub `.cpp`s
   providing the same symbols the rest of the code links against — at minimum
   `InitializeUpdateVerificationSubsystem()` (called from `main.cpp`) and
   `ChipMachine::open_file_dialog()` (GUI). The update check can be a no-op; the
   file dialog can be a GTK/xdg-desktop-portal call or a stub.
2. **Stale RPi CMake branches must be bypassed.** Ensure the build does **not**
   define `RASPBERRYPI` (root CMake, the ARMv6 flags) nor `RASPBERRY` (grappix,
   the bcm_host branch). The Pi 5 must fall through to the generic Linux/`UNIX`
   paths. Optionally delete/rewrite those branches so nobody re-triggers them.
3. **`build.py` `--target raspberry` is a stub.** The arg is parsed but never
   wired into `buildArgs` (there is a commented-out `-DCMAKE_TOOLCHAIN_FILE`).
   Either (a) native-build on the Pi so `--target native` is all that's needed,
   or (b) implement a real aarch64 toolchain file for cross-compiling (§5).
4. **Dependencies must come from apt, not brew** (§6).
5. **FFmpeg**: replace the bundled arm64-Mach-O `bin/ffmpeg` with an aarch64
   Linux `ffmpeg` (apt), and link `libavcodec/format/util/swresample` from apt
   `-dev` packages. The FFMPEG plugin also shells out to the `ffmpeg` binary for
   streaming/YouTube — that just needs the Linux binary on `PATH`.
6. **Packaging** is `.app`-centric (`package_app.sh`, `MACOSX_BUNDLE`, install
   bundle block) — need a Linux packaging path (§7).

---

## 4. Native UI glue (the `.mm` problem in detail)

The two Objective-C files encapsulate the only truly Apple-specific app logic:
- `NativeDialogs.mm` → `open_file_dialog()` (NSOpenPanel).
- `CheckForUpdate.mm` → update verification subsystem.

Recommended approach:
- Introduce a platform split: `APPLE` builds keep the `.mm` files; non-Apple
  builds compile `src/NativeDialogs_linux.cpp` + `src/CheckForUpdate_linux.cpp`
  (new) providing the same C++/`extern "C"` symbols.
- v1 Linux stubs: `InitializeUpdateVerificationSubsystem()` = no-op;
  `open_file_dialog()` = return empty / a minimal implementation. The player's
  core value (search + play from the remote DB) does not depend on either.
- Later: wire `open_file_dialog()` to `xdg-desktop-portal` (GTK) if a local-file
  open is wanted on the Pi.

This keeps the source single-tree: the same `.cpp`/`.h` compile everywhere;
only the two platform glue files diverge, selected in CMake by `if(APPLE)`.

---

## 5. Build model decision: native-on-Pi vs. cross-compile

Two supported ways to produce the aarch64 binary — pick per team workflow:

- **Option A — native compile on the Pi 5 (recommended first).**
  - The Pi 5 (4–8 GB RAM, NVMe/USB3 SSD advised) can compile the tree with
    `ninja`. It *is* a large codebase (60+ vendored emulator forks), so expect a
    long first build; use `ccache` (already wired in root CMake) and a swap file
    or `-j` tuned to RAM. Build in Release.
  - Steps: install apt deps (§6) → `cmake -GNinja -DCMAKE_BUILD_TYPE=Release ..`
    → `ninja`. No toolchain file, no `RASPBERRYPI` define.
  - Pro: simplest, no sysroot drift, dependencies resolve naturally. Con: slow
    iteration.

- **Option B — cross-compile from an x86-64 Linux host (or the Mac) for speed.**
  - Use an `aarch64-linux-gnu` GCC toolchain + a Pi OS **sysroot** (rsync'd from
    the Pi) and a real CMake toolchain file (`rpi5-aarch64.cmake` setting
    `CMAKE_SYSTEM_NAME=Linux`, `CMAKE_SYSTEM_PROCESSOR=aarch64`, the cross
    compilers, and `CMAKE_SYSROOT`/`CMAKE_FIND_ROOT_PATH`).
  - Wire this into `build.py`'s existing `--target raspberry` (currently inert):
    have it append `-DCMAKE_TOOLCHAIN_FILE=rpi5-aarch64.cmake`.
  - Pro: fast, CI-friendly. Con: sysroot setup, every apt dependency must exist
    in the sysroot, harder for the vendored libs that probe the host.
  - A pragmatic middle ground: cross-build inside an **aarch64 container**
    (QEMU/`docker buildx --platform linux/arm64`) with apt — no sysroot juggling,
    reproducible, works in CI.

**Recommendation:** bring the port up with **Option A** (fastest path to a known-
good binary), then add **Option B (container)** for repeatable/CI builds and
releases.

---

## 6. Dependencies (apt equivalents of the brew list)

The macOS README installs via brew: `git cmake ninja freetype glew glfw3 lua
fftw mpg123 python ffmpeg boost`. Debian/Pi OS equivalents (dev packages):

- Toolchain: `build-essential cmake ninja-build ccache pkg-config git python3`
- Audio: `libasound2-dev` (ALSA — the Linux audio backend), `libmpg123-dev`
- FFmpeg: `ffmpeg libavcodec-dev libavformat-dev libavutil-dev libswresample-dev`
- GUI/GL: `libglfw3-dev libglew-dev libgl1-mesa-dev libfreetype-dev`
  and X11 dev libs (`libx11-dev libxxf86vm-dev libxrandr-dev libxi-dev
  libxinerama-dev libxcursor-dev`) — matching grappix's `UNIX` link list
- Misc: `liblua5.x-dev` (or use the vendored `external/lua`), `libfftw3-dev`,
  `libboost-all-dev` (for `boost::di`), `zlib1g-dev`
- SunVox: download the official SunVox library package, which ships a
  **Linux `arm64`** `.so`; point `SUNVOX_RUNTIME_LIB` at it (the CMake already
  copies that blob next to each binary). If unavailable/undesirable, drop the
  `sunvoxplugin` from `MUSICPLAYER_PLUGINS` for the Pi build.

Most heavy third-party code is **vendored** under `external/` and compiles from
source, so the apt list is mainly the system libs above plus GL/X11.

**Watch items during first build (portability):**
- Any x86 SSE/AVX intrinsics or Apple-specific NEON in vendored plugin cores —
  aarch64 has NEON but not x86 intrinsics; guard or provide scalar fallbacks.
- Endianness is fine (both little-endian).
- Plugins that assume a subprocess/`posix_spawn` (ffmpeg/yt-dlp) work on Linux as
  long as the binaries are on `PATH`.
- `bin/ffmpeg` in the tree is a Mach-O binary — must not be shipped/used on Pi.

---

## 7. Packaging for the Pi

macOS uses `package_app.sh` + `MACOSX_BUNDLE` + the `install()` bundle block (all
already `if(APPLE)`-guarded). For the Pi, add a Linux packaging path:

- **Simplest:** a `cmake --install` layout + tarball that places the `cm` /
  `chipmachine` binaries alongside `lua/`, `data/`, `music/`, and the SunVox
  `.so`, mirroring the resource layout the code expects
  (`resolve_resource_root()`).
- **Nicer:** a `.deb` (or AppImage) so `apt install ./chipmachine.deb` pulls the
  runtime deps. Ship a `.desktop` entry for the GUI target.
- Ensure runtime resource resolution finds `lua/`/`data/` on Linux (verify the
  non-Apple branch of `resolve_resource_root()` / `Environment` paths).

---

## 8. Step-by-step execution plan

**Phase 0 — Provision (0.5 day)**
- Flash 64-bit Raspberry Pi OS (Bookworm) on a Pi 5; attach SSD; enable a swap
  file for the first big build. Install the apt deps (§6). Confirm `uname -m` =
  `aarch64`.

**Phase 1 — Make the tree Linux-clean (2–4 days) — the core CMake work**
- Guard the two `.mm` files as `APPLE`-only in `MAIN_FILES`; add Linux stubs
  (`NativeDialogs_linux.cpp`, `CheckForUpdate_linux.cpp`) (§4).
- Ensure `RASPBERRYPI`/`RASPBERRY` are never defined; confirm the build takes the
  generic Linux/`UNIX` grappix branch and the ALSA audio branch.
- Drop `APPLE_FRAMEWORKS` and `avcodec/...` come from apt on Linux (already
  conditioned by falling through the `if(APPLE)` blocks — verify link lists).
- Decide SunVox: bundle Linux arm64 `.so` or drop the plugin.

**Phase 2 — First native build of `cm` (textmode) (2–4 days)**
- Build **only the `cm` target first** (`-DTEXTMODE_ONLY`, no GL/GUI) — the
  smallest thing that exercises engine + all decoder plugins + ALSA. This is the
  fastest route to "the same player runs on the Pi 5."
- Triage per-plugin compile failures (intrinsics/portability); disable any
  stubborn plugin temporarily by trimming `MUSICPLAYER_PLUGINS` to keep momentum,
  then re-enable.
- **Milestone: `./cm <file>` plays a tune through ALSA on the Pi 5.**

**Phase 3 — Full GUI build (2–5 days)**
- Build the `chipmachine` GUI target (grappix desktop GL + GLFW3 + freetype).
  Validate under the Pi's Wayland/X11 desktop and Mesa V3D.
- Validate the database/search flow and remote fetch (RemoteLoader/libcurl) on
  the Pi.

**Phase 4 — Run `cmtest` & harden (2–3 days)**
- Build/run `cmtest` on the Pi to validate decoders match expected output on
  aarch64. Fix any endian/intrinsic/UB divergences surfaced.

**Phase 5 — Tooling & packaging (2–4 days)**
- ✅ **Done:** `build.py --target raspberry` is wired to the cross toolchain file
  `rpi5-aarch64.cmake`, with per-target build trees (Option B, §5). See §11.
- Add the container/CI cross-build wrapper around the above.
- Produce a Linux artifact (tarball/.deb/AppImage) and document the runtime deps.

---

## 9. Risks / open questions

- **Per-plugin portability**: the biggest unknown is whether all 60+ vendored
  emulator cores build cleanly on aarch64/GCC without Apple/x86 assumptions. The
  trim-and-re-enable approach in Phase 2 bounds this risk.
- **Native build time/RAM** on the Pi (mitigate with ccache + swap + SSD, or
  cross-compile).
- **SunVox** has no source (prebuilt blob) — depends on an available Linux arm64
  build; otherwise dropped on Pi. **Resolved — see §12 Finding 5:** the official
  aarch64 `sunvox.so` exists and just needs vendoring into `sunvox_lib/`; the
  build already stages it next to each binary.
- **File-dialog / update-check** get stubbed on Linux initially (acceptable for
  v1; the core player doesn't need them).
- **GL driver**: Pi 5 Mesa V3D generally provides adequate desktop GL for
  grappix's 2D/text rendering; confirm the GL version grappix requires is met
  (fall back to GLES path only if necessary — but *not* the removed bcm_host
  path).
- **Legal**: same GPLv3 combined-work terms as macOS; unchanged by the Pi target.

---

## 10. Immediate next actions

1. ✅ **Done:** Phase 1 CMake changes landed — the Objective-C `.mm` files are
   now `APPLE`-only, non-Apple builds compile `src/CheckForUpdate_stub.cpp` +
   `src/NativeDialogs_stub.cpp`, and the stale ARMv6 `RASPBERRYPI` branch carries
   a warning so it is never enabled for a Pi 5. `build.py --target raspberry` and
   the `rpi5-aarch64.cmake` cross toolchain are in place (§11).
2. Provision a 64-bit Pi 5 and install the apt dependency set (§6).
3. Native-build **`cm`** on the Pi and get one tune playing through ALSA — the
   minimal proof that the same codebase runs on the Raspberry Pi 5.

---

## 11. Building for Raspberry Pi 5

There are two supported workflows. Both build from the **same source tree** and
produce a 64-bit `aarch64` binary; neither uses the legacy 32-bit ARMv6
`RASPBERRYPI` path or the removed Broadcom `bcm_host` GL path (§1).

> Prerequisite for either: a **64-bit** Raspberry Pi OS (Debian Bookworm) image.
> Confirm with `uname -m` → `aarch64`.

### Option A — native build, on the Pi 5 (recommended first)

This is just an ordinary Linux build; `--target native` needs no special flags.

```bash
# 1. Install dependencies (see §6 for the full list)
sudo apt update
sudo apt install build-essential cmake ninja-build ccache pkg-config git python3 \
    libasound2-dev libmpg123-dev \
    ffmpeg libavcodec-dev libavformat-dev libavutil-dev libswresample-dev \
    libglfw3-dev libglew-dev libgl1-mesa-dev libfreetype-dev \
    libx11-dev libxxf86vm-dev libxrandr-dev libxi-dev libxinerama-dev libxcursor-dev \
    libfftw3-dev libboost-all-dev zlib1g-dev

# 2. Build. Bring up the small textmode target first (Phase 2 milestone):
./build.py build --target native            # builds into builds/release/
#   or, to target just the textmode player during bring-up:
#   cmake -B builds/release -GNinja -DCMAKE_BUILD_TYPE=Release
#   ninja -C builds/release cm

# 3. Play a tune through ALSA:
./builds/release/cm <song-file>
```

Notes:
- The tree is large (60+ vendored emulator forks). `ccache` is already wired in
  the root CMake; add a swap file and build off an SSD to keep RAM/time sane.
- `--target native` keeps the original `builds/<config>/` layout unchanged.

### Option B — cross-compile, from another host (fast / CI)

Uses the `rpi5-aarch64.cmake` toolchain file wired into `build.py`.

```bash
# On an x86-64 (or other) Linux host:
sudo apt install crossbuild-essential-arm64   # aarch64-linux-gnu-g++, etc.

# A sysroot = a copy of the Pi's root filesystem, so target headers/libs resolve.
# Populate the Pi with the apt deps above first, then:
rsync -a --rsync-path="sudo rsync" pi@raspberrypi:/{lib,usr} /path/to/pi-rootfs/
export RPI_SYSROOT=/path/to/pi-rootfs

./build.py build --target raspberry           # builds into builds/raspberry-release/
```

This runs, under the hood:

```
cmake -Bbuilds/raspberry-release -H. -DCMAKE_BUILD_TYPE=Release \
      -DCMAKE_TOOLCHAIN_FILE=<repo>/rpi5-aarch64.cmake -GNinja
```

The toolchain file (`rpi5-aarch64.cmake`, repo root):
- sets `CMAKE_SYSTEM_NAME=Linux`, `CMAKE_SYSTEM_PROCESSOR=aarch64`;
- uses the `aarch64-linux-gnu-` compilers (override the triple with
  `-DCROSS_PREFIX=...`);
- tunes for the Pi 5 with **`-mcpu=cortex-a76`** (not the legacy `-march=armv6`);
- honours `RPI_SYSROOT` (`-DRPI_SYSROOT=` or the env var) and points
  `pkg-config` into the sysroot.

Each non-native target lives in its own `builds/<target>-<config>/` tree, so the
cross build's CMake cache never collides with a native one.

A reproducible middle ground (§5) is to run Option B **inside an `arm64`
container** (`docker buildx --platform linux/arm64`) with the apt deps installed
normally — no sysroot to maintain. The cross-build artifact is then copied to the
Pi to run.

### What Phase 1 changed to make this build

- Root `CMakeLists.txt`: the two Objective-C glue files are now `APPLE`-only;
  non-Apple builds compile `src/CheckForUpdate_stub.cpp` (no-op update check) and
  `src/NativeDialogs_stub.cpp` (`open_file_dialog()` returns `""`).
- The legacy ARMv6 `if(RASPBERRYPI)` branch carries a warning comment — leave it
  **off** for the Pi 5.
- `build.py` gained working `--target raspberry` handling + per-target build
  dirs; `rpi5-aarch64.cmake` was added.

## 12. Phase 4 `cmtest` findings

### Finding 1 — case-sensitive FS: whole-path lower-casing broke content-sniffing

First `cmtest` run on the Pi: 2 of 7 cases failed — "STarKos host path plays
sound" (`playFile` returned false) and "OPL Archive routes to libvgm and plays"
(SIGABRT from `Blip_Buffer::end_frame` assert in GME). **Same root cause, in
shared host code — not aarch64-specific.**

`MusicPlayer::fromFile` (`src/MusicPlayer.cpp`) lower-cased the **entire path**
before calling each plugin's `canHandle`. That is fine for extension matching,
but several plugins **sniff file content inside `canHandle`** — they open `name`
to read magic bytes: `SksPlugin` (`File{name}.readAll()`), and GME's OPL/VSU
router `vgmNeedsLibVGM()` (`gzopen(path)`, `src/vgm_opl_detect.h`). On a
**case-sensitive filesystem (Linux/RPi ext4)** the lower-cased path of a
mixed-case file (`Targhan - Orion Prime - Introduction.sks`,
`2a03fox - Snowgoons vs Acid (OPL2).vgz`) does not exist:
- STarKos: the open fails, `SksPlugin` declines, no plugin claims it → silent
  fail (`playFile` false).
- OPL: `gzopen` fails so `vgmNeedsLibVGM` returns false, GME **stops declining**
  the OPL/VSU `.vgz`, claims it, and overflows `Blip_Buffer` → the debug `assert`
  aborts (masked in Release/NDEBUG, which is why only the Debug `cmtest`
  crashes; the underlying mis-routing was latent on all case-sensitive builds).

macOS/Windows never saw this because their filesystems are case-insensitive, so
the lower-cased path still opens the real file.

**Fix:** `fromFile` now lower-cases **only the extension**, preserving the rest
of the path's real case, so extension matching stays case-insensitive while the
on-disk path each plugin opens keeps its real case. Strictly better than the old
behaviour (an upper-case *extension* on a case-sensitive FS was already broken
for sniffers either way; the common mixed-case *stem* is now fixed).
`getSecondaryFiles` already passed the original-case name, so only `fromFile`
needed changing. Cross-platform no-op on case-insensitive filesystems.

> Note on Debug vs Release: GME's `Blip_Buffer`/`Ay_Apu` asserts are live only
> without NDEBUG. A Release `cmtest` would not have *aborted* on the OPL case —
> but it would still have mis-routed the file to GME (silent/garbage) instead of
> libvgm. The Debug build made a latent routing bug loud, which is a feature.
> (Caveat discovered later — see Finding 3: this project's *Release* also leaves
> asserts live, because it drops `-DNDEBUG`. So the OPL case aborts in Release
> here too.)

### Finding 2 — SGC RST-vector out-of-bounds read → GCC aarch64 `-O2` miscompile

`testmus/gme/Dynamite Headdy.sgc` aborted in `blargg_vector::operator[]`
(`assert(n <= size_)`). The `-O2` backtrace pointed at `Sgc_Impl::start_track`
line 94 but that looked impossible, so it took a two-stage probe to pin down:

- **Stage 1** (make `operator[]` `noinline`) — the crash *vanished* and the whole
  GME corpus passed. Classic signature of an inlining/optimisation-sensitive bug
  (UB the optimiser exploits), and proof the fault is codegen-dependent, not a
  plain logic error.
- **Stage 2** (keep `operator[]` inlinable, route only its failure path to a
  `cold noinline` reporter that prints `n`/`size_`/`__builtin_return_address`) —
  preserved the triggering codegen *and* captured the truth: **`n=1032`,
  `size_=1028`**. `size_ == page_size(1024)+page_padding(4)` uniquely identifies
  `vectors`, and `1032 == 129*8` — the loop `for (i=1; i<8; …) vectors[i*8+…]`
  had run to **i=129**.

Root cause, in the loop body (`Sgc_Impl.cpp:92`):
```cpp
vectors [i*8 + 1] = header_.rst_addrs [i*2 + 0];   // i=7 → rst_addrs[14]
vectors [i*8 + 2] = header_.rst_addrs [i*2 + 1];   // i=7 → rst_addrs[15]
```
`header_.rst_addrs` is `byte[7*2]` = 14 elements. RST vectors 0x08..0x38 (i=1..7)
should read entries **0..6**, i.e. `[(i-1)*2]`. The original `[i*2]` skipped
entry 0 and read `rst_addrs[14]`/`[15]` — **2 bytes out of bounds**. That OOB
read is undefined behaviour, and GCC 12 on aarch64 `-O2` miscompiled the loop
because of it (trip count ran away to i=129, writing `vectors[1032]` past the
1028-byte page). It's **also a plain correctness bug on every platform**: the RST
vectors were populated from the wrong header entries (off by one). macOS never
crashed only because its `NDEBUG` build silences the assert and the stray read
lands in adjacent header bytes.

**Fix:** index `header_.rst_addrs[(i-1)*2 + …]` (`Sgc_Impl.cpp`). Removes the UB
(so the miscompile is gone) and loads the correct RST addresses everywhere.
Confirmed: full GME corpus passes, `Dynamite Headdy.sgc` included. The diagnostic
probe in `blargg_common.h` was reverted after identification.

### Finding 3 — Release build silently drops `-DNDEBUG` (asserts ship live)

Surfaced while diagnosing Finding 2: the abort fired in an `-O2`-*optimised*
binary (backtrace full of `<optimized out>`), which shouldn't happen if `assert`
were compiled out. Cause: `CMakeLists.txt:133-134`
```cmake
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")
set(CMAKE_C_FLAGS_RELEASE   "${CMAKE_C_FLAGS} -O2")
```
overrides CMake's default `-O3 -DNDEBUG`, so **`-DNDEBUG` is dropped** and every
`assert()` across the tree — including all vendored emulator cores (GME
`Blip_Buffer`/`Ay_Apu`/`blargg_vector`, …) — stays live in Release. This is why
these asserts abort on the Linux/RPi build but not on the macOS release (whose
packaging keeps `NDEBUG`).

**Decision (deferred, not yet applied):** the correct end state is standard
Release semantics (define `NDEBUG`), matching macOS. But *do not* just re-add it
to paper over crashes — several of these asserts guard genuine UB (Finding 2 was
an OOB read/write), and silencing them would trade a clean abort for silent
corruption. Plan: keep asserts live as a bring-up safety net through Phase 4,
fix the real bugs they catch (as with Finding 2), then restore `-DNDEBUG` for the
shipping build once the corpus is clean. Track remaining asserts as they surface.

### Finding 4 — case-only-differing companion fixtures can't coexist in git

"secondary files resolve for multi-file fixtures" failed at `test.cpp` on
`qts.Big Pro -> SMP.set`: `File{ "testmus/uade/SMP.set" }.exists()` was false
because the bundled file is `smp.set` (lower-case). Two *different* shared UADE
banks differ only in case — Quartet ST's `SMP.set` (`qts`, `UADEPlugin.cpp:805`)
and Synth Dream's `smp.set` (`sdr`, `:790`, used by the `sdr.monsterbusiness 1`
fixture). A case-insensitive checkout (macOS/Windows) cannot hold both names at
one path, so the repo bundles a single physical file; macOS served it to both
via case-folding, the Pi cannot.

This is a **fixture-storage limitation, not a code bug**: `getSecondaryFiles`
correctly returns the exact-cased name (needed for modland's case-sensitive FTP),
and UADE's AmigaDOS file layer resolves the bank case-insensitively at play time,
so real streaming/playback is fine on Linux. Only the test's host-side
`utils::File::exists()` was too case-strict.

**Fix:** the fixture-existence assertion now matches the companion name
**case-insensitively** (lists the song's dir, compares lower-cased). The exact
name is still asserted against `getSecondaryFiles()` output (unchanged), so GUI
fetch-name correctness stays covered. Rejected alternatives: a second `SMP.set`
file (git case-collision on macOS/Windows — the very bug class we're fixing), and
moving the fixture to a subdir (`testPlugin` skips subdirs, so it would silently
drop qts from playback coverage).

### Finding 5 — SunVox engine: vendor the aarch64 `sunvox.so` (closes §9 risk)

`SunVox Player` cases fail with `./sunvox.so: cannot open shared object file`.
Not a bug — SunVox is a **closed-source prebuilt blob** the plugin `dlopen()`s at
runtime (`SunVoxPlugin.cpp` `libName()` → `sunvox.dll`/`.dylib`/`.so`), and only
the macOS `sunvox.dylib` is vendored in `sunvoxplugin/sunvox_lib/`. There is no
source to compile; the platform binary must be dropped in. This is the SunVox
risk flagged in §9.

The build machinery already handles everything else: `sunvoxplugin/CMakeLists.txt`
sets `SUNVOX_RUNTIME_LIB` **iff** `sunvox_lib/sunvox.so` exists at configure time,
and the root `CMakeLists.txt` (~L507) copies it next to each playable binary
(`chipmachine`/`cm`/`cmtest`) via a POST_BUILD step; `acquireEngine()` then loads
it from `getExeDir()`. So the only missing piece is the file.

**Setup (once):**
1. Download the official SunVox library (MIT, same licence as the vendored
   `.dylib`): <https://warmplace.ru/soft/sunvox/sunvox_lib.php>.
2. Take the 64-bit ARM Linux engine — Pi 5 / 64-bit Raspberry Pi OS is aarch64,
   so the `linux/lib_arm64/sunvox.so` (NOT `lib_arm`/armhf = 32-bit). Verify with
   `file sunvox.so` → `ELF 64-bit LSB shared object, ARM aarch64`.
3. Copy to `external/musicplayer/src/plugins/sunvoxplugin/sunvox_lib/sunvox.so`
   (next to the existing `sunvox.dylib`) and **commit it** — mirrors the macOS
   pattern and keeps RPi builds reproducible.
4. **Reconfigure** before building — the `if(EXISTS …/sunvox.so)` gate runs at
   configure time, so a bare `ninja` won't notice a freshly-dropped file:
   `cmake builds/release` (or `./build.py build`), then
   `ninja -C builds/release cmtest`.

**Packaging follow-up:** the Linux/RPi packaging step must ship `sunvox.so` next
to the executable, exactly as `package_app.sh` (L197-201) copies `sunvox.dylib`
into `Contents/MacOS/` for the macOS bundle.

### Finding 6 — PlayerPRO: big-endian MAD swap gated on a macro GCC doesn't define

"PlayerPRO routing" threw `PlayerPRO: could not load module` from `fromFile`
(`canHandle` passed — the "MADG" magic matched — but the deeper parse failed).
Root cause is **endianness**, but not the usual kind: both macOS and the Pi are
little-endian, so the divergence is the *compiler*, not the CPU.

The vendored MADDriver reads big-endian Macintosh `.mad` data through
`MADBE32`/`MADBE16` (`external/playerpro/MADFileUtils.h`), which swap **only**
`#ifdef __LITTLE_ENDIAN__`. Apple's toolchain predefines the bare
`__LITTLE_ENDIAN__` macro and `MADDefs.h`'s WIN32 block defines it too — but
**GCC/Clang on Linux predefine neither** `__LITTLE_ENDIAN__` nor `__BIG_ENDIAN__`
(they expose `__BYTE_ORDER__` instead), and `MADDefs.h` never derived it for the
Linux case. So on aarch64 Linux the swap was skipped, the big-endian module
header parsed as garbage, and `MADLoadMusicFileCString` failed. macOS worked
only because AppleClang happens to predefine the macro.

**Fix:** in `MADDefs.h`, when neither endian macro is defined, derive it from the
compiler's `__BYTE_ORDER__` (`__BIG_ENDIAN__` on a big-endian target, else
`__LITTLE_ENDIAN__`). No-op on macOS/Windows (already defined); fills the gap for
GCC/Linux, fixing every `MADBE*`/`MADLE*` swap site at once. Note the MAD macro
is `__LITTLE_ENDIAN__` (trailing `__`, Apple-style) — distinct from glibc's
`__LITTLE_ENDIAN` in `<endian.h>`, so there is no collision. Same *class* as
other "works on Apple's compiler, undefined elsewhere" macro gaps in vendored
Mac-origin code; on a hypothetical big-endian target the swap is now also correct
(it was effectively unreachable before).

### Finding 7 — cmtest hangs at exit: Furnace (DMF) log thread never stopped

`cmtest` finished the suite (the `coverage` gate reported its result) but never
returned to the shell — it hung on teardown. `gdb -p <pid> -ex 'thread apply all
bt'` showed it exactly (ffmpeg was a red herring): the **main thread** was in
`exit()` → `__run_exit_handlers` → `pthread_cond_destroy(logFileNotify)`, blocked,
while **thread 2** sat in `_logFileThread()`
(`dmfplugin/furnace/src/log.cpp:202`), parked in `logFileNotify.wait()`.

Furnace's async log-writer is started by `startLogFile()` inside
`DivEngine::preInit()` (`engine.cpp:4314`) — which the DMF plugin calls per song.
Its counterpart `finishLogFile()` (stops the flag, notifies, joins) is **never
called**: the standalone Furnace app calls it from `main()`, but embedded in the
plugin nothing does — `DivEngine::quit()` doesn't touch the log, and
`DMFPlayer`'s ctor can even throw *after* `preInit()` started the thread. Left
running, the thread stays parked on the global `logFileNotify` condvar; at exit
its static destructor calls `pthread_cond_destroy()` on a condvar that still has
a waiter — POSIX-UB, and glibc blocks forever → whole-process teardown hang.

**Fix:** in `startLogFile()` (`log.cpp`), register an `atexit` handler (once)
that calls `finishLogFile()`. An `atexit` registered at runtime runs **before**
the startup-constructed condvar's static destructor, so the thread is joined
first and the condvar is destroyed with no waiters. Robust to every path
(success, ctor-throw, N songs) since it fires once at exit regardless of whether
`quit()` ran; `finishLogFile()` is a no-op if already done. Not ffmpeg-related —
the ffmpeg teardown (`ExecPipe::Kill` SIGKILL+reap) was examined and is clean.

### Finding 8 — Audio Overload: `_lib` companion lower-cased, unfindable on Linux

`testmus/ao/01 - title.miniqsf` threw an empty `player_exception()` — a
`.miniqsf` (Capcom QSF; PSF-family "mini + shared `.qsflib`", like §31's GSF).
`AOPlugin`'s `ao_get_lib()` loads the companion named by the PSF `_lib` tag but
**lower-cased the name** (`baseDir + "/" + toLower(filename)`). The tag case and
the on-disk case disagree, inconsistently, across rips:

| fixture | `_lib` tag | on disk | old `toLower` |
|---|---|---|---|
| `01 - title` | `Mega Man - The Power Battle.qsflib` | mixed | miss → **fail** |
| `01 - opening` | `Mega Man 2 - The Power Fighters.qsflib` | lower | match |
| `pdz-06.minissf` | `EPISODE2.ssflib` | lower | match |

So blind lower-case only works on a case-insensitive FS; on Linux it fails
whenever the real file has upper-case letters (the `title` fixture), and neither
lower-case *nor* exact-case satisfies all three, because the fixtures themselves
are inconsistent.

**Fix:** `ao_get_lib` now resolves the companion **case-insensitively** — tries
the exact tag name, then scans the directory for a case-insensitive filename
match. Handles any tag/disk case combination and is robust for real
streaming (the fetched file keeps whatever case the archive used). Same
case-sensitivity theme as Findings 1/4 and §31; `.qsflib`/`.ssflib` companions
now load on Linux/RPi.

### Finding 9 — `testmus/zx/prom.asc` "NO SOUND": test sample-budget too short

`prom.asc` (ZX ASC Sound Master, Ayfly) reported `playback NO SOUND`. Playing it
directly (`cm testmus/zx/prom.asc`) proved it's fine — it just has a **several-
second silent intro**. `testPlugin`'s detection budget was `count = 50` blocks =
50 × 4096 frames ÷ 44100 ≈ **4.6 s**; the intro outlasts it, so the "any non-zero
sample?" check never triggers. NOT aarch64-specific: chip emulation is
sample-accurate, so the intro is identically silent on macOS — this fixture was
borderline/failing on every platform, the Pi bring-up just surfaced it.

**Fix (in `test.cpp` `testPlugin`, shared/all-platform):** split the single
`count` into two budgets. The **render** path (`rc > 0`) is a pure decode that
runs far faster than realtime (a block costs microseconds, not its 93 ms of
audio), so it now gets a generous `renderBudget = 300` (~28 s of audio, still
sub-second wall-clock, only fully consumed for a genuinely silent file) — enough
for long silent intros. The **buffering** path (`rc == 0`, ffmpeg cold-start
warmup) actually `sleepms(20)`s, so it keeps a bounded `bufferBudget = 50` (~1 s)
to avoid slowing ffmpeg-failure detection. A truly silent/broken file still
reports NO SOUND (just after more decode), so coverage isn't weakened.
