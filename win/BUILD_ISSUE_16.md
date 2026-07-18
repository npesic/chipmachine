FAILED: [code=1] plugins/ixsplugin/CMakeFiles/ixsplugin.dir/__/__/__/__/webixs/FileMap.cpp.obj
C:\msys64\mingw64\bin\c++.exe -DLINUX -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/ixsplugin -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/ixsplugin/../../../../webixs -IC:/msys64/home/lab/git/chipmachine/external/apone/mods/coreutils/.. -g -funsigned-char -include cstdint  -g -funsigned-char -include cstdint -O2 -std=gnu++17 -w -fsigned-char -MD -MT plugins/ixsplugin/CMakeFiles/ixsplugin.dir/__/__/__/__/webixs/FileMap.cpp.obj -MF plugins\ixsplugin\CMakeFiles\ixsplugin.dir\__\__\__\__\webixs\FileMap.cpp.obj.d -o plugins/ixsplugin/CMakeFiles/ixsplugin.dir/__/__/__/__/webixs/FileMap.cpp.obj -c C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp
C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp:36:13: error: conflicting declaration 'typedef int mode_t'
   36 | typedef int mode_t;
      |             ^~~~~~
In file included from C:/msys64/mingw64/include/sys/stat.h:26,
                 from C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp:17:
C:/msys64/mingw64/include/sys/types.h:77:17: note: previous declaration as 'typedef _mode_t mode_t'
   77 | typedef _mode_t mode_t;
      |                 ^~~~~~
[29/125] Building CXX object plugins/ixsplugin/CMakeFiles/ixsplugin.dir/IXSPlugin.cpp.obj
FAILED: [code=1] plugins/ixsplugin/CMakeFiles/ixsplugin.dir/IXSPlugin.cpp.obj
C:\msys64\mingw64\bin\c++.exe -DLINUX -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/ixsplugin -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/ixsplugin/../../../../webixs -IC:/msys64/home/lab/git/chipmachine/external/apone/mods/coreutils/.. -g -funsigned-char -include cstdint  -g -funsigned-char -include cstdint -O2 -std=gnu++17 -w -fsigned-char -MD -MT plugins/ixsplugin/CMakeFiles/ixsplugin.dir/IXSPlugin.cpp.obj -MF plugins\ixsplugin\CMakeFiles\ixsplugin.dir\IXSPlugin.cpp.obj.d -o plugins/ixsplugin/CMakeFiles/ixsplugin.dir/IXSPlugin.cpp.obj -c C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/ixsplugin/IXSPlugin.cpp
In file included from C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.h:36,
                 from C:/msys64/home/lab/git/chipmachine/external/webixs/FileMapSFXI.h:17,
                 from C:/msys64/home/lab/git/chipmachine/external/webixs/FileSFXI.h:19,
                 from C:/msys64/home/lab/git/chipmachine/external/webixs/Module.h:22,
                 from C:/msys64/home/lab/git/chipmachine/external/webixs/PlayerIXS.h:16,
                 from C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/ixsplugin/IXSPlugin.cpp:17:
C:/msys64/home/lab/git/chipmachine/external/webixs/basetypes.h:34:18: error: conflicting declaration 'typedef intptr_t HANDLE'
   34 | typedef intptr_t HANDLE;
      |                  ^~~~~~
In file included from C:/msys64/mingw64/include/minwindef.h:163,
                 from C:/msys64/mingw64/include/windef.h:9,
                 from C:/msys64/mingw64/include/windows.h:69,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/coreutils/exec.h:13,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/coreutils/utils.h:315,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/coreutils/file.h:3,
                 from C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/ixsplugin/IXSPlugin.cpp:4:
C:/msys64/mingw64/include/winnt.h:442:17: note: previous declaration as 'typedef void* HANDLE'
  442 |   typedef void *HANDLE;
      |                 ^~~~~~
[31/125] Building CXX object plugins/monotoneplugin/CMakeFiles/monotoneplugin.dir/MonotonePlugin.cpp.obj
ninja: build stopped: subcommand failed.
