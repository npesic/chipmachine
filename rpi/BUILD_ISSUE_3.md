# Build issue 3

```
FAILED: plugins/ptkplugin/CMakeFiles/ptkplugin.dir/__/__/__/__/protrekkr/src/files/files.cpp.o 
/usr/bin/ccache /usr/bin/c++ -DBZR2 -D__STAND_ALONE__ -D__WINAMP__ -I/home/pi5/git/chipmachine/external/musicplayer/src/plugins/ptkplugin -I/home/pi5/git/chipmachine/external/musicplayer/src/plugins/ptkplugin/../../../../protrekkr/release/ptk/replay/lib -I/home/pi5/git/chipmachine/external/musicplayer/src/plugins/ptkplugin/../../../../protrekkr/release/ptk/replay/lib/include -I/home/pi5/git/chipmachine/external/musicplayer/src/plugins/ptkplugin/../../../../protrekkr/release/ptk/replay/lib/sounddriver/include -I/home/pi5/git/chipmachine/external/musicplayer/src/plugins/ptkplugin/../../../../protrekkr/src/editors/include -I/home/pi5/git/chipmachine/external/musicplayer/src/plugins/ptkplugin/../../../../protrekkr/src/files/include -I/home/pi5/git/chipmachine/external/musicplayer/src/plugins/ptkplugin/../../../../protrekkr/src/include -I/home/pi5/git/chipmachine/external/apone/mods/coreutils/.. -g -funsigned-char  -g -funsigned-char -O2 -w -std=gnu++17 -MD -MT plugins/ptkplugin/CMakeFiles/ptkplugin.dir/__/__/__/__/protrekkr/src/files/files.cpp.o -MF plugins/ptkplugin/CMakeFiles/ptkplugin.dir/__/__/__/__/protrekkr/src/files/files.cpp.o.d -o plugins/ptkplugin/CMakeFiles/ptkplugin.dir/__/__/__/__/protrekkr/src/files/files.cpp.o -c /home/pi5/git/chipmachine/external/protrekkr/src/files/files.cpp
In file included from /home/pi5/git/chipmachine/external/protrekkr/src/files/../include/../include/../../release/ptk/replay/lib/include/replay.h:68,
                 from /home/pi5/git/chipmachine/external/protrekkr/src/files/../include/../include/variables.h:43,
                 from /home/pi5/git/chipmachine/external/protrekkr/src/files/../include/ptk.h:47,
                 from /home/pi5/git/chipmachine/external/protrekkr/src/files/files.cpp:40:
/home/pi5/git/chipmachine/external/protrekkr/src/files/../include/../include/../../release/ptk/replay/lib/include/sounddriver_dummy.h:19:49: error: ‘Mixer’ was not declared in this scope
   19 | inline int AUDIO_Init_Driver(uint32_t (STDCALL *Mixer)(UINT8 *, UINT32)) { return 1; }
      |                                                 ^~~~~
/home/pi5/git/chipmachine/external/protrekkr/src/files/../include/../include/../../release/ptk/replay/lib/include/sounddriver_dummy.h:19:30: error: ‘uint32_t’ was not declared in this scope
   19 | inline int AUDIO_Init_Driver(uint32_t (STDCALL *Mixer)(UINT8 *, UINT32)) { return 1; }
      |                              ^~~~~~~~
/home/pi5/git/chipmachine/external/protrekkr/src/files/../include/../include/../../release/ptk/replay/lib/include/sounddriver_dummy.h:8:1: note: ‘uint32_t’ is defined in header ‘<cstdint>’; did you forget to ‘#include <cstdint>’?
    7 | #include <math.h>
  +++ |+#include <cstdint>
    8 | 
/home/pi5/git/chipmachine/external/protrekkr/src/files/../include/../include/../../release/ptk/replay/lib/include/sounddriver_dummy.h:19:62: error: expected primary-expression before ‘*’ token
   19 | inline int AUDIO_Init_Driver(uint32_t (STDCALL *Mixer)(UINT8 *, UINT32)) { return 1; }
      |                                                              ^
/home/pi5/git/chipmachine/external/protrekkr/src/files/../include/../include/../../release/ptk/replay/lib/include/sounddriver_dummy.h:19:63: error: expected primary-expression before ‘,’ token
   19 | inline int AUDIO_Init_Driver(uint32_t (STDCALL *Mixer)(UINT8 *, UINT32)) { return 1; }
      |                                                               ^
/home/pi5/git/chipmachine/external/protrekkr/src/files/../include/../include/../../release/ptk/replay/lib/include/sounddriver_dummy.h:19:71: error: expected primary-expression before ‘)’ token
   19 | inline int AUDIO_Init_Driver(uint32_t (STDCALL *Mixer)(UINT8 *, UINT32)) { return 1; }
      |                                                                       ^
In file included from /home/pi5/git/chipmachine/external/protrekkr/src/files/../include/ptk.h:55:
/home/pi5/git/chipmachine/external/protrekkr/src/files/../include/../files/include/files.h:82:22: error: ‘uint8_t’ does not name a type
   82 |     CustomFile(const uint8_t *data, size_t size) : buf(data), maxSize(size) {}
      |                      ^~~~~~~
/home/pi5/git/chipmachine/external/protrekkr/src/files/../include/../files/include/files.h:40:1: note: ‘uint8_t’ is defined in header ‘<cstdint>’; did you forget to ‘#include <cstdint>’?
   39 | #include "../../include/variables.h"
  +++ |+#include <cstdint>
   40 | 
/home/pi5/git/chipmachine/external/protrekkr/src/files/../include/../files/include/files.h:83:11: error: ‘uint8_t’ does not name a type
   83 |     const uint8_t* buf;
      |           ^~~~~~~
/home/pi5/git/chipmachine/external/protrekkr/src/files/../include/../files/include/files.h:83:11: note: ‘uint8_t’ is defined in header ‘<cstdint>’; did you forget to ‘#include <cstdint>’?
/home/pi5/git/chipmachine/external/protrekkr/src/files/../include/../files/include/files.h: In constructor ‘CustomFile::CustomFile(const int*, size_t)’:
/home/pi5/git/chipmachine/external/protrekkr/src/files/../include/../files/include/files.h:82:52: error: class ‘CustomFile’ does not have any field named ‘buf’
   82 |     CustomFile(const uint8_t *data, size_t size) : buf(data), maxSize(size) {}
      |                                                    ^~~
/home/pi5/git/chipmachine/external/protrekkr/src/files/../include/../files/include/files.h: In member function ‘int CustomFile::Read(void*, size_t, size_t)’:
/home/pi5/git/chipmachine/external/protrekkr/src/files/../include/../files/include/files.h:94:29: error: ‘buf’ was not declared in this scope
   94 |                 memcpy(dst, buf + pos, maxSize - pos);
      |                             ^~~
/home/pi5/git/chipmachine/external/protrekkr/src/files/../include/../files/include/files.h:107:25: error: ‘buf’ was not declared in this scope
  107 |             memcpy(dst, buf + pos, size * count);
      |                         ^~~
ninja: build stopped: subcommand failed.
```
