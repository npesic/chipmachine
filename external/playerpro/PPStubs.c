// Stubs for the Mac live-audio + Finder-metadata entry points that the stock
// PlayerPRO build references on __APPLE__ (it auto-#defines _MAC_H, which keeps
// all the well-tested Mac IO/struct code paths). chipmachine never starts the
// CoreAudio backend -- it drives the engine offline with NoHardwareDriver +
// MADDirectSave -- and never writes module files, so these are inert. Providing
// trivial stubs avoids linking AudioToolbox/AudioUnit and the Objective-C
// CocoaFuncs.m purely to satisfy the symbol table.
//
// Public domain, like the rest of PlayerPRO.

#include "RDriver.h"

// These stubs stand in for Apple-only entry points, and every caller of them in
// playerpro is itself behind #ifdef _MAC_H (defined by MADDefs.h on __APPLE__,
// pulled in via RDriver.h above). On non-Apple platforms nothing references
// them, and CoreFoundation does not exist, so compile the whole body only for
// the Mac build; elsewhere this is an (inert) empty translation unit.
#ifdef _MAC_H
#include <CoreFoundation/CoreFoundation.h>

MADErr initCoreAudio(MADDriverRec* inMADDriver)
{
    (void)inMADDriver;
    return MADNoErr;
}

MADErr closeCoreAudio(MADDriverRec* inMADDriver)
{
    (void)inMADDriver;
    return MADNoErr;
}

// Sets a file's legacy HFS OSType on save; never reached (we only read).
void SetOSType(CFURLRef theURL, OSType theType)
{
    (void)theURL;
    (void)theType;
}

#endif // _MAC_H
