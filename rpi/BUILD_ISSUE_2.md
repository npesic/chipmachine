# Build Issue

Just indicates gsfplugin but not more than that:
```
[410/2377] Building CXX object plugins/gsfplugin/CMakeFiles/gsfplugin.dir/playgsf/VBA/GBA.cpp.o
ninja: build stopped: subcommand failed.
```

## UPDATE: more of stack trace
```
FAILED: plugins/fmpplugin/CMakeFiles/fmpplugin.dir/FMPPlugin.cpp.o
/usr/bin/ccache /usr/bin/c++  -I/home/pi5/git/chipmachine/external/98fmplayer/fmdriver -I/home/pi5/git/chipmachine/external/98fmplayer -I/home/pi5/git/chipmachine/external/musicplayer/src/plugins/fmpplugin/../s98plugin/m_s98/device/fmgen -I/home/pi5/git/chipmachine/external/musicplayer/src/plugins/fmpplugin/../s98plugin/m_s98/device -I/home/pi5/git/chipmachine/external/musicplayer/src/plugins/fmpplugin/../s98plugin/m_s98 -I/home/pi5/git/chipmachine/external/apone/mods/coreutils/.. -g -funsigned-char  -g -funsigned-char -O2 -std=gnu++17 -MD -MT plugins/fmpplugin/CMakeFiles/fmpplugin.dir/FMPPlugin.cpp.o -MF plugins/fmpplugin/CMakeFiles/fmpplugin.dir/FMPPlugin.cpp.o.d -o plugins/fmpplugin/CMakeFiles/fmpplugin.dir/FMPPlugin.cpp.o -c /home/pi5/git/chipmachine/external/musicplayer/src/plugins/fmpplugin/FMPPlugin.cpp
In file included from /home/pi5/git/chipmachine/external/98fmplayer/fmdriver/ppz8.h:7,
                 from /home/pi5/git/chipmachine/external/98fmplayer/fmdriver/fmdriver.h:6,
                 from /home/pi5/git/chipmachine/external/98fmplayer/fmdriver/fmdriver_fmp.h:8,
                 from /home/pi5/git/chipmachine/external/musicplayer/src/plugins/fmpplugin/FMPPlugin.cpp:13:
/home/pi5/git/chipmachine/external/98fmplayer/leveldata/leveldata.h:7:3: error: ‘atomic_flag’ does not name a type
    7 |   atomic_flag flag;
      |   ^~~~~~~~~~~
/home/pi5/git/chipmachine/external/98fmplayer/leveldata/leveldata.h: In function ‘unsigned int leveldata_read(leveldata*)’:
/home/pi5/git/chipmachine/external/98fmplayer/leveldata/leveldata.h:13:51: error: ‘struct leveldata’ has no member named ‘flag’
   13 |   while (atomic_flag_test_and_set_explicit(&data->flag, memory_order_acquire));
      |                                                   ^~~~
/home/pi5/git/chipmachine/external/98fmplayer/leveldata/leveldata.h:13:57: error: ‘memory_order_acquire’ was not declared in this scope; did you mean ‘std::memory_order_acquire’?
   13 |   while (atomic_flag_test_and_set_explicit(&data->flag, memory_order_acquire));
      |                                                         ^~~~~~~~~~~~~~~~~~~~
      |                                                         std::memory_order_acquire
In file included from /usr/include/c++/12/bits/shared_ptr_atomic.h:33,
                 from /usr/include/c++/12/memory:78,
                 from /home/pi5/git/chipmachine/external/musicplayer/src/plugins/fmpplugin/../../chipplugin.h:5,
                 from /home/pi5/git/chipmachine/external/musicplayer/src/plugins/fmpplugin/FMPPlugin.h:2,
                 from /home/pi5/git/chipmachine/external/musicplayer/src/plugins/fmpplugin/FMPPlugin.cpp:1:
/usr/include/c++/12/bits/atomic_base.h:82:7: note: ‘std::memory_order_acquire’ declared here
   82 |       memory_order_acquire,
      |       ^~~~~~~~~~~~~~~~~~~~
/home/pi5/git/chipmachine/external/98fmplayer/leveldata/leveldata.h:13:10: error: ‘atomic_flag_test_and_set_explicit’ was not declared in this scope; did you mean ‘std::atomic_flag_test_and_set_explicit’?
   13 |   while (atomic_flag_test_and_set_explicit(&data->flag, memory_order_acquire));
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      |          std::atomic_flag_test_and_set_explicit
In file included from /home/pi5/git/chipmachine/external/apone/mods/coreutils/../coreutils/utils.h:5,
                 from /home/pi5/git/chipmachine/external/musicplayer/src/plugins/fmpplugin/FMPPlugin.cpp:3:
/usr/include/c++/12/atomic:1215:3: note: ‘std::atomic_flag_test_and_set_explicit’ declared here
 1215 |   atomic_flag_test_and_set_explicit(volatile atomic_flag* __a,
      |   ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/pi5/git/chipmachine/external/98fmplayer/leveldata/leveldata.h:16:37: error: ‘struct leveldata’ has no member named ‘flag’
   16 |   atomic_flag_clear_explicit(&data->flag, memory_order_release);
      |                                     ^~~~
/home/pi5/git/chipmachine/external/98fmplayer/leveldata/leveldata.h:16:43: error: ‘memory_order_release’ was not declared in this scope; did you mean ‘std::memory_order_release’?
   16 |   atomic_flag_clear_explicit(&data->flag, memory_order_release);
      |                                           ^~~~~~~~~~~~~~~~~~~~
      |                                           std::memory_order_release
/usr/include/c++/12/bits/atomic_base.h:83:7: note: ‘std::memory_order_release’ declared here
   83 |       memory_order_release,
      |       ^~~~~~~~~~~~~~~~~~~~
/home/pi5/git/chipmachine/external/98fmplayer/leveldata/leveldata.h:16:3: error: ‘atomic_flag_clear_explicit’ was not declared in this scope; did you mean ‘std::atomic_flag_clear_explicit’?
   16 |   atomic_flag_clear_explicit(&data->flag, memory_order_release);
      |   ^~~~~~~~~~~~~~~~~~~~~~~~~~
      |   std::atomic_flag_clear_explicit
/usr/include/c++/12/atomic:1224:3: note: ‘std::atomic_flag_clear_explicit’ declared here
 1224 |   atomic_flag_clear_explicit(volatile atomic_flag* __a,
      |   ^~~~~~~~~~~~~~~~~~~~~~~~~~
/home/pi5/git/chipmachine/external/98fmplayer/leveldata/leveldata.h: In function ‘void leveldata_update(leveldata*, unsigned int)’:
/home/pi5/git/chipmachine/external/98fmplayer/leveldata/leveldata.h:21:51: error: ‘struct leveldata’ has no member named ‘flag’
   21 |   while (atomic_flag_test_and_set_explicit(&data->flag, memory_order_acquire));
      |                                                   ^~~~
/home/pi5/git/chipmachine/external/98fmplayer/leveldata/leveldata.h:21:57: error: ‘memory_order_acquire’ was not declared in this scope; did you mean ‘std::memory_order_acquire’?
   21 |   while (atomic_flag_test_and_set_explicit(&data->flag, memory_order_acquire));
      |                                                         ^~~~~~~~~~~~~~~~~~~~
      |                                                         std::memory_order_acquire
/usr/include/c++/12/bits/atomic_base.h:82:7: note: ‘std::memory_order_acquire’ declared here
   82 |       memory_order_acquire,
      |       ^~~~~~~~~~~~~~~~~~~~
/home/pi5/git/chipmachine/external/98fmplayer/leveldata/leveldata.h:21:10: error: ‘atomic_flag_test_and_set_explicit’ was not declared in this scope; did you mean ‘std::atomic_flag_test_and_set_explicit’?
   21 |   while (atomic_flag_test_and_set_explicit(&data->flag, memory_order_acquire));
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      |          std::atomic_flag_test_and_set_explicit
/usr/include/c++/12/atomic:1215:3: note: ‘std::atomic_flag_test_and_set_explicit’ declared here
 1215 |   atomic_flag_test_and_set_explicit(volatile atomic_flag* __a,
      |   ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/home/pi5/git/chipmachine/external/98fmplayer/leveldata/leveldata.h:24:37: error: ‘struct leveldata’ has no member named ‘flag’
   24 |   atomic_flag_clear_explicit(&data->flag, memory_order_release);
      |                                     ^~~~
/home/pi5/git/chipmachine/external/98fmplayer/leveldata/leveldata.h:24:43: error: ‘memory_order_release’ was not declared in this scope; did you mean ‘std::memory_order_release’?
   24 |   atomic_flag_clear_explicit(&data->flag, memory_order_release);
      |                                           ^~~~~~~~~~~~~~~~~~~~
      |                                           std::memory_order_release
/usr/include/c++/12/bits/atomic_base.h:83:7: note: ‘std::memory_order_release’ declared here
   83 |       memory_order_release,
      |       ^~~~~~~~~~~~~~~~~~~~
/home/pi5/git/chipmachine/external/98fmplayer/leveldata/leveldata.h:24:3: error: ‘atomic_flag_clear_explicit’ was not declared in this scope; did you mean ‘std::atomic_flag_clear_explicit’?
   24 |   atomic_flag_clear_explicit(&data->flag, memory_order_release);
      |   ^~~~~~~~~~~~~~~~~~~~~~~~~~
      |   std::atomic_flag_clear_explicit
/usr/include/c++/12/atomic:1224:3: note: ‘std::atomic_flag_clear_explicit’ declared here
 1224 |   atomic_flag_clear_explicit(volatile atomic_flag* __a,
      |   ^~~~~~~~~~~~~~~~~~~~~~~~~~
/home/pi5/git/chipmachine/external/98fmplayer/leveldata/leveldata.h: In function ‘void leveldata_init(leveldata*)’:
/home/pi5/git/chipmachine/external/98fmplayer/leveldata/leveldata.h:29:37: error: ‘struct leveldata’ has no member named ‘flag’
   29 |   atomic_flag_clear_explicit(&data->flag, memory_order_relaxed);
      |                                     ^~~~
/home/pi5/git/chipmachine/external/98fmplayer/leveldata/leveldata.h:29:43: error: ‘memory_order_relaxed’ was not declared in this scope; did you mean ‘std::memory_order_relaxed’?
   29 |   atomic_flag_clear_explicit(&data->flag, memory_order_relaxed);
      |                                           ^~~~~~~~~~~~~~~~~~~~
      |                                           std::memory_order_relaxed
/usr/include/c++/12/bits/atomic_base.h:80:7: note: ‘std::memory_order_relaxed’ declared here
   80 |       memory_order_relaxed,
      |       ^~~~~~~~~~~~~~~~~~~~
/home/pi5/git/chipmachine/external/98fmplayer/leveldata/leveldata.h:29:3: error: ‘atomic_flag_clear_explicit’ was not declared in this scope; did you mean ‘std::atomic_flag_clear_explicit’?
   29 |   atomic_flag_clear_explicit(&data->flag, memory_order_relaxed);
      |   ^~~~~~~~~~~~~~~~~~~~~~~~~~
      |   std::atomic_flag_clear_explicit
/usr/include/c++/12/atomic:1224:3: note: ‘std::atomic_flag_clear_explicit’ declared here
 1224 |   atomic_flag_clear_explicit(volatile atomic_flag* __a,
      |   ^~~~~~~~~~~~~~~~~~~~~~~~~~
[407/2377] Building CXX object plugins/uadeplugin/CMakeFiles/uadeplugin.dir/UADEPlugin.cpp.o
cc1plus: warning: command-line option ‘-Wno-implicit-function-declaration’ is valid for C/ObjC but not for C++
[410/2377] Building CXX object plugins/gsfplugin/CMakeFiles/gsfplugin.dir/playgsf/VBA/GBA.cpp.o
ninja: build stopped: subcommand failed.
```

