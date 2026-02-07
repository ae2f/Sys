/**
 * @file	WIN.auto.h
 * */

#ifndef	ae2fsys_WIN_auto_h
#define	ae2fsys_WIN_auto_h

#include <ae2f/Macro.h>
#include <ae2f/Sys.h>

#if	ae2f_Sys_WIN(!)0
#include <windows.h>
#include <time.h>
#include <assert.h>

typedef	DWORD	ae2fsys_thrdres_t;
typedef LPVOID	ae2fsys_thrdprm_t;
typedef HANDLE	ae2fsys_tid_t;
typedef ae2fsys_thrdres_t ae2fsys_thrdfn_t(ae2fsys_thrdprm_t);

typedef struct 
{
	/** @brief thread id */
	ae2fsys_tid_t	m_id;
} ae2fsys_thrd;


ae2f_MAC() ae2fsys_mk_thrd_imp(
		enum AE2FSYS_THRD_	ret_stat,
		ae2fsys_thrd		ret_thrd,
		ae2fsys_thrdfn_t* const	prm_func,
		const ae2fsys_thrdprm_t	prm_arg,
		const size_t		prm_stcksz
		)
{
	(ret_stat) = ((ret_thrd).m_id = 
		CreateThread(
				NULL
				, prm_stcksz
				, prm_func
				, prm_arg
				, STACK_SIZE_PARAM_IS_A_RESERVATION
				, NULL
			    ))
		? AE2FSYS_THRD_GOOD
		: AE2FSYS_THRD_UNKNOWN;
}

ae2f_MAC((L, )) ae2fsys_join_thrd_imp(
		enum AE2FSYS_THRD_	ret_stat,
		ae2fsys_thrdres_t	ret_rtn,
		const ae2fsys_thrd	prm_thrd
		)
{
	(ret_stat)
		= (
				WaitForSingleObject((prm_thrd).m_id, INFINITE) 
				&& GetExitCodeThread((prm_thrd).m_id, &(ret_rtn))
				&& CloseHandle((prm_thrd).m_id)
		  ) ? AE2FSYS_THRD_GOOD : AE2FSYS_THRD_UNKNOWN;
}



ae2f_MAC() ae2fsys_yield_thrd_imp(void)
{
	SwitchToThread();
}

ae2f_MAC() ae2fsys_sleep_thrd_imp(
		int ret_stat
		, const struct timespec * const prm_req
		, struct timespec * const prm_rem
		)
{
	assert(prm_req);
	assert(prm_rem);

	if (
			(prm_req) == NULL || 
			(prm_req)->tv_sec < 0 || 
			(prm_req)->tv_nsec < 0 || 
			(prm_req)->tv_nsec >= 1000000000
	   )
	{
		SetLastError(ERROR_INVALID_PARAMETER);
		(ret_stat) = -1;
	} else {
		Sleep((DWORD)((prm_req)->tv_sec * 1000 + (prm_req)->tv_nsec / 1000000));
		(prm_rem)->tv_sec = 0;
		(prm_rem)->tv_nsec = 0;
		(ret_stat) = 0;
	}
}



#endif

#endif
