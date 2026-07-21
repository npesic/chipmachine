#pragma once

// NOTE: only utils.h (for utils::sleepms) is needed. Do NOT add log.h here —
// utils.h includes this header, so anything pulled in here lands in every
// <coreutils/utils.h> consumer (log.h drags in format.h/fmt tree-wide).
#include "utils.h"

#include <cstdint>
#include <string>
#include <vector>
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
// These system headers MUST be included at global scope. They used to be
// #included inside `namespace utils` (in the POSIX ExecPipe impl below), which
// declares libc symbols such as ::signal / ::sig_atomic_t / ::__sighandler_t as
// utils::signal etc. A later <csignal> then fails ("using ::signal;" finds
// nothing). This only bit on glibc -- on macOS these headers are already pulled
// in globally before this namespace opens, so the in-namespace re-include was a
// guarded no-op there.
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cerrno>
#include <cstdio>
#endif

// Forward declaration only — do NOT include log.h here (see note above); it
// would drag the fmt tree into every <coreutils/utils.h> consumer. logDebug
// logs at Debug level, so these messages appear only when run with -d.
namespace logging {
void logDebug(const std::string& text);
}

namespace utils {

#ifdef _WIN32
typedef void* HANDLE;
#endif

struct ExecPipe
{
    ExecPipe() = default;
    explicit ExecPipe(const std::string& cmd);
    ~ExecPipe();

    ExecPipe(ExecPipe&& other) noexcept;
    ExecPipe(const ExecPipe& other) = delete;
    ExecPipe& operator=(const ExecPipe& other) = delete;
    ExecPipe& operator=(ExecPipe&& other) noexcept;

