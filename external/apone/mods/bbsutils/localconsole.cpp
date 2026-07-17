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

    // Input: raw + VT. Clear line editing/echo/Ctrl-C processing and, crucially,
    // window/mouse events -- so the only records that ever queue are key events,
    // which ReadFile() translates to ESC[... byte sequences (the same ones the
    // AnsiConsole key parser already understands). This keeps read() from
    // blocking on non-key events.
    DWORD wantIn = inMode;
    wantIn &= ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT | ENABLE_PROCESSED_INPUT
                | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
    wantIn |= ENABLE_VIRTUAL_TERMINAL_INPUT;
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
    // read() to return immediately (0) when nothing is queued. Gate the read on
    // there being queued input; with mouse/window events disabled in open(),
    // those records are key events and ReadFile() returns their VT bytes.
    DWORD avail = 0;
    if(!GetNumberOfConsoleInputEvents((HANDLE)hIn, &avail) || avail == 0)
        return 0;
    if((int)target.size() < len)
        target.resize(len);
    DWORD got = 0;
    if(!ReadFile((HANDLE)hIn, target.data(), (DWORD)len, &got, nullptr))
        return 0;
    return (int)got;
}

WindowsTerminal localTerminal;

Console *Console::createLocalConsole() {
    return new AnsiConsole(localTerminal);
}

#endif

}
