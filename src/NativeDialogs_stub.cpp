// Non-Apple stub for native file dialogs.
//
// The macOS build implements this in NativeDialogs.mm using NSOpenPanel. On
// other platforms (Linux / Raspberry Pi, etc.) there is no bundled native file
// picker yet, so open_file_dialog() returns an empty string, which the caller
// (ChipMachine_commands.cpp) treats as "no file selected".
//
// A future implementation can wire this to xdg-desktop-portal (the modern,
// desktop-agnostic file-chooser D-Bus API) or GTK's GtkFileChooser.
#include "ChipMachine.h"

namespace chipmachine {

std::string ChipMachine::open_file_dialog()
{
    return "";
}

} // namespace chipmachine
