#ifndef LOCALCONSOLE_H
#define LOCALCONSOLE_H

#include "console.h"

#ifndef _WIN32
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#endif

namespace bbs {

#ifndef _WIN32

class LocalTerminal : public Terminal {
public:

	virtual void open() override;
	virtual int getWidth() const override;
	virtual int getHeight() const override;

	virtual void close() override;

	virtual int write(const std::vector<Char> &source, int len) override;
	virtual int read(std::vector<Char> &target, int len) override;
private:
	struct termios orig_term_attr;
	struct winsize ws;


};
extern LocalTerminal localTerminal;

#else

// Windows console backend. It drives the console in "virtual terminal" (VT)
// mode, so the same AnsiConsole protocol used on POSIX works unchanged: ANSI
// escape sequences are rendered on output, and keys (arrows included) arrive as
// ESC[... byte sequences on input. The Win32 handles/modes are kept as opaque
// members so <windows.h> stays out of this header.
class WindowsTerminal : public Terminal {
public:

	virtual void open() override;
	virtual int getWidth() const override;
	virtual int getHeight() const override;

	virtual void close() override;

	virtual int write(const std::vector<Char> &source, int len) override;
	virtual int read(std::vector<Char> &target, int len) override;
private:
	void *hIn = nullptr;          // HANDLE (stdin)
	void *hOut = nullptr;         // HANDLE (stdout)
	unsigned long origInMode = 0; // DWORD
	unsigned long origOutMode = 0;// DWORD
	unsigned int origOutCP = 0;   // UINT

};
extern WindowsTerminal localTerminal;

#endif

}

#endif // LOCALCONSOLE_H
