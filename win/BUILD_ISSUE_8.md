FAILED: [code=1] ap1mods/audioplayer/CMakeFiles/audioplayer.dir/audioplayer.cpp.obj
C:\msys64\mingw64\bin\c++.exe   -g -funsigned-char  -g -funsigned-char -O2 -std=gnu++17 -MD -MT ap1mods/audioplayer/CMakeFiles/audioplayer.dir/audioplayer.cpp.obj -MF ap1mods\audioplayer\CMakeFiles\audioplayer.dir\audioplayer.cpp.obj.d -o ap1mods/audioplayer/CMakeFiles/audioplayer.dir/audioplayer.cpp.obj -c C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.cpp
In file included from C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.cpp:1:
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:21:36: error: 'int16_t' was not declared in this scope
   21 |     AudioPlayer(std::function<void(int16_t *, int)> cb, int hz = 44100);
      |                                    ^~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:6:1: note: 'int16_t' is defined in header '<cstdint>'; this is probably fixable by adding '#include <cstdint>'
    5 | #include <stdexcept>
  +++ |+#include <cstdint>
    6 | #include <string>
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:21:50: error: expression list treated as compound expression in functional cast [-fpermissive]
   21 |     AudioPlayer(std::function<void(int16_t *, int)> cb, int hz = 44100);
      |                                                  ^
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:21:51: error: template argument 1 is invalid
   21 |     AudioPlayer(std::function<void(int16_t *, int)> cb, int hz = 44100);
      |                                                   ^
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:24:42: error: 'int16_t' was not declared in this scope
   24 |     virtual void play(std::function<void(int16_t *, int)> cb);
      |                                          ^~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:24:42: note: 'int16_t' is defined in header '<cstdint>'; this is probably fixable by adding '#include <cstdint>'
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:24:56: error: expression list treated as compound expression in functional cast [-fpermissive]
   24 |     virtual void play(std::function<void(int16_t *, int)> cb);
      |                                                        ^
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:24:57: error: template argument 1 is invalid
   24 |     virtual void play(std::function<void(int16_t *, int)> cb);
      |                                                         ^
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:24:42: error: 'int16_t' was not declared in this scope
   24 |     virtual void play(std::function<void(int16_t *, int)> cb);
      |                                          ^~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:24:42: note: 'int16_t' is defined in header '<cstdint>'; this is probably fixable by adding '#include <cstdint>'
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:24:56: error: expression list treated as compound expression in functional cast [-fpermissive]
   24 |     virtual void play(std::function<void(int16_t *, int)> cb);
      |                                                        ^
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:24:57: error: template argument 1 is invalid
   24 |     virtual void play(std::function<void(int16_t *, int)> cb);
      |                                                         ^
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:24:42: error: 'int16_t' was not declared in this scope
   24 |     virtual void play(std::function<void(int16_t *, int)> cb);
      |                                          ^~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:24:42: note: 'int16_t' is defined in header '<cstdint>'; this is probably fixable by adding '#include <cstdint>'
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:24:56: error: expression list treated as compound expression in functional cast [-fpermissive]
   24 |     virtual void play(std::function<void(int16_t *, int)> cb);
      |                                                        ^
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:24:57: error: template argument 1 is invalid
   24 |     virtual void play(std::function<void(int16_t *, int)> cb);
      |                                                         ^
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:24:23: error: invalid template-id
   24 |     virtual void play(std::function<void(int16_t *, int)> cb);
      |                       ^~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:24:42: error: 'int16_t' was not declared in this scope
   24 |     virtual void play(std::function<void(int16_t *, int)> cb);
      |                                          ^~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:24:42: note: 'int16_t' is defined in header '<cstdint>'; this is probably fixable by adding '#include <cstdint>'
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:24:56: error: expression list treated as compound expression in functional cast [-fpermissive]
   24 |     virtual void play(std::function<void(int16_t *, int)> cb);
      |                                                        ^
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:24:37: error: expected primary-expression before 'void'
   24 |     virtual void play(std::function<void(int16_t *, int)> cb);
      |                                     ^~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:24:37: error: expected '>' before 'void'
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:24:23: error: missing template argument list after 'std::function'; template placeholder not permitted in parameter
   24 |     virtual void play(std::function<void(int16_t *, int)> cb);
      |                       ^~~
      |                          <>
In file included from C:/msys64/mingw64/include/c++/16.1.0/functional:76,
                 from C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:3:
