[14/136] Building C object plugins/playerproplugin/CMakeFiles/playerproplugin.dir/__/__/__/__/playerpro/stub-VSTPlugIn.c.obj
FAILED: [code=1] plugins/playerproplugin/CMakeFiles/playerproplugin.dir/__/__/__/__/playerpro/stub-VSTPlugIn.c.obj
C:\msys64\mingw64\bin\cc.exe -DEMBEDPLUGS=1 -DPPRO_PORTABLE_PLUG -IC:/msys64/home/lab/git/chipmachine/external/playerpro -IC:/msys64/home/lab/git/chipmachine/external/apone/mods/coreutils/.. -g -funsigned-char -std=gnu17 -Wno-incompatible-pointer-types -Wno-int-conversion -Wno-implicit-function-declaration -Wno-implicit-int  -g -funsigned-char -std=gnu17 -Wno-incompatible-pointer-types -Wno-int-conversion -Wno-implicit-function-declaration -Wno-implicit-int -O2 -w -fvisibility=hidden -fsigned-char -MD -MT plugins/playerproplugin/CMakeFiles/playerproplugin.dir/__/__/__/__/playerpro/stub-VSTPlugIn.c.obj -MF plugins\playerproplugin\CMakeFiles\playerproplugin.dir\__\__\__\__\playerpro\stub-VSTPlugIn.c.obj.d -o plugins/playerproplugin/CMakeFiles/playerproplugin.dir/__/__/__/__/playerpro/stub-VSTPlugIn.c.obj -c C:/msys64/home/lab/git/chipmachine/external/playerpro/stub-VSTPlugIn.c
In file included from C:/msys64/home/lab/git/chipmachine/external/playerpro/VSTFunctions.h:12,
                 from C:/msys64/home/lab/git/chipmachine/external/playerpro/stub-VSTPlugIn.c:9:
C:/msys64/home/lab/git/chipmachine/external/playerpro/RDriver.h:511:16: error: redefinition of 'struct PlugInfo'
  511 | typedef struct PlugInfo {
      |                ^~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/playerpro/RDriver.h:468:16: note: originally defined here
  468 | typedef struct PlugInfo {
      |                ^~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/playerpro/RDriver.h:527:3: error: conflicting types for 'PlugInfo'; have 'struct PlugInfo'
  527 | } PlugInfo;
      |   ^~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/playerpro/RDriver.h:484:3: note: previous declaration of 'PlugInfo' with type 'PlugInfo'
  484 | } PlugInfo;
      |   ^~~~~~~~
[16/136] Building CXX object plugins/playerproplugin/CMakeFiles/playerproplugin.dir/PlayerProPlugin.cpp.obj
ninja: build stopped: subcommand failed.
