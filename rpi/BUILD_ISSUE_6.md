# Build Issue 6

```
FAILED: plugins/famitrackerplugin/CMakeFiles/famitrackerplugin_objs.dir/__/__/__/__/famitracker-cx/famitracker-core/SoundGen.cpp.o 
/usr/bin/ccache /usr/bin/c++  -I/home/pi5/git/chipmachine/external/musicplayer/src/plugins/famitrackerplugin -I/home/pi5/git/chipmachine/external/famitracker-cx -I/home/pi5/git/chipmachine/external/famitracker-cx/famitracker-core -I/home/pi5/git/chipmachine/external/apone/mods/coreutils/.. -g -funsigned-char  -g -funsigned-char -O2 -fvisibility=hidden -fvisibility-inlines-hidden -w -std=gnu++17 -MD -MT plugins/famitrackerplugin/CMakeFiles/famitrackerplugin_objs.dir/__/__/__/__/famitracker-cx/famitracker-core/SoundGen.cpp.o -MF plugins/famitrackerplugin/CMakeFiles/famitrackerplugin_objs.dir/__/__/__/__/famitracker-cx/famitracker-core/SoundGen.cpp.o.d -o plugins/famitrackerplugin/CMakeFiles/famitrackerplugin_objs.dir/__/__/__/__/famitracker-cx/famitracker-core/SoundGen.cpp.o -c /home/pi5/git/chipmachine/external/famitracker-cx/famitracker-core/SoundGen.cpp
In file included from /home/pi5/git/chipmachine/external/famitracker-cx/famitracker-core/SoundGen.cpp:25:
/home/pi5/git/chipmachine/external/famitracker-cx/core/time.hpp: In function ‘void core::sleep_us(unsigned int)’:
/home/pi5/git/chipmachine/external/famitracker-cx/core/time.hpp:67:17: error: ‘usleep’ was not declared in this scope
   67 |                 usleep(us);
      |                 ^~~~~~
[64/1206] Building CXX object plugins/famitrackerplugin/CMakeFiles/famitrackerplugin_objs.dir/FamiTrackerPlugin.cpp.o
ninja: build stopped: subcommand failed.
```
