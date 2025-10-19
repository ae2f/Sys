/**
 * @file Thrd.auto.h
 *
 * @brief
 * Contains various implementations which could be various
 *
 * @details
 * 
 * Following operations would be implemented
 *
 * create
 * join
 * sleep
 * yield
 * delete
 *
 * */

#ifndef ae2f_Sys_Thrd_auto_h
#include <ae2f/Sys/Thrd.h>
#define ae2f_Sys_Thrd_auto_h


#if __ae2f_MACRO_GENERATED
#else
#include <ae2f/Macro.h>
#endif

struct timespec;

#if ae2f_Sys__linux(!)0

#include <errno.h>

ae2f_MAC() __linux_ae2f_SysThrdMk_imp_call(
		ae2f_eSysThrd_t			ret_stat,
		ae2f_SysThrdID_t		ret_tid,
		ae2f_SysThrdFn_t* const		prm_func,
		_ae2f_SysThrdRunnerPrm_t* const prm_stck,
		void* const			prm_stcktop,
		size_t				prm_stcksz
		)
{
	(ret_tid) = clone(
			ae2f_reinterpret_cast(ae2f_SysThrdFn_t*, _ae2f_SysThrdRunner)
			, (prm_stcktop)
			, (CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_THREAD | CLONE_SYSVSEM)
			, (prm_stck)
			);

	if((ret_tid) == -1) {
		(ret_stat) = ae2f_eSysThrdErr;

	} else if((ret_tid) == 0)
	{
		syscall(SYS_exit, 0);
	}
	else
	{
		(ret_stat) = ae2f_eSysThrdSuccess;

	}
}



/**
 * @brief
 * Create a thread.
 * */
ae2f_MAC() ae2f_SysThrdMk_imp(
		ae2f_eSysThrd_t		ret_stat,
		ae2f_SysThrd		ret_thrd,
		ae2f_SysThrdFn_t* const	prm_func,
		void* const		prm_arg,
		const size_t		prm_stcksz
		)
{
	(ret_thrd).m_stck.m_void = mmap(
			NULL, ((ret_thrd).m_stcksz = (
					(prm_stcksz) 
					+ sizeof(_ae2f_SysThrdRunnerPrm_t)
					+ sizeof(void*)
					)
			      )
			, PROT_READ | PROT_WRITE
			, MAP_PRIVATE | MAP_STACK | MAP_ANONYMOUS
			, -1, 0
			);

	if(MAP_FAILED == (ret_thrd).m_stck.m_void || !(ret_thrd).m_stck.m_void) {
		(ret_stat) = ae2f_eSysThrdMemOut;
		(ret_thrd).m_stck.m_void = NULL;
	}
	else {
		(ret_thrd).m_stck.m_prm->m_arg = (prm_arg);
		(ret_thrd).m_stck.m_prm->m_fn = (prm_func);
		(ret_thrd).m_stck.m_prm->m_stcksz = (ret_thrd).m_stcksz;

		___linux_ae2f_SysThrdMk_imp_call(
				ret_stat, (ret_thrd).m_id
				, prm_func
				, (ret_thrd).m_stck.m_prm
				, __ae2f_SysThrdStckTopOper(((ret_thrd).m_stck.m_char), (prm_stcksz))
				, prm_stcksz
				);

		if(ret_stat != ae2f_eSysThrdSuccess)
		{
			munmap(
					(ret_thrd).m_stck.m_void
					, (ret_thrd).m_stcksz
			      );
			(ret_thrd).m_stck.m_void = NULL;
		}
	}
}


ae2f_MAC() ae2f_SysThrdJoin_imp(
		ae2f_eSysThrd_t		ret_stat,
		ae2f_SysThrdRes_t	ret_rtn,
		const ae2f_SysThrd	prm_thrd
		)
{
	ae2f_SysFtxRet_t v_res;

	unless((prm_thrd).m_stck.m_void) {
		(ret_stat) = ae2f_eSysThrdErr;
	}
	else {
		do {
			if((prm_thrd).m_stck.m_prm->m_done)
			{
				break;
			}

			_ae2f_SysFtxWait(
					v_res
					, &(prm_thrd).m_stck.m_prm->m_done
					, 0
					);

			(ret_rtn) = (prm_thrd).m_stck.m_prm->m_ret;
			munmap((prm_thrd).m_stck.m_void, (prm_thrd).m_stcksz);
		} while(0);

		if(v_res)
		{
			(ret_stat) = ae2f_eSysThrdErr;
		} else {
			(ret_stat) = ae2f_eSysThrdSuccess;
		}
	}
}

ae2f_MAC() ae2f_SysThrdYield_imp()
{
	syscall(SYS_sched_yield);
}

