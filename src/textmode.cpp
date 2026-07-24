#include "modutils.h"

#include "ChipInterface.h"
#include "TextListView.h"

#include <bbsutils/ansiconsole.h>
#include <bbsutils/editor.h>
#include <bbsutils/petsciiconsole.h>
#include <bbsutils/telnetserver.h>

#include <sol.hpp>

#include <cctype>
#include <map>

void initYoutube(sol::state&);

namespace chipmachine {

// Flatten a possibly multi-line song comment into a single ticker line: turn
// newlines/tabs into spaces, collapse runs of whitespace, and trim the ends.
// (The GUI's compressWhitespace lives in a GUI-only TU, so cm reimplements it.)
static std::string compressWs(const std::string& in)
{
    std::string out;
    out.reserve(in.size());
    bool prevSpace = false;
    for (char c : in) {
        if (c == '\n' || c == '\r' || c == '\t') c = ' ';
        bool sp = (c == ' ');
        if (sp && prevSpace) continue;
        out += c;
        prevSpace = sp;
    }
    auto a = out.find_first_not_of(' ');
    if (a == std::string::npos) return "";
    auto b = out.find_last_not_of(' ');
    return out.substr(a, b - a + 1);
}

void runConsole(std::shared_ptr<bbs::Console> console, ChipInterface& ci)
{
    using namespace bbs;
    int bgColor = Console::DARK_GREY;

    auto iquery = ci.createQuery();

    console->clear();
    console->flush();
    console->setColor(Console::WHITE);
    console->put(0, 0, "#", Console::WHITE);
    console->moveCursor(1, 0);
    LineEditor searchField(*console);
    int width = console->getWidth();
    int height = console->getHeight();
    int currentTune = 0;
    console->fill(bgColor, 0, 1, width, 1);
    console->moveCursor(0, 2);
    console->setColor(Console::WHITE, Console::BLACK);
    // The results/filter lists are one row shorter than the window's usable
    // height leaves room for: they give up row (height-5) to the song-message
    // scroller (drawn just above the TITLE/AUTHOR/FORMAT block).
    TextListView listView(*console, height - 7, width);

    // Filter overlay: TAB cycles through the same filter dimensions the GUI
    // exposes -- Formats, Databases, Plugins -- each drawn as a selectable list
    // over the search-results region. filterView shares that region with
    // listView; only one is shown at a time (filterScreen picks which). The
    // three DB filters are mutually exclusive (they share one slot in the
    // engine), so activeFilterLabel names whichever is currently applied.
    TextListView filterView(*console, height - 7, width);
    enum { FS_SEARCH = 0, FS_PLATFORM, FS_FORMAT, FS_DATABASE, FS_PLUGIN, FS_COUNT };
    int filterScreen = FS_SEARCH;
    std::string activeFilterLabel;
    // The platform tree is static, so flatten it once for the Platforms screen.
    auto platformEntries = ci.platformFilterEntries();

    SongInfo info{};

    // Song-message scroller (one line, just above the now-playing block). Many
    // module files carry an embedded comment/greeting; the GUI ping-pongs it in
    // a graphical scroller, here it marquees across one text row.
    int scrollRow = height - 5;
    std::string scrollText;
    int scrollPos = 0;
    // Marquee: the text starts fully off the right edge (blank line) and slides
    // left. scrollPos is how far it has moved; the text's left edge sits at
    // column (width - scrollPos). Once it has fully exited on the left the line
    // is blank again and it re-enters from the right (see tickScroll's wrap).
    auto drawScrollLine = [&]() {
        console->fill(bgColor, 0, scrollRow, width, 1);
        if (scrollText.empty()) return;
        int textLen = (int)scrollText.size();
        int x = width - scrollPos; // left edge of the text on screen
        std::string line(width, ' ');
        for (int c = 0; c < width; c++) {
            int idx = c - x;
            if (idx >= 0 && idx < textLen) line[c] = scrollText[idx];
        }
        console->put(0, scrollRow, line, Console::LIGHT_GREEN, bgColor);
    };

    auto holder = ci.onMeta([&](const SongInfo& si) {
        info = si;
        currentTune = si.starttune;
        LOGD("Got new info %s %s", info.title, info.composer);
        console->fill(bgColor, 0, height - 4, width, 4);
        console->put(0, height - 4, utils::format(" TITLE: %s", si.title),
                     Console::CURRENT_COLOR, bgColor);
        console->put(0, height - 3, utils::format("AUTHOR: %s", si.composer),
                     Console::CURRENT_COLOR, bgColor);
        console->put(0, height - 2, utils::format("FORMAT: %s", si.format),
                     Console::CURRENT_COLOR, bgColor);
        // Rebuild the scroll message for the new song: prefer the DB INFO field,
        // else the module's embedded "message" comment -- same source order the
        // GUI scroller uses.
        std::string msg = (si.metadata.size() > SongInfo::INFO)
                              ? si.metadata[SongInfo::INFO]
                              : std::string();
        if (msg.empty()) msg = ci.getMeta("message");
        std::string s = compressWs(msg);
        // Always append the format/description section (same as the GUI), so the
        // ticker has content even when the tune carries no embedded message.
        std::string fmt = ci.formatDescription(si);
        if (!fmt.empty()) s = s.empty() ? fmt : (s + "  ...  " + fmt);
        scrollText = s;
        scrollPos = 0; // restart off the right edge for the new song
        drawScrollLine();
        console->flush();
    });

    listView.setCallback([&](Console& c, int index, bool marked) {
        static const std::map<uint32_t, int> colors = {
            { NOT_SET, Console::PURPLE },  { PLAYLIST, Console::GREY },
            { OTHER, Console::RED },     { SID, Console::BROWN },
            { ZXBEEPER, Console::PINK },   { ZXAY, Console::PURPLE },   { SPECTRUM, Console::PURPLE },
            { MSX, Console::BLUE },        { AMSTRAD, Console::LIGHT_GREY },
            { ACORN, Console::WHITE },     { SAMCOUPE, Console::PINK },
            { ATARI, Console::YELLOW },    { POKEY, Console::ORANGE },
            { ATARIVCS, Console::BROWN },  { ATARI7800, Console::ORANGE },
            { ATARIFALCON, Console::LIGHT_GREEN },
            { ATARILYNX, Console::YELLOW },
            { ATARIJAGUAR, Console::BROWN },
            { MP3, Console::GREEN },
            { APPLE, Console::CYAN },
            { M3U, Console::LIGHT_GREEN }, { RADIO, Console::ORANGE },
            { YOUTUBE, Console::RED },
            { PC, Console::CYAN },         { AMIGA, Console::LIGHT_BLUE },
            { JPFM, Console::PINK },       { PCTRACKER, Console::LIGHT_GREY },
            { JPX68000, Console::ORANGE }, { JPFMTOWNS, Console::PURPLE },
            { VIRTUALBOY, Console::RED },
            { 255, Console::ORANGE }
        };

        int color = 0;
        auto parts = utils::split(iquery->getResult(index), "\t");
        std::string text;
        int f = atoi(parts[3]) & 0xff;
        if (f == PLAYLIST) {
            if (*parts[1] == 0)
                text = utils::format("<%s>", parts[0]);
            else
                text = utils::format("<%s / %s>", parts[0], parts[1]);
        } else
            text = utils::format("%s / %s", parts[0], parts[1]);

        auto it = --colors.upper_bound(f);
        color = it->second;
        if (marked)
            c.put(text, Console::WHITE, color);
        else
            c.put(text, color, Console::CURRENT_COLOR);
    });
    // Row 0 of every filter screen is the "[ no filter ]" reset entry; group g
    // sits at row g+1. Renders the group name and its song count for whichever
    // screen is active.
    filterView.setCallback([&](Console& c, int index, bool marked) {
        std::string text;
        bool isGroup = false;
        if (index == 0) {
            text = "[ no filter ]";
        } else if (filterScreen == FS_PLATFORM) {
            if (index - 1 < (int)platformEntries.size()) {
                auto const& p = platformEntries[index - 1];
                text = (p.child ? "    " : "") + p.label;
                isGroup = !p.child; // top-level rows (leaves + group heads)
            }
        } else if (filterScreen == FS_FORMAT) {
            auto const& g = ci.extensionGroups();
            if (index - 1 < (int)g.size()) {
                auto const& e = g[index - 1];
                std::string ext = e.ext;
                for (auto& ch : ext)
                    ch = static_cast<char>(::toupper((unsigned char)ch));
                text = "." + ext;
                if (!e.name.empty()) text += "  " + e.name;
                text += "  (" + std::to_string(e.count) + ")";
            }
        } else if (filterScreen == FS_DATABASE) {
            auto const& g = ci.databaseGroups();
            if (index - 1 < (int)g.size()) {
                auto const& d = g[index - 1];
                text = (d.name.empty() ? d.id : d.name) + "  (" +
                       std::to_string(d.count) + ")";
            }
        } else if (filterScreen == FS_PLUGIN) {
            auto const& g = ci.pluginGroups();
            if (index - 1 < (int)g.size()) {
                auto const& p = g[index - 1];
                text = p.name + "  (" + std::to_string(p.count) + ")";
            }
        }
        if (marked)
            c.put(text, Console::WHITE, Console::BLUE);
        else
            c.put(text, isGroup ? Console::WHITE : Console::LIGHT_GREY,
                  Console::CURRENT_COLOR);
    });

    std::string lastLine;
    int olds = -1;

    auto getSelectedSong = [&]() -> SongInfo {
        auto i = listView.marked();
        return ci.getSongInfo(iquery->getIndex(i));
    };

    int last_marked = -1;

    // ---- Filter-screen helpers (TAB) ------------------------------------
    auto filterRowCount = [&]() -> int {
        switch (filterScreen) {
        case FS_PLATFORM: return 1 + (int)platformEntries.size();
        case FS_FORMAT: return 1 + (int)ci.extensionGroups().size();
        case FS_DATABASE: return 1 + (int)ci.databaseGroups().size();
        case FS_PLUGIN: return 1 + (int)ci.pluginGroups().size();
        default: return 0;
        }
    };
    auto screenTitle = [&]() -> std::string {
        switch (filterScreen) {
        case FS_PLATFORM: return "PLATFORM FILTER";
        case FS_FORMAT: return "FORMAT FILTER";
        case FS_DATABASE: return "DATABASE FILTER";
        case FS_PLUGIN: return "PLUGIN FILTER";
        default: return "";
        }
    };
    // The status bar (row 1) shows the active filter on the search screen, and
    // the current screen's key hints while browsing a filter list.
    auto drawStatusBar = [&]() {
        console->fill(bgColor, 0, 1, width, 1);
        std::string s;
        if (filterScreen != FS_SEARCH)
            s = screenTitle() + "    ENTER: apply    TAB: next    ESC: cancel";
        else if (!activeFilterLabel.empty())
            s = "FILTER: " + activeFilterLabel + "    (TAB to change)";
        else
            s = "TAB: filter search";
        console->put(0, 1, s, Console::CURRENT_COLOR, bgColor);
    };
    auto enterFilterScreen = [&]() {
        filterView.setLength(filterRowCount());
        filterView.select(0);
        drawStatusBar();
        console->fill(Console::BLACK, 0, 2, width, height - 7);
        filterView.refresh();
    };
    auto enterSearchScreen = [&]() {
        drawStatusBar();
        console->fill(Console::BLACK, 0, 2, width, height - 7);
        listView.refresh();
        console->fill(Console::BLACK, 0, 0, width, 1);
        console->put(0, 0, "#", Console::WHITE);
        searchField.refresh();
    };
    // ENTER on a filter screen: apply the highlighted group (row 0 clears), then
    // re-run the current search under the new filter.
    auto applyFilter = [&]() {
        int idx = filterView.marked();
        activeFilterLabel = "";
        if (idx <= 0) {
            ci.clearSearchFilter();
        } else if (filterScreen == FS_PLATFORM) {
            if (idx - 1 < (int)platformEntries.size()) {
                ci.setFormatFilter(platformEntries[idx - 1].formats);
                activeFilterLabel = platformEntries[idx - 1].label;
            }
        } else if (filterScreen == FS_FORMAT) {
            auto const& g = ci.extensionGroups();
            if (idx - 1 < (int)g.size()) {
                ci.setExtensionFilter(idx - 1);
                std::string ext = g[idx - 1].ext;
                for (auto& ch : ext)
                    ch = static_cast<char>(::toupper((unsigned char)ch));
                activeFilterLabel = "." + ext;
            }
        } else if (filterScreen == FS_DATABASE) {
            auto const& g = ci.databaseGroups();
            if (idx - 1 < (int)g.size()) {
                ci.setDatabaseFilter(g[idx - 1].rowid);
                activeFilterLabel =
                    g[idx - 1].name.empty() ? g[idx - 1].id : g[idx - 1].name;
            }
        } else if (filterScreen == FS_PLUGIN) {
            auto const& g = ci.pluginGroups();
            if (idx - 1 < (int)g.size()) {
                ci.setPluginFilter(idx - 1);
                activeFilterLabel = g[idx - 1].name;
            }
        }
        iquery->invalidate();
        auto line = searchField.getResult();
        iquery->setString(line);
        listView.setLength(iquery->numHits());
        lastLine = line;
        filterScreen = FS_SEARCH;
    };

    // Advance the message marquee one step and redraw it. Returns whether it
    // drew anything (so the caller can decide to flush).
    auto tickScroll = [&]() -> bool {
        if (scrollText.empty()) return false;
        // Travel from "text just off the right" (scrollPos 0) to "text fully off
        // the left" (scrollPos width+textLen), then wrap back to the right.
        int span = width + (int)scrollText.size();
        scrollPos = (scrollPos + 1) % span;
        drawScrollLine();
        return true;
    };

    drawStatusBar();
    console->flush();

    while (true) {
        int k = console->getKey(100);
        bool doFlush = false;
        if (k == 3) {
            console->clear();
            console->flush();
            break;
        }

        // TAB cycles the filter screens: search -> Format -> Database -> Plugin
        // -> search. A raw Tab arrives as ASCII 9 from the ANSI console
        // (Console::KEY_TAB is the parsed constant), so accept either.
        if (k == Console::KEY_TAB || k == 9) {
            filterScreen = (filterScreen + 1) % FS_COUNT;
            if (filterScreen == FS_SEARCH)
                enterSearchScreen();
            else
                enterFilterScreen();
            console->flush(true);
            continue;
        }

        // While a filter screen is up, keys drive its list; the search field is
        // untouched. ESC backs out without changing the filter, ENTER applies.
        if (filterScreen != FS_SEARCH) {
            if (k == Console::KEY_ESCAPE) {
                filterScreen = FS_SEARCH;
                enterSearchScreen();
            } else if (k == Console::KEY_ENTER) {
                applyFilter();
                enterSearchScreen();
            } else if (k != Console::KEY_TIMEOUT) {
                if (filterView.putKey(k)) filterView.refresh();
            } else {
                ci.update();
                tickScroll();
            }
            console->flush(true);
            continue;
        }

        if (k == Console::KEY_F1) {
            ci.pause(ci.playing());
        } else if (k == Console::KEY_F3) {
            ci.nextSong();
        } else if (k == Console::KEY_F2) {
            if (iquery->numHits() > 0) {
                ci.addSong(getSelectedSong());
                if (listView.putKey(Console::KEY_DOWN)) {
                    listView.refresh();
                    doFlush = true;
                }
            }
        } else if (k == Console::KEY_ENTER) {
            if (iquery->numHits() > 0) {
                ci.play(getSelectedSong());
                currentTune = 0;
                olds = -1;
            }
        } else if (k == Console::KEY_RIGHT) {
            if (currentTune < info.numtunes - 1) ci.setTune(++currentTune);
            olds = -1;
        } else if (k == Console::KEY_LEFT) {
            if (currentTune > 0) ci.setTune(--currentTune);
            olds = -1;
        } else if (k != Console::KEY_TIMEOUT) {
            bool sfr = false;

            bool lvr = listView.putKey(k);
            if (searchField.putKey(k)) {
                sfr = true;
                auto line = searchField.getResult();
                if (line != lastLine) {
                    iquery->setString(line);
                    listView.setLength(iquery->numHits());
                    lastLine = line;
                    lvr = true;
                }
            }
            if (lvr) listView.refresh();
            if (sfr) {
                console->fill(Console::BLACK, 0, 0, width, 1);
                console->put(0, 0, "#", Console::WHITE);
                searchField.refresh();
            }
            if (sfr || lvr) doFlush = true;
            int m = listView.marked();
            if (!sfr && m >= 0 && iquery->numHits() > 0 && m != last_marked) {
                auto song = getSelectedSong();
                auto ext = getTypeFromName(song.path);
                bool isoffline = ci.getRemoteLoader().isOffline(song.path);
                console->fill(Console::BLACK, 0, 0, width, 1);
                console->put(0, 0,
                             utils::format("Format: %s (%s)%s", song.format,
                                           ext, isoffline ? "*" : ""),
                             Console::YELLOW);
                last_marked = m;
                doFlush = true;
            }
        } else {
            ci.update();
            if (tickScroll()) doFlush = true;
            int s = ci.seconds();
            if (s != olds) {
                auto state = ci.playing() ? "PLAYING" : " PAUSED";
                console->put(0, height - 1,
                             utils::format("%s %02d:%02d [%02d/%02d]", state,
                                           s / 60, s % 60, currentTune + 1,
                                           info.numtunes),
                             Console::CURRENT_COLOR, bgColor);
                doFlush = true;
                olds = s;
            }
        }
        if (doFlush) console->flush(true);
    }
}

} // namespace chipmachine
