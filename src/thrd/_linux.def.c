#ifndef ae2fsys_thrd__linux_auto_h
#define ae2fsys_thrd__linux_auto_h

#include <ae2f/Sys.h>
#include <stdatomic.h>

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
#include <stdlib.h>
#include <c89atomic.h>

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

typedef struct {
	/** 
	 * if 1, is done.
	 * This member must not be changed by multiple threads
	 * */
	ae2fsys_ftxel_t		m_done;
	ae2fsys_thrdres_t	m_ret;
	c89atomic_uint32	m_u32_atom;
}	_linux_ae2fsys_thrd_state_t;

typedef struct 
{
	/** @brief stack ptr */
	union {
		void* ae2f_restrict				m_void;
		char* ae2f_restrict				m_char;
		uintptr_t					m_uintptr;

	} m_stckbase__linux;

	void*			m_arg__linux;

	ae2fsys_thrdfn_t*	m_fn__linux;
	_linux_ae2fsys_thrd_state_t* ae2f_restrict	m_state__linux;


	/** @brief stack size (linux only) */
	size_t			m_stcksz__linux;
	long			m_pgsz__linux;

	/** @brief thread id */
	ae2fsys_tid_t		m_id;
} ae2fsys_thrd;



static ae2fsys_thrdres_t _linux_ae2fsys_thrd_runner(ae2fsys_thrdprm_t prm_stck) {
#define	prm_stck	ae2f_reinterpret_cast(ae2fsys_thrd* ae2f_restrict, prm_stck)

	_linux_ae2fsys_thrd_state_t* ae2f_restrict const
		STATE = prm_stck->m_state__linux;

	enum	AE2FSYS_FTXWAKE_
		ENUM;


	ae2f_expected_if(prm_stck && STATE) {
		/** child section */
		c89atomic_fetch_and_32(&STATE->m_u32_atom, 0);
		STATE->m_done = 0;
		STATE->m_ret = (prm_stck->m_fn__linux)((prm_stck)->m_arg__linux);
		STATE->m_done = 1;
		_ae2fsys_ftxwake_one_imp(L, ENUM, &STATE->m_done);
		c89atomic_fetch_or_32(&STATE->m_u32_atom, 1);
		(void)ENUM;
		return 0;
	}

	return -1;
#undef	prm_stck
}


#ifndef	_linux_ae2fsys_thrdstck_redzone
#define	_linux_ae2fsys_thrdstck_redzone	4096
#endif

#ifndef	_linux_ae2fsys_thrd_mk_stckallocsz
#define	_linux_ae2fsys_thrd_mk_stckallocsz(c_sz)	\
	(((c_sz)) + 31)
#endif


#ifndef	_linux_ae2fsys_thrd_mk_stckentry
#define	_linux_ae2fsys_thrd_mk_stckentry(rdwr_ptr, c_sz)	\
	(((ae2f_reinterpret_cast(uintptr_t, rdwr_ptr) + c_sz)) & ~ae2f_reinterpret_cast(uintptr_t, 31))
#endif