ae2f_MAC() ae2f_SysThrdSleep_imp(
		int ret_stat
		, const struct timespec * const prm_req
		, struct timespec * const prm_rem
		)
{
	(ret_stat) = syscall(SYS_nanosleep, prm_req, prm_rem);
}

#elif ae2f_Sys_WIN(!)0
ae2f_MAC() ae2f_SysThrdMk_imp(
		ae2f_eSysThrd_t		ret_stat,
		ae2f_SysThrd		ret_thrd,
		ae2f_SysThrdFn_t* const	prm_func,
		void* const		prm_arg,
		const size_t		prm_stcksz
		)
{
	(ret_thrd).m_id = 
		CreateThread(
				NULL
				, prm_stcksz
				, prm_func
				, prm_arg
				, STACK_SIZE_PARAM_IS_A_RESERVATION
				, NULL
			    );

	unless((ret_thrd).m_id) {
		(ret_stat) = ae2f_eSysThrdErr;
	} else 
		(ret_stat) = ae2f_eSysThrdSuccess;
}

ae2f_MAC() ae2f_SysThrdJoin_imp(
		ae2f_eSysThrd_t		ret_stat,
		ae2f_SysThrdRes_t	ret_rtn,
		const ae2f_SysThrd	prm_thrd
		)
{
	(ret_stat)
		= (
				WaitForSingleObject((prm_thrd).m_id, INFINITE) 
				&& GetExitCodeThread((prm_thrd).m_id, &(ret_rtn))
				&& CloseHandle((prm_thrd).m_id)
		  ) ? ae2f_eSysThrdSuccess : ae2f_eSysThrdErr;
}



ae2f_MAC() ae2f_SysThrdYield_imp()
{
	SwitchToThread();
}

ae2f_MAC() ae2f_SysThrdSleep_imp(
		int ret_stat
		, const struct timespec * const prm_req
		, struct timespec * const prm_rem
		)
{
	if (
			(prm_req) == NULL || 
			(prm_req)->tv_sec < 0 || 
			(prm_req)->tv_nsec < 0 || 
			(prm_req)->tv_nsec >= 1000000000
	   )
	{
		SetLastError(ERROR_INVALID_PARAMETER);
		(ret_stat) = -1;
	} else do {
		Sleep((DWORD)((prm_req)->tv_sec * 1000 + (prm_req)->tv_nsec / 1000000));
		if ((prm_rem) != NULL) {
			(prm_rem)->tv_sec = 0;
			(prm_rem)->tv_nsec = 0;
		}
		(ret_stat) = 0;
	} while(0);
}



#else

/** 
 * @param prm_stacksz_unused is not used here.
 * */
ae2f_MAC() ae2f_SysThrdMk_imp(
		ae2f_eSysThrd_t		ret_stat,
		ae2f_SysThrd		ret_thrd,
		ae2f_SysThrdFn_t* const	prm_func,
		void* const		prm_arg,
		const size_t		prm_stcksz_unused
		)
{
	(ret_stat) = pthread_create(
			&(ret_thrd).m_id
			, ae2f_reinterpret_cast(const pthread_attr_t*, NULL)
			, prm_func
			, prm_arg
			);

	switch(ret_stat) {
		case 0:
			(ret_stat) = ae2f_eSysThrdSuccess;
			break;

		case EAGAIN:
			(ret_stat) = ae2f_eSysThrdMemOut;
			break;

		case EINVAL:
		case EPERM:
		default:
			(ret_stat) = ae2f_eSysThrdErr;
			break;
	}
}

ae2f_MAC() ae2f_SysThrdJoin_imp(
		ae2f_eSysThrd_t		ret_stat,
		ae2f_SysThrdRes_t	ret_rtn,
		ae2f_SysThrd		ref_thrd
		)
{
	switch(pthread_join((ref_thrd).m_id, &(ret_rtn)))
	{
		case EDEADLK:
			(ret_stat) = ae2f_eSysThrdBusy;
			break;
		case EINVAL:
			(ret_stat) = (ae2f_eSysThrdErr);
			break;
		case ESRCH:
			(ret_stat) = (ae2f_eSysThrdMemOut);
			break;
		case 0:
			(ret_stat) = ae2f_eSysThrdSuccess;
			break;
	}
}


ae2f_MAC() ae2f_SysThrdSleep_imp(
		int ret_stat
		, const struct timespec * const prm_req
		, struct timespec * const prm_rem
		)
{
	(ret_stat) = nanosleep(prm_req, prm_rem);
}

ae2f_MAC() ae2f_SysThrdYield_imp()
{
	sched_yield();
}

#endif
#endif
