/**
 * @file	core.h
 * @brief	thread
 * */

#ifndef	ae2fsys_thrd_core_h
#define	ae2fsys_thrd_core_h

#include <ae2f/Sys/probe.h>

/**
 * @enum	AE2FSYS_THRD_
 *
 * @brief 
 * enum values related to thread. \n
 * 't follows C11 thread standard.
 * */
enum AE2FSYS_THRD_ {
	/** Good */
	AE2FSYS_THRD_GOOD,
	AE2FSYS_THRD_UNKNOWN,

	/** Out of host memory */
	AE2FSYS_THRD_MEMOUT,

	/** Timeout */
	AE2FSYS_THRD_TMOUT,

	AE2FSYS_THRD_BUSY
};

#define	AE2FSYS_THRD_WINDOWS	_AE2FSYS_PROBE_WINDOWS
#define	AE2FSYS_THRD_LINUX	_AE2FSYS_PROBE_LINUX
#define	AE2FSYS_THRD_PTHREAD	(!(AE2FSYS_THRD_WINDOWS || AE2FSYS_THRD_LINUX))

#endif
