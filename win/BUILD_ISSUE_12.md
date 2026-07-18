[1329/1656] Building C object plugins/uadeplugin/CMakeFiles/uadeplugin.dir/uade/src/frontends/common/uadeconf.c.obj
FAILED: [code=1] plugins/uadeplugin/CMakeFiles/uadeplugin.dir/uade/src/frontends/common/uadeconf.c.obj
C:\msys64\mingw64\bin\cc.exe -DPART_1 -DPART_2 -DPART_3 -DPART_4 -DPART_5 -DPART_6 -DPART_7 -DPART_8 -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/uadeplugin/bencode/include -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/uadeplugin/uade -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/uadeplugin/uade/src -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/uadeplugin/uade/src/include -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/uadeplugin/uade/src/frontends/include -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/uadeplugin/uade/src/frontends/common -IC:/msys64/home/lab/git/chipmachine/external/apone/mods/coreutils/.. -g -funsigned-char -std=gnu17 -Wno-incompatible-pointer-types -Wno-int-conversion -Wno-implicit-function-declaration -Wno-implicit-int  -g -funsigned-char -std=gnu17 -Wno-incompatible-pointer-types -Wno-int-conversion -Wno-implicit-function-declaration -Wno-implicit-int -O2 -Wno-implicit-function-declaration -MD -MT plugins/uadeplugin/CMakeFiles/uadeplugin.dir/uade/src/frontends/common/uadeconf.c.obj -MF plugins\uadeplugin\CMakeFiles\uadeplugin.dir\uade\src\frontends\common\uadeconf.c.obj.d -o plugins/uadeplugin/CMakeFiles/uadeplugin.dir/uade/src/frontends/common/uadeconf.c.obj -c C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/uadeplugin/uade/src/frontends/common/uadeconf.c
C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/uadeplugin/uade/src/frontends/common/uadeconf.c: In function 'uade_open_create_home':
C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/uadeplugin/uade/src/frontends/common/uadeconf.c:428:25: error: too many arguments to function 'mkdir'; expected 1, have 2
  428 |                         mkdir(name, S_IRUSR | S_IWUSR | S_IXUSR);
      |                         ^~~~~       ~~~~~~~
In file included from C:/msys64/mingw64/include/sys/stat.h:14,
                 from C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/uadeplugin/uade/src/frontends/common/uadeconf.c:28:
C:/msys64/mingw64/include/io.h:270:15: note: declared here
  270 |   int __cdecl mkdir (const char *) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
      |               ^~~~~
[1337/1656] Building CXX object plugins/uadeplugin/CMakeFiles/uadeplugin.dir/UADEPlugin.cpp.obj
FAILED: [code=1] plugins/uadeplugin/CMakeFiles/uadeplugin.dir/UADEPlugin.cpp.obj
C:\msys64\mingw64\bin\c++.exe -DPART_1 -DPART_2 -DPART_3 -DPART_4 -DPART_5 -DPART_6 -DPART_7 -DPART_8 -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/uadeplugin/bencode/include -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/uadeplugin/uade -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/uadeplugin/uade/src -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/uadeplugin/uade/src/include -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/uadeplugin/uade/src/frontends/include -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/uadeplugin/uade/src/frontends/common -IC:/msys64/home/lab/git/chipmachine/external/apone/mods/coreutils/.. -g -funsigned-char -include cstdint  -g -funsigned-char -include cstdint -O2 -std=gnu++17 -Wno-implicit-function-declaration -MD -MT plugins/uadeplugin/CMakeFiles/uadeplugin.dir/UADEPlugin.cpp.obj -MF plugins\uadeplugin\CMakeFiles\uadeplugin.dir\UADEPlugin.cpp.obj.d -o plugins/uadeplugin/CMakeFiles/uadeplugin.dir/UADEPlugin.cpp.obj -c C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/uadeplugin/UADEPlugin.cpp
cc1plus.exe: warning: command-line option '-Wno-implicit-function-declaration' is valid for C/ObjC but not for C++
C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/uadeplugin/UADEPlugin.cpp: In static member function 'static uade_file* musix::UADEPlayer::amigaloader(const char*, const char*, void*, uade_state*)':
C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/uadeplugin/UADEPlugin.cpp:108:69: error: invalid initialization of reference of type 'const std::string&' {aka 'const std::__cxx11::basic_string<char>&'} from expression of type 'std::filesystem::__cxx11::path'
  108 |                        (player->baseName + "." + utils::path_prefix(fileName));
      |                                                                     ^~~~~~~~
In file included from C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/uadeplugin/UADEPlugin.cpp:7:
C:/msys64/home/lab/git/chipmachine/external/apone/mods/coreutils/utils.h:165:44: note: in passing argument 1 of 'std::string utils::path_prefix(const std::string&)'
  165 | std::string path_prefix(const std::string& name);
      |                         ~~~~~~~~~~~~~~~~~~~^~~~
[1341/1656] Building C object ap1mods/sqlite3/CMakeFiles/sqlite3.dir/sqlite3.c.obj
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
[1342/1656] Building CXX object plugins/gsfplugin/CMakeFiles/gsfplugin.dir/playgsf/VBA/GBA.cpp.obj
ninja: build stopped: subcommand failed.
