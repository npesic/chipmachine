# Build issue 5

```
FAILED: plugins/playerproplugin/CMakeFiles/playerproplugin.dir/__/__/__/__/playerpro/PPStubs.c.o 
/usr/bin/ccache /usr/bin/cc -DEMBEDPLUGS=1 -DPPRO_PORTABLE_PLUG -I/home/pi5/git/chipmachine/external/playerpro -I/home/pi5/git/chipmachine/external/apone/mods/coreutils/.. -g -funsigned-char  -g -funsigned-char -O2 -w -fvisibility=hidden -fsigned-char -MD -MT plugins/playerproplugin/CMakeFiles/playerproplugin.dir/__/__/__/__/playerpro/PPStubs.c.o -MF plugins/playerproplugin/CMakeFiles/playerproplugin.dir/__/__/__/__/playerpro/PPStubs.c.o.d -o plugins/playerproplugin/CMakeFiles/playerproplugin.dir/__/__/__/__/playerpro/PPStubs.c.o -c /home/pi5/git/chipmachine/external/playerpro/PPStubs.c
/home/pi5/git/chipmachine/external/playerpro/PPStubs.c:12:10: fatal error: CoreFoundation/CoreFoundation.h: No such file or directory
   12 | #include <CoreFoundation/CoreFoundation.h>
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
compilation terminated.
[6/1211] Building CXX object plugins/jxsplugin/CMakeFiles/jxsplugin.dir/JxsPlugin.cpp.o
ninja: build stopped: subcommand failed.
```
