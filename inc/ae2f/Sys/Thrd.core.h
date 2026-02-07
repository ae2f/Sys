/**
 * @file Thrd.core.h
 * @brief Contains unified types and dependencies.
 * */
#ifndef	ae2f_Sys_Thrd_core_h
#define	ae2f_Sys_Thrd_core_h

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

#endif
