# Build issue 9

```
FAILED: cm 
: && /usr/bin/c++ -g -funsigned-char  -g -funsigned-char -O2  CMakeFiles/cm.dir/src/MusicDatabase.cpp.o CMakeFiles/cm.dir/src/GZPlugin.cpp.o CMakeFiles/cm.dir/src/LhaArchive.cpp.o CMakeFiles/cm.dir/src/MusicPlayer.cpp.o CMakeFiles/cm.dir/src/MusicPlayerList.cpp.o CMakeFiles/cm.dir/src/RemoteLoader.cpp.o CMakeFiles/cm.dir/src/SearchIndex.cpp.o CMakeFiles/cm.dir/src/SongFileIdentifier.cpp.o CMakeFiles/cm.dir/src/state_machine.cpp.o CMakeFiles/cm.dir/src/youtube.cpp.o CMakeFiles/cm.dir/src/textmode.cpp.o CMakeFiles/cm.dir/src/CheckForUpdate_stub.cpp.o CMakeFiles/cm.dir/src/NativeDialogs_stub.cpp.o CMakeFiles/cm.dir/src/main.cpp.o -o cm  ap1mods/grappix/coreutils/libcoreutils.a  ap1mods/audioplayer/libaudioplayer.a  ap1mods/archive/libarchive.a  ap1mods/webutils/libwebutils.a  ap1mods/sqlite3/libsqlite3.a  ap1mods/xml/libxml.a  ap1mods/bbsutils/libbbsutils.a  ap1mods/crypto/libcrypto.a  plugins/openmptplugin/libopenmptplugin.a  plugins/htplugin/libhtplugin.a  plugins/heplugin/libheplugin.a  plugins/ndsplugin/libndsplugin.a  plugins/gmeplugin/libgmeplugin.a  plugins/sc68plugin/libsc68plugin.a  plugins/usfplugin/libusfplugin.a  plugins/stsoundplugin/libstsoundplugin.a  plugins/adplugin/libadplugin.a  plugins/mp3plugin/libmp3plugin.a  plugins/hivelyplugin/libhivelyplugin.a  plugins/rsnplugin/librsnplugin.a  plugins/ayflyplugin/libayflyplugin.a  plugins/mdxplugin/libmdxplugin.a  plugins/s98plugin/libs98plugin.a  plugins/aoplugin/libaoplugin.a  plugins/gsfplugin/libgsfplugin.a  plugins/tedplugin/libtedplugin.a  plugins/v2plugin/libv2plugin.a  plugins/ffmpegplugin/libffmpegplugin.a  plugins/uadeplugin/libuadeplugin.a  plugins/fmpplugin/libfmpplugin.a  plugins/pxtoneplugin/libpxtoneplugin.a  plugins/ptkplugin/libptkplugin.a  plugins/orgplugin/liborgplugin.a  plugins/sunvoxplugin/libsunvoxplugin.a  plugins/eupplugin/libeupplugin.a  plugins/kssplugin/libkssplugin.a  plugins/quartetplugin/libquartetplugin.a  plugins/wsrplugin/libwsrplugin.a  plugins/zxtuneplugin/libzxtuneplugin.a  plugins/pokeynoiseplugin/libpokeynoiseplugin.a  plugins/bbsongplugin/libbbsongplugin.a  plugins/soundsmithplugin/libsoundsmithplugin.a  plugins/musxplugin/libmusxplugin.a  plugins/cocoplugin/libcocoplugin.a  plugins/mgtplugin/libmgtplugin.a  plugins/medplugin/libmedplugin.a  plugins/sbstudioplugin/libsbstudioplugin.a  plugins/maxtraxplugin/libmaxtraxplugin.a  plugins/sksplugin/libsksplugin.a  plugins/nedplugin/libnedplugin.a  plugins/sccmusixxplugin/libsccmusixxplugin.a  plugins/playerproplugin/libplayerproplugin.a  plugins/jxsplugin/libjxsplugin.a  plugins/monotoneplugin/libmonotoneplugin.a  plugins/mikmodplugin/libmikmodplugin.a  plugins/ixsplugin/libixsplugin.a  plugins/copplugin/libcopplugin.a  plugins/famitrackerplugin/libfamitrackerplugin.a  plugins/goattrackerplugin/libgoattrackerplugin.a  plugins/dmfplugin/libdmfplugin.a  plugins/libvgmplugin/liblibvgmplugin.a  plugins/vgmstreamplugin/libvgmstreamplugin.a  plugins/zxtuneplugin/zxt/lhasa/liblhasa.a  plugins/vicepluginbridge/libvicepluginbridge.a  -lavcodec  -lavformat  -lavutil  -lswresample  libplugin_register.a  /usr/lib/aarch64-linux-gnu/libasound.so  -lcurl  ap1mods/bbsutils/netlink/libnetlink.a  /usr/lib/aarch64-linux-gnu/libmpg123.so  ap1mods/archive/libarchive.a  ap1mods/archive/unrar/libunrar.a  ap1mods/archive/miniz/libminiz.a  psf/libpsf.a  plugins/s98plugin/libs98plugin.a  libpxtone.a  plugins/zxtuneplugin/zxt/lzma/liblzma.a  plugins/zxtuneplugin/zxt/z80ex/libz80ex.a  plugins/zxtuneplugin/zxt/analysis/libanalysis.a  plugins/zxtuneplugin/zxt/binary/libbinary.a  plugins/zxtuneplugin/zxt/binary_format/libbinary_format.a  plugins/zxtuneplugin/zxt/binary_compression/libbinary_compression.a  plugins/zxtuneplugin/zxt/core/libcore.a  plugins/zxtuneplugin/zxt/core_plugins_archives/libcore_plugins_archives.a  plugins/zxtuneplugin/zxt/core_plugins_players/libcore_plugins_players.a  plugins/zxtuneplugin/zxt/dbg/libdbg.a  plugins/zxtuneplugin/zxt/devices_aym/libdevices_aym.a  plugins/zxtuneplugin/zxt/devices_beeper/libdevices_beeper.a  plugins/zxtuneplugin/zxt/devices_dac/libdevices_dac.a  plugins/zxtuneplugin/zxt/devices_fm/libdevices_fm.a  plugins/zxtuneplugin/zxt/devices_saa/libdevices_saa.a  plugins/zxtuneplugin/zxt/devices_z80/libdevices_z80.a  plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a  plugins/zxtuneplugin/zxt/formats_packed/libformats_packed.a  plugins/zxtuneplugin/zxt/formats_multitrack/libformats_multitrack.a  plugins/zxtuneplugin/zxt/formats_archived/libformats_archived.a  plugins/zxtuneplugin/zxt/l10n_stub/libl10n_stub.a  plugins/zxtuneplugin/zxt/module_conversion/libmodule_conversion.a  plugins/zxtuneplugin/zxt/module_players/libmodule_players.a  plugins/zxtuneplugin/zxt/module_properties/libmodule_properties.a  plugins/zxtuneplugin/zxt/parameters/libparameters.a  plugins/zxtuneplugin/zxt/platform_version/libplatform_version.a  plugins/zxtuneplugin/zxt/sound/libsound.a  plugins/zxtuneplugin/zxt/strings/libstrings.a  plugins/zxtuneplugin/zxt/tools/libtools.a  /usr/lib/aarch64-linux-gnu/libz.so  plugins/musxplugin/libmusxplugin.a  plugins/sksplugin/at3_baseexport/libBaseExport.a  plugins/sksplugin/at3_rasm/libThirdPartyRasm.a  plugins/sksplugin/at3_basecli/libBaseCli.a  plugins/sksplugin/at3_lzh/libThirdPartyLzh.a  -flto  -lrt  -ldl  -lpthread  /usr/lib/aarch64-linux-gnu/libz.so  /usr/lib/aarch64-linux-gnu/libz.so  -lm  ap1mods/crypto/libcrypto.a  -lz  external/lua/liblua.a  ap1mods/grappix/coreutils/libcoreutils.a  ap1mods/grappix/coreutils/fmt/fmt/libfmt.a && cd /home/pi5/git/chipmachine/builds/release && /usr/bin/cmake -E copy_if_different /home/pi5/git/chipmachine/external/musicplayer/src/plugins/sunvoxplugin/sunvox_lib/sunvox.dylib /home/pi5/git/chipmachine/builds/release
/usr/bin/ld: plugins/zxtuneplugin/zxt/core_plugins_archives/libcore_plugins_archives.a(zdata_supp.cpp.o): in function `ZXTune::Zdata::Marker::Encode() const':
/home/pi5/git/chipmachine/external/zxtune/src/core/plugins/archives/zdata_supp.cpp:95: undefined reference to `Binary::Base64::Encode(unsigned char const*, unsigned char const*, char*, char const*)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/core_plugins_archives/libcore_plugins_archives.a(zdata_supp.cpp.o): in function `ZXTune::Zdata::Compress(Binary::View, Binary::DataBuilder&)':
/home/pi5/git/chipmachine/external/zxtune/src/core/plugins/archives/zdata_supp.cpp:216: undefined reference to `Binary::Compression::Zlib::Compress(Binary::DataInputStream&, Binary::DataBuilder&)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/core/plugins/archives/zdata_supp.cpp:219: undefined reference to `Binary::Crc32(Binary::View, unsigned int)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/core_plugins_archives/libcore_plugins_archives.a(zdata_supp.cpp.o): in function `ZXTune::Zdata::Header::Decode(std::array<char, 16ul> const&)':
/home/pi5/git/chipmachine/external/zxtune/src/core/plugins/archives/zdata_supp.cpp:115: undefined reference to `Binary::Base64::Decode(char const*, char const*, unsigned char*, unsigned char const*)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/core_plugins_archives/libcore_plugins_archives.a(zdata_supp.cpp.o): in function `ZXTune::Zdata::Layout::GetBody(unsigned long) const':
/home/pi5/git/chipmachine/external/zxtune/src/core/plugins/archives/zdata_supp.cpp:165: undefined reference to `Binary::Base64::CalculateConvertedSize(unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/core_plugins_archives/libcore_plugins_archives.a(zdata_supp.cpp.o): in function `ZXTune::Zdata::Decode(Binary::View, ZXTune::Zdata::Marker const&)':
/home/pi5/git/chipmachine/external/zxtune/src/core/plugins/archives/zdata_supp.cpp:191: undefined reference to `Binary::Base64::Decode(std::basic_string_view<char, std::char_traits<char> >)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/core/plugins/archives/zdata_supp.cpp:193: undefined reference to `Binary::Compression::Zlib::Decompress(Binary::View, unsigned long)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/core/plugins/archives/zdata_supp.cpp:195: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/core/plugins/archives/zdata_supp.cpp:195: undefined reference to `Binary::Crc32(Binary::View, unsigned int)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/core_plugins_archives/libcore_plugins_archives.a(zdata_supp.cpp.o): in function `ZXTune::Zdata::Convert(Binary::View)':
/home/pi5/git/chipmachine/external/zxtune/src/core/plugins/archives/zdata_supp.cpp:224: undefined reference to `Binary::Base64::CalculateConvertedSize(unsigned long)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/core/plugins/archives/zdata_supp.cpp:228: undefined reference to `Binary::Base64::Encode(unsigned char const*, unsigned char const*, char*, char const*)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/core_plugins_archives/libcore_plugins_archives.a(zdata_supp.cpp.o): in function `ZXTune::Zdata::Compress(Binary::View, Binary::DataBuilder&)':
/home/pi5/git/chipmachine/external/zxtune/src/core/plugins/archives/zdata_supp.cpp:216: undefined reference to `Binary::Compression::Zlib::Compress(Binary::DataInputStream&, Binary::DataBuilder&)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/core/plugins/archives/zdata_supp.cpp:219: undefined reference to `Binary::Crc32(Binary::View, unsigned int)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/core_plugins_archives/libcore_plugins_archives.a(zdata_supp.cpp.o): in function `ZXTune::Zdata::Plugin::Detect(Parameters::Accessor const&, std::shared_ptr<ZXTune::DataLocation const>, ZXTune::ArchiveCallback&) const':
/home/pi5/git/chipmachine/external/zxtune/src/core/plugins/archives/zdata_supp.cpp:284: undefined reference to `Analysis::CreateUnmatchedResult(unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/core_plugins_archives/libcore_plugins_archives.a(zdata_supp.cpp.o): in function `ZXTune::Zdata::Plugin::TryOpen(Parameters::Accessor const&, std::shared_ptr<ZXTune::DataLocation const>, Analysis::Path const&) const':
/home/pi5/git/chipmachine/external/zxtune/src/core/plugins/archives/zdata_supp.cpp:295: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/core/plugins/archives/zdata_supp.cpp:297: undefined reference to `ZXTune::CreateNestedLocation(std::shared_ptr<ZXTune::DataLocation const>, std::shared_ptr<Binary::Container const>, ZXTune::PluginId, std::basic_string_view<char, std::char_traits<char> >)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(ascsoundmaster.cpp.o): in function `Formats::Chiptune::ASCSoundMaster::Parse(Formats::Chiptune::ASCSoundMaster::VersionTraits const&, Binary::Container const&, Formats::Chiptune::ASCSoundMaster::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/ascsoundmaster.cpp:1175: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(ascsoundmaster.cpp.o): in function `Formats::Chiptune::ASCSoundMaster::VersionedDecoder::VersionedDecoder(Formats::Chiptune::ASCSoundMaster::VersionTraits const&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/ascsoundmaster.cpp:1244: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(ascsoundmaster.cpp.o): in function `std::shared_ptr<Binary::Container const> Formats::Chiptune::ASCSoundMaster::InsertMetaInformation<Formats::Chiptune::ASCSoundMaster::Version0>(Binary::Container const&, Binary::View)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/ascsoundmaster.cpp:1214: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/ascsoundmaster.cpp:1218: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(ascsoundmaster.cpp.o): in function `std::shared_ptr<Binary::Container const> Formats::Chiptune::ASCSoundMaster::InsertMetaInformation<Formats::Chiptune::ASCSoundMaster::Version1>(Binary::Container const&, Binary::View)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/ascsoundmaster.cpp:1214: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/ascsoundmaster.cpp:1218: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(ayc.cpp.o): in function `Formats::Chiptune::AYC::Parse(Binary::Container const&, Formats::Chiptune::AYC::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/ayc.cpp:229: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(ayc.cpp.o): in function `Formats::Chiptune::AYC::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/ayc.cpp:100: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(fasttracker.cpp.o): in function `Formats::Chiptune::FastTracker::Parse(Binary::Container const&, Formats::Chiptune::FastTracker::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/fasttracker.cpp:1169: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(fasttracker.cpp.o): in function `Formats::Chiptune::FastTracker::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/fasttracker.cpp:1134: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(fasttracker.cpp.o): in function `Formats::Chiptune::FastTracker::Decoder::Decode(Binary::Container const&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/fasttracker.cpp:1155: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(globaltracker.cpp.o): in function `Formats::Chiptune::GlobalTracker::Parse(Binary::Container const&, Formats::Chiptune::GlobalTracker::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/globaltracker.cpp:982: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(globaltracker.cpp.o): in function `Formats::Chiptune::GlobalTracker::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/globaltracker.cpp:947: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(globaltracker.cpp.o): in function `Formats::Chiptune::GlobalTracker::Decoder::Decode(Binary::Container const&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/globaltracker.cpp:968: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(prosoundcreator.cpp.o): in function `Formats::Chiptune::ProSoundCreator::Parse(Binary::Container const&, Formats::Chiptune::ProSoundCreator::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/prosoundcreator.cpp:1163: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(prosoundcreator.cpp.o): in function `Formats::Chiptune::ProSoundCreator::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/prosoundcreator.cpp:1128: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(prosoundcreator.cpp.o): in function `Formats::Chiptune::ProSoundCreator::Decoder::Decode(Binary::Container const&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/prosoundcreator.cpp:1149: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(prosoundmaker_compiled.cpp.o): in function `Formats::Chiptune::ProSoundMaker::ParseCompiled(Binary::Container const&, Formats::Chiptune::ProSoundMaker::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/prosoundmaker_compiled.cpp:1051: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(prosoundmaker_compiled.cpp.o): in function `Formats::Chiptune::ProSoundMakerCompiled::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/prosoundmaker_compiled.cpp:1011: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(prosoundmaker_compiled.cpp.o): in function `Formats::Chiptune::ProSoundMakerCompiled::Decoder::Decode(Binary::Container const&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/prosoundmaker_compiled.cpp:1032: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(protracker1.cpp.o): in function `Formats::Chiptune::ProTracker1::Parse(Binary::Container const&, Formats::Chiptune::ProTracker1::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/protracker1.cpp:874: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(protracker1.cpp.o): in function `Formats::Chiptune::ProTracker1::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/protracker1.cpp:839: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(protracker1.cpp.o): in function `Formats::Chiptune::ProTracker1::Decoder::Decode(Binary::Container const&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/protracker1.cpp:860: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(protracker2.cpp.o): in function `Formats::Chiptune::ProTracker2::Parse(Binary::Container const&, Formats::Chiptune::ProTracker2::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/protracker2.cpp:936: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(protracker2.cpp.o): in function `Formats::Chiptune::ProTracker2::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/protracker2.cpp:901: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(protracker2.cpp.o): in function `Formats::Chiptune::ProTracker2::Decoder::Decode(Binary::Container const&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/protracker2.cpp:922: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(protracker3_compiled.cpp.o): in function `Formats::Chiptune::ProTracker3::Parse(Binary::Container const&, Formats::Chiptune::ProTracker3::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/protracker3_compiled.cpp:954: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(protracker3_compiled.cpp.o): in function `Formats::Chiptune::ProTracker3::BinaryDecoder::BinaryDecoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/protracker3_compiled.cpp:914: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(protracker3_compiled.cpp.o): in function `Formats::Chiptune::ProTracker3::BinaryDecoder::Decode(Binary::Container const&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/protracker3_compiled.cpp:935: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(protracker3_vortex.cpp.o): in function `Binary::InputStream::InputStream(Binary::Container const&)':
/home/pi5/git/chipmachine/external/zxtune/src/binary/input_stream.h:172: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(protracker3_vortex.cpp.o): in function `Formats::Chiptune::ProTracker3::VortexTracker2::TextDecoder::TextDecoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/protracker3_vortex.cpp:1250: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(protracker3_vortex.cpp.o): in function `Formats::Chiptune::ProTracker3::VortexTracker2::TextDecoder::Decode(Binary::Container const&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/protracker3_vortex.cpp:1270: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(soundtracker.cpp.o): in function `Formats::Chiptune::SoundTrackerUncompiled::ParseUncompiled(Binary::Container const&, Formats::Chiptune::SoundTracker::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/soundtracker.cpp:436: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(soundtracker.cpp.o): in function `Formats::Chiptune::SoundTrackerUncompiled::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/soundtracker.cpp:476: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(soundtracker.cpp.o): in function `Formats::Chiptune::SoundTrackerUncompiled::Decoder::Decode(Binary::Container const&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/soundtracker.cpp:496: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(soundtracker3.cpp.o): in function `Formats::Chiptune::SoundTracker::Ver3::Parse(Binary::Container const&, Formats::Chiptune::SoundTracker::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/soundtracker3.cpp:758: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(soundtracker3.cpp.o): in function `Formats::Chiptune::SoundTracker::Ver3::InsertMetainformation(Binary::Container const&, Binary::View)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/soundtracker3.cpp:801: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/soundtracker3.cpp:805: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(soundtracker3.cpp.o): in function `Formats::Chiptune::SoundTracker3::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/soundtracker3.cpp:708: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(soundtracker3.cpp.o): in function `Formats::Chiptune::SoundTracker3::Decoder::Decode(Binary::Container const&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/soundtracker3.cpp:729: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(soundtracker_compiled.cpp.o): in function `Formats::Chiptune::SoundTrackerCompiled::ParseCompiled(Binary::Container const&, Formats::Chiptune::SoundTracker::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/soundtracker_compiled.cpp:697: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(soundtracker_compiled.cpp.o): in function `Formats::Chiptune::SoundTrackerCompiled::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/soundtracker_compiled.cpp:737: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(soundtracker_compiled.cpp.o): in function `Formats::Chiptune::SoundTrackerCompiled::Decoder::Decode(Binary::Container const&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/soundtracker_compiled.cpp:757: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(soundtrackerpro_compiled.cpp.o): in function `Formats::Chiptune::SoundTrackerPro::ParseCompiled(Binary::Container const&, Formats::Chiptune::SoundTrackerPro::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/soundtrackerpro_compiled.cpp:918: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(soundtrackerpro_compiled.cpp.o): in function `Formats::Chiptune::SoundTrackerPro::InsertMetaInformation(Binary::Container const&, Binary::View)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/soundtrackerpro_compiled.cpp:959: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/soundtrackerpro_compiled.cpp:963: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(soundtrackerpro_compiled.cpp.o): in function `Formats::Chiptune::SoundTrackerProCompiled::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/soundtrackerpro_compiled.cpp:868: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(sqtracker_compiled.cpp.o): in function `Formats::Chiptune::SQTracker::ParseCompiled(Binary::Container const&, Formats::Chiptune::SQTracker::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/sqtracker_compiled.cpp:976: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(sqtracker_compiled.cpp.o): in function `Formats::Chiptune::SQTracker::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/sqtracker_compiled.cpp:941: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(sqtracker_compiled.cpp.o): in function `Formats::Chiptune::SQTracker::Decoder::Decode(Binary::Container const&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/sqtracker_compiled.cpp:962: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(ym_vtx.cpp.o): in function `Formats::Chiptune::YM::YMDecoder::YMDecoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/ym_vtx.cpp:417: undefined reference to `Binary::CreateMatchOnlyFormat(std::basic_string_view<char, std::char_traits<char> >)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(ym_vtx.cpp.o): in function `Formats::Chiptune::YM::PackedDecoder::PackedDecoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/ym_vtx.cpp:458: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(ym_vtx.cpp.o): in function `Formats::Chiptune::VTX::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/ym_vtx.cpp:654: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(ym_vtx.cpp.o): in function `Formats::Chiptune::YM::YMDecoder::YMDecoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/ym_vtx.cpp:417: undefined reference to `Binary::CreateMatchOnlyFormat(std::basic_string_view<char, std::char_traits<char> >)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(ym_vtx.cpp.o): in function `Formats::Chiptune::YM::PackedDecoder::PackedDecoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/ym_vtx.cpp:458: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(ym_vtx.cpp.o): in function `Formats::Chiptune::VTX::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/ym_vtx.cpp:654: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(ym_vtx.cpp.o): in function `Binary::InputStream::InputStream(Binary::Container const&)':
/home/pi5/git/chipmachine/external/zxtune/src/binary/input_stream.h:172: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/binary/input_stream.h:172: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(ym_vtx.cpp.o): in function `Formats::Chiptune::YM::ParsePacked(Binary::Container const&, Formats::Chiptune::YM::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/ym_vtx.cpp:378: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(ym_vtx.cpp.o): in function `Formats::Chiptune::VTX::ParseVTX(Binary::Container const&, Formats::Chiptune::YM::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/ym_vtx.cpp:586: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(ym_vtx.cpp.o): in function `Binary::InputStream::InputStream(Binary::Container const&)':
/home/pi5/git/chipmachine/external/zxtune/src/binary/input_stream.h:172: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(ym_vtx.cpp.o):/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/ym_vtx.cpp:627: more undefined references to `Binary::View::View(Binary::Data const&)' follow
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(chiptracker.cpp.o): in function `Formats::Chiptune::ChipTracker::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/digital/chiptracker.cpp:470: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(chiptracker.cpp.o): in function `Formats::Chiptune::ChipTracker::Decoder::Decode(Binary::Container const&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/digital/chiptracker.cpp:490: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(digitalmusicmaker.cpp.o): in function `Formats::Chiptune::DigitalMusicMaker::Parse(Binary::Container const&, Formats::Chiptune::DigitalMusicMaker::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/digital/digitalmusicmaker.cpp:621: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(digitalmusicmaker.cpp.o): in function `Formats::Chiptune::DigitalMusicMaker::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/digital/digitalmusicmaker.cpp:586: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(digitalmusicmaker.cpp.o): in function `Formats::Chiptune::DigitalMusicMaker::Decoder::Decode(Binary::Container const&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/digital/digitalmusicmaker.cpp:606: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(digitalstudio.cpp.o): in function `Formats::Chiptune::DigitalStudio::Parse(Binary::Container const&, Formats::Chiptune::Digital::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/digital/digitalstudio.cpp:497: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(digitalstudio.cpp.o): in function `Formats::Chiptune::DigitalStudio::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/digital/digitalstudio.cpp:463: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(digitalstudio.cpp.o): in function `Formats::Chiptune::DigitalStudio::Decoder::Decode(Binary::Container const&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/digital/digitalstudio.cpp:483: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(extremetracker1.cpp.o): in function `Formats::Chiptune::ExtremeTracker1::Parse(Binary::Container const&, Formats::Chiptune::ExtremeTracker1::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/digital/extremetracker1.cpp:656: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(extremetracker1.cpp.o): in function `Formats::Chiptune::ExtremeTracker1::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/digital/extremetracker1.cpp:620: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(extremetracker1.cpp.o): in function `Formats::Chiptune::ExtremeTracker1::Decoder::Decode(Binary::Container const&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/digital/extremetracker1.cpp:640: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(prodigitracker.cpp.o): in function `Formats::Chiptune::ProDigiTracker::Parse(Binary::Container const&, Formats::Chiptune::ProDigiTracker::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/digital/prodigitracker.cpp:560: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(prodigitracker.cpp.o): in function `Formats::Chiptune::ProDigiTracker::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/digital/prodigitracker.cpp:526: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(prodigitracker.cpp.o): in function `Formats::Chiptune::ProDigiTracker::Decoder::Decode(Binary::Container const&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/digital/prodigitracker.cpp:546: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(sampletracker.cpp.o): in function `Formats::Chiptune::SampleTracker::Parse(Binary::Container const&, Formats::Chiptune::Digital::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/digital/sampletracker.cpp:355: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(sampletracker.cpp.o): in function `Formats::Chiptune::SampleTracker::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/digital/sampletracker.cpp:321: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(sampletracker.cpp.o): in function `Formats::Chiptune::SampleTracker::Decoder::Decode(Binary::Container const&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/digital/sampletracker.cpp:341: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(sqdigitaltracker.cpp.o): in function `Formats::Chiptune::SQDigitalTracker::Parse(Binary::Container const&, Formats::Chiptune::SQDigitalTracker::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/digital/sqdigitaltracker.cpp:541: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(sqdigitaltracker.cpp.o): in function `Formats::Chiptune::SQDigitalTracker::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/digital/sqdigitaltracker.cpp:505: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(sqdigitaltracker.cpp.o): in function `Formats::Chiptune::SQDigitalTracker::Decoder::Decode(Binary::Container const&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/digital/sqdigitaltracker.cpp:525: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(ay.cpp.o): in function `Formats::Chiptune::AY::Parse(Binary::Container const&, unsigned long, Formats::Chiptune::AY::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/emulation/ay.cpp:531: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/emulation/ay.cpp:571: undefined reference to `Binary::Crc32(Binary::View, unsigned int)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(ay.cpp.o): in function `Formats::Chiptune::AY::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/emulation/ay.cpp:223: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(ay.cpp.o): in function `Formats::Chiptune::AY::FileBuilder::Result() const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/emulation/ay.cpp:464: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(tfc.cpp.o): in function `Formats::Chiptune::TFC::Parse(Binary::Container const&, Formats::Chiptune::TFC::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/fm/tfc.cpp:277: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(tfc.cpp.o): in function `Formats::Chiptune::TFC::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/fm/tfc.cpp:95: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(tfd.cpp.o): in function `Formats::Chiptune::TFD::Parse(Binary::Container const&, Formats::Chiptune::TFD::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/fm/tfd.cpp:108: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(tfd.cpp.o): in function `Binary::InputStream::InputStream(Binary::Container const&)':
/home/pi5/git/chipmachine/external/zxtune/src/binary/input_stream.h:172: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(tfd.cpp.o): in function `Formats::Chiptune::TFD::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/fm/tfd.cpp:78: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(tfmmusicmaker.cpp.o): in function `Formats::Chiptune::TFMMusicMaker::VersionedDecoder<Formats::Chiptune::TFMMusicMaker::Version13>::Decode(Binary::Container const&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/fm/tfmmusicmaker.cpp:1061: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(tfmmusicmaker.cpp.o): in function `Formats::Chiptune::TFMMusicMaker::VersionedDecoder<Formats::Chiptune::TFMMusicMaker::Version05>::Decode(Binary::Container const&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/fm/tfmmusicmaker.cpp:1061: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(tfmmusicmaker.cpp.o): in function `Formats::Chiptune::TFMMusicMaker::VersionedDecoder<Formats::Chiptune::TFMMusicMaker::Version05>::VersionedDecoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/fm/tfmmusicmaker.cpp:1041: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(tfmmusicmaker.cpp.o): in function `Formats::Chiptune::TFMMusicMaker::VersionedDecoder<Formats::Chiptune::TFMMusicMaker::Version13>::VersionedDecoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/fm/tfmmusicmaker.cpp:1041: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(tfmmusicmaker.cpp.o): in function `Formats::Chiptune::TFMMusicMaker::VersionedDecoder<Formats::Chiptune::TFMMusicMaker::Version13>::Parse(Binary::Container const&, Formats::Chiptune::TFMMusicMaker::Builder&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/fm/tfmmusicmaker.cpp:1073: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/fm/tfmmusicmaker.cpp:1091: undefined reference to `Binary::Crc32(Binary::View, unsigned int)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(tfmmusicmaker.cpp.o): in function `Formats::Chiptune::TFMMusicMaker::VersionedDecoder<Formats::Chiptune::TFMMusicMaker::Version05>::Parse(Binary::Container const&, Formats::Chiptune::TFMMusicMaker::Builder&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/fm/tfmmusicmaker.cpp:1073: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/fm/tfmmusicmaker.cpp:1091: undefined reference to `Binary::Crc32(Binary::View, unsigned int)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(etracker.cpp.o): in function `Formats::Chiptune::ETracker::Parse(Binary::Container const&, Formats::Chiptune::ETracker::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/saa/etracker.cpp:937: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(etracker.cpp.o): in function `Formats::Chiptune::ETracker::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/saa/etracker.cpp:902: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(etracker.cpp.o): in function `Formats::Chiptune::ETracker::Decoder::Decode(Binary::Container const&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/saa/etracker.cpp:923: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/module_players/libmodule_players.a(ayemul.cpp.o): in function `Module::AYEMUL::CreateBeeper(unsigned int, std::shared_ptr<Parameters::Accessor const>)':
/home/pi5/git/chipmachine/external/zxtune/src/module/players/aym/ayemul.cpp:710: undefined reference to `Devices::Beeper::CreateChip(std::unique_ptr<Devices::Beeper::ChipParameters const, std::default_delete<Devices::Beeper::ChipParameters const> >)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/module_players/libmodule_players.a(ayemul.cpp.o): in function `Module::AYEMUL::ModuleData::CreateCPU(std::shared_ptr<Devices::Z80::ChipParameters const>, std::shared_ptr<Devices::Z80::ChipIO>) const':
/home/pi5/git/chipmachine/external/zxtune/src/module/players/aym/ayemul.cpp:479: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/module/players/aym/ayemul.cpp:479: undefined reference to `Devices::Z80::CreateChip(std::shared_ptr<Devices::Z80::ChipParameters const>, Binary::View, std::shared_ptr<Devices::Z80::ChipIO>)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/module/players/aym/ayemul.cpp:479: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/module/players/aym/ayemul.cpp:479: undefined reference to `Devices::Z80::CreateChip(std::shared_ptr<Devices::Z80::ChipParameters const>, Binary::View, std::shared_ptr<Devices::Z80::ChipIO>)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/module_players/libmodule_players.a(aym_parameters.cpp.o): in function `Module::AYM::TSTrackParameters::FreqTable(std::array<unsigned short, 96ul>&) const':
/home/pi5/git/chipmachine/external/zxtune/src/module/players/aym/aym_parameters.cpp:246: undefined reference to `Module::GetFreqTable(std::basic_string_view<char, std::char_traits<char> >, std::array<unsigned short, 96ul>&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/module_players/libmodule_players.a(aym_parameters.cpp.o): in function `Module::AYM::AYTrackParameters::FreqTable(std::array<unsigned short, 96ul>&) const':
/home/pi5/git/chipmachine/external/zxtune/src/module/players/aym/aym_parameters.cpp:206: undefined reference to `Module::GetFreqTable(std::basic_string_view<char, std::char_traits<char> >, std::array<unsigned short, 96ul>&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/module_conversion/libmodule_conversion.a(aym.cpp.o): in function `Module::ConvertAYMFormat(Module::AYM::Holder const&, Module::Conversion::Parameter const&, std::shared_ptr<Parameters::Accessor const> const&)':
/home/pi5/git/chipmachine/external/zxtune/src/module/conversion/aym.cpp:110: undefined reference to `Devices::AYM::CreatePSGDumper(Devices::AYM::DumperParameters const&)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/module/conversion/aym.cpp:117: undefined reference to `Devices::AYM::CreateZX50Dumper(Devices::AYM::DumperParameters const&)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/module/conversion/aym.cpp:124: undefined reference to `Devices::AYM::CreateDebugDumper(Devices::AYM::DumperParameters const&)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/module/conversion/aym.cpp:131: undefined reference to `Devices::AYM::CreateRawStreamDumper(Devices::AYM::DumperParameters const&)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/module/conversion/aym.cpp:138: undefined reference to `Devices::AYM::CreateFYMDumper(std::unique_ptr<Devices::AYM::FYMDumperParameters const, std::default_delete<Devices::AYM::FYMDumperParameters const> >)'
/usr/bin/ld: libplugin_register.a(plugin_register.cpp.o): in function `register_plugins()':
/home/pi5/git/chipmachine/src/plugin_register.cpp:64: undefined reference to `adplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:65: undefined reference to `aoplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:66: undefined reference to `ayflyplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:69: undefined reference to `libvgmplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:70: undefined reference to `gmeplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:71: undefined reference to `gsfplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:72: undefined reference to `heplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:73: undefined reference to `hivelyplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:74: undefined reference to `htplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:75: undefined reference to `mdxplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:76: undefined reference to `mp3plugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:77: undefined reference to `ndsplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:78: undefined reference to `openmptplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:79: undefined reference to `rsnplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:81: undefined reference to `fmpplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:82: undefined reference to `sc68plugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:83: undefined reference to `stsoundplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:84: undefined reference to `tedplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:85: undefined reference to `usfplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:86: undefined reference to `v2plugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:87: undefined reference to `vicepluginbridge_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:88: undefined reference to `ffmpegplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:89: undefined reference to `uadeplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:90: undefined reference to `pxtoneplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:91: undefined reference to `ptkplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:92: undefined reference to `orgplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:93: undefined reference to `sunvoxplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:94: undefined reference to `eupplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:95: undefined reference to `kssplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:96: undefined reference to `quartetplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:97: undefined reference to `wsrplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:99: undefined reference to `pokeynoiseplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:100: undefined reference to `bbsongplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:101: undefined reference to `soundsmithplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:102: undefined reference to `ixsplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:104: undefined reference to `cocoplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:105: undefined reference to `mgtplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:106: undefined reference to `medplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:107: undefined reference to `sbstudioplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:108: undefined reference to `maxtraxplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:109: undefined reference to `sksplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:110: undefined reference to `nedplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:111: undefined reference to `sccmusixxplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:112: undefined reference to `copplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:113: undefined reference to `playerproplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:114: undefined reference to `jxsplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:115: undefined reference to `monotoneplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:116: undefined reference to `mikmodplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:117: undefined reference to `famitrackerplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:118: undefined reference to `goattrackerplugin_register'
/usr/bin/ld: /home/pi5/git/chipmachine/src/plugin_register.cpp:119: undefined reference to `dmfplugin_register'
/usr/bin/ld: plugins/zxtuneplugin/zxt/core/libcore.a(service.cpp.o): in function `ZXTune::ServiceImpl::OpenLocation(std::shared_ptr<Binary::Container const>, std::basic_string_view<char, std::char_traits<char> >) const':
/home/pi5/git/chipmachine/external/zxtune/src/core/src/service.cpp:226: undefined reference to `Analysis::ParsePath(std::basic_string_view<char, std::char_traits<char> >, char)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/core/libcore.a(enumerator.cpp.o): in function `ZXTune::AllPlugins::AllPlugins()':
/home/pi5/git/chipmachine/external/zxtune/src/core/plugins/enumerator.cpp:60: undefined reference to `ZXTune::RegisterArchivePlugins(ZXTune::ArchivePluginsRegistrator&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/core/libcore.a(location_open.cpp.o): in function `ZXTune::CreateEmptyPath()':
/home/pi5/git/chipmachine/external/zxtune/src/core/src/location_open.cpp:22: undefined reference to `Analysis::ParsePath(std::basic_string_view<char, std::char_traits<char> >, char)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/core/libcore.a(location_open.cpp.o): in function `ZXTune::CreateEmptyPluginsChain()':
/home/pi5/git/chipmachine/external/zxtune/src/core/src/location_open.cpp:28: undefined reference to `Analysis::ParsePath(std::basic_string_view<char, std::char_traits<char> >, char)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/core/libcore.a(location_open.cpp.o): in function `ZXTune::GeneratedLocation::GeneratedLocation(std::shared_ptr<Binary::Container const>, std::basic_string_view<char, std::char_traits<char> >, std::basic_string_view<char, std::char_traits<char> >)':
/home/pi5/git/chipmachine/external/zxtune/src/core/src/location_open.cpp:63: undefined reference to `Analysis::ParsePath(std::basic_string_view<char, std::char_traits<char> >, char)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/core/src/location_open.cpp:64: undefined reference to `Analysis::ParsePath(std::basic_string_view<char, std::char_traits<char> >, char)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/core_plugins_players/libcore_plugins_players.a(plugin.cpp.o): in function `ZXTune::CommonPlayerPlugin::TryOpen(Parameters::Accessor const&, Binary::Container const&, std::shared_ptr<Parameters::Container>) const':
/home/pi5/git/chipmachine/external/zxtune/src/core/plugins/players/plugin.cpp:79: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/core_plugins_players/libcore_plugins_players.a(plugin.cpp.o): in function `ZXTune::CommonPlayerPlugin::Detect(Parameters::Accessor const&, std::shared_ptr<ZXTune::DataLocation const>, Module::DetectCallback&) const':
/home/pi5/git/chipmachine/external/zxtune/src/core/plugins/players/plugin.cpp:60: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/core/plugins/players/plugin.cpp:70: undefined reference to `Analysis::CreateMatchedResult(unsigned long)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/core/plugins/players/plugin.cpp:73: undefined reference to `ZXTune::CreateUnmatchedResult(Parameters::Accessor const&, std::shared_ptr<Binary::Format const>, std::shared_ptr<Binary::Container const>)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/core_plugins_players/libcore_plugins_players.a(plugin.cpp.o): in function `ZXTune::ExternalParsingPlayerPlugin::Detect(Parameters::Accessor const&, std::shared_ptr<ZXTune::DataLocation const>, Module::DetectCallback&) const':
/home/pi5/git/chipmachine/external/zxtune/src/core/plugins/players/plugin.cpp:149: undefined reference to `Analysis::CreateMatchedResult(unsigned long)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/core/plugins/players/plugin.cpp:152: undefined reference to `ZXTune::CreateUnmatchedResult(Parameters::Accessor const&, std::shared_ptr<Binary::Format const>, std::shared_ptr<Binary::Container const>)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(psg.cpp.o): in function `Formats::Chiptune::PSG::Parse(Binary::Container const&, Formats::Chiptune::PSG::Builder&)':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/psg.cpp:107: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(psg.cpp.o): in function `Formats::Chiptune::PSG::Decoder::Decoder()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/psg.cpp:77: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(turbosound.cpp.o): in function `Formats::Chiptune::TurboSound::FooterFormat::FooterFormat()':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/turbosound.cpp:117: undefined reference to `Binary::CreateFormat(std::basic_string_view<char, std::char_traits<char> >)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(turbosound.cpp.o): in function `Formats::Chiptune::TurboSound::DecoderImpl::Parse(Binary::Container const&, Formats::Chiptune::TurboSound::Builder&) const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/aym/turbosound.cpp:171: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(container.cpp.o): in function `Formats::Chiptune::BaseDelegateContainer::Checksum() const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/container.cpp:33: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/container.cpp:33: undefined reference to `Binary::Crc32(Binary::View, unsigned int)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(container.cpp.o): in function `Formats::Chiptune::CachingCrcContainer::Checksum() const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/container.cpp:85: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/container.cpp:85: undefined reference to `Binary::Crc32(Binary::View, unsigned int)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(container.cpp.o): in function `Formats::Chiptune::CalculatingCrcContainer::FixedChecksum() const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/container.cpp:65: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/container.cpp:65: undefined reference to `Binary::Crc32(Binary::View, unsigned int)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/container.cpp:65: undefined reference to `Binary::Crc32(Binary::View, unsigned int)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_chiptune/libformats_chiptune.a(container.cpp.o): in function `Formats::Chiptune::CachingCrcContainer::Checksum() const':
/home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/container.cpp:85: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/formats/chiptune/container.cpp:85: undefined reference to `Binary::Crc32(Binary::View, unsigned int)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/formats_packed/libformats_packed.a(lha_file.cpp.o): in function `Binary::InputStream::InputStream(Binary::Container const&)':
/home/pi5/git/chipmachine/external/zxtune/src/binary/input_stream.h:172: undefined reference to `Binary::View::View(Binary::Data const&)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/module_players/libmodule_players.a(aym_base.cpp.o): in function `Module::AYM::CreateChip(unsigned int, std::shared_ptr<Parameters::Accessor const>)':
/home/pi5/git/chipmachine/external/zxtune/src/module/players/aym/aym_base.cpp:155: undefined reference to `Devices::AYM::CreateChip(std::unique_ptr<Devices::AYM::ChipParameters const, std::default_delete<Devices::AYM::ChipParameters const> >, std::shared_ptr<Sound::FixedChannelsMixer<3u> const>)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/module_players/libmodule_players.a(turbosound.cpp.o): in function `Module::TurboSound::CreateChip(unsigned int, std::shared_ptr<Parameters::Accessor const>)':
/home/pi5/git/chipmachine/external/zxtune/src/module/players/aym/turbosound.cpp:377: undefined reference to `Devices::TurboSound::CreateChip(std::unique_ptr<Devices::AYM::ChipParameters const, std::default_delete<Devices::AYM::ChipParameters const> >, std::shared_ptr<Sound::FixedChannelsMixer<3u> const>)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/module_players/libmodule_players.a(chiptracker.cpp.o): in function `Module::ChipTracker::DataBuilder::SetSample(unsigned int, unsigned long, Binary::View)':
/home/pi5/git/chipmachine/external/zxtune/src/module/players/dac/chiptracker.cpp:84: undefined reference to `Devices::DAC::CreateU8Sample(Binary::View, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/module_players/libmodule_players.a(dac_simple.cpp.o): in function `Module::DAC::SimpleDataBuilderImpl::SetSample(unsigned int, unsigned long, Binary::View, bool)':
/home/pi5/git/chipmachine/external/zxtune/src/module/players/dac/dac_simple.cpp:62: undefined reference to `Devices::DAC::CreateU4Sample(Binary::View, unsigned long)'
/usr/bin/ld: /home/pi5/git/chipmachine/external/zxtune/src/module/players/dac/dac_simple.cpp:62: undefined reference to `Devices::DAC::CreateU8Sample(Binary::View, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/module_players/libmodule_players.a(digitalmusicmaker.cpp.o): in function `Module::DigitalMusicMaker::DataBuilder::SetSample(unsigned int, unsigned long, Binary::View)':
/home/pi5/git/chipmachine/external/zxtune/src/module/players/dac/digitalmusicmaker.cpp:224: undefined reference to `Devices::DAC::CreateU4PackedSample(Binary::View, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/module_players/libmodule_players.a(extremetracker1.cpp.o): in function `Module::ExtremeTracker1::DataBuilder::SetSample(unsigned int, unsigned long, Binary::View)':
/home/pi5/git/chipmachine/external/zxtune/src/module/players/dac/extremetracker1.cpp:76: undefined reference to `Devices::DAC::CreateU8Sample(Binary::View, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/module_players/libmodule_players.a(prodigitracker.cpp.o): in function `Module::ProDigiTracker::DataBuilder::SetSample(unsigned int, unsigned long, Binary::View)':
/home/pi5/git/chipmachine/external/zxtune/src/module/players/dac/prodigitracker.cpp:73: undefined reference to `Devices::DAC::CreateU8Sample(Binary::View, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/module_players/libmodule_players.a(sqdigitaltracker.cpp.o): in function `Module::SQDigitalTracker::DataBuilder::SetSample(unsigned int, unsigned long, Binary::View)':
/home/pi5/git/chipmachine/external/zxtune/src/module/players/dac/sqdigitaltracker.cpp:69: undefined reference to `Devices::DAC::CreateU8Sample(Binary::View, unsigned long)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/module_players/libmodule_players.a(saa_base.cpp.o): in function `Module::SAAHolder::CreateRenderer(unsigned int, std::shared_ptr<Parameters::Accessor const>) const':
/home/pi5/git/chipmachine/external/zxtune/src/module/players/saa/saa_base.cpp:149: undefined reference to `Devices::SAA::CreateChip(std::unique_ptr<Devices::SAA::ChipParameters const, std::default_delete<Devices::SAA::ChipParameters const> >)'
/usr/bin/ld: plugins/zxtuneplugin/zxt/parameters/libparameters.a(container.cpp.o): in function `Parameters::StorageContainer::TransientMap<std::shared_ptr<Binary::Data const> >::Visit(Parameters::Visitor&) const':
/home/pi5/git/chipmachine/external/zxtune/src/parameters/src/container.cpp:133: undefined reference to `Binary::View::View(Binary::Data const&)'
collect2: error: ld returned 1 exit status
ninja: build stopped: subcommand failed.
```
