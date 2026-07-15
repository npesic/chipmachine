// Non-Apple stub for the update-check subsystem.
//
// The macOS build implements this in CheckForUpdate.mm, which queries the
// GitHub releases API via NSURLSession and pops an NSAlert when a newer version
// is available. That path is AppKit/Foundation-only, so on every other platform
// (Linux / Raspberry Pi, etc.) the update check is currently a no-op.
//
// A future cross-platform implementation could reuse webutils to fetch the
// releases API and surface the result through the normal UI.
extern "C" void InitializeUpdateVerificationSubsystem() {}
