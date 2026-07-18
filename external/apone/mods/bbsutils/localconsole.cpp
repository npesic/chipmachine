#include "localconsole.h"
#include "ansiconsole.h"

#ifdef _WIN32
#include <windows.h>

// These VT console-mode flags require a Windows 10+ SDK; define them if the
// MinGW headers in use predate that, so the backend builds either way.
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
#ifndef DISABLE_NEWLINE_AUTO_RETURN
#define DISABLE_NEWLINE_AUTO_RETURN 0x0008
#endif
#ifndef ENABLE_VIRTUAL_TERMINAL_INPUT
#define ENABLE_VIRTUAL_TERMINAL_INPUT 0x0200
#endif
#endif

namespace bbs {

#ifndef _WIN32

// ---------------------------------------------------------------------------
// POSIX (termios) local terminal
// ---------------------------------------------------------------------------

void LocalTerminal::open() {
    struct termios new_term_attr;
    // set the terminal to raw mode
    LOGD("Setting RAW mode");
    if(tcgetattr(fileno(stdin), &orig_term_attr) < 0)
        LOGD("FAIL");
    memcpy(&new_term_attr, &orig_term_attr, sizeof(struct termios));
    new_term_attr.c_lflag &= ~(ECHO|ICANON);
    new_term_attr.c_cc[VTIME] = 0;
    new_term_attr.c_cc[VMIN] = 0;
    if(tcsetattr(fileno(stdin), TCSANOW, &new_term_attr) < 0)
        LOGD("FAIL");

    if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) < 0)
        LOGD("IOCTL FAIL");

    setvbuf(stdout, NULL, _IONBF, 0);
}

int LocalTerminal::getWidth() const {
    return ws.ws_col;
}

int LocalTerminal::getHeight() const {
    return ws.ws_row;
}

void LocalTerminal::close() {
    LOGD("Restoring terminal");
    tcsetattr(fileno(stdin), TCSANOW, &orig_term_attr);
}

int LocalTerminal::write(const std::vector<Char> &source, int len) {
    return ::write(fileno(stdout), &source[0], len);
}

int LocalTerminal::read(std::vector<Char> &target, int len) {
    return ::read(fileno(stdin), &target[0], len);
}

LocalTerminal localTerminal;

Console *Console::createLocalConsole() {
    return new AnsiConsole(localTerminal);
}

#else

// ---------------------------------------------------------------------------
// Windows (Win32 console, virtual-terminal mode)
// ---------------------------------------------------------------------------

void WindowsTerminal::open() {
    hIn = GetStdHandle(STD_INPUT_HANDLE);
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    DWORD inMode = 0, outMode = 0;
    GetConsoleMode((HANDLE)hIn, &inMode);
    GetConsoleMode((HANDLE)hOut, &outMode);
    origInMode = inMode;
    origOutMode = outMode;
    origOutCP = GetConsoleOutputCP();

    // Output: process ANSI escape sequences (colors, cursor moves, clears) that
    // AnsiConsole emits, and don't auto-wrap/CR at the last column.
    SetConsoleMode((HANDLE)hOut,
                   outMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING
                           | DISABLE_NEWLINE_AUTO_RETURN);

    // Input: raw. Clear line editing/echo/Ctrl-C processing and mouse/window
    // events. We do NOT use ENABLE_VIRTUAL_TERMINAL_INPUT: conhost's VT-input
    // byte translation does not reliably deliver a whole ESC[.. sequence in one
    // ReadFile(), so multi-byte keys (arrows) would arrive split and the parser
    // would see a bare ESC. Instead read() consumes raw INPUT_RECORDs and
    // synthesizes the ANSI sequences itself (see WindowsTerminal::read).
    DWORD wantIn = inMode;
    wantIn &= ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT | ENABLE_PROCESSED_INPUT
                | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
    SetConsoleMode((HANDLE)hIn, wantIn);

    // UTF-8 output so non-ASCII / box-drawing renders like a POSIX terminal.
    SetConsoleOutputCP(CP_UTF8);
}

int WindowsTerminal::getWidth() const {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(hOut && GetConsoleScreenBufferInfo((HANDLE)hOut, &csbi))
        return csbi.srWindow.Right - csbi.srWindow.Left + 1;
    return 80;
}

