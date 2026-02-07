#ifndef	ae2fsys_thrd_POSIX_auto_h
#define ae2fsys_thrd_POSIX_auto_h

#include <ae2f/Sys.h>

#if !(ae2f_Sys__linux(!)0 || ae2f_Sys_WIN(!)0)

#include <pthread.h>
#include <errno.h>
#include <sched.h>

#include <ae2f/Sys/Thrd.core.h>

typedef	void*		ae2fsys_thrdres_t;
typedef	void*		ae2fsys_thrdprm_t;
typedef pthread_t	ae2fsys_tid_t;
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
		void* const		prm_arg,
		const size_t		prm_stcksz_unused
		)
{
	switch(pthread_create(
			&(ret_thrd).m_id
			, ae2f_reinterpret_cast(const pthread_attr_t*, NULL)
			, prm_func
			, prm_arg
			)) {
		case 0:
			(ret_stat) = AE2FSYS_THRD_GOOD;
			break;

		case EAGAIN:
			(ret_stat) = AE2FSYS_THRD_MEMOUT;
			break;

		case EINVAL:
		case EPERM:
		default:
			(ret_stat) = AE2FSYS_THRD_UNKNOWN;
			break;
	}
}

ae2f_MAC((L, )) ae2fsys_join_thrd_imp(
		enum AE2FSYS_THRD_	ret_stat,
		ae2fsys_thrdres_t	ret_rtn,
		ae2fsys_thrd		ref_thrd
		)
{
	ae2fsys_thrdres_t	L$$ret = ae2f_reinterpret_cast(ae2fsys_thrdres_t, -1);
	switch(pthread_join((ref_thrd).m_id, &(L$$ret)))
	{
		case EDEADLK:
			(ret_stat) = AE2FSYS_THRD_BUSY;
			break;

		default:
		case EINVAL:
			(ret_stat) = AE2FSYS_THRD_UNKNOWN;
			break;
		case ESRCH:
			(ret_stat) = AE2FSYS_THRD_MEMOUT;
			break;
		case 0:
			(ret_stat) = AE2FSYS_THRD_GOOD;
			break;
	}

	(ret_rtn) = L$$ret;
}


ae2f_MAC() ae2fsys_sleep_thrd_imp(
		int ret_stat
		, const struct timespec * const prm_req
		, struct timespec * const prm_rem
		)
{
	(ret_stat) = nanosleep(prm_req, prm_rem);
}

ae2f_MAC() ae2fsys_yield_thrd_imp()
{
	sched_yield();
}

#endif

#endif
