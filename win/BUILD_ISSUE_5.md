FAILED: [code=1] plugins/zxtuneplugin/zxt/binary_compression/CMakeFiles/binary_compression.dir/src/zlib.cpp.obj
C:\msys64\mingw64\bin\c++.exe -DHAVE_BOOST -DNO_DEBUG_LOGS -IC:/msys64/home/lab/git/chipmachine/external/zxtune -IC:/msys64/home/lab/git/chipmachine/external/zxtune/include -IC:/msys64/home/lab/git/chipmachine/external/zxtune/src -g -funsigned-char  -g -funsigned-char -O2 -std=gnu++20 -fvisibility=hidden -fno-keep-inline-dllexport -w -MD -MT plugins/zxtuneplugin/zxt/binary_compression/CMakeFiles/binary_compression.dir/src/zlib.cpp.obj -MF plugins\zxtuneplugin\zxt\binary_compression\CMakeFiles\binary_compression.dir\src\zlib.cpp.obj.d -o plugins/zxtuneplugin/zxt/binary_compression/CMakeFiles/binary_compression.dir/src/zlib.cpp.obj -c C:/msys64/home/lab/git/chipmachine/external/zxtune/src/binary/compression/src/zlib.cpp
In file included from C:/msys64/home/lab/git/chipmachine/external/zxtune/include/error.h:13,
                 from C:/msys64/home/lab/git/chipmachine/external/zxtune/src/binary/compression/src/zlib.cpp:16:
C:/msys64/home/lab/git/chipmachine/external/zxtune/include/source_location.h: In instantiation of 'constexpr auto Debug::MakeSourceFile() [with long long unsigned int Offset = 0; C = char; C Head = 'C'; C ...Tail = {':', '/', 'm', 's', 'y', 's', '6', '4', '/', 'h', 'o', 'm', 'e', '/', 'l', 'a', 'b', '/', 'g', 'i', 't', '/', 'c', 'h', 'i', 'p', 'm', 'a', 'c', 'h', 'i', 'n', 'e', '/', 'e', 'x', 't', 'e', 'r', 'n', 'a', 'l', '/', 'z', 'x', 't', 'u', 'n', 'e', '/', 's', 'r', 'c', '/', 'b', 'i', 'n', 'a', 'r', 'y', '/', 'c', 'o', 'm', 'p', 'r', 'e', 's', 's', 'i', 'o', 'n', '/', 's', 'r', 'c', '/', 'z', 'l', 'i', 'b', '.', 'c', 'p', 'p'}]':
C:/msys64/home/lab/git/chipmachine/external/zxtune/include/source_location.h:151:47:   required from 'constexpr auto operator""_source() [with C = char; C ...Chars = {'C', ':', '/', 'm', 's', 'y', 's', '6', '4', '/', 'h', 'o', 'm', 'e', '/', 'l', 'a', 'b', '/', 'g', 'i', 't', '/', 'c', 'h', 'i', 'p', 'm', 'a', 'c', 'h', 'i', 'n', 'e', '/', 'e', 'x', 't', 'e', 'r', 'n', 'a', 'l', '/', 'z', 'x', 't', 'u', 'n', 'e', '/', 's', 'r', 'c', '/', 'b', 'i', 'n', 'a', 'r', 'y', '/', 'c', 'o', 'm', 'p', 'r', 'e', 's', 's', 'i', 'o', 'n', '/', 's', 'r', 'c', '/', 'z', 'l', 'i', 'b', '.', 'c', 'p', 'p'}]'
  151 |   return Debug::MakeSourceFile<0, C, Chars...>();
      |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~
C:/msys64/home/lab/git/chipmachine/external/zxtune/src/binary/compression/src/zlib.cpp:77:50:   required from here
  154 | #define ThisFile() DO_LITERAL(__FILE__, _source)
      |                               ^~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/zxtune/include/source_location.h:137:33: error: static assertion failed: SOURCES_ROOT should not end with slash
  137 |       static_assert(Head == '/' || Head == '\\', "SOURCES_ROOT should not end with slash");
      |                     ~~~~~~~~~~~~^~~~~~~~~~~~~~~
  ΓÇó '((67 == 47) || (67 == 92))' evaluates to false
[95/2753] Building C object plugins/sksplugin/at3_rasm/CMakeFiles/ThirdPartyRasm.dir/rasm.c.obj
ninja: build stopped: subcommand failed.

