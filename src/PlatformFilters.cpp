#include "PlatformFilters.h"

// The format-byte constants (AMIGA, SID, NES, ...) live in the Formats enum in
// MusicDatabase.h (namespace chipmachine).
#include "MusicDatabase.h"

namespace chipmachine {

const std::vector<FilterOption> platformFilterOptions = {
    { "[no filter, search all]", {} },
    { "Amiga", { AMIGA, PROTRACKER, SOUNDTRACKER, UADE, TRACKER } },
    // Children in chronological order (VCS 1977 first), not by corpus size.
    // "Atari" is the house logo (Atari.png) for the group row itself.
    { "Atari", {}, {
        { "Atari VCS Console", { ATARIVCS } },
        { "Atari 8bit Computers (XL/XE)", { POKEY } },
        { "Atari 7800 Console", { ATARI7800 } },
        { "Atari ST/STE/TT", { ATARI } },
        { "Atari Falcon", { ATARIFALCON } },
        { "Atari Lynx", { ATARILYNX } },
        { "Atari Jaguar", { ATARIJAGUAR } },
    }, "Atari" },
    { "Commodore 64 (SID)", { SID, STR } },
    { "Commodore 16/116/+4 (TED)", { PRG } },
    { "Commodore VIC-20", { VIC20 } },
    { "ZX Spectrum 16K/48K (Beeper)", { ZXBEEPER } },
    { "ZX Spectrum 128K (AY)", { ZXAY, SPECTRUM } },
    { "IBM PC (Trackers/DAWs)", { FASTTRACKER, IMPULSETRACKER, SCREAMTRACKER, PCTRACKER, PC } },
    { "IBM PC (AdLib/OPL)", { ADPLUG } },
    { "MSX", { MSX } },
    { "Amstrad CPC", { AMSTRAD } },
    { "Sam Coupe", { SAMCOUPE } },
    { "Acorn Archimedes", { ACORN } },
    { "Apple", {}, {
        { "Original Apple Mac", { APPLEMAC } },
        { "Apple IIGS", { APPLE } },
        { "Mac OS", { MACOS } },
        { "iOS", { IOS } },
    }, "Apple" },
    { "Sony", {}, {
        { "Sony PlayStation 1/2", { PLAYSTATION, PLAYSTATION2 } },
        { "Sony PlayStation 3", { PS3 } },
        { "Sony PSP", { PSP } },
    }, "Sony" },
    { "Nintendo", {}, {
        { "Nintendo NES", { NES } },
        { "Nintendo SNES", { SNES } },
        { "Nintendo GameBoy/GBA", { GAMEBOY, GBA } },
        { "Nintendo 64", { NINTENDO64 } },
        { "Nintendo DS", { NDS } },
        { "Nintendo 3DS", { N3DS } },
        { "Nintendo GameCube", { GAMECUBE } },
        { "Nintendo Wii", { WII } },
        { "Nintendo Virtual Boy", { VIRTUALBOY } },
    }, "Nintendo" },
    { "Microsoft", {}, {
        { "Microsoft Xbox", { XBOX } },
        { "Microsoft Xbox 360", { XBOX360 } },
    }, "Microsoft" },
    { "Sega", {}, {
        { "Sega 8bit", { SEGAMS } },
        { "Sega 16bit/32X/Saturn", { SEGA, MEGADRIVE, SATURN } },
        { "Sega Dreamcast", { DREAMCAST } },
    }, "Sega" },
    { "Japanese Computers", {}, {
        { "PC-98", { JPFM } },
        { "X68000", { JPX68000 } },
        { "FM Towns", { JPFMTOWNS } },
    }, "Japanese Computers" },
    { "PC Engine/TurboGrafx-16", { HES } },
    { "WonderSwan", { WONDERSWAN } },
    { "Neo Geo Pocket", { NEOGEOPOCKET } },
    { "Arcade", { ARCADE } },
    // "Other" is too generic a byte-slug to outrank a specific ext logo
    // elsewhere (see platformSlugForByte's specificPlatform check), so this
    // group-less leaf row still needs its own explicit logo, same as the
    // three rows below.
    { "Other Platforms", { OTHER }, {}, "Other" },
    // Rendered audio with no hardware identity: BotB allgear/remix/wildchip/
    // fakebit compos, standalone demoscene MP3s, untagged chipmusic.org tracks.
    // Not "unclassified" -- the source itself declares no platform.
    // MP3/OGG/Radio/Podcast are "nonHardware" in platformSlugForByte, so their
    // byte resolves to no slug at all -- these rows need an explicit `logo` or
    // the TAB filter screen shows nothing when they're highlighted.
    { "MP3/OGG (no platform)", { MP3, OGG }, {}, "MP3-OGG" },
    // No "YouTube (no platform)" row: a capture whose pouet tag names no
    // hardware (Animation/Video, mIRC, Alambik, Wild, JavaScript, ...) resolves
    // to OTHER, so it lands in the Other Platforms drill alongside the
    // "Youtube (Wild)" / "Youtube (JavaScript)" groups that already live there.
    // The YOUTUBE byte is consequently never produced (see formatToByte).
    { "Podcasts", { PODCAST }, {}, "Podcasts" },
    { "Radio Stations", { RADIO }, {}, "Radio" }
};

} // namespace chipmachine
