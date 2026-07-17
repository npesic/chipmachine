$ ninja -C builds/release cm
ninja: Entering directory `builds/release'
[0/2] Re-checking globbed directories...
[1/2821] Building CXX object ap1mods/archive/unrar/CMakeFiles/unrar.dir/filcreat.cpp.obj
FAILED: [code=1] ap1mods/archive/unrar/CMakeFiles/unrar.dir/filcreat.cpp.obj
C:\msys64\mingw64\bin\c++.exe -DLITTLE_ENDIAN -DRARDLL -DSILENT  -g -funsigned-char -Wno-logical-op-parentheses -Wno-dangling-else -Wno-switch  -g -funsigned-char -O2 -std=gnu++17 -MD -MT ap1mods/archive/unrar/CMakeFiles/unrar.dir/filcreat.cpp.obj -MF ap1mods\archive\unrar\CMakeFiles\unrar.dir\filcreat.cpp.obj.d -o ap1mods/archive/unrar/CMakeFiles/unrar.dir/filcreat.cpp.obj -c C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/filcreat.cpp
In file included from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/rar.hpp:5,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/filcreat.cpp:1:
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:22:9: warning: 'LITTLE_ENDIAN' redefined
   22 | #define LITTLE_ENDIAN
      |         ^~~~~~~~~~~~~
<command-line>: note: this is the location of the previous definition
In file included from C:/msys64/mingw64/include/combaseapi.h:155,
                 from C:/msys64/mingw64/include/objbase.h:14,
                 from C:/msys64/mingw64/include/ole2.h:17,
                 from C:/msys64/mingw64/include/wtypesbase.h:13,
                 from C:/msys64/mingw64/include/shlobj.h:9,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:49:
C:/msys64/mingw64/include/objidlbase.h:3584:3: error: conflicting declaration 'typedef struct tagSOLE_AUTHENTICATION_SERVICE SOLE_AUTHENTICATION_SERVICE'
 3584 | } SOLE_AUTHENTICATION_SERVICE;
      |   ^~~~~~~~~~~~~~~~~~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:47:10: note: previous declaration as 'struct SOLE_AUTHENTICATION_SERVICE'
   47 |   struct SOLE_AUTHENTICATION_SERVICE;
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~
cc1plus.exe: note: unrecognized command-line option '-Wno-logical-op-parentheses' may have been intended to silence earlier diagnostics
[2/2821] Building CXX object ap1mods/archive/unrar/CMakeFiles/unrar.dir/scantree.cpp.obj
FAILED: [code=1] ap1mods/archive/unrar/CMakeFiles/unrar.dir/scantree.cpp.obj
C:\msys64\mingw64\bin\c++.exe -DLITTLE_ENDIAN -DRARDLL -DSILENT  -g -funsigned-char -Wno-logical-op-parentheses -Wno-dangling-else -Wno-switch  -g -funsigned-char -O2 -std=gnu++17 -MD -MT ap1mods/archive/unrar/CMakeFiles/unrar.dir/scantree.cpp.obj -MF ap1mods\archive\unrar\CMakeFiles\unrar.dir\scantree.cpp.obj.d -o ap1mods/archive/unrar/CMakeFiles/unrar.dir/scantree.cpp.obj -c C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/scantree.cpp
In file included from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/rar.hpp:5,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/scantree.cpp:1:
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:22:9: warning: 'LITTLE_ENDIAN' redefined
   22 | #define LITTLE_ENDIAN
      |         ^~~~~~~~~~~~~
<command-line>: note: this is the location of the previous definition
In file included from C:/msys64/mingw64/include/combaseapi.h:155,
                 from C:/msys64/mingw64/include/objbase.h:14,
                 from C:/msys64/mingw64/include/ole2.h:17,
                 from C:/msys64/mingw64/include/wtypesbase.h:13,
                 from C:/msys64/mingw64/include/shlobj.h:9,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:49:
C:/msys64/mingw64/include/objidlbase.h:3584:3: error: conflicting declaration 'typedef struct tagSOLE_AUTHENTICATION_SERVICE SOLE_AUTHENTICATION_SERVICE'
 3584 | } SOLE_AUTHENTICATION_SERVICE;
      |   ^~~~~~~~~~~~~~~~~~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:47:10: note: previous declaration as 'struct SOLE_AUTHENTICATION_SERVICE'
   47 |   struct SOLE_AUTHENTICATION_SERVICE;
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~
cc1plus.exe: note: unrecognized command-line option '-Wno-logical-op-parentheses' may have been intended to silence earlier diagnostics
[3/2821] Building CXX object ap1mods/archive/unrar/CMakeFiles/unrar.dir/savepos.cpp.obj
FAILED: [code=1] ap1mods/archive/unrar/CMakeFiles/unrar.dir/savepos.cpp.obj
C:\msys64\mingw64\bin\c++.exe -DLITTLE_ENDIAN -DRARDLL -DSILENT  -g -funsigned-char -Wno-logical-op-parentheses -Wno-dangling-else -Wno-switch  -g -funsigned-char -O2 -std=gnu++17 -MD -MT ap1mods/archive/unrar/CMakeFiles/unrar.dir/savepos.cpp.obj -MF ap1mods\archive\unrar\CMakeFiles\unrar.dir\savepos.cpp.obj.d -o ap1mods/archive/unrar/CMakeFiles/unrar.dir/savepos.cpp.obj -c C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/savepos.cpp
In file included from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/rar.hpp:5,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/savepos.cpp:1:
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:22:9: warning: 'LITTLE_ENDIAN' redefined
   22 | #define LITTLE_ENDIAN
      |         ^~~~~~~~~~~~~
<command-line>: note: this is the location of the previous definition
In file included from C:/msys64/mingw64/include/combaseapi.h:155,
                 from C:/msys64/mingw64/include/objbase.h:14,
                 from C:/msys64/mingw64/include/ole2.h:17,
                 from C:/msys64/mingw64/include/wtypesbase.h:13,
                 from C:/msys64/mingw64/include/shlobj.h:9,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:49:
C:/msys64/mingw64/include/objidlbase.h:3584:3: error: conflicting declaration 'typedef struct tagSOLE_AUTHENTICATION_SERVICE SOLE_AUTHENTICATION_SERVICE'
 3584 | } SOLE_AUTHENTICATION_SERVICE;
      |   ^~~~~~~~~~~~~~~~~~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:47:10: note: previous declaration as 'struct SOLE_AUTHENTICATION_SERVICE'
   47 |   struct SOLE_AUTHENTICATION_SERVICE;
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~
cc1plus.exe: note: unrecognized command-line option '-Wno-logical-op-parentheses' may have been intended to silence earlier diagnostics
[4/2821] Building CXX object ap1mods/archive/unrar/CMakeFiles/unrar.dir/strfn.cpp.obj
FAILED: [code=1] ap1mods/archive/unrar/CMakeFiles/unrar.dir/strfn.cpp.obj
C:\msys64\mingw64\bin\c++.exe -DLITTLE_ENDIAN -DRARDLL -DSILENT  -g -funsigned-char -Wno-logical-op-parentheses -Wno-dangling-else -Wno-switch  -g -funsigned-char -O2 -std=gnu++17 -MD -MT ap1mods/archive/unrar/CMakeFiles/unrar.dir/strfn.cpp.obj -MF ap1mods\archive\unrar\CMakeFiles\unrar.dir\strfn.cpp.obj.d -o ap1mods/archive/unrar/CMakeFiles/unrar.dir/strfn.cpp.obj -c C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/strfn.cpp
In file included from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/rar.hpp:5,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/strfn.cpp:1:
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:22:9: warning: 'LITTLE_ENDIAN' redefined
   22 | #define LITTLE_ENDIAN
      |         ^~~~~~~~~~~~~
<command-line>: note: this is the location of the previous definition
In file included from C:/msys64/mingw64/include/combaseapi.h:155,
                 from C:/msys64/mingw64/include/objbase.h:14,
                 from C:/msys64/mingw64/include/ole2.h:17,
                 from C:/msys64/mingw64/include/wtypesbase.h:13,
                 from C:/msys64/mingw64/include/shlobj.h:9,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:49:
C:/msys64/mingw64/include/objidlbase.h:3584:3: error: conflicting declaration 'typedef struct tagSOLE_AUTHENTICATION_SERVICE SOLE_AUTHENTICATION_SERVICE'
 3584 | } SOLE_AUTHENTICATION_SERVICE;
      |   ^~~~~~~~~~~~~~~~~~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:47:10: note: previous declaration as 'struct SOLE_AUTHENTICATION_SERVICE'
   47 |   struct SOLE_AUTHENTICATION_SERVICE;
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/strfn.cpp: In function 'unsigned char loctolower(unsigned char)':
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/strfn.cpp:107:33: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
  107 |   return((int)(LPARAM)CharLower((LPTSTR)ch));
      |                                 ^~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/strfn.cpp: In function 'unsigned char loctoupper(unsigned char)':
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/strfn.cpp:118:33: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
  118 |   return((int)(LPARAM)CharUpper((LPTSTR)ch));
      |                                 ^~~~~~~~~~
At global scope:
cc1plus.exe: note: unrecognized command-line option '-Wno-logical-op-parentheses' may have been intended to silence earlier diagnostics
[5/2821] Building CXX object ap1mods/archive/unrar/CMakeFiles/unrar.dir/global.cpp.obj
FAILED: [code=1] ap1mods/archive/unrar/CMakeFiles/unrar.dir/global.cpp.obj
C:\msys64\mingw64\bin\c++.exe -DLITTLE_ENDIAN -DRARDLL -DSILENT  -g -funsigned-char -Wno-logical-op-parentheses -Wno-dangling-else -Wno-switch  -g -funsigned-char -O2 -std=gnu++17 -MD -MT ap1mods/archive/unrar/CMakeFiles/unrar.dir/global.cpp.obj -MF ap1mods\archive\unrar\CMakeFiles\unrar.dir\global.cpp.obj.d -o ap1mods/archive/unrar/CMakeFiles/unrar.dir/global.cpp.obj -c C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/global.cpp
In file included from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/rar.hpp:5,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/global.cpp:4:
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:22:9: warning: 'LITTLE_ENDIAN' redefined
   22 | #define LITTLE_ENDIAN
      |         ^~~~~~~~~~~~~
<command-line>: note: this is the location of the previous definition
In file included from C:/msys64/mingw64/include/combaseapi.h:155,
                 from C:/msys64/mingw64/include/objbase.h:14,
                 from C:/msys64/mingw64/include/ole2.h:17,
                 from C:/msys64/mingw64/include/wtypesbase.h:13,
                 from C:/msys64/mingw64/include/shlobj.h:9,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:49:
C:/msys64/mingw64/include/objidlbase.h:3584:3: error: conflicting declaration 'typedef struct tagSOLE_AUTHENTICATION_SERVICE SOLE_AUTHENTICATION_SERVICE'
 3584 | } SOLE_AUTHENTICATION_SERVICE;
      |   ^~~~~~~~~~~~~~~~~~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:47:10: note: previous declaration as 'struct SOLE_AUTHENTICATION_SERVICE'
   47 |   struct SOLE_AUTHENTICATION_SERVICE;
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~
cc1plus.exe: note: unrecognized command-line option '-Wno-logical-op-parentheses' may have been intended to silence earlier diagnostics
[6/2821] Building CXX object ap1mods/archive/unrar/CMakeFiles/unrar.dir/dll.cpp.obj
FAILED: [code=1] ap1mods/archive/unrar/CMakeFiles/unrar.dir/dll.cpp.obj
C:\msys64\mingw64\bin\c++.exe -DLITTLE_ENDIAN -DRARDLL -DSILENT  -g -funsigned-char -Wno-logical-op-parentheses -Wno-dangling-else -Wno-switch  -g -funsigned-char -O2 -std=gnu++17 -MD -MT ap1mods/archive/unrar/CMakeFiles/unrar.dir/dll.cpp.obj -MF ap1mods\archive\unrar\CMakeFiles\unrar.dir\dll.cpp.obj.d -o ap1mods/archive/unrar/CMakeFiles/unrar.dir/dll.cpp.obj -c C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/dll.cpp
In file included from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/rar.hpp:5,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/dll.cpp:1:
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:22:9: warning: 'LITTLE_ENDIAN' redefined
   22 | #define LITTLE_ENDIAN
      |         ^~~~~~~~~~~~~
<command-line>: note: this is the location of the previous definition
In file included from C:/msys64/mingw64/include/combaseapi.h:155,
                 from C:/msys64/mingw64/include/objbase.h:14,
                 from C:/msys64/mingw64/include/ole2.h:17,
                 from C:/msys64/mingw64/include/wtypesbase.h:13,
                 from C:/msys64/mingw64/include/shlobj.h:9,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:49:
C:/msys64/mingw64/include/objidlbase.h:3584:3: error: conflicting declaration 'typedef struct tagSOLE_AUTHENTICATION_SERVICE SOLE_AUTHENTICATION_SERVICE'
 3584 | } SOLE_AUTHENTICATION_SERVICE;
      |   ^~~~~~~~~~~~~~~~~~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:47:10: note: previous declaration as 'struct SOLE_AUTHENTICATION_SERVICE'
   47 |   struct SOLE_AUTHENTICATION_SERVICE;
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~
cc1plus.exe: note: unrecognized command-line option '-Wno-logical-op-parentheses' may have been intended to silence earlier diagnostics
[7/2821] Building CXX object ap1mods/archive/unrar/CMakeFiles/unrar.dir/pathfn.cpp.obj
FAILED: [code=1] ap1mods/archive/unrar/CMakeFiles/unrar.dir/pathfn.cpp.obj
C:\msys64\mingw64\bin\c++.exe -DLITTLE_ENDIAN -DRARDLL -DSILENT  -g -funsigned-char -Wno-logical-op-parentheses -Wno-dangling-else -Wno-switch  -g -funsigned-char -O2 -std=gnu++17 -MD -MT ap1mods/archive/unrar/CMakeFiles/unrar.dir/pathfn.cpp.obj -MF ap1mods\archive\unrar\CMakeFiles\unrar.dir\pathfn.cpp.obj.d -o ap1mods/archive/unrar/CMakeFiles/unrar.dir/pathfn.cpp.obj -c C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/pathfn.cpp
In file included from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/rar.hpp:5,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/pathfn.cpp:1:
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:22:9: warning: 'LITTLE_ENDIAN' redefined
   22 | #define LITTLE_ENDIAN
      |         ^~~~~~~~~~~~~
<command-line>: note: this is the location of the previous definition
In file included from C:/msys64/mingw64/include/combaseapi.h:155,
                 from C:/msys64/mingw64/include/objbase.h:14,
                 from C:/msys64/mingw64/include/ole2.h:17,
                 from C:/msys64/mingw64/include/wtypesbase.h:13,
                 from C:/msys64/mingw64/include/shlobj.h:9,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:49:
C:/msys64/mingw64/include/objidlbase.h:3584:3: error: conflicting declaration 'typedef struct tagSOLE_AUTHENTICATION_SERVICE SOLE_AUTHENTICATION_SERVICE'
 3584 | } SOLE_AUTHENTICATION_SERVICE;
      |   ^~~~~~~~~~~~~~~~~~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:47:10: note: previous declaration as 'struct SOLE_AUTHENTICATION_SERVICE'
   47 |   struct SOLE_AUTHENTICATION_SERVICE;
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~
cc1plus.exe: note: unrecognized command-line option '-Wno-logical-op-parentheses' may have been intended to silence earlier diagnostics
[8/2821] Building CXX object ap1mods/archive/unrar/CMakeFiles/unrar.dir/file.cpp.obj
FAILED: [code=1] ap1mods/archive/unrar/CMakeFiles/unrar.dir/file.cpp.obj
C:\msys64\mingw64\bin\c++.exe -DLITTLE_ENDIAN -DRARDLL -DSILENT  -g -funsigned-char -Wno-logical-op-parentheses -Wno-dangling-else -Wno-switch  -g -funsigned-char -O2 -std=gnu++17 -MD -MT ap1mods/archive/unrar/CMakeFiles/unrar.dir/file.cpp.obj -MF ap1mods\archive\unrar\CMakeFiles\unrar.dir\file.cpp.obj.d -o ap1mods/archive/unrar/CMakeFiles/unrar.dir/file.cpp.obj -c C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/file.cpp
In file included from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/rar.hpp:5,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/file.cpp:1:
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:22:9: warning: 'LITTLE_ENDIAN' redefined
   22 | #define LITTLE_ENDIAN
      |         ^~~~~~~~~~~~~
<command-line>: note: this is the location of the previous definition
In file included from C:/msys64/mingw64/include/combaseapi.h:155,
                 from C:/msys64/mingw64/include/objbase.h:14,
                 from C:/msys64/mingw64/include/ole2.h:17,
                 from C:/msys64/mingw64/include/wtypesbase.h:13,
                 from C:/msys64/mingw64/include/shlobj.h:9,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:49:
C:/msys64/mingw64/include/objidlbase.h:3584:3: error: conflicting declaration 'typedef struct tagSOLE_AUTHENTICATION_SERVICE SOLE_AUTHENTICATION_SERVICE'
 3584 | } SOLE_AUTHENTICATION_SERVICE;
      |   ^~~~~~~~~~~~~~~~~~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:47:10: note: previous declaration as 'struct SOLE_AUTHENTICATION_SERVICE'
   47 |   struct SOLE_AUTHENTICATION_SERVICE;
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~
cc1plus.exe: note: unrecognized command-line option '-Wno-logical-op-parentheses' may have been intended to silence earlier diagnostics
[9/2821] Building CXX object ap1mods/archive/unrar/CMakeFiles/unrar.dir/filefn.cpp.obj
FAILED: [code=1] ap1mods/archive/unrar/CMakeFiles/unrar.dir/filefn.cpp.obj
C:\msys64\mingw64\bin\c++.exe -DLITTLE_ENDIAN -DRARDLL -DSILENT  -g -funsigned-char -Wno-logical-op-parentheses -Wno-dangling-else -Wno-switch  -g -funsigned-char -O2 -std=gnu++17 -MD -MT ap1mods/archive/unrar/CMakeFiles/unrar.dir/filefn.cpp.obj -MF ap1mods\archive\unrar\CMakeFiles\unrar.dir\filefn.cpp.obj.d -o ap1mods/archive/unrar/CMakeFiles/unrar.dir/filefn.cpp.obj -c C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/filefn.cpp
In file included from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/rar.hpp:5,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/filefn.cpp:1:
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:22:9: warning: 'LITTLE_ENDIAN' redefined
   22 | #define LITTLE_ENDIAN
      |         ^~~~~~~~~~~~~
<command-line>: note: this is the location of the previous definition
In file included from C:/msys64/mingw64/include/combaseapi.h:155,
                 from C:/msys64/mingw64/include/objbase.h:14,
                 from C:/msys64/mingw64/include/ole2.h:17,
                 from C:/msys64/mingw64/include/wtypesbase.h:13,
                 from C:/msys64/mingw64/include/shlobj.h:9,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:49:
C:/msys64/mingw64/include/objidlbase.h:3584:3: error: conflicting declaration 'typedef struct tagSOLE_AUTHENTICATION_SERVICE SOLE_AUTHENTICATION_SERVICE'
 3584 | } SOLE_AUTHENTICATION_SERVICE;
      |   ^~~~~~~~~~~~~~~~~~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:47:10: note: previous declaration as 'struct SOLE_AUTHENTICATION_SERVICE'
   47 |   struct SOLE_AUTHENTICATION_SERVICE;
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~
cc1plus.exe: note: unrecognized command-line option '-Wno-logical-op-parentheses' may have been intended to silence earlier diagnostics
[10/2821] Building CXX object ap1mods/archive/unrar/CMakeFiles/unrar.dir/archive.cpp.obj
FAILED: [code=1] ap1mods/archive/unrar/CMakeFiles/unrar.dir/archive.cpp.obj
C:\msys64\mingw64\bin\c++.exe -DLITTLE_ENDIAN -DRARDLL -DSILENT  -g -funsigned-char -Wno-logical-op-parentheses -Wno-dangling-else -Wno-switch  -g -funsigned-char -O2 -std=gnu++17 -MD -MT ap1mods/archive/unrar/CMakeFiles/unrar.dir/archive.cpp.obj -MF ap1mods\archive\unrar\CMakeFiles\unrar.dir\archive.cpp.obj.d -o ap1mods/archive/unrar/CMakeFiles/unrar.dir/archive.cpp.obj -c C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/archive.cpp
In file included from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/rar.hpp:5,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/archive.cpp:1:
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:22:9: warning: 'LITTLE_ENDIAN' redefined
   22 | #define LITTLE_ENDIAN
      |         ^~~~~~~~~~~~~
<command-line>: note: this is the location of the previous definition
In file included from C:/msys64/mingw64/include/combaseapi.h:155,
                 from C:/msys64/mingw64/include/objbase.h:14,
                 from C:/msys64/mingw64/include/ole2.h:17,
                 from C:/msys64/mingw64/include/wtypesbase.h:13,
                 from C:/msys64/mingw64/include/shlobj.h:9,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:49:
C:/msys64/mingw64/include/objidlbase.h:3584:3: error: conflicting declaration 'typedef struct tagSOLE_AUTHENTICATION_SERVICE SOLE_AUTHENTICATION_SERVICE'
 3584 | } SOLE_AUTHENTICATION_SERVICE;
      |   ^~~~~~~~~~~~~~~~~~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:47:10: note: previous declaration as 'struct SOLE_AUTHENTICATION_SERVICE'
   47 |   struct SOLE_AUTHENTICATION_SERVICE;
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~
cc1plus.exe: note: unrecognized command-line option '-Wno-logical-op-parentheses' may have been intended to silence earlier diagnostics
[11/2821] Building CXX object ap1mods/archive/unrar/CMakeFiles/unrar.dir/smallfn.cpp.obj
FAILED: [code=1] ap1mods/archive/unrar/CMakeFiles/unrar.dir/smallfn.cpp.obj
C:\msys64\mingw64\bin\c++.exe -DLITTLE_ENDIAN -DRARDLL -DSILENT  -g -funsigned-char -Wno-logical-op-parentheses -Wno-dangling-else -Wno-switch  -g -funsigned-char -O2 -std=gnu++17 -MD -MT ap1mods/archive/unrar/CMakeFiles/unrar.dir/smallfn.cpp.obj -MF ap1mods\archive\unrar\CMakeFiles\unrar.dir\smallfn.cpp.obj.d -o ap1mods/archive/unrar/CMakeFiles/unrar.dir/smallfn.cpp.obj -c C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/smallfn.cpp
In file included from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/rar.hpp:5,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/smallfn.cpp:1:
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:22:9: warning: 'LITTLE_ENDIAN' redefined
   22 | #define LITTLE_ENDIAN
      |         ^~~~~~~~~~~~~
<command-line>: note: this is the location of the previous definition
In file included from C:/msys64/mingw64/include/combaseapi.h:155,
                 from C:/msys64/mingw64/include/objbase.h:14,
                 from C:/msys64/mingw64/include/ole2.h:17,
                 from C:/msys64/mingw64/include/wtypesbase.h:13,
                 from C:/msys64/mingw64/include/shlobj.h:9,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:49:
C:/msys64/mingw64/include/objidlbase.h:3584:3: error: conflicting declaration 'typedef struct tagSOLE_AUTHENTICATION_SERVICE SOLE_AUTHENTICATION_SERVICE'
 3584 | } SOLE_AUTHENTICATION_SERVICE;
      |   ^~~~~~~~~~~~~~~~~~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:47:10: note: previous declaration as 'struct SOLE_AUTHENTICATION_SERVICE'
   47 |   struct SOLE_AUTHENTICATION_SERVICE;
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~
cc1plus.exe: note: unrecognized command-line option '-Wno-logical-op-parentheses' may have been intended to silence earlier diagnostics
[12/2821] Building CXX object ap1mods/archive/unrar/CMakeFiles/unrar.dir/filestr.cpp.obj
FAILED: [code=1] ap1mods/archive/unrar/CMakeFiles/unrar.dir/filestr.cpp.obj
C:\msys64\mingw64\bin\c++.exe -DLITTLE_ENDIAN -DRARDLL -DSILENT  -g -funsigned-char -Wno-logical-op-parentheses -Wno-dangling-else -Wno-switch  -g -funsigned-char -O2 -std=gnu++17 -MD -MT ap1mods/archive/unrar/CMakeFiles/unrar.dir/filestr.cpp.obj -MF ap1mods\archive\unrar\CMakeFiles\unrar.dir\filestr.cpp.obj.d -o ap1mods/archive/unrar/CMakeFiles/unrar.dir/filestr.cpp.obj -c C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/filestr.cpp
In file included from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/rar.hpp:5,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/filestr.cpp:1:
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:22:9: warning: 'LITTLE_ENDIAN' redefined
   22 | #define LITTLE_ENDIAN
      |         ^~~~~~~~~~~~~
<command-line>: note: this is the location of the previous definition
In file included from C:/msys64/mingw64/include/combaseapi.h:155,
                 from C:/msys64/mingw64/include/objbase.h:14,
                 from C:/msys64/mingw64/include/ole2.h:17,
                 from C:/msys64/mingw64/include/wtypesbase.h:13,
                 from C:/msys64/mingw64/include/shlobj.h:9,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:49:
C:/msys64/mingw64/include/objidlbase.h:3584:3: error: conflicting declaration 'typedef struct tagSOLE_AUTHENTICATION_SERVICE SOLE_AUTHENTICATION_SERVICE'
 3584 | } SOLE_AUTHENTICATION_SERVICE;
      |   ^~~~~~~~~~~~~~~~~~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:47:10: note: previous declaration as 'struct SOLE_AUTHENTICATION_SERVICE'
   47 |   struct SOLE_AUTHENTICATION_SERVICE;
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~
cc1plus.exe: note: unrecognized command-line option '-Wno-logical-op-parentheses' may have been intended to silence earlier diagnostics
[13/2821] Building CXX object ap1mods/archive/unrar/CMakeFiles/unrar.dir/strlist.cpp.obj
FAILED: [code=1] ap1mods/archive/unrar/CMakeFiles/unrar.dir/strlist.cpp.obj
C:\msys64\mingw64\bin\c++.exe -DLITTLE_ENDIAN -DRARDLL -DSILENT  -g -funsigned-char -Wno-logical-op-parentheses -Wno-dangling-else -Wno-switch  -g -funsigned-char -O2 -std=gnu++17 -MD -MT ap1mods/archive/unrar/CMakeFiles/unrar.dir/strlist.cpp.obj -MF ap1mods\archive\unrar\CMakeFiles\unrar.dir\strlist.cpp.obj.d -o ap1mods/archive/unrar/CMakeFiles/unrar.dir/strlist.cpp.obj -c C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/strlist.cpp
In file included from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/rar.hpp:5,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/strlist.cpp:1:
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:22:9: warning: 'LITTLE_ENDIAN' redefined
   22 | #define LITTLE_ENDIAN
      |         ^~~~~~~~~~~~~
<command-line>: note: this is the location of the previous definition
In file included from C:/msys64/mingw64/include/combaseapi.h:155,
                 from C:/msys64/mingw64/include/objbase.h:14,
                 from C:/msys64/mingw64/include/ole2.h:17,
                 from C:/msys64/mingw64/include/wtypesbase.h:13,
                 from C:/msys64/mingw64/include/shlobj.h:9,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:49:
C:/msys64/mingw64/include/objidlbase.h:3584:3: error: conflicting declaration 'typedef struct tagSOLE_AUTHENTICATION_SERVICE SOLE_AUTHENTICATION_SERVICE'
 3584 | } SOLE_AUTHENTICATION_SERVICE;
      |   ^~~~~~~~~~~~~~~~~~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:47:10: note: previous declaration as 'struct SOLE_AUTHENTICATION_SERVICE'
   47 |   struct SOLE_AUTHENTICATION_SERVICE;
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~
cc1plus.exe: note: unrecognized command-line option '-Wno-logical-op-parentheses' may have been intended to silence earlier diagnostics
[14/2821] Building CXX object ap1mods/coreutils/CMakeFiles/coreutils.dir/file.cpp.obj
FAILED: [code=1] ap1mods/coreutils/CMakeFiles/coreutils.dir/file.cpp.obj
C:\msys64\mingw64\bin\c++.exe  -IC:/msys64/home/lab/git/chipmachine/external/apone/mods/coreutils -g -funsigned-char  -g -funsigned-char -O2 -std=gnu++17 -MD -MT ap1mods/coreutils/CMakeFiles/coreutils.dir/file.cpp.obj -MF ap1mods\coreutils\CMakeFiles\coreutils.dir\file.cpp.obj.d -o ap1mods/coreutils/CMakeFiles/coreutils.dir/file.cpp.obj -c C:/msys64/home/lab/git/chipmachine/external/apone/mods/coreutils/file.cpp
C:/msys64/home/lab/git/chipmachine/external/apone/mods/coreutils/file.cpp:39:18: error: duplicate initialization of 'utils::File::PATH_SEPARATOR'
   39 | const char File::PATH_SEPARATOR = ':';
      |                  ^~~~~~~~~~~~~~
ninja: build stopped: subcommand failed.

