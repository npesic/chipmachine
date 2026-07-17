FAILED: [code=1] plugins/zxtuneplugin/zxt/strings/CMakeFiles/strings.dir/src/prefixed_index.cpp.obj
C:\msys64\mingw64\bin\c++.exe -DHAVE_BOOST -DNO_DEBUG_LOGS -DSOURCES_ROOT=\"C:/msys64/home/lab/git/chipmachine/external/zxtune\" -IC:/msys64/home/lab/git/chipmachine/external/zxtune -IC:/msys64/home/lab/git/chipmachine/external/zxtune/include -IC:/msys64/home/lab/git/chipmachine/external/zxtune/src -IC:/msys64/home/lab/git/chipmachine/external/zxtune/src/strings/../../3rdparty/fmt/include -g -funsigned-char  -g -funsigned-char -O2 -std=gnu++20 -fvisibility=hidden -fno-keep-inline-dllexport -w -MD -MT plugins/zxtuneplugin/zxt/strings/CMakeFiles/strings.dir/src/prefixed_index.cpp.obj -MF plugins\zxtuneplugin\zxt\strings\CMakeFiles\strings.dir\src\prefixed_index.cpp.obj.d -o plugins/zxtuneplugin/zxt/strings/CMakeFiles/strings.dir/src/prefixed_index.cpp.obj -c C:/msys64/home/lab/git/chipmachine/external/zxtune/src/strings/src/prefixed_index.cpp
In file included from C:/msys64/home/lab/git/chipmachine/external/zxtune/src/strings/src/prefixed_index.cpp:14:
C:/msys64/home/lab/git/chipmachine/external/zxtune/src/strings/conversion.h: In function 'T Strings::ParsePartial(StringView&)':
C:/msys64/home/lab/git/chipmachine/external/zxtune/src/strings/conversion.h:36:72: error: 'intmax_t' is not a member of 'std' [-Wtemplate-body]
   36 |         using WiderType = std::conditional_t<std::is_signed_v<T>, std::intmax_t, std::uintmax_t>;
      |                                                                        ^~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/zxtune/src/strings/conversion.h:36:87: error: 'uintmax_t' is not a member of 'std' [-Wtemplate-body]
   36 |         using WiderType = std::conditional_t<std::is_signed_v<T>, std::intmax_t, std::uintmax_t>;
      |                                                                                       ^~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/zxtune/src/strings/conversion.h:17:1: note: 'std::uintmax_t' is defined in header '<cstdint>'; this is probably fixable by adding '#include <cstdint>'
   16 | #include <charconv>
  +++ |+#include <cstdint>
   17 | #include <type_traits>
C:/msys64/home/lab/git/chipmachine/external/zxtune/src/strings/conversion.h:36:96: error: template argument 2 is invalid [-Wtemplate-body]
   36 |         using WiderType = std::conditional_t<std::is_signed_v<T>, std::intmax_t, std::uintmax_t>;
      |                                                                                                ^
C:/msys64/home/lab/git/chipmachine/external/zxtune/src/strings/conversion.h:36:96: error: template argument 3 is invalid [-Wtemplate-body]
C:/msys64/home/lab/git/chipmachine/external/zxtune/src/strings/conversion.h:36:27: error: expected type-specifier [-Wtemplate-body]
   36 |         using WiderType = std::conditional_t<std::is_signed_v<T>, std::intmax_t, std::uintmax_t>;
      |                           ^~~
C:/msys64/home/lab/git/chipmachine/external/zxtune/src/strings/conversion.h:37:44: error: 'WiderType' was not declared in this scope [-Wtemplate-body]
   37 |         return static_cast<T>(ParsePartial<WiderType>(str));
      |                                            ^~~~~~~~~
[255/2650] Building CXX object plugins/zxtuneplugin/zxt/strings/CMakeFiles/strings.dir/__/__/3rdparty/fmt/src/format.cc.obj
ninja: build stopped: subcommand failed.

