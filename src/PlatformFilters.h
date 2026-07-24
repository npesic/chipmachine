#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace chipmachine {

// The platform (TAB) filter tree: a curated grouping of the engine's format
// bytes into human platforms ("Amiga", "Commodore 64 (SID)", "Nintendo" -> NES/
// SNES/...). This is pure data with no GUI dependency, so it lives here rather
// than in ChipMachine (the grappix front end) -- both the GUI and the text-mode
// front end (via ChipInterface) drive the same list, so neither owns it.
struct FilterOption {
    std::string name;
    std::vector<uint8_t> matchedFormats;
    // A grouping entry (e.g. "Nintendo", "Sony"): selecting it does not apply a
    // filter but drills into a 2nd-level list of these child options, which
    // themselves apply the filter. Empty for ordinary (leaf) entries.
    std::vector<FilterOption> children;
    // House logo for a GROUP row, as the basename of an image in
    // data/misc/platformscreenshots (e.g. "Atari" -> Atari.png). A group has no
    // format byte of its own, so by default it borrows its first child's logo --
    // which makes the row look like that one machine. Set this to show the family
    // mark instead: on the platform screen when the group row is highlighted, and
    // on the splash.
    // Also used by ordinary (leaf) entries whose format byte resolves to no
    // platform-shot slug at all (MP3/OGG/Radio/Podcasts/Other Platforms --
    // platformSlugForByte's "nonHardware" bytes plus the too-generic "Other"),
    // since those have neither a byte-slug fallback nor a child to borrow from.
    // Give such a row its own logo here or it shows nothing when highlighted on
    // the TAB filter screen (updateFilterLogo). Remember to also add the
    // basename to splashExcludePlatforms if it isn't real hardware.
    // The image is OPTIONAL -- a group falls back to the borrowed child logo
    // rather than failing -- but it IS reported at startup like the other logo
    // gaps, so it doesn't stay un-drawn just because nothing breaks.
    std::string logo;
};

// The top-level platform list. Index 0 is the "[no filter, search all]" entry.
extern const std::vector<FilterOption> platformFilterOptions;

} // namespace chipmachine
