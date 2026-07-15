# Build Issue 1

Looks like the gmeplugin failed the build:
```
[474/2821] Building CXX object plugins/gmeplugin/CMakeFiles/gmeplugin.dir/gme/Nsf_Emu.cpp.o
FAILED: plugins/gmeplugin/CMakeFiles/gmeplugin.dir/gme/Nsf_Emu.cpp.o 
/usr/bin/ccache /usr/bin/c++ -DBLARGG_LITTLE_ENDIAN -DHAVE_ZLIB_H -DVGM_YM2612_NUKED -I/home/pi5/git/chipmachine/external/musicplayer/src/plugins/gmeplugin/psf -I/home/pi5/git/chipmachine/external/apone/mods/coreutils/.. -g -funsigned-char  -g -funsigned-char -O2 -fwrapv -std=gnu++17 -MD -MT plugins/gmeplugin/CMakeFiles/gmeplugin.dir/gme/Nsf_Emu.cpp.o -MF plugins/gmeplugin/CMakeFiles/gmeplugin.dir/gme/Nsf_Emu.cpp.o.d -o plugins/gmeplugin/CMakeFiles/gmeplugin.dir/gme/Nsf_Emu.cpp.o -c /home/pi5/git/chipmachine/external/musicplayer/src/plugins/gmeplugin/gme/Nsf_Emu.cpp
In file included from /home/pi5/git/chipmachine/external/musicplayer/src/plugins/gmeplugin/gme/gme.h:7,
                 from /home/pi5/git/chipmachine/external/musicplayer/src/plugins/gmeplugin/gme/Gme_File.h:7,
                 from /home/pi5/git/chipmachine/external/musicplayer/src/plugins/gmeplugin/gme/Music_Emu.h:7,
                 from /home/pi5/git/chipmachine/external/musicplayer/src/plugins/gmeplugin/gme/Classic_Emu.h:9,
                 from /home/pi5/git/chipmachine/external/musicplayer/src/plugins/gmeplugin/gme/Nsf_Emu.h:7,
                 from /home/pi5/git/chipmachine/external/musicplayer/src/plugins/gmeplugin/gme/Nsf_Emu.cpp:3:
/home/pi5/git/chipmachine/external/musicplayer/src/plugins/gmeplugin/gme/blargg_source.h:15:24: error: expected unqualified-id before ‘void’
   15 | #define dprintf(...) ((void)0)
      |                        ^~~~
/home/pi5/git/chipmachine/external/musicplayer/src/plugins/gmeplugin/gme/blargg_source.h:15:24: error: expected ‘)’ before ‘void’
   15 | #define dprintf(...) ((void)0)
      |                       ~^~~~
/home/pi5/git/chipmachine/external/musicplayer/src/plugins/gmeplugin/gme/blargg_source.h:15:24: error: expected ‘)’ before ‘void’
   15 | #define dprintf(...) ((void)0)
      |                      ~ ^~~~
[479/2821] Building CXX object plugins/gmeplugin/CMakeFiles/gmeplugin.dir/gme/Sap_Cpu.cpp.o
ninja: build stopped: subcommand failed.
```
