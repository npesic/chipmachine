FAILED: [code=1] CMakeFiles/cm.dir/src/main.cpp.obj
C:\msys64\mingw64\bin\c++.exe -DNO_IXSPLUGIN -DSOL_USING_CXX_LUA -DTEXTMODE_ONLY -IC:/msys64/home/lab/git/chipmachine/external/apone/mods/grappix -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/plugins -IC:/msys64/home/lab/git/chipmachine/external/zxtune/3rdparty/lhasa/lib/public -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/.. -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/src/psf/include -IC:/msys64/home/lab/git/chipmachine/external/apone/mods/coreutils/.. -isystem C:/msys64/home/lab/git/chipmachine/external/sol2 -isystem C:/msys64/home/lab/git/chipmachine/external/lua -g -funsigned-char -include cstdint  -g -funsigned-char -include cstdint -O2 -std=gnu++17 -MD -MT CMakeFiles/cm.dir/src/main.cpp.obj -MF CMakeFiles\cm.dir\src\main.cpp.obj.d -o CMakeFiles/cm.dir/src/main.cpp.obj -c C:/msys64/home/lab/git/chipmachine/src/main.cpp
In file included from C:/msys64/home/lab/git/chipmachine/external/apone/mods/netlink/include/netlink/core.h:46,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/netlink/include/netlink/socket.h:25,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/bbsutils/telnetserver.h:16,
                 from C:/msys64/home/lab/git/chipmachine/src/main.cpp:9:
C:/msys64/mingw64/include/winsock2.h:15:2: warning: #warning Please include winsock2.h before windows.h [-Wcpp]
   15 | #warning Please include winsock2.h before windows.h
      |  ^~~~~~~
C:/msys64/home/lab/git/chipmachine/src/main.cpp: In function 'int main(int, char**)':
C:/msys64/home/lab/git/chipmachine/src/main.cpp:253:5: error: 'setenv' was not declared in this scope; did you mean 'getenv'?
  253 |     setenv("PATH", newPath.c_str(), 1);
      |     ^~~~~~
      |     getenv
[63/70] Building CXX object CMakeFiles/cm.dir/src/textmode.cpp.obj
In file included from C:/msys64/home/lab/git/chipmachine/external/apone/mods/netlink/include/netlink/core.h:46,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/netlink/include/netlink/socket.h:25,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/bbsutils/telnetserver.h:16,
                 from C:/msys64/home/lab/git/chipmachine/src/textmode.cpp:9:
C:/msys64/mingw64/include/winsock2.h:15:2: warning: #warning Please include winsock2.h before windows.h [-Wcpp]
   15 | #warning Please include winsock2.h before windows.h
      |  ^~~~~~~
[66/70] Building CXX object CMakeFiles/cm.dir/src/MusicDatabase.cpp.obj
ninja: build stopped: subcommand failed.
