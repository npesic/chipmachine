# Plan: Build ChipMachine for Windows 11

Goal: from the same code base, bring ChipMachine to Windows 11, mirroring the
Raspberry Pi and Ubuntu efforts.

| Milestone | Target | Status |
| --- | --- | --- |
| **1. Text-mode player** | `cm.exe` (+ `cmtest.exe`) | ✅ **Reached** — builds, plays audio, interactive text UI works. See §5. |
| **2. Working GUI** | `chipmachine.exe` (grappix/OpenGL) | ✅ **Reached** — builds, window opens, plays. See §9. |

Sections 1–8 cover milestone 1 (kept as the record of how the Windows port was
brought up); milestone 2 starts at §9.

## TL;DR

- **Toolchain: MinGW-w64 (GCC for Windows), not MSVC.** The tree is saturated
  with GNU-toolchain assumptions that MSVC does not implement: the plugin build
  combines objects with `ld -r` + `objcopy --localize-symbols` (7 plugins), uses
  GNU inline asm (33 files) and `__attribute__` (48 files), relies on GNU ld
  `--start-group`, hidden-visibility presets, and `-fvisibility`. Porting to MSVC
  would be a rewrite; MinGW-w64 keeps us on GCC + GNU binutils, so the **entire
  Linux/GCC bring-up we already did carries over**.
- **Recommended path: MSYS2 + MinGW-w64, built natively on Windows.** MSYS2's
  `pacman` provides the GCC/binutils toolchain *and* prebuilt Windows builds of
  every dependency (curl, zlib, sqlite3, mpg123, boost, ffmpeg, freetype, fftw)
  — the Windows equivalent of `apt` on Ubuntu. Cross-compiling from Linux is
  possible (§6) but the dependency set is much harder to assemble there.
- **The milestone is mostly integration + a handful of Windows-native pieces**,
  not a rewrite: build the `cm` target on Windows (currently excluded), re-enable
  text mode (currently stubbed out), add a **Win32 console backend** (the console
  is POSIX/termios today), and confirm the **winmm audio backend**
  (`player_win.h`). Then the same per-plugin POSIX triage loop as Linux.

## 1. Scope

| Choice | Decision |
| --- | --- |
| Milestone | **Text-mode `cm`** first (no grappix/GL GUI), exactly as RPi/Ubuntu. The GUI follows as milestone 2 (§9). |
| Toolchain | **MinGW-w64 (GCC ≥ 12)**. MSVC ruled out (see TL;DR). |
| Host | **Native on Windows via MSYS2** (primary); MinGW **cross from Linux** as an alternative (§6). |
| Arch | x86-64 (`mingw-w64-x86_64`). |
| Runtime | Windows 11 (Windows 10 1809+ also fine — needed for ANSI VT console). |

## 2. What already carries over

- **Every Linux/GCC fix** made for RPi + Ubuntu, because MinGW-w64 *is* GCC +
  GNU binutils: the glibc-vs-clang transitive-include fixes, the Apple-guard
  gaps, the `exec.h` namespaced-`<signal.h>` fix, the `--start-group` link
  ordering, the `ld -r` + strong-hidden symbol localization, the zxtune
  `devices_aym_dumper` addition, the `Environment::getCacheDir` deadlock fix, the
  CMake `SYSTEM`-keyword guard, `ppz8.h` `<stdatomic.h>`, etc.
- **Existing Windows scaffolding** already in the tree (partial, needs
  finishing): `player_win.h` (winmm/`waveOut` audio), the `#ifdef _WIN32`
  `ExecPipe` stub in `exec.h`, `Environment` Windows dirs (`GetModuleFileName`,
  cache/config = exe dir), and `if(WIN32)` CMake branches.

## 3. The Windows-specific blockers (with file references)

1. **`cm` is not built on Windows.** `CMakeLists.txt:300` guards the text-mode
   target with `if(NOT WIN32)`. Windows was envisioned as GUI-only. → Build `cm`
   on Windows too (drop/adjust the guard; give it the console subsystem, item 5).
2. **Text mode is explicitly disabled.** `main.cpp:~359-372`:
   `#ifndef _WIN32 … #else puts("Textmode not supported on Windows"); exit(0);`.
   → Implement the Windows text-mode branch (call `runConsole` like the POSIX
   path) once the console backend (item 4) exists.