    bool hasEnded();
    void Kill();
    int read(uint8_t* target, int size);
    int write(uint8_t* source, int size);
    // Put the read (stdout) end into non-blocking mode so read() returns -1 on
    // EAGAIN instead of blocking. Used by the streaming player so the audio
    // thread can poll for "buffering" without stalling.
    void setReadNonBlocking();
    // Close the write (stdin) end so the child sees EOF on stdin, flushes and
    // exits. Read end stays open to drain remaining output.
    void closeWrite();
    // Non-explicit on purpose: main.cpp's cm_execute Lua helper relies on the
    // implicit ExecPipe->std::string conversion (run command, capture stdout).
    operator std::string();

#ifdef _WIN32
    HANDLE hPipeRead{nullptr};
    HANDLE hPipeWrite{nullptr};
    HANDLE hProcess{nullptr};
    bool nonBlocking{false}; // set by setReadNonBlocking(); read() polls when true
#else
    pid_t pid = -1;
    int outfd{-1};
    int infd{-1};
#endif
};

#ifdef _WIN32

// Win32 ExecPipe: spawn `cmd` (via cmd.exe /c, matching the POSIX /bin/sh -c),
// wired to anonymous pipes for the child's stdin and stdout. Return-code
// contract matches the POSIX version so callers (FFMPEGPlayer, cm_execute) are
// identical across platforms:
//   read():  >0 = bytes; 0 = EOF (child closed stdout); -1 = no data yet
//            (only in non-blocking mode); -2 = pipe not open / error.
//   write(): bytes written; <=0 = child gone.
//   hasEnded(): true once the child process has exited.

inline ExecPipe::ExecPipe(const std::string& cmd)
{
    logging::logDebug("ExecPipe (win32) Command Line: '" + cmd + "'");

    SECURITY_ATTRIBUTES sa{};
    sa.nLength = sizeof(sa);
    sa.bInheritHandle = TRUE;        // pipe ends are inheritable by the child
    sa.lpSecurityDescriptor = nullptr;

    HANDLE childStdoutWrite = nullptr;
    HANDLE childStdinRead = nullptr;

    // Buffer size for the pipes. Windows' default (nSize=0) is a mere ~4 KB,
    // versus 64 KB on POSIX. For the streaming audio path that is far too small:
    // at 44100*2ch*2B = 176 KB/s of PCM, a 4 KB buffer drains in ~23 ms, so the
    // non-blocking reader constantly outruns ffmpeg and getSamples() keeps
    // reporting "buffering" (0 samples) -> audible hiccups. A large buffer lets
    // ffmpeg run ahead and smooths the reads. (This is why mp3 stuttered while
    // ogg -- with a slightly steadier decode cadence -- happened to squeak by.)
    constexpr DWORD kPipeBuf = 1u << 20; // 1 MB (a hint; Windows may round)

    // Child stdout -> our hPipeRead ; our hPipeWrite -> child stdin.
    if (!CreatePipe(&hPipeRead, &childStdoutWrite, &sa, kPipeBuf) ||
        !CreatePipe(&childStdinRead, &hPipeWrite, &sa, kPipeBuf)) {
        hPipeRead = hPipeWrite = hProcess = nullptr;
        return;
    }

    // The parent ends must NOT be inherited by the child, or the child holds a
    // copy of the stdout write end and we never see EOF (same reasoning as the
    // POSIX FD_CLOEXEC dance).
    SetHandleInformation(hPipeRead, HANDLE_FLAG_INHERIT, 0);
    SetHandleInformation(hPipeWrite, HANDLE_FLAG_INHERIT, 0);

    STARTUPINFOA si{};
    si.cb = sizeof(si);
    si.dwFlags = STARTF_USESTDHANDLES;
    si.hStdInput = childStdinRead;
    si.hStdOutput = childStdoutWrite;
    // Match the POSIX impl (dup2 STDOUT->STDERR): child stderr goes to the same
    // pipe as stdout. ffmpeg is invoked with quiet logging when it pipes PCM, so
    // this does not corrupt the audio stream; for cm_execute it captures both.
    si.hStdError = childStdoutWrite;

    // Run through cmd.exe so quoting/redirection in `cmd` behaves like /bin/sh -c.
    std::string full = "cmd.exe /c " + cmd;
    std::vector<char> mutableCmd(full.begin(), full.end());
    mutableCmd.push_back('\0');

    PROCESS_INFORMATION pi{};
    BOOL ok = CreateProcessA(nullptr, mutableCmd.data(), nullptr, nullptr,
                             TRUE, // inherit handles (the child ends)
                             CREATE_NO_WINDOW, nullptr, nullptr, &si, &pi);

    // Close the child ends in the parent regardless: if spawn failed we don't
    // need them, and if it succeeded the child has its own copies.
    CloseHandle(childStdoutWrite);
    CloseHandle(childStdinRead);

    if (!ok) {
        CloseHandle(hPipeRead);
        CloseHandle(hPipeWrite);
        hPipeRead = hPipeWrite = nullptr;
        hProcess = nullptr;
        return;
    }

    CloseHandle(pi.hThread);
    hProcess = pi.hProcess;
}

inline ExecPipe::~ExecPipe() { Kill(); }

inline ExecPipe::ExecPipe(ExecPipe&& other) noexcept
{
    hPipeRead = other.hPipeRead;
    hPipeWrite = other.hPipeWrite;
    hProcess = other.hProcess;
    nonBlocking = other.nonBlocking;
    other.hPipeRead = other.hPipeWrite = other.hProcess = nullptr;
}

inline ExecPipe& ExecPipe::operator=(ExecPipe&& other) noexcept
{
    if (this != &other) {
        Kill();
        hPipeRead = other.hPipeRead;
        hPipeWrite = other.hPipeWrite;
        hProcess = other.hProcess;
        nonBlocking = other.nonBlocking;
        other.hPipeRead = other.hPipeWrite = other.hProcess = nullptr;
    }
    return *this;
}

inline void ExecPipe::Kill()
{
    if (hProcess) {
        DWORD code = 0;
        if (GetExitCodeProcess(hProcess, &code) && code == STILL_ACTIVE)
            TerminateProcess(hProcess, 1);
        CloseHandle(hProcess);
        hProcess = nullptr;
    }
    if (hPipeRead) { CloseHandle(hPipeRead); hPipeRead = nullptr; }
    if (hPipeWrite) { CloseHandle(hPipeWrite); hPipeWrite = nullptr; }
}

inline int ExecPipe::read(uint8_t* target, int size)
{
    if (!hPipeRead) return -2;

    if (nonBlocking) {
        // Poll: how many bytes can be read without blocking?
        DWORD avail = 0;
        if (!PeekNamedPipe(hPipeRead, nullptr, 0, nullptr, &avail, nullptr)) {
            // Pipe closed by the child == EOF.
            return (GetLastError() == ERROR_BROKEN_PIPE) ? 0 : -2;
        }
        if (avail == 0)
            return -1; // no data yet (child still producing) -> "buffering"
        if ((DWORD)size > avail) size = (int)avail;
    }

    DWORD got = 0;
    if (!ReadFile(hPipeRead, target, (DWORD)size, &got, nullptr)) {
        return (GetLastError() == ERROR_BROKEN_PIPE) ? 0 : -2; // EOF vs error
    }
    return (int)got; // 0 here also means EOF
}

inline int ExecPipe::write(uint8_t* source, int size)
{
    if (!hPipeWrite) return -2;
    DWORD put = 0;
    if (!WriteFile(hPipeWrite, source, (DWORD)size, &put, nullptr))
        return -2; // broken pipe / child gone
    return (int)put;
}

inline void ExecPipe::setReadNonBlocking()
{
    // Anonymous pipes have no non-blocking mode toggle; read() emulates it via
    // PeekNamedPipe when this flag is set.
    nonBlocking = true;
}

inline void ExecPipe::closeWrite()
{
    if (hPipeWrite) {
        // A feeder thread may be parked in a *synchronous* WriteFile on this
        // handle -- normal backpressure: ffmpeg's stdin buffer fills whenever we
        // stop draining its stdout, so the write blocks until playback catches
        // up. On POSIX, close() of the write fd makes that write fail with EPIPE
        // so the feeder exits; the destructor relies on that to join() cleanly.
        // On Windows, CloseHandle does NOT unblock another thread's pending
        // WriteFile -- the feeder stays parked, ~FFMPEGPlayer's join() hangs
        // forever, and because teardown runs on the player thread holding
        // plMutex, the whole UI freezes. CancelIoEx aborts the pending I/O so the
        // parked WriteFile returns (ERROR_OPERATION_ABORTED); write() reports that
        // as <=0 and the feeder exits. Cancels I/O on this handle across all
        // threads of the process (hOverlapped == nullptr).
        CancelIoEx(hPipeWrite, nullptr);
        CloseHandle(hPipeWrite);
        hPipeWrite = nullptr;
    }
}

inline bool ExecPipe::hasEnded()
{
    if (!hProcess) return true;
    DWORD code = 0;
    if (!GetExitCodeProcess(hProcess, &code)) return true;
    return code != STILL_ACTIVE;
}

#else

// NOTE: the POSIX/C system headers this code needs are included at global scope
// near the top of this file, NOT here -- including them inside `namespace utils`
// pollutes utils:: with libc symbols and breaks a later <csignal>.

__attribute__((noinline)) inline pid_t popen2_simple(const char* command, int* infp, int* outfp)
{
    enum { READ, WRITE };
    int p_stdin[2], p_stdout[2];
    pid_t pid;

    logging::logDebug("Forking shell command execution...");

    if (pipe(p_stdin) != 0 || pipe(p_stdout) != 0) return -1;

    // Mark all pipe ends close-on-exec so they cannot leak into unrelated child
    // processes spawned elsewhere. A leaked copy of an output pipe's write end
    // would keep the reader from ever seeing EOF. The child below dup2()s the
    // ends it needs onto stdin/stdout, which clears O_CLOEXEC on those targets,
    // so the spawned command still gets its standard streams.
    for (int fd : {p_stdin[0], p_stdin[1], p_stdout[0], p_stdout[1]}) {
        fcntl(fd, F_SETFD, fcntl(fd, F_GETFD) | FD_CLOEXEC);
    }

    pid = fork();
    if (pid < 0) return pid;

    if (pid == 0) {
        dup2(p_stdin[READ], STDIN_FILENO);
        dup2(p_stdout[WRITE], STDOUT_FILENO);
        
        dup2(STDOUT_FILENO, STDERR_FILENO);

        close(p_stdin[READ]);
        close(p_stdin[WRITE]);
        close(p_stdout[READ]);
        close(p_stdout[WRITE]);

        execl("/bin/sh", "sh", "-c", command, NULL);
        perror("execl failed");
        _exit(1);
    }

    close(p_stdin[READ]);
    close(p_stdout[WRITE]);

    if (infp == nullptr) close(p_stdin[WRITE]); else *infp = p_stdin[WRITE];
    if (outfp == nullptr) close(p_stdout[READ]); else *outfp = p_stdout[READ];

    return pid;
}

__attribute__((noinline)) inline ExecPipe::ExecPipe(const std::string& cmd)
{
    logging::logDebug("ExecPipe Constructor Command Line: '" + cmd + "'");

    pid = popen2_simple(cmd.c_str(), &infd, &outfd);

    if (outfd >= 0) {
        int flags = fcntl(outfd, F_GETFL, 0);
        fcntl(outfd, F_SETFL, flags & ~O_NONBLOCK);
    }

    // Writing to the child's stdin (infd) after the child has exited would raise
    // SIGPIPE, whose default action silently kills the whole app (no crash
    // report). This is exactly what happened when a track switch tore down the
    // ffmpeg stream player while the feeder thread was still mid-write to a dying
    // ffmpeg. Ask the kernel to fail those writes with EPIPE instead of a signal;
    // the feeder already treats a <=0 write as "child gone" and stops cleanly.
#ifdef F_SETNOSIGPIPE
    if (infd >= 0) fcntl(infd, F_SETNOSIGPIPE, 1);
    if (outfd >= 0) fcntl(outfd, F_SETNOSIGPIPE, 1);
#endif
}

__attribute__((noinline)) inline ExecPipe::~ExecPipe() { Kill(); }

inline ExecPipe::ExecPipe(ExecPipe&& other) noexcept
{
    pid = other.pid;
    outfd = other.outfd;
    infd = other.infd;
    other.pid = -1;
    other.outfd = -1;
    other.infd = -1;
}

inline ExecPipe& ExecPipe::operator=(ExecPipe&& other) noexcept
{
    if (this != &other) {
        Kill();
        pid = other.pid;
        outfd = other.outfd;
        infd = other.infd;
        other.pid = -1;
        other.outfd = -1;
        other.infd = -1;
    }
    return *this;
}

__attribute__((noinline)) inline void ExecPipe::Kill()
{
    if (pid != -1) {
        int result = 0;
        if (waitpid(pid, &result, WNOHANG) == 0) {
            kill(pid, SIGKILL);
            waitpid(pid, &result, 0);
        }
        pid = -1;
    }
    if (outfd >= 0) { close(outfd); outfd = -1; }
    if (infd >= 0) { close(infd); infd = -1; }
}

__attribute__((noinline)) inline int ExecPipe::read(uint8_t* target, int size)
{
    if (outfd < 0) return -2;
    
    while (true) {
        int rc = ::read(outfd, target, size);
        if (rc >= 0) return rc;
        if (errno == EINTR) continue;
        // Only happens when the fd is non-blocking (setReadNonBlocking): tell the
        // caller "no data yet" rather than conflating it with a real error/EOF.
        if (errno == EAGAIN || errno == EWOULDBLOCK) return -1;
        return -2;
    }
}

inline int ExecPipe::write(uint8_t* source, int size)
{
    if (infd < 0) return -2;
    return ::write(infd, source, size);
}

inline void ExecPipe::setReadNonBlocking()
{
    if (outfd >= 0) {
        int flags = fcntl(outfd, F_GETFL, 0);
        fcntl(outfd, F_SETFL, flags | O_NONBLOCK);
    }
}

inline void ExecPipe::closeWrite()
{
    if (infd >= 0) {
        close(infd);
        infd = -1;
    }
}

__attribute__((noinline)) inline bool ExecPipe::hasEnded()
{
    if (pid == -1) return true;
    int rc = 0;
    pid_t res = waitpid(pid, &rc, WNOHANG);
    if (res == pid) {
        pid = -1;
        return true;
    } else if (res < 0 && errno == ECHILD) {
        pid = -1;
        return true;
    }
    return false;
}

#endif

inline ExecPipe::operator std::string()
{
    char buf[1024];
    std::string result;
    bool ended = false;
    while (true) {
        int sz = read(reinterpret_cast<uint8_t*>(&buf[0]), sizeof(buf));
        if (sz > 0) {
            result += std::string(buf, 0, sz);
        } else if (sz != -1 || ended)
            return result;
        ended = hasEnded();
        sleepms(100);
    }
    return result;
}

inline int shellExec(const std::string& cmd, const std::string& binDir = "")
{
    return system((binDir + "/" + cmd).c_str());
}

inline ExecPipe execPipe(const std::string& cmd)
{
    return ExecPipe{cmd};
}

} // namespace utils
