/**
 * @file Ftx-POSIX.h
 * */

#ifndef ae2f_Sys_Ftx_POSIX_h
#define ae2f_Sys_Ftx_POSIX_h

#include "./Ftx.h"

#if ae2f_SysFtx_POSIX(!)0

#include <pthread.h>
#include <errno.h>
#include <ae2f/c90/StdInt.h>

#define	_ae2f_SysFtxEl_POSIX	int32_t

#define ae2f_SysFtxLibDefine_POSIX(tprm_export) \
	key_export pthread_mutex_t __ae2f_gSysFtxMtx = PTHREAD_MUTEX_INITIALIZER; \
	key_export pthread_cond_t __ae2f_gSysFtxCnd = PTHREAD_COND_INITIALIZER;


#define ae2f_SysFtxLibDeclare_POSIX(tprm_import) \
	key_extern pthread_mutex_t	__ae2f_gSysFtxMtx; \
	key_extern pthread_cond_t	__ae2f_gSysFtxCnd;

#endif

#endif
