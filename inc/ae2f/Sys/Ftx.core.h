/**
 * @file Ftx.core.h
 * */

#ifndef ae2f_Futex_core_h
#define ae2f_Futex_core_h

#include <time.h>

#include "./Ftx-WIN.h"
#include "./Ftx-_linux.h"
#include "./Ftx-POSIX.h"

/**
 * @enum ae2f_eSysFtxWait
 * @brief Guaranteed not to be duplicated.
 * @see _ae2f_SysFtxWait
 * */
typedef enum {
	/** @brief Succesful */
	ae2f_SysFtxWait_GOOD = 0,

	/** @brief timeout */
	ae2f_SysFtxWait_TMOUT 
		ae2f_Sys_WIN(= ERROR_TIMEOUT)
		ae2f_Sys__linux(= ETIMEDOUT)
		ae2f_SysFtx_POSIX(= ETIMEDOUT)
		,

	/** @brief Invalid pointer to ae2f_SysFtxEl_t. */
	ae2f_SysFtxWait_PTRINVAL 
		ae2f_Sys__linux(=EFAULT),

	/** @brief Invalid arguments (or not initialised) */
	ae2f_SysFtxWait_INVAL 
		ae2f_Sys__linux(=EINVAL) 
		ae2f_SysFtx_POSIX(=EINVAL),

	/** @brief Value expected did not match */
	ae2f_SysFtxWait_MISMATCH
		ae2f_Sys__linux(= EAGAIN),

	/** @brief Interrupted by a user */
	ae2f_SysFtxWait_INTERRUPTED
		ae2f_Sys__linux(= EINTR),

	/** @brief Target system does not support this */
	ae2f_SysFtxWait_NO_IMP
		ae2f_Sys__linux(= ENOSYS),

	/** @brief Mutex is uncoverable */
	ae2f_SysFtxWait_MTXNCOVERABLE 
		ae2f_SysFtx_POSIX(= ENOTRECOVERABLE),

	/** @brief Mutex's owner is dead */
	ae2f_SysFtxWait_MTXOWNDEAD
		ae2f_SysFtx_POSIX(= EOWNERDEAD),

	/** @brief Current system already has mutex. */
	ae2f_SysFtxWait_MTXBLK
		ae2f_SysFtx_POSIX(= EDEADLK),

	/** @brief Mutex is not owned by this thread */
	ae2f_SysFtxWait_MTXNOWN
		N_ae2f_Sys_WIN(= EPERM),
} ae2f_eSysFtxWait;

/** 
 * @enum ae2f_eSysFtxWake 
 * */
typedef enum {
	ae2f_SysFtxWake_GOOD = 0,

	/** @brief Invalid pointer to uaddr */
	ae2f_SysFtxWake_PTRINVAL 
		ae2f_Sys__linux(= EFAULT),

	/** @brief Not initialised */
	ae2f_SysFtxWake_INVAL 
		ae2f_Sys__linux(= EINVAL),

	/** @brief Implementation is not included on your system */
	ae2f_SysFtxWake_NO_IMP
		ae2f_Sys__linux(= ENOSYS),

	/** @brief Mutex is uncoverable */
	ae2f_SysFtxWake_MTXNCOVERABLE 
		ae2f_SysFtx_POSIX(= ENOTRECOVERABLE),

	/** @brief Mutex's owner is dead */
	ae2f_SysFtxWake_MTXOWNDEAD
		ae2f_SysFtx_POSIX(= EOWNERDEAD),

	/** @brief Current system already has mutex. */
	ae2f_SysFtxWake_MTXBLK
		ae2f_SysFtx_POSIX(= EDEADLK),

	/** @brief Mutex is not owned by this thread */
	ae2f_SysFtxWake_MTXNOWN
		N_ae2f_Sys_WIN(= EPERM),
	
} ae2f_eSysFtxWake;

#endif
