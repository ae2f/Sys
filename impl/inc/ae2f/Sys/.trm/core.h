/**
 * @file	core.h
 * @brief	Terminal
 * */

#ifndef	ae2fsys_trm_core_h
#define	ae2fsys_trm_core_h

#include <ae2f/Sys/probe.h>

enum	AE2FSYS_TRM_ {
	AE2FSYS_TRM_GOOD
};

#define	AE2FSYS_TRM_WINDOWS	_AE2FSYS_PROBE_WINDOWS
#define	AE2FSYS_TRM_OTHERS	(!_AE2FSYS_PROBE_WINDOWS)

#endif
