FAILED: [code=1] plugins/ixsplugin/CMakeFiles/ixsplugin.dir/__/__/__/__/webixs/FileMap.cpp.obj
C:\msys64\mingw64\bin\c++.exe -DLINUX -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/ixsplugin -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/ixsplugin/../../../../webixs -IC:/msys64/home/lab/git/chipmachine/external/apone/mods/coreutils/.. -g -funsigned-char -include cstdint  -g -funsigned-char -include cstdint -O2 -std=gnu++17 -w -fsigned-char -MD -MT plugins/ixsplugin/CMakeFiles/ixsplugin.dir/__/__/__/__/webixs/FileMap.cpp.obj -MF plugins\ixsplugin\CMakeFiles\ixsplugin.dir\__\__\__\__\webixs\FileMap.cpp.obj.d -o plugins/ixsplugin/CMakeFiles/ixsplugin.dir/__/__/__/__/webixs/FileMap.cpp.obj -c C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp
C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp: In function 'IXS::FileMap* IXS::IXS__FileMap__ctor_00413620(FileMap*, char*, int)':
C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp:194:21: error: invalid conversion from 'int' to 'HANDLE' {aka 'void*'} [-fpermissive]
  194 |       fHandle = open(fileName, O_RDWR, mode2);
      |                     ^
      |                     |
      |                     int
C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp:203:21: error: invalid conversion from 'int' to 'HANDLE' {aka 'void*'} [-fpermissive]
  203 |       fHandle = open(fileName, O_RDONLY, mode2);
      |                     ^
      |                     |
      |                     int
C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp:206:21: error: invalid conversion from 'int' to 'HANDLE' {aka 'void*'} [-fpermissive]
  206 |       fHandle = open(fileName, O_WRONLY | O_CREAT, mode2);
      |                     ^
      |                     |
      |                     int
C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp: In function 'void IXS::IXS__FileMap__dtor_004136a0(FileMap*)':
C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp:231:16: error: invalid conversion from 'HANDLE' {aka 'void*'} to 'int' [-fpermissive]
  231 |     close(map->fileHandle);
      |           ~~~~~^~~~~~~~~~
      |                |
      |                HANDLE {aka void*}
In file included from C:/msys64/mingw64/include/fcntl.h:8,
                 from C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp:15:
C:/msys64/mingw64/include/io.h:212:34: note: initializing argument 1 of 'int _close(int)'
  212 |   _CRTIMP int __cdecl _close(int _FileHandle);
      |                              ~~~~^~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp: In function 'uint IXS::IXS__FileMap__readFile_004136e0(FileMap*, LPVOID, uint)':
C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp:236:23: error: invalid conversion from 'HANDLE' {aka 'void*'} to 'int' [-fpermissive]
  236 |      return read(map->fileHandle, buffer, nNumberOfBytesToRead);
      |                  ~~~~~^~~~~~~~~~
      |                       |
      |                       HANDLE {aka void*}
C:/msys64/mingw64/include/io.h:231:33: note: initializing argument 1 of 'int _read(int, void*, unsigned int)'
  231 |   _CRTIMP int __cdecl _read(int _FileHandle,void *_DstBuf,unsigned int _MaxCharCount);
      |                             ~~~~^~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp: In function 'uint IXS::IXS__FileMap__writeFile_00413710(FileMap*, void*, uint)':
C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp:241:23: error: invalid conversion from 'HANDLE' {aka 'void*'} to 'int' [-fpermissive]
  241 |     return write(map->fileHandle, buffer, nNumberOfBytesToWrite);
      |                  ~~~~~^~~~~~~~~~
      |                       |
      |                       HANDLE {aka void*}
C:/msys64/mingw64/include/io.h:247:34: note: initializing argument 1 of 'int _write(int, const void*, unsigned int)'
  247 |   _CRTIMP int __cdecl _write(int _FileHandle,const void *_Buf,unsigned int _MaxCharCount);
      |                              ~~~~^~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp: In function 'int IXS::IXS__FileMap__getFileSize_00413740(FileMap*)':
