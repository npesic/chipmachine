FAILED: [code=1] CMakeFiles/cmtest.dir/test.cpp.obj
C:\msys64\mingw64\bin\c++.exe -DNO_DMFPLUGIN -DNO_EUPPLUGIN -DNO_IXSPLUGIN -DNO_MIKMODPLUGIN -DNO_PLAYERPROPLUGIN -DNO_WSRPLUGIN -DSOL_USING_CXX_LUA -DTESTING -IC:/msys64/home/lab/git/chipmachine/external/apone/mods/grappix -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/plugins -IC:/msys64/home/lab/git/chipmachine/external/zxtune/3rdparty/lhasa/lib/public -I/mods -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/s98plugin/m_s98/device/fmgen -IC:/msys64/home/lab/git/chipmachine/external/apone/mods/coreutils/.. -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/.. -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/src/psf/include -isystem C:/msys64/home/lab/git/chipmachine/external/sol2 -isystem C:/msys64/home/lab/git/chipmachine/external/lua -g -funsigned-char -include cstdint  -g -funsigned-char -include cstdint -O2 -std=gnu++17 -MD -MT CMakeFiles/cmtest.dir/test.cpp.obj -MF CMakeFiles\cmtest.dir\test.cpp.obj.d -o CMakeFiles/cmtest.dir/test.cpp.obj -c C:/msys64/home/lab/git/chipmachine/test.cpp
C:/msys64/home/lab/git/chipmachine/test.cpp: In function 'void ____C_A_T_C_H____T_E_S_T____313()':
C:/msys64/home/lab/git/chipmachine/test.cpp:329:27: error: reference to 'SID' is ambiguous
  329 |         { "Commodore 64", SID },          { "Apple IIgs", APPLE },
      |                           ^~~
  • there are 2 candidates
In file included from C:/msys64/mingw64/include/minwindef.h:163,
                 from C:/msys64/mingw64/include/windef.h:9,
                 from C:/msys64/mingw64/include/windows.h:69,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/coreutils/exec.h:13,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/coreutils/utils.h:315,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/coreutils/file.h:3,
                 from C:/msys64/home/lab/git/chipmachine/src/SearchIndex.h:4,
                 from C:/msys64/home/lab/git/chipmachine/src/MusicDatabase.h:4,
                 from C:/msys64/home/lab/git/chipmachine/test.cpp:3:
    • candidate 1: 'typedef struct _SID SID'
      C:/msys64/mingw64/include/winnt.h:3216:7:
       3216 |     } SID,*PISID;
            |       ^~~
    • candidate 2: 'chipmachine::Formats chipmachine::SID'
      C:/msys64/home/lab/git/chipmachine/src/MusicDatabase.h:68:5:
         68 |     SID, // Commodore 64 SID tunes (formerly C64)
            |     ^~~
C:/msys64/home/lab/git/chipmachine/test.cpp: In function 'void ____C_A_T_C_H____T_E_S_T____442()':
C:/msys64/home/lab/git/chipmachine/test.cpp:449:60: error: reference to 'SID' is ambiguous
  449 |         { "Amiga", AMIGA },              { "Commodore 64", SID },
      |                                                            ^~~
  • there are 2 candidates
    • candidate 1: 'typedef struct _SID SID'
      C:/msys64/mingw64/include/winnt.h:3216:7:
       3216 |     } SID,*PISID;
            |       ^~~
    • candidate 2: 'chipmachine::Formats chipmachine::SID'
      C:/msys64/home/lab/git/chipmachine/src/MusicDatabase.h:68:5:
         68 |     SID, // Commodore 64 SID tunes (formerly C64)
            |     ^~~
C:/msys64/home/lab/git/chipmachine/test.cpp: In function 'void ____C_A_T_C_H____T_E_S_T____475()':
C:/msys64/home/lab/git/chipmachine/test.cpp:490:18: error: reference to 'SID' is ambiguous
  490 |         if (b == SID && sidPos < 0) sidPos = (int)i;     // real HVSC .sid
      |                  ^~~
  • there are 2 candidates
    • candidate 1: 'typedef struct _SID SID'
      C:/msys64/mingw64/include/winnt.h:3216:7:
       3216 |     } SID,*PISID;
            |       ^~~
    • candidate 2: 'chipmachine::Formats chipmachine::SID'
      C:/msys64/home/lab/git/chipmachine/src/MusicDatabase.h:68:5:
         68 |     SID, // Commodore 64 SID tunes (formerly C64)
            |     ^~~
[11/17] Building CXX object CMakeFiles/cmtest.dir/src/textmode.cpp.obj
In file included from C:/msys64/home/lab/git/chipmachine/external/apone/mods/netlink/include/netlink/core.h:46,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/netlink/include/netlink/socket.h:25,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/bbsutils/telnetserver.h:16,
                 from C:/msys64/home/lab/git/chipmachine/src/textmode.cpp:9:
C:/msys64/mingw64/include/winsock2.h:15:2: warning: #warning Please include winsock2.h before windows.h [-Wcpp]
   15 | #warning Please include winsock2.h before windows.h
      |  ^~~~~~~
[15/17] Building CXX object CMakeFiles/cmtest.dir/src/MusicDatabase.cpp.obj
ninja: build stopped: subcommand failed.
