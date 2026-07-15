# Build issue 4

```
FAILED: plugins/playerproplugin/CMakeFiles/playerproplugin.dir/__/__/__/__/playerpro/MainDriver.c.o 
/usr/bin/ccache /usr/bin/cc -DEMBEDPLUGS=1 -DPPRO_PORTABLE_PLUG -I/home/pi5/git/chipmachine/external/playerpro -I/home/pi5/git/chipmachine/external/apone/mods/coreutils/.. -g -funsigned-char  -g -funsigned-char -O2 -w -fvisibility=hidden -fsigned-char -MD -MT plugins/playerproplugin/CMakeFiles/playerproplugin.dir/__/__/__/__/playerpro/MainDriver.c.o -MF plugins/playerproplugin/CMakeFiles/playerproplugin.dir/__/__/__/__/playerpro/MainDriver.c.o.d -o plugins/playerproplugin/CMakeFiles/playerproplugin.dir/__/__/__/__/playerpro/MainDriver.c.o -c /home/pi5/git/chipmachine/external/playerpro/MainDriver.c
/home/pi5/git/chipmachine/external/playerpro/MainDriver.c: In function ‘MADReadMAD’:
/home/pi5/git/chipmachine/external/playerpro/MainDriver.c:2201:34: error: ‘MADCFReadStreamType’ undeclared (first use in this function); did you mean ‘MADReadStream’?
 2201 |                 if (InPutType != MADCFReadStreamType)
      |                                  ^~~~~~~~~~~~~~~~~~~
      |                                  MADReadStream
/home/pi5/git/chipmachine/external/playerpro/MainDriver.c:2201:34: note: each undeclared identifier is reported only once for each function it appears in
[720/1944] Building CXX object plugins/sksplugin/at3_baseexport/CMakeFiles/BaseExport.dir/__/__/__/JUCE/modules/juce_core/juce_core.cpp.o
ninja: build stopped: subcommand failed.
```
