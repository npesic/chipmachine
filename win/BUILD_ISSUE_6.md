FAILED: [code=1] plugins/zxtuneplugin/zxt/formats_archived/CMakeFiles/formats_archived.dir/trdos_utils.cpp.obj
C:\msys64\mingw64\bin\c++.exe -DHAVE_BOOST -DNO_DEBUG_LOGS -DSOURCES_ROOT=\"C:/msys64/home/lab/git/chipmachine/external/zxtune\" -IC:/msys64/home/lab/git/chipmachine/external/zxtune -IC:/msys64/home/lab/git/chipmachine/external/zxtune/include -IC:/msys64/home/lab/git/chipmachine/external/zxtune/src -g -funsigned-char  -g -funsigned-char -O2 -std=gnu++20 -fvisibility=hidden -fno-keep-inline-dllexport -w -MD -MT plugins/zxtuneplugin/zxt/formats_archived/CMakeFiles/formats_archived.dir/trdos_utils.cpp.obj -MF plugins\zxtuneplugin\zxt\formats_archived\CMakeFiles\formats_archived.dir\trdos_utils.cpp.obj.d -o plugins/zxtuneplugin/zxt/formats_archived/CMakeFiles/formats_archived.dir/trdos_utils.cpp.obj -c C:/msys64/home/lab/git/chipmachine/external/zxtune/src/formats/archived/trdos_utils.cpp
In file included from C:/msys64/home/lab/git/chipmachine/external/zxtune/src/formats/archived/trdos_utils.cpp:13:
C:/msys64/home/lab/git/chipmachine/external/zxtune/src/strings/encoding.h:20:45: error: 'uint16_t' was not declared in this scope
   20 |   String Utf16ToUtf8(std::basic_string_view<uint16_t> str);
      |                                             ^~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/zxtune/src/strings/encoding.h:15:1: note: 'uint16_t' is defined in header '<cstdint>'; this is probably fixable by adding '#include <cstdint>'
   14 | #include "string_view.h"
  +++ |+#include <cstdint>
   15 |
C:/msys64/home/lab/git/chipmachine/external/zxtune/src/strings/encoding.h:20:53: error: template argument 1 is invalid
   20 |   String Utf16ToUtf8(std::basic_string_view<uint16_t> str);
      |                                                     ^
C:/msys64/home/lab/git/chipmachine/external/zxtune/src/strings/encoding.h:20:53: error: template argument 2 is invalid
[70/2718] Building C object plugins/zxtuneplugin/zxt/z80ex/CMakeFiles/z80ex.dir/z80ex.c.obj
ninja: build stopped: subcommand failed.

