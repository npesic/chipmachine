# Build issue 8

```
FAILED: CMakeFiles/cm.dir/src/main.cpp.o 
/usr/bin/ccache /usr/bin/c++ -DSOL_USING_CXX_LUA -DTEXTMODE_ONLY -I/home/pi5/git/chipmachine/external/apone/mods/grappix -I/home/pi5/git/chipmachine/external/musicplayer/plugins -I/home/pi5/git/chipmachine/external/zxtune/3rdparty/lhasa/lib/public -I/home/pi5/git/chipmachine/external/musicplayer/.. -I/home/pi5/git/chipmachine/external/musicplayer/src/psf/include -I/home/pi5/git/chipmachine/external/apone/mods/coreutils/.. -isystem /home/pi5/git/chipmachine/external/sol2 -isystem /home/pi5/git/chipmachine/external/lua -g -funsigned-char  -g -funsigned-char -O2 -std=gnu++17 -MD -MT CMakeFiles/cm.dir/src/main.cpp.o -MF CMakeFiles/cm.dir/src/main.cpp.o.d -o CMakeFiles/cm.dir/src/main.cpp.o -c /home/pi5/git/chipmachine/src/main.cpp
In file included from /home/pi5/git/chipmachine/src/main.cpp:34:
/usr/include/c++/12/csignal:52:11: error: ‘sig_atomic_t’ has not been declared in ‘::’
   52 |   using ::sig_atomic_t;
      |           ^~~~~~~~~~~~
/usr/include/c++/12/csignal:53:11: error: ‘signal’ has not been declared in ‘::’
   53 |   using ::signal;
      |           ^~~~~~
/usr/include/c++/12/csignal:54:11: error: ‘raise’ has not been declared in ‘::’
   54 |   using ::raise;
      |           ^~~~~
/home/pi5/git/chipmachine/src/main.cpp: In function ‘int main(int, char**)’:
/home/pi5/git/chipmachine/src/main.cpp:55:10: error: ‘signal’ is not a member of ‘std’; did you mean ‘utils::signal’?
   55 |     std::signal(SIGPIPE, SIG_IGN);
      |          ^~~~~~
In file included from /home/pi5/git/chipmachine/external/apone/mods/coreutils/../coreutils/exec.h:75,
                 from /home/pi5/git/chipmachine/external/apone/mods/coreutils/../coreutils/utils.h:315,
                 from /home/pi5/git/chipmachine/external/apone/mods/coreutils/../coreutils/file.h:3,
                 from /home/pi5/git/chipmachine/src/SearchIndex.h:4,
                 from /home/pi5/git/chipmachine/src/MusicDatabase.h:4,
                 from /home/pi5/git/chipmachine/src/ChipInterface.h:3,
                 from /home/pi5/git/chipmachine/src/main.cpp:1:
/usr/include/signal.h:88:23: note: ‘utils::signal’ declared here
   88 | extern __sighandler_t signal (int __sig, __sighandler_t __handler)
      |                       ^~~~~~
In file included from /usr/include/signal.h:30:
/home/pi5/git/chipmachine/src/main.cpp:55:26: error: ‘__sighandler_t’ was not declared in this scope; did you mean ‘utils::__sighandler_t’?
   55 |     std::signal(SIGPIPE, SIG_IGN);
      |                          ^~~~~~~
/usr/include/signal.h:72:16: note: ‘utils::__sighandler_t’ declared here
   72 | typedef void (*__sighandler_t) (int);
      |                ^~~~~~~~~~~~~~
/home/pi5/git/chipmachine/src/main.cpp:55:26: error: expected ‘)’ before numeric constant
   55 |     std::signal(SIGPIPE, SIG_IGN);
      |                          ^~~~~~~
[1024/1026] Building CXX object CMakeFiles/cm.dir/src/NativeDialogs_stub.cpp.o
In file included from /home/pi5/git/chipmachine/external/apone/mods/grappix/grappix/grappix.h:3,
                 from /home/pi5/git/chipmachine/external/apone/mods/grappix/grappix/gui/renderable.h:4,
                 from /home/pi5/git/chipmachine/src/TextField.h:4,
                 from /home/pi5/git/chipmachine/src/LineEdit.h:4,
                 from /home/pi5/git/chipmachine/src/Dialog.h:4,
                 from /home/pi5/git/chipmachine/src/ChipMachine.h:3,
                 from /home/pi5/git/chipmachine/src/NativeDialogs_stub.cpp:10:
/home/pi5/git/chipmachine/external/apone/mods/grappix/grappix/window.h: In member function ‘std::pair<float, float> grappix::Window::size()’:
/home/pi5/git/chipmachine/external/apone/mods/grappix/grappix/window.h:88:36: note: parameter passing for argument of type ‘std::pair<float, float>’ when C++17 is enabled changed to match C++14 in GCC 10.1
   88 |     std::pair<float, float> size() { return std::make_pair(_width, _height); }
      |                                    ^
[1025/1026] Building CXX object CMakeFiles/cm.dir/src/MusicDatabase.cpp.o
ninja: build stopped: subcommand failed.
```
