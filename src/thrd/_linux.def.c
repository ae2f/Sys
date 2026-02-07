#ifndef ae2fsys_thrd__linux_auto_h
#define ae2fsys_thrd__linux_auto_h

#include <ae2f/Sys.h>

#if ae2f_Sys__linux(!)0

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <sys/mman.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sched.h>
#include <linux/sched.h>
#include <signal.h>

#include <ae2f/Sys/Ftx.h>
#include <ae2f/Sys/Thrd.core.h>
#include <ae2f/c90/StdInt.h>
#include <ae2f/Keys.h>
#include <ae2f/Macro.h>
#include <ae2f/Cast.h>

typedef int	ae2fsys_thrdres_t;
typedef void*	ae2fsys_thrdprm_t;
typedef int	ae2fsys_tid_t;
typedef ae2fsys_thrdres_t ae2fsys_thrdfn_t(ae2fsys_thrdprm_t);


typedef struct 
{

	int_least64_t		m_ftxret;
	size_t			m_stcksz;
	void*			m_arg;


	int			m_ret;
	/** 
	 * if 1, is done.
	 * This member must not be changed by multiple threads
	 * */
	ae2fsys_ftxel_t		m_done;

	ae2fsys_thrdfn_t*	m_fn;
} _linux_ae2fsys_thrd_runner_prm;


static ae2fsys_thrdres_t _linux_ae2fsys_thrd_runner(_linux_ae2fsys_thrd_runner_prm* prm_stck) {
	(void)_linux_ae2fsys_thrd_runner;

	if(prm_stck) {
		/** child section */
		(prm_stck)->m_done = 0;
		(prm_stck)->m_ret = (prm_stck->m_fn)((prm_stck)->m_arg);
		(prm_stck)->m_done = 1;

		_ae2fsys_ftxwake_one_imp(
				L, (prm_stck)->m_ftxret
				, &(prm_stck)->m_done
				);

		return 0;
	}

	return -1;
}

/**
 * @macro _linux_ae2fsys_thrd_stcktop_oper
 * A macro to make top pointer.
 * */
#ifndef _linux_ae2fsys_thrd_stcktop_oper
#define _linux_ae2fsys_thrd_stcktop_oper(prm_ptr, prm_sz)	\
	((prm_ptr) + (prm_sz))
#endif

typedef union
{
	void* ae2f_restrict				m_void;
	char* ae2f_restrict				m_char;
	_linux_ae2fsys_thrd_runner_prm* ae2f_restrict	m_prm;
} _linux_ae2fsys_ptr_thrdstck_t;


typedef struct 
{
	/** @brief thread id */
	ae2fsys_tid_t	m_id;

	/** @brief stack ptr */
	_linux_ae2fsys_ptr_thrdstck_t	m_stck__linux;

	/** @brief stack size (linux only) */
	size_t				m_stcksz__linux;
} ae2fsys_thrd;


#if	!__ae2f_MACRO_GENERATED
#define	__linux_ae2fsys_mkthrd_imp	_linux_ae2fsys_mkthrd_imp
#endif

ae2f_MAC() _linux_ae2fsys_mkthrd_imp(
		enum AE2FSYS_THRD_				ret_stat,
		ae2fsys_tid_t					ret_tid,
		_linux_ae2fsys_thrd_runner_prm* ae2f_restrict const
								prm_stck,
		void* ae2f_restrict const			prm_stcktop
		)
{
	(ret_tid) = clone(
			ae2f_reinterpret_cast(
				ae2fsys_thrdfn_t*
				, _linux_ae2fsys_thrd_runner
				)
			, (prm_stcktop)
			, (CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_THREAD | CLONE_SYSVSEM)
			, (prm_stck)
			);

	switch((ret_tid)) {
		case -1:
			(ret_stat) = AE2FSYS_THRD_UNKNOWN;
			break;
		case 0:
			syscall(SYS_exit, 0);
			break;
		default:
			(ret_stat) = AE2FSYS_THRD_GOOD;
			break;
	}
}