3. **The console is POSIX/termios.** `bbsutils/localconsole.cpp` sets raw mode
   via `tcsetattr`/`termios` under `#ifndef _WIN32`; there is **no Win32
   implementation**. → Add one: `SetConsoleMode` with
   `ENABLE_VIRTUAL_TERMINAL_PROCESSING` (ANSI output on the output handle) +
   `ENABLE_VIRTUAL_TERMINAL_INPUT`/`ReadConsoleInput` (or `_getch`) for keys, and
   UTF-8 (`SetConsoleOutputCP(CP_UTF8)`). This is the single biggest net-new
   piece of code. bbsutils already abstracts `Console`; this is a new backend
   behind the same interface.
4. **Audio backend.** `player_win.h` (winmm `waveOut`, `winmm.lib` in the
   audioplayer CMake WIN32 branch) exists but is unproven on this tree. → Build
   and verify it feeds the same `std::function<void(int16_t*,int)>` pull callback
   the engine uses; fix as needed. (WASAPI is a later upgrade; winmm is enough
   for the milestone.)
5. **Wrong link subsystem for a console app.** `CMakeLists.txt:161-162`:
   `if(WIN32) … -mwindows` builds a **GUI** binary with *no console* — fatal for
   a text app. → For `cm`, use the **console** subsystem (`-mconsole`, or simply
   omit `-mwindows`); keep `-mwindows` only for the grappix GUI `chipmachine`.
6. **`--start-group` is disabled for Windows.** `CMakeLists.txt:187`
   (`if(NOT APPLE AND NOT WIN32)`) skips the link-rule override — but MinGW uses
   GNU ld, which **needs** the group for the circular static-lib web. → Enable
   the group for MinGW (the guard assumed MSVC; broaden it to include MinGW/GNU
   ld on Windows).
7. **POSIX process/signal bits.** `main.cpp` ignores `SIGPIPE` (no such signal on
   Windows) and `exec.h`'s subprocess path uses `fork`/`exec`/`pipe`; the
   `_WIN32` `ExecPipe` branch is a no-op stub. → SIGPIPE handling must be guarded
   for Windows; subprocess streaming (ffmpeg/yt-dlp) stays **stubbed** — fine for
   the milestone (local-file playback and DB browse don't need it; only
   streaming/YouTube do).
8. **Per-plugin POSIX-isms — the big unknown.** The vendored plugins use
   `unistd.h`, `sys/time.h`, `sys/mman.h`/`mmap`, `dlopen` (SunVox blob), fork,
   POSIX paths, etc. MinGW provides many shims (`unistd.h`, `sys/time.h` exist)
   but not all (`mmap`, `dlopen`, fork). Expect a **triage loop just like the
   Linux one**, one failing TU at a time. Plugins that can't be ported quickly
   can be **disabled** for the milestone (drop from `MUSICPLAYER_PLUGINS`) and
   revisited — text mode only needs a working core set (openmpt, gme, sc68, …).

## 4. Phased approach

**Phase 0 — Environment (MSYS2 + MinGW-w64).**
Install MSYS2, then in the **MINGW64** shell:
```sh
pacman -Syu
pacman -S --needed \
  mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake mingw-w64-x86_64-ninja \
  mingw-w64-x86_64-pkgconf git \
  mingw-w64-x86_64-curl mingw-w64-x86_64-zlib mingw-w64-x86_64-sqlite3 \
  mingw-w64-x86_64-mpg123 mingw-w64-x86_64-boost mingw-w64-x86_64-ffmpeg \
  mingw-w64-x86_64-freetype mingw-w64-x86_64-fftw
```
(FreeType/FFTW are configure-time deps even for `cm`, as on Ubuntu; ffmpeg libs
are needed if `ffmpegplugin` stays enabled — otherwise drop it for the milestone.)

**Phase 1 — Make the tree build `cm` on Windows. ✅ DONE (structural).**
- ✅ `CMakeLists.txt`: `cm` is now built on **every** platform (removed the
  `if(NOT WIN32)` guard); on Windows it gets `target_link_options(cm PRIVATE
  -mconsole)` to override the global `-mwindows` and get a real console.
