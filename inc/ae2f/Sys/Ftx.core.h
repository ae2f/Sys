#ifndef ae2f_Futex_core_h
#define ae2f_Futex_core_h

#include "../Sys.h"

#if ae2f_Sys_WIN(!)0
#include <windows.h>

/** synchronization link */
#pragma comment(lib, "synchronization")

#define	_ae2f_SysFtxEl_t	volatile LONG
#define _ae2f_SysFtxRet_t	BOOL

#elif ae2f_Sys__linux(!)0

#include <linux/futex.h>
#include <sys/syscall.h>
#include <unistd.h>

#define	_ae2f_SysFtxEl_t	int
#define _ae2f_SysFtxRet_t	int

#else
#include <pthread.h>
#include <errno.h>

#define	_ae2f_SysFtxEl_t	int32_t
#define _ae2f_SysFtxRet_t	int

#endif

#endif
