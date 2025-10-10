/**
 * @file Thrd.core.h
 * @brief Contains unified types and dependencies.
 * */
#ifndef	ae2f_Sys_Thrd_core_h
#define	ae2f_Sys_Thrd_core_h

#include <ae2f/LangVer.h>
#include <ae2f/Cast.h>

#include "../Sys.h"

#if	ae2f_Sys_WIN(!)0
#include <windows.h>
#include <time.h>

#define _ae2f_SysThrdRes_t	DWORD /* WINAPI */
#define _ae2f_SysThrdPrm_t	/* __drv_aliasesMem */ LPVOID
#define _ae2f_SysThrdID_t	HANDLE

#elif	ae2f_Sys__linux(!)0

/**
 * @macro __ae2f_SysThrdStckTopOper
 * A macro to make top pointer.
 * */
#ifndef __ae2f_SysThrdStckTopOper
#define __ae2f_SysThrdStckTopOper(prm_ptr, prm_sz)	((prm_ptr) + (prm_sz))
#endif

#define _GNU_SOURCE
#include <sys/mman.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <c89atomic.h>
#include <sched.h>
#include <linux/sched.h>
#include <signal.h>
#include "./Ftx.h"

#define	_ae2f_SysThrdRes_t	int
#define _ae2f_SysThrdPrm_t	void*
#define _ae2f_SysThrdID_t	int

ae2f_structdef(struct, _ae2f_SysThrdRunnerPrm_t)
{
	int			m_ret;
	/** 
	 * if 1, is done.
	 * This member must not be changed by multiple threads
	 * */
	ae2f_SysFtxEl_t		m_done;
	ae2f_SysFtxRet_t	m_ftxret;

	int		(*m_fn)(void*);
	void*		m_arg;
	size_t		m_stcksz;
};

ae2f_structdef(union, _ae2f_SysThrdStckPtr_t)
{
	void* ae2f_restrict				m_void;
	char* ae2f_restrict				m_char;
	_ae2f_SysThrdRunnerPrm_t* ae2f_restrict	m_prm;
};

static void	_ae2f_SysThrdRunner(_ae2f_SysThrdRunnerPrm_t* prm_stck) {

	if(prm_stck) {
		/** child section */
		(prm_stck)->m_done = 0;
		(prm_stck)->m_ret = (prm_stck->m_fn)((prm_stck)->m_arg);
		(prm_stck)->m_done = 1;

		_ae2f_SysFtxWakeOne(
				(prm_stck)->m_ftxret
				, (&(prm_stck)->m_done)
				);

		syscall(SYS_exit, 0);
	}

	syscall(SYS_exit, -1);
}

#else
#include <pthread.h>
#include <errno.h>
#include <sched.h>

#define _ae2f_SysThrdRes_t	void*
#define _ae2f_SysThrdPrm_t	void*
#define _ae2f_SysThrdID_t	pthread_t
#endif

#endif
