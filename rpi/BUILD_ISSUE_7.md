# Build issue 7

```
FAILED: plugins/dmfplugin/CMakeFiles/dmfplugin_objs.dir/__/__/__/__/furnace/src/engine/dispatchContainer.cpp.o 
/usr/bin/ccache /usr/bin/c++ -DHAVE_DIRENT_TYPE -DHAVE_SNDFILE -I/home/pi5/git/chipmachine/external/musicplayer/src/plugins/dmfplugin -I/home/pi5/git/chipmachine/external/musicplayer/src/plugins/dmfplugin/sndfile_stub -I/home/pi5/git/chipmachine/external/musicplayer/src/plugins/dmfplugin/../../../../furnace/src -I/home/pi5/git/chipmachine/external/musicplayer/src/plugins/dmfplugin/../../../../furnace/src/engine -I/home/pi5/git/chipmachine/external/musicplayer/src/plugins/dmfplugin/../../../../furnace/src/icon -I/home/pi5/git/chipmachine/external/musicplayer/src/plugins/dmfplugin/../../../../furnace/extern/fmt/include -I/home/pi5/git/chipmachine/external/musicplayer/src/plugins/dmfplugin/../../../../furnace/extern/blip_buf -I/home/pi5/git/chipmachine/external/musicplayer/src/plugins/dmfplugin/../../../../furnace/extern/vgsound_emu-modified -I/home/pi5/git/chipmachine/external/musicplayer/src/plugins/dmfplugin/../../../../furnace/extern/macports-legacy-support/include -I/home/pi5/git/chipmachine/external/musicplayer/src/plugins/dmfplugin/../../../../furnace/extern/IconFontCppHeaders -g -funsigned-char  -g -funsigned-char -O2 -fvisibility=hidden -fvisibility-inlines-hidden -Wno-deprecated-declarations -std=gnu++14 -MD -MT plugins/dmfplugin/CMakeFiles/dmfplugin_objs.dir/__/__/__/__/furnace/src/engine/dispatchContainer.cpp.o -MF plugins/dmfplugin/CMakeFiles/dmfplugin_objs.dir/__/__/__/__/furnace/src/engine/dispatchContainer.cpp.o.d -o plugins/dmfplugin/CMakeFiles/dmfplugin_objs.dir/__/__/__/__/furnace/src/engine/dispatchContainer.cpp.o -c /home/pi5/git/chipmachine/external/furnace/src/engine/dispatchContainer.cpp
In file included from /home/pi5/git/chipmachine/external/furnace/src/engine/engine.h:32,
                 from /home/pi5/git/chipmachine/external/furnace/src/engine/dispatchContainer.cpp:21:
/home/pi5/git/chipmachine/external/furnace/src/engine/filePlayer.h:83:56: error: ‘UINT_MAX’ was not declared in this scope
   83 |     ssize_t setPos(ssize_t newPos, unsigned int offset=UINT_MAX);
      |                                                        ^~~~~~~~
/home/pi5/git/chipmachine/external/furnace/src/engine/filePlayer.h:31:1: note: ‘UINT_MAX’ is defined in header ‘<climits>’; did you forget to ‘#include <climits>’?
   30 | #include "sfWrapper.h"
  +++ |+#include <climits>
   31 | #else
/home/pi5/git/chipmachine/external/furnace/src/engine/filePlayer.h:84:67: error: ‘UINT_MAX’ was not declared in this scope
   84 |     ssize_t setPosSeconds(TimeMicros newTime, unsigned int offset=UINT_MAX);
      |                                                                   ^~~~~~~~
/home/pi5/git/chipmachine/external/furnace/src/engine/filePlayer.h:84:67: note: ‘UINT_MAX’ is defined in header ‘<climits>’; did you forget to ‘#include <climits>’?
/home/pi5/git/chipmachine/external/furnace/src/engine/filePlayer.h:90:35: error: ‘UINT_MAX’ was not declared in this scope
   90 |     void play(unsigned int offset=UINT_MAX);
      |                                   ^~~~~~~~
/home/pi5/git/chipmachine/external/furnace/src/engine/filePlayer.h:90:35: note: ‘UINT_MAX’ is defined in header ‘<climits>’; did you forget to ‘#include <climits>’?
/home/pi5/git/chipmachine/external/furnace/src/engine/filePlayer.h:91:35: error: ‘UINT_MAX’ was not declared in this scope
   91 |     void stop(unsigned int offset=UINT_MAX);
      |                                   ^~~~~~~~
/home/pi5/git/chipmachine/external/furnace/src/engine/filePlayer.h:91:35: note: ‘UINT_MAX’ is defined in header ‘<climits>’; did you forget to ‘#include <climits>’?
[122/1143] Building CXX object plugins/dmfplugin/CMakeFiles/dmfplugin_objs.dir/__/__/__/__/furnace/src/engine/config.cpp.o
ninja: build stopped: subcommand failed.
```