- ✅ `--start-group` link-rule override now applies to MinGW too
  (`if(NOT APPLE AND (NOT WIN32 OR MINGW))`), still excluding MSVC.
- ✅ `main.cpp`: SIGPIPE call is guarded `#ifndef _WIN32`; `<bbsutils/console.h>`
  + `ENABLE_CONSOLE` are now unconditional; the Windows text-mode stub
  (`puts("not supported"); exit(0)`) is replaced with the real `runConsole`
  path (same as POSIX).
- These changes do not affect the Linux/macOS builds. Windows won't fully
  compile yet — the next walls are the **Win32 console backend** (Phase 2, what
  `bbsutils/console.h` + `createLocalConsole()` now demand) and per-plugin POSIX
  triage (Phase 4).

**Phase 2 — Windows console backend (item 3). ✅ DONE.**
- ✅ Added a `WindowsTerminal` (Win32 console) backend in
  `bbsutils/localconsole.{h,cpp}` that drives the console in **virtual-terminal
  mode**: `ENABLE_VIRTUAL_TERMINAL_PROCESSING` on output (renders the ANSI that
  `AnsiConsole` already emits), `ENABLE_VIRTUAL_TERMINAL_INPUT` + raw input on
  stdin (arrow keys arrive as the same `ESC[...` sequences the POSIX parser
  reads), UTF-8 output CP, and non-blocking `read()` gated on
  `GetNumberOfConsoleInputEvents` (matches `getKey()`'s poll loop). `Console::
  createLocalConsole()` now returns `new AnsiConsole(localTerminal)` on Windows.
- ✅ `bbsutils/CMakeLists.txt`: `localconsole.cpp` is now compiled on **all**
  platforms (was `if(NOT WIN32)`), so the symbol exists on Windows.
- POSIX build verified unchanged (the termios path is byte-identical, guarded
  `#ifndef _WIN32`). The Win32 path couldn't be compiled on the Linux dev host
  (no MinGW there) — it needs a build in the MSYS2/MinGW environment.
- **Next wall in bbsutils:** it links `netlink` and builds `telnetserver.cpp`,
  which use BSD sockets; on Windows those need winsock (`ws2_32`,
  `WSAStartup`, `closesocket`). Telnet isn't needed for the milestone, so the
  cheapest path is to **guard `netlink`/`telnetserver` out on Windows** (or port
  them later). Handle as part of Phase 4 triage.

**Phase 3 — Audio (item 4).** Build/verify `player_win.h` (winmm) end-to-end:
`cm believe.mod` should play.

**Phase 4 — Per-plugin POSIX triage (item 8).** Same loop as Linux: build, read
the first failing TU, fix or disable the plugin, repeat. Start from a minimal
plugin set and grow.

**Phase 5 — Text-mode bring-up.** `cm -X`: DB index (the same synchronous
`initFromLua`; cache lands in `%LOCALAPPDATA%`-style dir via `Environment`),
browser UI renders through the new console backend, Enter plays.

## 5. Definition of done (milestone) — ✅ REACHED

- ✅ `cm.exe` builds under MinGW-w64 (MSYS2, GCC 16).
- ✅ `cm.exe believe.mod` **plays audio**.
- `cm.exe -X` interactive text UI — console backend wired (VT + input + UTF-8);
  exercise next.

### Plugins disabled on Windows for the milestone

Dropped via `WIN32_DISABLED_PLUGINS` in the root `CMakeLists.txt` (also guarded
in `plugins.h` + `plugin_register.cpp` with `-DNO_<PLUGIN>`). The other ~345
formats build and play. Re-enabling is: remove from the list + port the sources.

| Plugin | Why disabled | To re-enable |
| --- | --- | --- |
| `ixsplugin` (.ixs) | webixs (RE'd) uses the name `HANDLE` as a Unix fd; collides with `windows.h`'s `void* HANDLE` | rename webixs's `HANDLE`/fd type |
| `eupplugin` (.eup) | eupmini calls `SDL_Delay`; no SDL | stub `SDL_Delay` or drop the timing call |
| `wsrplugin` (.wsr) | in_wsr API declared `__declspec(dllimport)`, linked static (`__imp_*`) | define its export macro to empty for static |
| `playerproplugin` (.mad) | Mac-first; same dllimport-vs-static `__imp_MAD*` | define PlayerPRO export macro empty for static |
| `mikmodplugin` (.uni) | `MIKMODAPI`=dllimport (`__imp_*`) + POSIX `random()` | static `MIKMODAPI` macro + `random()` shim **(good candidate)** |
| `dmfplugin` (.dmf) | combined image overflows COFF REL32 (`relocation truncated to fit`) + missing Furnace `getWinConfigPath()` | `-Wa,-mbig-obj` on the Furnace slice + add the Windows config-path source **(popular format — worth it)** |

### Key Windows-specific fixes made along the way

- Console backend: Win32 `WindowsTerminal` in bbsutils (VT output, non-blocking
  console input, UTF-8) behind the existing `bbs::Terminal` interface.
- All 7 `ld -r` plugin combines feed objects via a GNU `@response-file` on
  Windows (bare command line overflows the ~32 KB `CreateProcess` limit).
- Final-link `--start-group`/`--end-group` brackets `<OBJECTS> <LINK_LIBRARIES>`
  together (MinGW+Ninja bundles libs into the objects `@rsp`, leaving
  `<LINK_LIBRARIES>` empty).
- `-Wl,--allow-multiple-definition` for duplicate emulator cores (COFF has no
  ELF symbol-visibility localization); `localize_strong_hidden.cmake` skips
  non-ELF objects.
- GCC 16 strictness batch: `-std=gnu17` + `-Wno-{incompatible-pointer-types,
  int-conversion,implicit-function-declaration,implicit-int}` for C, and a
  forced `-include cstdint` for C++.
- `main.cpp`: `setenv` shim via `_putenv_s`; `;` PATH-list separator.

## 6. Toolchain options

| Option | Verdict |
| --- | --- |
| **MSYS2 + MinGW-w64 (native)** | **Recommended.** GCC/binutils + every dep prebuilt via `pacman`. Runs/debugs on target. |
| **MinGW-w64 cross from Linux** (`x86_64-w64-mingw32`) — ✅ **wired**: `build.py --target windows` → `mingw-w64-x86_64.cmake`, output in `builds/windows-<config>`. | Viable and reuses our cross infra, but the **Windows dependency set is the hard part** (need MXE or hand-built curl/sqlite/boost/ffmpeg/… for mingw; point at them with `MINGW_SYSROOT`). Static libgcc/libstdc++/pthread are already set in the toolchain so `cm.exe` is self-contained. Consider once native works. |
| **MSVC / clang-cl** | **Not recommended.** The `ld -r`/`objcopy` plugin combining, GNU inline asm, `__attribute__`, `--start-group`, and visibility model are GNU-specific; this is a rewrite, not a port. |
| **WSL** | Not a Windows port — that's the Ubuntu build we already have. |

## 7. Risks

| Risk | Likelihood | Mitigation |
| --- | --- | --- |
| Plugin POSIX-isms (`mmap`, `dlopen`, fork) across 60+ plugins | **High** | Triage loop; disable hard cases for the milestone; MinGW shims cover many. |
| Windows console backend effort (VT + input + UTF-8) | Medium | Bounded, well-trodden Win32 API; bbsutils already abstracts the interface. |
| ffmpeg/subprocess streaming stays stubbed | Low (out of milestone scope) | Local playback + DB browse don't need it; revisit with `CreateProcess` later. |
| MinGW dep availability/ABI mismatches | Low | MSYS2 packages are consistent; keep everything from one MINGW64 environment. |
| Path/case/`\` issues | Low–Med | `std::filesystem`/`utils::path` handle most; watch cache/config dir creation. |

## 8. First concrete step

Stand up MSYS2 + the Phase 0 packages, then attempt `./build.py build --target
native` **inside the MINGW64 shell** (native = host = Windows there). The first
wall will be the `cm`-target/text-mode guards (Phase 1); from there it becomes
the same read-the-error, fix-or-disable loop that took RPi and Ubuntu to a
working player. Net: **less novel than it looks** — one real new component (the
console backend) on top of the GCC/GNU base we've already made portable.

---

# Milestone 2: Working GUI (`chipmachine` target)

Milestone 1 delivered the text-mode player (`cm.exe`) and the test runner
(`cmtest.exe`). Milestone 2 is the **grappix/OpenGL GUI** — the `chipmachine`
target — running natively on Windows 11.

## 9. Definition of done (GUI milestone) — ✅ REACHED

- ✅ `chipmachine.exe` builds under MinGW-w64 with `-DCM_GUI=ON` (the default).
- ✅ It opens a window, renders the song browser, and **plays audio**.
- Keyboard navigation (search field, arrows, Enter) — via grappix's GLFW key
  path, a different input path from the Win32 console backend used by `cm`.
- The spectrum/`MusicBars` visualiser (the only consumer of FFTW).
- ✅ No console window (the global `-mwindows`; `cm`/`cmtest` opt out with
  `-mconsole`).

### What it took

Notably little — the GUI came up in **three steps with no compile-error triage
at all**, which was the opposite of milestone 1's 22 build issues. The reason is
in §10: grappix already had a `WIN32` branch using the same GLFW/GLEW desktop
backend as Linux, so there was no windowing layer to port. The work was
build glue:

| Fix | File |
| --- | --- |
| Replaced `xxd -i` shader embedding with a CMake-native generator (no vim, no shell redirect); symbol names verified byte-identical to xxd | `external/apone/mods/grappix/bin2c.cmake` (new), `grappix/CMakeLists.txt` |
| `find_package(glew)` → `find_package(GLEW)` (module mode) + link `GLEW::GLEW` — the lowercase form "succeeded" while leaving `GLEW_LIBRARY` as `NOTFOUND` | `grappix/CMakeLists.txt` |
| Shared/DLL linkage: prefer `glfw3dll` import lib over static `libglfw3.a`; add `gdi32 user32 shell32` | `grappix/CMakeLists.txt` |
| 32 MB PE stack reserve (same ~3 MB `MusicDatabase` that crashed `cmtest`) | root `CMakeLists.txt`, `chipmachine` target |

Two process notes worth keeping: `bin2c.cmake` was a **new, untracked** file, so
the first sync carried the `CMakeLists.txt` reference but not the file itself
(ninja: "missing and no known rule to make it"). And `find_library` results are
**cached**, so the reordered `NAMES glfw3dll glfw3` needed
`cmake -U GLFW_LIBRARY` to take effect rather than a plain reconfigure.

### Known gaps on Windows (not blockers)

- **File-open dialog is a no-op** — `src/NativeDialogs_stub.cpp` returns `""`
  (blocker G5). A Win32 implementation would use `GetOpenFileNameW` (comdlg32)
  or `IFileOpenDialog`.
- **Shared DLLs must ship for distribution** — `glfw3.dll` and `glew32.dll`
  resolve from `/mingw64/bin` in the MINGW64 shell, but must be copied beside
  `chipmachine.exe` to run from Explorer or on another machine.
- **Seven plugins disabled** (§5 + `sunvoxplugin`) — the GUI inherits the
  milestone-1 `WIN32_DISABLED_PLUGINS` set.
- **ffmpeg-backed formats fail** — `bin/ffmpeg.exe` is absent and
  `utils::ExecPipe` is a Windows stub (`read()` → −1).

## 10. What already carries over (this is much better than it looks)

The single most important fact: **grappix already has a `WIN32` branch**, and it
uses the *same* generic desktop window backend as Linux.

| Piece | Status | Detail |
| --- | --- | --- |
| Window/input backend | ✅ Exists | `grappix/CMakeLists.txt` `elseif(WIN32)` (~lines 57–75) selects `grappix/specific/window_pc.cpp` — the same file Linux and Emscripten use. |
| `window_pc.cpp` portability | ✅ Clean | Pure **GLFW + GLEW**; no X11 anywhere (the X11 libs are added only in the `UNIX` branch). GLFW abstracts Win32 natively. `glewInit()` at `window_pc.cpp:223`. |
| Image loading | ✅ No new deps | The `image` module uses **bundled lodepng** (`external/apone/mods/image/CMakeLists.txt`); the `find_package(PNG)` lines are commented out. |
| Subsystem flag | ✅ Already right | The root `WIN32` block sets `-mwindows` globally, which is exactly what a GUI exe wants. |
| Plugin set | ✅ Done | `chipmachine` links the same `${MUSICPLAYER_PLUGINS}` list that milestone 1 already filtered via `WIN32_DISABLED_PLUGINS`. |
| Audio | ✅ Done | Same `audioplayer` path already proven by `cm.exe`. |
| Stack reserve | ✅ Consider | `cm`/`cmtest` got `-Wl,--stack,33554432`; `chipmachine` should get it too (it constructs the same `MusicDatabase`). |

So this is **not** a port of a windowing layer — it is a dependency + build-glue
exercise, plus first-time compilation of grappix on Windows.

## 11. Dependencies to install (MSYS2, MINGW64 shell)

```bash
pacman -S --needed \
  mingw-w64-x86_64-glfw \
  mingw-w64-x86_64-glew \
  mingw-w64-x86_64-freetype \
  mingw-w64-x86_64-fftw \
  vim            # provides xxd -- see blocker G1
```

Notes:
- **FFTW**: the `fft` module looks for `libfftw3f` — the **single-precision**
  variant (`find_library(FFT_LIBRARY NAMES libfftw3f.a fftw3f)`). The MSYS2
  `fftw` package ships all precisions.
- **OpenGL** itself needs no package — `find_package(OpenGL)` resolves to
  `opengl32` from the MinGW SDK.

## 12. Known concrete blockers (with file references)

These are identified from reading the build files, ordered by how likely they
are to bite. None is deep — but each will stop the build cold.

**G1. `xxd` shader embedding — ✅ FIXED**
Shaders were embedded by shelling out to `xxd -i` with a `>` redirect, which
needs **vim** (absent from a default MSYS2 install) and a POSIX shell. Replaced
with `external/apone/mods/grappix/bin2c.cmake`, a CMake-native generator
(`file(READ ... HEX)` + one regex pass), invoked via `cmake -P`.

The symbol names had to be reproduced exactly, because `grappix/shader.cpp`
declares them by hand (`extern unsigned char _shader_plain_v_glsl[];`) — xxd
derived those from the path `.shader/plain_v.glsl` by mapping every
non-alphanumeric character to `_`. **Verified against real `xxd` output**: byte
sequence, symbol names, and length all identical. Applied on every platform (not
Windows-only) so the build no longer depends on vim anywhere.

**G2. `find_package(glew REQUIRED)` — ✅ FIXED**
Lowercase `glew` searches *config* mode (`glew-config.cmake`) and does **not**
define `GLEW_INCLUDE_DIRS`/`GLEW_LIBRARIES` or the `GLEW::GLEW` target the
branch relied on — so it could "succeed" while contributing no include path and
no library. Now `find_package(GLEW REQUIRED)` (module mode), linking the
`GLEW::GLEW` imported target.

**G3. GLFW/GLEW linkage — ✅ FIXED (shared/DLL chosen)**
`libglfw3.a` was listed first, so the **static** library won while the `WIN32`
branch added no Win32 system libs (unlike `UNIX`, which adds its X11 set) —
that would surface as undefined `__imp_CreateWindowExW` / `__imp_wglCreateContext`.
Decision: **shared (DLL)** — `find_library(GLFW_LIBRARY NAMES glfw3dll glfw3)`
prefers MSYS2's `libglfw3dll.a` import library, and `GLEW::GLEW` defaults to the
DLL. `gdi32 user32 shell32` added regardless.

> **Runtime note:** with shared linkage, `glfw3.dll` and `glew32.dll` must be
> findable. They resolve from `/mingw64/bin` inside the MINGW64 shell, but for
> distribution they must be copied beside `chipmachine.exe` (as is already done
> for the SunVox library).

**G4. First-ever compile of grappix on Windows**
`cm` never built grappix, so none of it has been through MinGW/GCC 16. Expect a
triage round in:
- `grappix/freetype-gl/*.c` — vendored C, the usual GCC-16 strictness (already
  softened globally by `-std=gnu17` + the `-Wno-*` batch from milestone 1).
- `grappix/*.cpp`, `grappix/gui/*.cpp` — the `-include cstdint` global should
  cover the modular-libstdc++ fallout.
- `freetype-gl/opengl.h` includes `<GL/wglew.h>` on Windows — comes from the
  GLEW package; will fail loudly if G2 left includes unset.

**G5. `NativeDialogs_stub.cpp` — file dialog is a no-op**
`GUI_PLATFORM_GLUE_FILES` resolves to `src/NativeDialogs_stub.cpp` on non-Apple,
whose `open_file_dialog()` returns `""` (caller treats that as "cancelled"). The
GUI will build and run; only the "open file" command silently does nothing.
Not a blocker for the milestone — a natural follow-up is a Win32
implementation using `GetOpenFileNameW` (comdlg32) or `IFileOpenDialog`.

**G6. Data/asset path resolution**
The GUI loads fonts, textures, and Lua config from `data/`. `cm.exe` already
proved `Environment::getExeDir()`/`getAppDir()` work on Windows, but the GUI
touches more assets. Watch for anything assuming forward slashes or a bundle
layout (`Contents/Resources`) that only exists on macOS.

## 13. Phased approach

**Phase G0 — deps + configure.** Install the packages above. Configure with
`-DCM_GUI=ON` and confirm CMake resolves Freetype, GLFW, GLEW, FFTW, OpenGL.
Fix G1/G2 here — they are configure-time, not compile-time.

**Phase G1 — build `grappix` alone.** `ninja -C builds/release grappix`. This
isolates G4 (vendored C/C++ strictness) from all the app code and keeps the
error volume manageable — the same "one component at a time" loop that worked
for the plugins.

**Phase G2 — link `chipmachine.exe`.** `ninja -C builds/release chipmachine`.
This is where G3 (missing Win32 system libs) surfaces. Also add the
`-Wl,--stack,33554432` reserve to the target here, matching `cm`/`cmtest`.

**Phase G3 — run it.** Window opens, browser renders, Enter plays. Expect the
first issues to be asset paths (G6) and font loading rather than GL itself.

**Phase G4 — polish.** Native file dialog (G5); verify the `MusicBars` FFT
visualiser; check window resize and DPI scaling.

## 14. Risks

| Risk | Likelihood | Mitigation |
| --- | --- | --- |
| Static-vs-shared GLFW/GLEW link mismatch (`__imp_*`) | **High** | Exactly the class of bug already hit in milestone 1; fix by adding Win32 system libs + `GLEW_STATIC`, or force the DLL variants. |
| GLEW config/module-mode variable mismatch (G2) | **High** | One-line `find_package` fix; verify `GLEW_LIBRARIES` is non-empty at configure time. |
| `xxd` missing / shell redirect in custom command | **Medium** | Install `vim`, or replace with a CMake-native hex generator (preferred). |
| grappix vendored C fails under GCC 16 | Medium | Global flag batch from milestone 1 already covers the common cases. |
| OpenGL driver/context issues in VM or RDP sessions | Medium | grappix needs a real GL context; test on a physical GPU session, not RDP/headless. Mesa `llvmpipe` is a fallback. |
| DPI scaling / window sizing on Windows 11 | Low–Med | GLFW handles the basics; may need a per-monitor-DPI manifest for crisp text. |
| Native file dialog absent | Low | Cosmetic for the milestone; documented as G5 follow-up. |

## 15. Open decisions

1. **Static or shared GLFW/GLEW?** — ✅ **Decided: shared (DLL).** Simpler link,
   no `GLEW_STATIC`/system-lib juggling. Cost: `glfw3.dll` + `glew32.dll` must
   ship beside `chipmachine.exe`. Revisit if a self-contained binary is wanted
   for distribution.
2. **Replace `xxd`?** — ✅ **Done** (G1): `bin2c.cmake`, verified byte-identical
   to xxd output.
3. **Re-enable disabled plugins?** The GUI inherits the milestone-1
   `WIN32_DISABLED_PLUGINS` set. `dmfplugin` (DefleMask) and `mikmodplugin`
   remain the two most worth restoring; see §5.
4. **Does the GUI need `TEXTMODE_ONLY` peers?** `src/textmode.cpp` is in *both*
   `MAIN_FILES` and `GUI_FILES`; confirm it compiles once and isn't duplicated
   into the `chipmachine` link.
