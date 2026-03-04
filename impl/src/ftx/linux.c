/** 
 * @file	linux.c 
 * @brief	futex
 * */

#ifndef	ae2fsys_ftx_linux_h
#define	ae2fsys_ftx_linux_h

#include <ae2f/Sys/.ftx/core.h>

#if	_AE2FSYS_PROBE_LINUX

/******************************/

#include <ae2f/pat/macrofunc.h>
#include <time.h>
#include <errno.h>
#include <sys/syscall.h>
#include <linux/futex.h>
#include <unistd.h>

typedef	int ae2fsys_ftxel_t;


ae2f_MAC((L, )) ae2fsys_ftxwait_imp(
		enum AE2FSYS_FTX_		ret_err,
		ae2fsys_ftxel_t* const		prm_uaddr,
		const ae2fsys_ftxel_t		prm_val,
		const struct timespec * const	pprm_time_opt
		)
{
	switch(syscall(SYS_futex, prm_uaddr, FUTEX_WAIT
				, prm_val, pprm_time_opt, NULL, 0) == 1
		? errno : 0)
	{
		case ETIMEDOUT:
			(ret_err) = AE2FSYS_FTX_TMOUT;
			break;
		case EINVAL:
			(ret_err) = AE2FSYS_FTX_INVAL;
			break;
		case EAGAIN:
			(ret_err) = AE2FSYS_FTX_MISMATCH;
			break;
		case EFAULT:
			(ret_err) = AE2FSYS_FTX_PTRINVAL;
			break;
		case EINTR:
			(ret_err) = AE2FSYS_FTX_INTERRUPTED;
			break;
		case ENOSYS:
			(ret_err) = AE2FSYS_FTX_NO_IMP;
			break;
		case EPERM:
			(ret_err) = AE2FSYS_FTX_MTXNOWN;
			break;
		default:
			(ret_err) = AE2FSYS_FTX_UNKNOWN;
			break;
		case 0:	
			(ret_err) = 0;
			break;
	}
}

ae2f_MAC((L, )) linux_ae2fsys_ftxwake_imp(
		enum AE2FSYS_FTX_	ret_err,
		ae2fsys_ftxel_t* const	prm_uaddr,
		const int		prm_numthrd
		)
{

	switch(syscall(SYS_futex, prm_uaddr, FUTEX_WAKE, prm_numthrd, NULL, NULL, 0))
	{
		case 0:
			(ret_err) = AE2FSYS_FTX_GOOD;
			break;
		case ENOSYS:
			(ret_err) = AE2FSYS_FTX_NO_IMP;
			break;
		case EINVAL:
			(ret_err) = AE2FSYS_FTX_INVAL;
			break;
		case EFAULT:
			(ret_err) = AE2FSYS_FTX_PTRINVAL;
			break;
		case EPERM:
			(ret_err) = AE2FSYS_FTX_MTXOWNDEAD;
			break;
		default:
			(ret_err) = AE2FSYS_FTX_UNKNOWN;
			break;
	}
}

#if	!__ae2f_MACRO_GENERATED
#define	_linux_ae2fsys_ftxwake_imp(L, ret_err, prm_uaddr, prm_numthrd)	\
	(void)(ret_err);(void)(prm_uaddr);
#endif

ae2f_MAC((L, )) ae2fsys_ftxwake_one_imp(
		enum AE2FSYS_FTX_	ret_err,
		ae2fsys_ftxel_t* const	prm_uaddr
		)
{
	_linux_ae2fsys_ftxwake_imp(L, ret_err, prm_uaddr, 1);
}

/******************************/

#endif
#endif
