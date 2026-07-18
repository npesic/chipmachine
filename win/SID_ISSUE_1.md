# Thread from gdb

```
Thread 8 (Thread 4520.0xa00):
#0  0x00007ff6df5169f4 in vicii_raster_draw_alarm_handler (offset=<optimized out>, data=<optimized out>) at C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/vicepluginbridge/vice/vicii/vicii.c:1326
        prev_sprite_sprite_collisions = 0 '\000'
        prev_sprite_background_collisions = 0 '\000'
        in_visible_area = 1
#1  0x00007ff6df4f65fc in alarm_context_dispatch (context=<optimized out>, cpu_clk=<optimized out>) at C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/vicepluginbridge/vice/alarm.h:145
        offset = <optimized out>
        idx = <optimized out>
        alarm = <optimized out>
#2  psid_play (buf=<optimized out>, n=<optimized out>) at C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/vicepluginbridge/overrides/maincpu.c:526
        dest_addr = <optimized out>
        dummy = <optimized out>
#3  0x00007ff6df77e503 in musix::VicePlayerBridge::getSamples (this=<optimized out>, target=<optimized out>, size=130120) at C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/vicepluginbridge/VicePluginBridge.cpp:56
No locals.
#4  0x00007ff6dea80916 in chipmachine::MusicPlayer::update (this=this@entry=0x1a8bd08) at C:/msys64/home/lab/git/chipmachine/src/MusicPlayer.cpp:79
        space_left = 131144
        samples_generated = <optimized out>
        temp_buf = std::vector of length 131144, capacity 131144 = {27024, 2367, 0, 0, -7776, 2185, 0, 0, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274, -274...}
#5  0x00007ff6dea93689 in chipmachine::MusicPlayerList::update (this=0x1a8bc90) at C:/msys64/home/lab/git/chipmachine/src/MusicPlayerList.cpp:429
        guard = <optimized out>
        br = ""
#6  0x00007ff6dea94386 in operator() (__closure=0x1ade568) at C:/msys64/home/lab/git/chipmachine/src/MusicPlayerList.cpp:91
        this = 0x1a8bc90
#7  std::__invoke_impl<void, chipmachine::MusicPlayerList::MusicPlayerList(chipmachine::MusicDatabase&, RemoteLoader&, std::shared_ptr<AudioPlayer>)::<lambda()> > (__f=...) at C:/msys64/mingw64/include/c++/16.1.0/bits/invoke.h:63
No locals.
#8  std::__invoke<chipmachine::MusicPlayerList::MusicPlayerList(chipmachine::MusicDatabase&, RemoteLoader&, std::shared_ptr<AudioPlayer>)::<lambda()> > (__fn=...) at C:/msys64/mingw64/include/c++/16.1.0/bits/invoke.h:98
No locals.
#9  std::thread::_Invoker<std::tuple<chipmachine::MusicPlayerList::MusicPlayerList(chipmachine::MusicDatabase&, RemoteLoader&, std::shared_ptr<AudioPlayer>)::<lambda()> > >::_M_invoke<0> (this=0x1ade568) at C:/msys64/mingw64/include/c++/16.1.0/bits/std_thread.h:303
No locals.
#10 std::thread::_Invoker<std::tuple<chipmachine::MusicPlayerList::MusicPlayerList(chipmachine::MusicDatabase&, RemoteLoader&, std::shared_ptr<AudioPlayer>)::<lambda()> > >::operator() (this=0x1ade568) at C:/msys64/mingw64/include/c++/16.1.0/bits/std_thread.h:310
No locals.
#11 std::thread::_State_impl<std::thread::_Invoker<std::tuple<chipmachine::MusicPlayerList::MusicPlayerList(chipmachine::MusicDatabase&, RemoteLoader&, std::shared_ptr<AudioPlayer>)::<lambda()> > > >::_M_run(void) (this=0x1ade560) at C:/msys64/mingw64/include/c++/16.1.0/bits/std_thread.h:255
No locals.
#12 0x00007ffa97660ccf in ?? () from C:\msys64\mingw64\bin\libstdc++-6.dll
No symbol table info available.
#13 0x00007ffab2f16ced in ?? () from C:\msys64\mingw64\bin\libwinpthread-1.dll
No symbol table info available.
#14 0x00007ffac196f0ad in msvcrt!_beginthreadex () from C:\WINDOWS\System32\msvcrt.dll
No symbol table info available.
#15 0x00007ffac196f17c in msvcrt!_endthreadex () from C:\WINDOWS\System32\msvcrt.dll
No symbol table info available.
#16 0x00007ffac141e957 in KERNEL32!BaseThreadInitThunk () from C:\WINDOWS\System32\kernel32.dll
No symbol table info available.
#17 0x00007ffac2a2ad6c in ntdll!RtlUserThreadStart () from C:\WINDOWS\SYSTEM32\ntdll.dll
No symbol table info available.
#18 0x0000000000000000 in ?? ()
No symbol table info available.
```
