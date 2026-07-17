FAILED: [code=1] ap1mods/archive/unrar/CMakeFiles/unrar.dir/smallfn.cpp.obj
C:\msys64\mingw64\bin\c++.exe -DLITTLE_ENDIAN -DRARDLL -DSILENT  -g -funsigned-char -Wno-logical-op-parentheses -Wno-dangling-else -Wno-switch  -g -funsigned-char -O2 -std=gnu++17 -MD -MT ap1mods/archive/unrar/CMakeFiles/unrar.dir/smallfn.cpp.obj -MF ap1mods\archive\unrar\CMakeFiles\unrar.dir\smallfn.cpp.obj.d -o ap1mods/archive/unrar/CMakeFiles/unrar.dir/smallfn.cpp.obj -c C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/smallfn.cpp
In file included from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/rar.hpp:5,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/smallfn.cpp:1:
C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:22:9: warning: 'LITTLE_ENDIAN' redefined
   22 | #define LITTLE_ENDIAN
      |         ^~~~~~~~~~~~~
<command-line>: note: this is the location of the previous definition
In file included from C:/msys64/mingw64/include/winbase.h:18,
                 from C:/msys64/mingw64/include/windows.h:70,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/archive/unrar/os.hpp:36:
C:/msys64/mingw64/include/fileapi.h:196:65: error: 'FINDEX_INFO_LEVELS' has not been declared; did you mean 'GET_FILEEX_INFO_LEVELS'?
  196 |   WINBASEAPI HANDLE WINAPI FindFirstFileExA (LPCSTR lpFileName, FINDEX_INFO_LEVELS fInfoLevelId, LPVOID lpFindFileData, FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter, DWORD dwAdditionalFlags);
      |                                                                 ^~~~~~~~~~~~~~~~~~
      |                                                                 GET_FILEEX_INFO_LEVELS
C:/msys64/mingw64/include/fileapi.h:196:121: error: 'FINDEX_SEARCH_OPS' has not been declared
  196 |   WINBASEAPI HANDLE WINAPI FindFirstFileExA (LPCSTR lpFileName, FINDEX_INFO_LEVELS fInfoLevelId, LPVOID lpFindFileData, FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter, DWORD dwAdditionalFlags);
      |                                                                                                                         ^~~~~~~~~~~~~~~~~
C:/msys64/mingw64/include/fileapi.h:197:66: error: 'FINDEX_INFO_LEVELS' has not been declared; did you mean 'GET_FILEEX_INFO_LEVELS'?
  197 |   WINBASEAPI HANDLE WINAPI FindFirstFileExW (LPCWSTR lpFileName, FINDEX_INFO_LEVELS fInfoLevelId, LPVOID lpFindFileData, FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter, DWORD dwAdditionalFlags);
      |                                                                  ^~~~~~~~~~~~~~~~~~
      |                                                                  GET_FILEEX_INFO_LEVELS
C:/msys64/mingw64/include/fileapi.h:197:122: error: 'FINDEX_SEARCH_OPS' has not been declared
  197 |   WINBASEAPI HANDLE WINAPI FindFirstFileExW (LPCWSTR lpFileName, FINDEX_INFO_LEVELS fInfoLevelId, LPVOID lpFindFileData, FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter, DWORD dwAdditionalFlags);
      |                                                                                                                          ^~~~~~~~~~~~~~~~~
cc1plus.exe: note: unrecognized command-line option '-Wno-logical-op-parentheses' may have been intended to silence earlier diagnostics
[16/2829] Building CXX object ap1mods/coreutils/CMakeFiles/coreutils.dir/utils.cpp.obj
ninja: build stopped: subcommand failed.