C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp:247:20: error: invalid conversion from 'HANDLE' {aka 'void*'} to 'int' [-fpermissive]
  247 |     if (fstat(map->fileHandle, &sb) == -1) {
      |               ~~~~~^~~~~~~~~~
      |                    |
      |                    HANDLE {aka void*}
In file included from C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp:17:
C:/msys64/mingw64/include/sys/stat.h:73:39: note: initializing argument 1 of 'int _fstat64i32(int, _stat64i32*)'
   73 |   _CRTIMP int __cdecl _fstat64i32(int _FileDes,struct _stat64i32 *_Stat);
      |                                   ~~~~^~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp: In function 'uint IXS::IXS__FileMap__getFilePtr_00413760(FileMap*)':
C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp:284:23: error: invalid conversion from 'HANDLE' {aka 'void*'} to 'int' [-fpermissive]
  284 |     return lseek(map->fileHandle, 0, mapDw2Whence(1));
      |                  ~~~~~^~~~~~~~~~
      |                       |
      |                       HANDLE {aka void*}
C:/msys64/mingw64/include/io.h:224:35: note: initializing argument 1 of 'long int _lseek(int, long int, int)'
  224 |   _CRTIMP long __cdecl _lseek(int _FileHandle,long _Offset,int _Origin);
      |                               ~~~~^~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp: In function 'void IXS::IXS__FileMap__setFilePtr_00413780(FileMap*, long int, uint)':
C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp:289:16: error: invalid conversion from 'HANDLE' {aka 'void*'} to 'int' [-fpermissive]
  289 |     lseek(map->fileHandle, lDistanceToMove, mapDw2Whence(dwMoveMethod));
      |           ~~~~~^~~~~~~~~~
      |                |
      |                HANDLE {aka void*}
C:/msys64/mingw64/include/io.h:224:35: note: initializing argument 1 of 'long int _lseek(int, long int, int)'
  224 |   _CRTIMP long __cdecl _lseek(int _FileHandle,long _Offset,int _Origin);
      |                               ~~~~^~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp: In function 'byte* IXS::IXS__FileMap__getMemBuffer_004137c0(FileMap*)':
C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp:310:32: error: invalid conversion from 'HANDLE' {aka 'void*'} to 'int' [-fpermissive]
  310 |     long savedPos = lseek(map->fileHandle, 0, SEEK_CUR);
      |                           ~~~~~^~~~~~~~~~
      |                                |
      |                                HANDLE {aka void*}
C:/msys64/mingw64/include/io.h:224:35: note: initializing argument 1 of 'long int _lseek(int, long int, int)'
  224 |   _CRTIMP long __cdecl _lseek(int _FileHandle,long _Offset,int _Origin);
      |                               ~~~~^~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp:311:16: error: invalid conversion from 'HANDLE' {aka 'void*'} to 'int' [-fpermissive]
  311 |     lseek(map->fileHandle, 0, SEEK_SET);
      |           ~~~~~^~~~~~~~~~
      |                |
      |                HANDLE {aka void*}
C:/msys64/mingw64/include/io.h:224:35: note: initializing argument 1 of 'long int _lseek(int, long int, int)'
  224 |   _CRTIMP long __cdecl _lseek(int _FileHandle,long _Offset,int _Origin);
      |                               ~~~~^~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp:312:31: error: invalid conversion from 'HANDLE' {aka 'void*'} to 'int' [-fpermissive]
  312 |     int bytesRead = read(map->fileHandle, memAddr, size);
      |                          ~~~~~^~~~~~~~~~
      |                               |
      |                               HANDLE {aka void*}
C:/msys64/mingw64/include/io.h:231:33: note: initializing argument 1 of 'int _read(int, void*, unsigned int)'
  231 |   _CRTIMP int __cdecl _read(int _FileHandle,void *_DstBuf,unsigned int _MaxCharCount);
      |                             ~~~~^~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/webixs/FileMap.cpp:313:16: error: invalid conversion from 'HANDLE' {aka 'void*'} to 'int' [-fpermissive]
  313 |     lseek(map->fileHandle, savedPos, SEEK_SET);
      |           ~~~~~^~~~~~~~~~
      |                |
      |                HANDLE {aka void*}
C:/msys64/mingw64/include/io.h:224:35: note: initializing argument 1 of 'long int _lseek(int, long int, int)'
  224 |   _CRTIMP long __cdecl _lseek(int _FileHandle,long _Offset,int _Origin);
      |                               ~~~~^~~~~~~~~~~
[14/107] Building CXX object plugins/ixsplugin/CMakeFiles/ixsplugin.dir/IXSPlugin.cpp.obj
ninja: build stopped: subcommand failed.
