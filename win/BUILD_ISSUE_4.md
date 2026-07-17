FAILED: [code=1] plugins/s98plugin/CMakeFiles/s98plugin.dir/m_s98/device/s_sng.c.obj
C:\msys64\mingw64\bin\cc.exe  -IC:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/s98plugin/m_s98 -IC:/msys64/home/lab/git/chipmachine/external/apone/mods/coreutils/.. -g -funsigned-char  -g -funsigned-char -O2 -MD -MT plugins/s98plugin/CMakeFiles/s98plugin.dir/m_s98/device/s_sng.c.obj -MF plugins\s98plugin\CMakeFiles\s98plugin.dir\m_s98\device\s_sng.c.obj.d -o plugins/s98plugin/CMakeFiles/s98plugin.dir/m_s98/device/s_sng.c.obj -c C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/s98plugin/m_s98/device/s_sng.c
C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/s98plugin/m_s98/device/s_sng.c: In function 'SNGSoundAlloc':
C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/s98plugin/m_s98/device/s_sng.c:198:28: error: assignment to 'void (*)(void *)' from incompatible pointer type 'void (*)(SNGSOUND *)' [-Wincompatible-pointer-types]
  198 |         sndp->kmif.release = sndrelease;
      |                            ^
C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/s98plugin/m_s98/device/s_sng.c:183:13: note: 'sndrelease' declared here
  183 | static void sndrelease(SNGSOUND *sndp)
      |             ^~~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/s98plugin/m_s98/device/s_sng.c:199:26: error: assignment to 'void (*)(void *, Uint32,  Uint32)' {aka 'void (*)(void *, unsigned int,  unsigned int)'} from incompatible pointer type 'void (*)(SNGSOUND *, Uint32,  Uint32)' {aka 'void (*)(SNGSOUND *, unsigned int,  unsigned int)'} [-Wincompatible-pointer-types]
  199 |         sndp->kmif.reset = sndreset;
      |                          ^
C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/s98plugin/m_s98/device/s_sng.c:167:13: note: 'sndreset' declared here
  167 | static void sndreset(SNGSOUND *sndp, Uint32 clock, Uint32 freq)
      |             ^~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/s98plugin/m_s98/device/s_sng.c:200:26: error: assignment to 'void (*)(void *, Int32 *)' {aka 'void (*)(void *, int *)'} from incompatible pointer type 'void (*)(SNGSOUND *, Int32 *)' {aka 'void (*)(SNGSOUND *, int *)'} [-Wincompatible-pointer-types]
  200 |         sndp->kmif.synth = sndsynth;
      |                          ^
C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/s98plugin/m_s98/device/s_sng.c:97:13: note: 'sndsynth' declared here
   97 | static void sndsynth(SNGSOUND *sndp, Int32 *p)
      |             ^~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/s98plugin/m_s98/device/s_sng.c:201:27: error: assignment to 'void (*)(void *, Int32)' {aka 'void (*)(void *, int)'} from incompatible pointer type 'void (*)(SNGSOUND *, Int32)' {aka 'void (*)(SNGSOUND *, int)'} [-Wincompatible-pointer-types]
  201 |         sndp->kmif.volume = sndvolume;
      |                           ^
C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/s98plugin/m_s98/device/s_sng.c:112:13: note: 'sndvolume' declared here
  112 | static void sndvolume(SNGSOUND *sndp, Int32 volume)
      |             ^~~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/s98plugin/m_s98/device/s_sng.c:202:26: error: assignment to 'void (*)(void *, Uint32,  Uint32)' {aka 'void (*)(void *, unsigned int,  unsigned int)'} from incompatible pointer type 'void (*)(SNGSOUND *, Uint32,  Uint32)' {aka 'void (*)(SNGSOUND *, unsigned int,  unsigned int)'} [-Wincompatible-pointer-types]
  202 |         sndp->kmif.write = sndwrite;
      |                          ^
C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/s98plugin/m_s98/device/s_sng.c:123:13: note: 'sndwrite' declared here
  123 | static void sndwrite(SNGSOUND *sndp, Uint32 a, Uint32 v)
      |             ^~~~~~~~
C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/s98plugin/m_s98/device/s_sng.c:203:25: error: assignment to 'Uint32 (*)(void *, Uint32)' {aka 'unsigned int (*)(void *, unsigned int)'} from incompatible pointer type 'Uint32 (*)(SNGSOUND *, Uint32)' {aka 'unsigned int (*)(SNGSOUND *, unsigned int)'} [-Wincompatible-pointer-types]
  203 |         sndp->kmif.read = sndread;
      |                         ^
C:/msys64/home/lab/git/chipmachine/external/musicplayer/src/plugins/s98plugin/m_s98/device/s_sng.c:118:15: note: 'sndread' declared here
  118 | static Uint32 sndread(SNGSOUND *sndp, Uint32 a)
      |               ^~~~~~~
[77/2821] Building CXX object plugins/sksplugin/at3_basecli/CMakeFiles/BaseCli.dir/__/__/__/JUCE/modules/juce_core/juce_core.cpp.obj
ninja: build stopped: subcommand failed.