C:/msys64/mingw64/include/c++/16.1.0/bits/std_function.h:113:11: note: 'template<class _Signature> class std::function' declared here
  113 |     class function;
      |           ^~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.cpp:21:1: error: no declaration matches 'AudioPlayer::AudioPlayer(std::function<void(short int*, int)>, int)'
   21 | AudioPlayer::AudioPlayer(std::function<void(int16_t*, int)> cb, int hz)
      | ^~~~~~~~~~~
  ΓÇó there are 3 candidates
    ΓÇó candidate 1: 'AudioPlayer::AudioPlayer(const AudioPlayer&)'
      C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:18:7:
         18 | class AudioPlayer {
            |       ^~~~~~~~~~~
    ΓÇó candidate 2: 'AudioPlayer::AudioPlayer(int, int)'
      C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:21:5:
         21 |     AudioPlayer(std::function<void(int16_t *, int)> cb, int hz = 44100);
            |     ^~~~~~~~~~~
      ΓÇó parameter 1 of candidate has type 'int'...
        C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:21:53:
           21 |     AudioPlayer(std::function<void(int16_t *, int)> cb, int hz = 44100);
              |                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~
      ΓÇó ...which does not match type 'std::function<void(short int*, int)>'
        C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.cpp:21:61:
           21 | AudioPlayer::AudioPlayer(std::function<void(int16_t*, int)> cb, int hz)
              |                          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~
    ΓÇó candidate 3: 'AudioPlayer::AudioPlayer(int)'
      C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.cpp:17:1:
         17 | AudioPlayer::AudioPlayer(int hz)
            | ^~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:18:7: note: 'class AudioPlayer' defined here
   18 | class AudioPlayer {
      |       ^~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.cpp:27:6: error: no declaration matches 'void AudioPlayer::play(std::function<void(short int*, int)>)'
   27 | void AudioPlayer::play(std::function<void(int16_t*, int)> cb)
      |      ^~~~~~~~~~~
  ΓÇó there is 1 candidate
    ΓÇó candidate is: 'virtual void AudioPlayer::play(...)'
      C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:24:18:
         24 |     virtual void play(std::function<void(int16_t *, int)> cb);
            |                  ^~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/audioplayer/audioplayer.h:18:7: note: 'class AudioPlayer' defined here
   18 | class AudioPlayer {
      |       ^~~~~~~~~~~
[1685/2677] Building C object ap1mods/sqlite3/CMakeFiles/sqlite3.dir/sqlite3.c.obj
C:/msys64/home/lab/git/chipmachine/external/apone/mods/sqlite3/sqlite3.c: In function 'sqlite3SelectNew':
C:/msys64/home/lab/git/chipmachine/external/apone/mods/sqlite3/sqlite3.c:124524:10: warning: function may return address of local variable [-Wreturn-local-addr]
124524 |   return pNew;
       |          ^~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/sqlite3/sqlite3.c:124484:10: note: declared here
124484 |   Select standin;
       |          ^~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/sqlite3/sqlite3.c: In function 'sqlite3VdbeExpandSql':
C:/msys64/home/lab/git/chipmachine/external/apone/mods/sqlite3/sqlite3.c:83270:10: warning: function may return address of local variable [-Wreturn-local-addr]
83270 |   return sqlite3StrAccumFinish(&out);
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/sqlite3/sqlite3.c:83166:8: note: declared here
83166 |   char zBase[100];         /* Initial working space */
      |        ^~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/sqlite3/sqlite3.c:83270:10: warning: function may return address of local variable [-Wreturn-local-addr]
83270 |   return sqlite3StrAccumFinish(&out);
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/sqlite3/sqlite3.c:83166:8: note: declared here
83166 |   char zBase[100];         /* Initial working space */
      |        ^~~~~
C:/msys64/home/lab/git/chipmachine/external/apone/mods/sqlite3/sqlite3.c:83166:8: note: declared here
C:/msys64/home/lab/git/chipmachine/external/apone/mods/sqlite3/sqlite3.c:83166:8: note: declared here
C:/msys64/home/lab/git/chipmachine/external/apone/mods/sqlite3/sqlite3.c:83166:8: note: declared here
C:/msys64/home/lab/git/chipmachine/external/apone/mods/sqlite3/sqlite3.c:83166:8: note: declared here
ninja: build stopped: subcommand failed.

