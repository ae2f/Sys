/**
 * @file Ftx.core.h
 * */

#ifndef ae2fsys_ftx_core_h
#define ae2fsys_ftx_core_h

#include "../Sys.h"

/**
 * @enum ae2f_eSysFtxWait
 * @brief Guaranteed not to be duplicated.
 * @see _ae2f_SysFtxWait
 * */
enum AE2FSYS_FTXWAIT_ {
	/** @brief Succesful */
	AE2FSYS_FTXWAIT_GOOD,

	AE2FSYS_FTXWAIT_UNKNOWN,

	/** @brief timeout */
	AE2FSYS_FTXWAIT_TMOUT,

	/** @brief Invalid pointer to ae2f_SysFtxEl_t. */
	AE2FSYS_FTXWAIT_PTRINVAL,

	/** @brief Invalid arguments (or not initialised) */
	AE2FSYS_FTXWAIT_INVAL,

	/** @brief Value expected did not match */
	AE2FSYS_FTXWAIT_MISMATCH,

	/** @brief Interrupted by a user */
	AE2FSYS_FTXWAIT_INTERRUPTED,

	/** @brief Target system does not support this */
	AE2FSYS_FTXWAIT_NO_IMP,

	/** @brief Mutex is uncoverable */
	AE2FSYS_FTXWAIT_MTXNCOVERABLE,

	/** @brief Mutex's owner is dead */
	AE2FSYS_FTXWAIT_MTXOWNDEAD,

	/** @brief Current system already has mutex. */
	AE2FSYS_FTXWAIT_MTXBLK,

	/** @brief Mutex is not owned by this thread */
	AE2FSYS_FTXWAIT_MTXNOWN
};

/** 
 * @enum ae2f_eSysFtxWake 
 * */
enum AE2FSYS_FTXWAKE_ {
	AE2FSYS_FTXWAKE_GOOD,

	AE2FSYS_FTXWAKE_UNKNOWN,

	/** @brief Invalid pointer to uaddr */
	AE2FSYS_FTXWAKE_PTRINVAL,

	/** @brief Not initialised */
	AE2FSYS_FTXWAKE_INVAL,

	/** @brief Implementation is not included on your system */
	AE2FSYS_FTXWAKE_NO_IMP,

	/** @brief Mutex is uncoverable */
	AE2FSYS_FTXWAKE_MTXNCOVERABLE,

	/** @brief Mutex's owner is dead */
	AE2FSYS_FTXWAKE_MTXOWNDEAD,

	/** @brief Current system already has mutex. */
	AE2FSYS_FTXWAKE_MTXBLK,

	/** @brief Mutex is not owned by this thread */
	AE2FSYS_FTXWAKE_MTXNOWN
	
};

#endif
