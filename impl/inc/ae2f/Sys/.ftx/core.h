#ifndef	ae2fsys_ftx_core_h
#define	ae2fsys_ftx_core_h

#include <ae2f/Sys/probe.h>

#define	_AE2FSYS_FTX_WINDOWS	_AE2FSYS_PROBE_WINDOWS
#define	_AE2FSYS_FTX_LINUX	_AE2FSYS_PROBE_LINUX
#define	_AE2FSYS_FTX_OPENBSD	_AE2FSYS_PROBE_OPENBSD

#define	_AE2FSYS_FTX_OTHERS	\
	(!(_AE2FSYS_PROBE_WINDOWS || _AE2FSYS_PROBE_LINUX || _AE2FSYS_PROBE_OPENBSD))

enum	AE2FSYS_FTX_ {
	/** @brief Succesful */
	AE2FSYS_FTX_GOOD,

	AE2FSYS_FTX_UNKNOWN,

	/** @brief timeout */
	AE2FSYS_FTX_TMOUT,

	/** @brief Invalid pointer to ae2f_SysFtxEl_t. */
	AE2FSYS_FTX_PTRINVAL,

	/** @brief Invalid arguments (or not initialised) */
	AE2FSYS_FTX_INVAL,

	/** @brief Value expected did not match */
	AE2FSYS_FTX_MISMATCH,

	/** @brief Interrupted by a user */
	AE2FSYS_FTX_INTERRUPTED,
	AE2FSYS_FTX_CANCELED,

	/** @brief Target system does not support this */
	AE2FSYS_FTX_NO_IMP,

	/** @brief Mutex is uncoverable */
	AE2FSYS_FTX_MTXNCOVERABLE,

	/** @brief Mutex's owner is dead */
	AE2FSYS_FTX_MTXOWNDEAD,

	/** @brief Current system already has mutex. */
	AE2FSYS_FTX_MTXBLK,

	/** @brief Mutex is not owned by this thread */
	AE2FSYS_FTX_MTXNOWN
};

#endif