/**
 * @brief
 * Create a thread.
 * */
ae2f_MAC() ae2fsys_mk_thrd_imp(
		enum AE2FSYS_THRD_	ret_stat,
		ae2fsys_thrd		ret_thrd,
		ae2fsys_thrdfn_t* const	prm_func,
		void* const		prm_arg,
		const size_t		prm_stcksz
		)
{
	(ret_thrd).m_stck__linux.m_void = mmap(
			ae2f_NIL, ((ret_thrd).m_stcksz__linux = (
					(prm_stcksz)
					+ ae2f_static_cast(size_t, sizeof(_linux_ae2fsys_thrd_runner_prm))
					+ ae2f_static_cast(size_t, sizeof(void*))
					)
			      )
			, PROT_READ | PROT_WRITE
			, MAP_PRIVATE | MAP_STACK | MAP_ANONYMOUS
			, -1, 0
			);

	if(MAP_FAILED == (ret_thrd).m_stck__linux.m_void || !(ret_thrd).m_stck__linux.m_void) {
		(ret_stat) = AE2FSYS_THRD_MEMOUT;
		(ret_thrd).m_stck__linux.m_void = ae2f_NIL;
		(ret_thrd).m_id = -1;
	}
	else {
		(ret_thrd).m_stck__linux.m_prm->m_arg = (prm_arg);
		(ret_thrd).m_stck__linux.m_prm->m_fn = (prm_func);
		(ret_thrd).m_stck__linux.m_prm->m_stcksz = (ret_thrd).m_stcksz__linux;

		__linux_ae2fsys_mkthrd_imp(
				ret_stat, (ret_thrd).m_id
				, (ret_thrd).m_stck__linux.m_prm
				, _linux_ae2fsys_thrd_stcktop_oper(
					(ret_thrd).m_stck__linux.m_char
					, (prm_stcksz)
					)
				);

		ae2f_unexpected_but_if((ret_stat))
		{
			munmap(
					(ret_thrd).m_stck__linux.m_void
					, (ret_thrd).m_stcksz__linux
			      );
			(ret_thrd).m_stck__linux.m_void = ae2f_NIL;
		}
	}
}


ae2f_MAC((L, )) ae2fsys_join_thrd_imp(
		enum AE2FSYS_THRD_	ret_stat,
		ae2fsys_thrdres_t	ret_rtn,
		const ae2fsys_thrd	prm_thrd
		)
{
	enum AE2FSYS_FTXWAIT_	L$$res = AE2FSYS_FTXWAIT_GOOD;

	unless((prm_thrd).m_stck__linux.m_void) {
		(ret_stat) = AE2FSYS_THRD_UNKNOWN;
	}
	else {
		unless((prm_thrd).m_stck__linux.m_prm->m_done) {
			_ae2fsys_ftxwait_imp(
					L
					, L$$res
					, &(prm_thrd).m_stck__linux.m_prm->m_done
					, 0
					, 0
					);

			(ret_rtn) = (prm_thrd).m_stck__linux.m_prm->m_ret;
			munmap((prm_thrd).m_stck__linux.m_void, (prm_thrd).m_stcksz__linux);
		}

		if(L$$res) {
			(ret_stat) = AE2FSYS_THRD_UNKNOWN;
		} else {
			(ret_stat) = AE2FSYS_THRD_GOOD;
		}
	}
}

ae2f_MAC() ae2fsys_yield_thrd_imp(void)
{
	syscall(SYS_sched_yield);
}

ae2f_MAC() ae2fsys_sleep_thrd_imp(
		long ret_stat
		, const struct timespec * const prm_req
		, struct timespec * const prm_rem
		)
{
	(ret_stat) = syscall(SYS_nanosleep, prm_req, prm_rem);
}

#endif

#endif
