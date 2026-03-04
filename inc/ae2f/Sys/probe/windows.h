#ifndef	ae2fsys_probe_windows_h
#define	ae2fsys_probe_windows_h

#include "./win32.h"
#include "./win64.h"

#define	_AE2FSYS_PROBE_WINDOWS	\
	(_AE2FSYS_PROBE_WIN64 || _AE2FSYS_PROBE_WIN32)


#endif
