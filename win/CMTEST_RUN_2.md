# builds/release/cmtest -d yes -s

```
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cmtest.exe is a Catch v1.5.6 host application.
Run with -? for options

-------------------------------------------------------------------------------
modutils
-------------------------------------------------------------------------------
C:/msys64/home/lab/git/chipmachine/test.cpp:115
...............................................................................

C:/msys64/home/lab/git/chipmachine/test.cpp:118:
PASSED:
  REQUIRE( x == std::make_tuple("mdat", "gurgle%tjosan") )
with expansion:
  { "mdat", "gurgle%tjosan" }
  ==
  { "mdat", "gurgle%tjosan" }

C:/msys64/home/lab/git/chipmachine/test.cpp:121:
PASSED:
  REQUIRE( x == std::make_tuple("mod", "skurk.mannen.x") )
with expansion:
  { "mod", "skurk.mannen.x" }
  ==
  { "mod", "skurk.mannen.x" }

C:/msys64/home/lab/git/chipmachine/test.cpp:124:
PASSED:
  REQUIRE( x == std::make_tuple("whatever", "hejsan hoppsan") )
with expansion:
  { "whatever", "hejsan hoppsan" }
  ==
  { "whatever", "hejsan hoppsan" }

C:/msys64/home/lab/git/chipmachine/test.cpp:126:
PASSED:
  REQUIRE( getBaseName("/asda/das/test.mod") == "test.mod" )
with expansion:
  "test.mod" == "test.mod"

C:/msys64/home/lab/git/chipmachine/test.cpp:127:
PASSED:
  REQUIRE( getTypeFromName("gurgle.format") == "format" )
with expansion:
  "format" == "format"

C:/msys64/home/lab/git/chipmachine/test.cpp:128:
PASSED:
  REQUIRE( getTypeFromName("mdat.gurgle") == "mdat" )
with expansion:
  "mdat" == "mdat"

C:/msys64/home/lab/git/chipmachine/test.cpp:129:
PASSED:
  REQUIRE( getTypeFromName("mdat.gurgle") == "mdat" )
with expansion:
  "mdat" == "mdat"

C:/msys64/home/lab/git/chipmachine/test.cpp:130:
PASSED:
  REQUIRE( getTypeFromName("ftp%3a%2f%2fftp.modland.com%2fpub%2fmodules%" "2fSunTronic%2fTSM%2fmsx-intro.sun") == "sun" )
with expansion:
  "sun" == "sun"

C:/msys64/home/lab/git/chipmachine/test.cpp:132: 
PASSED:
  REQUIRE( getTypeFromName("ftp%3a%2f%2fftp.modland.com%2fpub%2fmodules%2fTFMX%" "2fChris Huelsbeck%2fmdat.apidya (level 3)") == "mdat" )
with expansion:
  "mdat" == "mdat"

Completed in 0.012162s
[MusicDatabase.cpp:3904] INDEX SKIPPED UNSUPPORTED EXTENSIONS: .arj .lzx .tgz .xz .img .one .flp .ps1 .tic .m8s .legoz .asg .snort .rns .xrns .psy .sn .sn2 .fls .axs .am .sho .bmx .pmd .spm .sps .dux .skm .ct .pol .mgb .edl .fw .smufi .brt .xex .0cc .kftm
-------------------------------------------------------------------------------
music database
-------------------------------------------------------------------------------
C:/msys64/home/lab/git/chipmachine/test.cpp:137
...............................................................................

C:/msys64/home/lab/git/chipmachine/test.cpp:143:
PASSED:
  REQUIRE( mdb->initFromLua(utils::path(".")) == true )
with expansion:
  true == true

Completed in 0.436023s
[FFMPEGPlugin.cpp:200] FFMPEG PLUGIN INITIALIZED WITH PATH 'bin\ffmpeg.exe'
musicplayerlist completed in 0.324297s
-------------------------------------------------------------------------------
musicplayer
-------------------------------------------------------------------------------
C:/msys64/home/lab/git/chipmachine/test.cpp:190
...............................................................................

C:/msys64/home/lab/git/chipmachine/test.cpp:198:
PASSED:
  REQUIRE( ok )
with expansion:
  true

C:/msys64/home/lab/git/chipmachine/test.cpp:203:
PASSED:
  REQUIRE( sum != 0 )
with expansion:
  -19699840 != 0

Completed in 0.016892s
-------------------------------------------------------------------------------
MusicPlayer fetches the playing plugin's secondary files
-------------------------------------------------------------------------------
C:/msys64/home/lab/git/chipmachine/test.cpp:214
...............................................................................

C:/msys64/home/lab/git/chipmachine/test.cpp:220:
PASSED:
  REQUIRE( std::find(sec.begin(), sec.end(), "DRUMKIT1.SM1") != sec.end() )
with expansion:
  {?} != {?}

C:/msys64/home/lab/git/chipmachine/test.cpp:221:
PASSED:
  REQUIRE( std::find(sec.begin(), sec.end(), "DRUMKIT1.SM2") != sec.end() )
with expansion:
  {?} != {?}

Completed in 0.003347s
-------------------------------------------------------------------------------
STarKos host path plays sound
-------------------------------------------------------------------------------
C:/msys64/home/lab/git/chipmachine/test.cpp:228
...............................................................................

C:/msys64/home/lab/git/chipmachine/test.cpp:236:
PASSED:
  REQUIRE( ok )
with expansion:
  true

C:/msys64/home/lab/git/chipmachine/test.cpp:244: 
PASSED:
  REQUIRE( sum != 0 )
with expansion:
  211532 (0x33a4c) != 0

Completed in 0.043338s
-------------------------------------------------------------------------------
OPL Archive routes to libvgm and plays
-------------------------------------------------------------------------------
C:/msys64/home/lab/git/chipmachine/test.cpp:254
...............................................................................

C:/msys64/home/lab/git/chipmachine/test.cpp:263:
PASSED:
  REQUIRE( mp.playFile(vgz) )
with expansion:
  true

C:/msys64/home/lab/git/chipmachine/test.cpp:271:
PASSED:
  REQUIRE( sum != 0 )
with expansion:
  553548 (0x8724c) != 0

C:/msys64/home/lab/git/chipmachine/test.cpp:263:
PASSED:
  REQUIRE( mp.playFile(vgz) )
with expansion:
  true

C:/msys64/home/lab/git/chipmachine/test.cpp:271:
PASSED:
  REQUIRE( sum != 0 )
with expansion:
  9366478 (0x8eebce) != 0

Completed in 0.013455s
-------------------------------------------------------------------------------
VGMRips non-Sega VGM routes to libvgm
-------------------------------------------------------------------------------
C:/msys64/home/lab/git/chipmachine/test.cpp:281
...............................................................................

C:/msys64/home/lab/git/chipmachine/test.cpp:297:
PASSED:
  REQUIRE( lv.canHandle(vgz) )
with expansion:
  true

C:/msys64/home/lab/git/chipmachine/test.cpp:298:
PASSED:
  REQUIRE_FALSE( gme.canHandle(vgz) )
with expansion:
  !false

C:/msys64/home/lab/git/chipmachine/test.cpp:297:
PASSED:
  REQUIRE( lv.canHandle(vgz) )
with expansion:
  true

C:/msys64/home/lab/git/chipmachine/test.cpp:298:
PASSED:
  REQUIRE_FALSE( gme.canHandle(vgz) )
with expansion:
  !false

C:/msys64/home/lab/git/chipmachine/test.cpp:297:
PASSED:
  REQUIRE( lv.canHandle(vgz) )
with expansion:
  true

C:/msys64/home/lab/git/chipmachine/test.cpp:298:
PASSED:
  REQUIRE_FALSE( gme.canHandle(vgz) )
with expansion:
  !false

C:/msys64/home/lab/git/chipmachine/test.cpp:297:
PASSED:
  REQUIRE( lv.canHandle(vgz) )
with expansion:
  true

C:/msys64/home/lab/git/chipmachine/test.cpp:298:
PASSED:
  REQUIRE_FALSE( gme.canHandle(vgz) )
with expansion:
  !false

C:/msys64/home/lab/git/chipmachine/test.cpp:297:
PASSED:
  REQUIRE( lv.canHandle(vgz) )
with expansion:
  true

C:/msys64/home/lab/git/chipmachine/test.cpp:298:
PASSED:
  REQUIRE_FALSE( gme.canHandle(vgz) )
with expansion:
  !false

C:/msys64/home/lab/git/chipmachine/test.cpp:297:
PASSED:
  REQUIRE( lv.canHandle(vgz) )
with expansion:
  true

C:/msys64/home/lab/git/chipmachine/test.cpp:298:
PASSED:
  REQUIRE_FALSE( gme.canHandle(vgz) )
with expansion:
  !false

C:/msys64/home/lab/git/chipmachine/test.cpp:297:
PASSED:
  REQUIRE( lv.canHandle(vgz) )
with expansion:
  true

C:/msys64/home/lab/git/chipmachine/test.cpp:298:
PASSED:
  REQUIRE_FALSE( gme.canHandle(vgz) )
with expansion:
  !false

C:/msys64/home/lab/git/chipmachine/test.cpp:297:
PASSED:
  REQUIRE( lv.canHandle(vgz) )
with expansion:
  true

C:/msys64/home/lab/git/chipmachine/test.cpp:298:
PASSED:
  REQUIRE_FALSE( gme.canHandle(vgz) )
with expansion:
  !false

C:/msys64/home/lab/git/chipmachine/test.cpp:303:
PASSED:
  REQUIRE( gme.canHandle(vgz) )
with expansion:
  true

C:/msys64/home/lab/git/chipmachine/test.cpp:304:
PASSED:
  REQUIRE_FALSE( lv.canHandle(vgz) )
with expansion:
  !false

C:/msys64/home/lab/git/chipmachine/test.cpp:303: 
PASSED:
  REQUIRE( gme.canHandle(vgz) )
with expansion:
  true

C:/msys64/home/lab/git/chipmachine/test.cpp:304:
PASSED:
  REQUIRE_FALSE( lv.canHandle(vgz) )
with expansion:
  !false

Completed in 0.025042s
```
