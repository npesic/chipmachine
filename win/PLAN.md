# Plan: Build ChipMachine for Windows 11

Goal: from the same code base, reach the first milestone — a **working
text-mode `cm` player on Windows 11** — mirroring the Raspberry Pi and Ubuntu
efforts.

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
| Milestone | **Text-mode `cm`** first (no grappix/GL GUI), exactly as RPi/Ubuntu. |
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