#if	!__ae2f_MACRO_GENERATED
#define	__linux_ae2fsys_mkthrd_imp	_linux_ae2fsys_mkthrd_imp
#endif

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

	(ret_thrd).m_stcksz__linux = 
		_linux_ae2fsys_thrd_mk_stckallocsz(prm_stcksz) + _linux_ae2fsys_thrdstck_redzone;

	(ret_thrd).m_pgsz__linux	= sysconf(_SC_PAGESIZE);

	(ret_thrd).m_stcksz__linux = 
		((ret_thrd).m_stcksz__linux + ae2f_static_cast(size_t, (ret_thrd).m_pgsz__linux - 1))
		& ae2f_static_cast(size_t, ~((ret_thrd).m_pgsz__linux - 1));

	(ret_thrd).m_stckbase__linux.m_void = mmap(
			ae2f_NIL
			, (ret_thrd).m_stcksz__linux
			, PROT_READ | PROT_WRITE 
			, MAP_PRIVATE | MAP_STACK | MAP_ANONYMOUS
			, -1, 0
			);

	ae2f_unexpected_but_if(mprotect((ret_thrd).m_stckbase__linux.m_void
				, ae2f_static_cast(size_t, (ret_thrd).m_pgsz__linux), PROT_NONE
				)) {
		munmap((ret_thrd).m_stckbase__linux.m_void, (ret_thrd).m_stcksz__linux);
		(ret_thrd).m_stckbase__linux.m_void = 0;
	} else {
		(ret_thrd).m_state__linux = ae2f_reinterpret_cast(
				_linux_ae2fsys_thrd_state_t*
				, malloc(sizeof(_linux_ae2fsys_thrd_state_t))
				);
	}

	ae2f_unexpected_but_if(
			MAP_FAILED == (ret_thrd).m_stckbase__linux.m_void 
			|| !(ret_thrd).m_stckbase__linux.m_void
			|| !(ret_thrd).m_state__linux)
	{
		unless(MAP_FAILED == (ret_thrd).m_stckbase__linux.m_void 
				|| !(ret_thrd).m_stckbase__linux.m_void)
		{
			munmap((ret_thrd).m_stckbase__linux.m_void, (ret_thrd).m_stcksz__linux);
		}

		free((ret_thrd).m_state__linux);

		(ret_stat) = AE2FSYS_THRD_MEMOUT;
		(ret_thrd).m_stckbase__linux.m_void = ae2f_NIL;
		(ret_thrd).m_state__linux = 0;
		(ret_thrd).m_id = -1;
	}
	else {
		(ret_thrd).m_arg__linux = (prm_arg);
		(ret_thrd).m_fn__linux = (prm_func);

		(ret_thrd).m_id = clone(
				ae2f_reinterpret_cast(
					ae2fsys_thrdfn_t*
					, _linux_ae2fsys_thrd_runner
					)
				, ae2f_reinterpret_cast(char*, _linux_ae2fsys_thrd_mk_stckentry(
						(ret_thrd).m_stckbase__linux.m_uintptr 
						+ (size_t)(ret_thrd).m_pgsz__linux
						, (ret_thrd).m_stcksz__linux 
						- _linux_ae2fsys_thrdstck_redzone))
				, (CLONE_VM | CLONE_FS | CLONE_FILES 
					| CLONE_SIGHAND | CLONE_THREAD 
					| CLONE_SYSVSEM)
				, &(ret_thrd)
				);

		switch((ret_thrd).m_id) {
			case -1:
				(ret_stat) = AE2FSYS_THRD_UNKNOWN;
				ae2f_fallthrough;
			case 0:
				ae2f_unreachable();
				break;
			default:
				(ret_stat) = AE2FSYS_THRD_GOOD;
				ae2f_unexpected_but_if((ret_stat))
				{
					munmap(
							(ret_thrd).m_stckbase__linux.m_void
							, (ret_thrd).m_stcksz__linux
					      );
					(ret_thrd).m_stckbase__linux.m_void = ae2f_NIL;
				}
				break;
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

	unless((prm_thrd).m_stckbase__linux.m_void && (prm_thrd).m_state__linux) {
		if((prm_thrd).m_stckbase__linux.m_void) {
			munmap(
					(prm_thrd).m_stckbase__linux.m_void
					, (prm_thrd).m_stcksz__linux);
		}

		free((prm_thrd).m_state__linux);
		(ret_stat) = AE2FSYS_THRD_UNKNOWN;
	}
	else {
		if(!c89atomic_load_32(&prm_thrd.m_state__linux->m_u32_atom)) {
			_ae2fsys_ftxwait_imp(
					L
					, L$$res
					, &(prm_thrd).m_state__linux->m_done
					, 0
					, 0
					);
		}

		(ret_rtn) = (prm_thrd).m_state__linux->m_ret;
		munmap((prm_thrd).m_stckbase__linux.m_void, (prm_thrd).m_stcksz__linux);
		free((prm_thrd).m_state__linux);

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