int WindowsTerminal::getHeight() const {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(hOut && GetConsoleScreenBufferInfo((HANDLE)hOut, &csbi))
        return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    return 25;
}

void WindowsTerminal::close() {
    if(hIn) SetConsoleMode((HANDLE)hIn, origInMode);
    if(hOut) SetConsoleMode((HANDLE)hOut, origOutMode);
    if(origOutCP) SetConsoleOutputCP(origOutCP);
}

int WindowsTerminal::write(const std::vector<Char> &source, int len) {
    DWORD written = 0;
    if(!WriteFile((HANDLE)hOut, source.data(), (DWORD)len, &written, nullptr))
        return -1;
    return (int)written;
}

int WindowsTerminal::read(std::vector<Char> &target, int len) {
    // Non-blocking: Console::getKey() drives its own 100ms poll loop and expects
    // read() to return immediately (0) when nothing is queued. Read raw console
    // INPUT_RECORDs and translate each key-down into the byte sequence the
    // AnsiConsole parser expects: named keys (arrows, Home/End, PageUp/Down,
    // Delete) become their ANSI ESC[.. sequence, emitted contiguously so the
    // parser never sees a partial escape; printable keys become their UTF-8
    // bytes. Key-up and non-key records are ignored.
    DWORD avail = 0;
    if(!GetNumberOfConsoleInputEvents((HANDLE)hIn, &avail) || avail == 0)
        return 0;
    if((int)target.size() < len)
        target.resize(len);

    int out = 0;
    while(out == 0 && avail > 0) {
        INPUT_RECORD recs[32];
        DWORD toRead = avail < 32 ? avail : 32;
        DWORD got = 0;
        if(!ReadConsoleInputW((HANDLE)hIn, recs, toRead, &got) || got == 0)
            break;
        for(DWORD i = 0; i < got && out < len; i++) {
            if(recs[i].EventType != KEY_EVENT) continue;
            const KEY_EVENT_RECORD &k = recs[i].Event.KeyEvent;
            if(!k.bKeyDown) continue;

            // Named navigation keys -> ANSI escape sequences.
            const char* seq = nullptr;
            switch(k.wVirtualKeyCode) {
            case VK_UP:     seq = "\x1b[A";  break;
            case VK_DOWN:   seq = "\x1b[B";  break;
            case VK_RIGHT:  seq = "\x1b[C";  break;
            case VK_LEFT:   seq = "\x1b[D";  break;
            case VK_HOME:   seq = "\x1b[H";  break;
            case VK_END:    seq = "\x1b[F";  break;
            case VK_PRIOR:  seq = "\x1b[5~"; break; // Page Up
            case VK_NEXT:   seq = "\x1b[6~"; break; // Page Down
            case VK_DELETE: seq = "\x1b[3~"; break;
            default: break;
            }
            if(seq) {
                for(const char* p = seq; *p && out < len; p++)
                    target[out++] = (Char)(uint8_t)*p;
                continue;
            }

            wchar_t wc = k.uChar.UnicodeChar;
            if(wc == 0) continue;              // pure modifier / unmapped
            if(wc == 0x08) {                    // Backspace: parser wants 0x7f
                target[out++] = (Char)0x7f;
                continue;
            }
            // UTF-8 encode the (BMP) character.
            if(wc < 0x80) {
                target[out++] = (Char)wc;
            } else if(wc < 0x800) {
                if(out + 2 > len) break;
                target[out++] = (Char)(0xC0 | (wc >> 6));
                target[out++] = (Char)(0x80 | (wc & 0x3F));
            } else {
                if(out + 3 > len) break;
                target[out++] = (Char)(0xE0 | (wc >> 12));
                target[out++] = (Char)(0x80 | ((wc >> 6) & 0x3F));
                target[out++] = (Char)(0x80 | (wc & 0x3F));
            }
        }
        // Records consumed above may have produced no bytes (e.g. all key-up);
        // refresh the queue depth so we keep draining until we get a key or the
        // queue empties, preserving the non-blocking contract.
        if(out == 0 && (!GetNumberOfConsoleInputEvents((HANDLE)hIn, &avail)))
            break;
    }
    return out;
}

WindowsTerminal localTerminal;

Console *Console::createLocalConsole() {
    return new AnsiConsole(localTerminal);
}

#endif

}
