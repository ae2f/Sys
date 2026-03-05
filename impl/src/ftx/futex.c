/**
 * @file	futex.c
 * @brief	futex (sys/futex.h)
 * */

#ifndef	ae2fsys_ftx_futex_h
#define	ae2fsys_ftx_futex_h
#include <ae2f/Sys/.ftx/core.h>
#if	_AE2FSYS_FTX_FUTEX
/*********************/

#include <sys/time.h>
#include <sys/futex.h>
#include <ae2f/pat/macrofunc.h>

#define _ae2fsys_ftxlibdecl(tprm_export)
#define _ae2fsys_ftxlibdef(tprm_import)

ae2f_MAC((L, )) ae2fsys_ftxwait_imp(
		enum AE2FSYS_FTX_		ret_err,
		ae2fsys_ftxel_t* const		prm_uaddr,
		const ae2fsys_ftxel_t		prm_val,
		const struct timespec * const	pprm_time_opt
		) {
	switch(futex(prm_uaddr, FUTEX_WAIT, (int)prm_val, pprm_time_opt, 0))
	{
		case ENOSYS:
			(ret_err) = AE2FSYS_FTX_NO_IMP;
			break;
		case EFAULT:
			(ret_err) = AE2FSYS_FTX_PTRINVAL;
			break;
		case EAGAIN:
			(ret_err) = AE2FSYS_FTX_MISMATCH;
			break;
		case EINVAL:
			(ret_err) = AE2FSYS_FTX_INVAL;
			break;
		case ETIMEDOUT:
			(ret_err) = AE2FSYS_FTX_TMOUT;
			break;
		case EINTR:
			(ret_err) = AE2FSYS_FTX_INTERRUPTED;
			break;
		case ECANCELED:
			(ret_err) = AE2FSYS_FTX_CANCELED;
			break;
	}
}

ae2f_MAC((L, )) openbsd_ae2fsys_ftxwake_imp(
		enum AE2FSYS_FTX_	ret_err,
		ae2fsys_ftxel_t* const	prm_uaddr,
		const int		prm_numthrd
		)
{
	switch(futex(prm_uaddr, FUTEX_WAKE, prm_numthrd, 0, 0)) {
		case ENOSYS:
			(ret_err) = AE2FSYS_FTX_NO_IMP;
			break;
		case EFAULT:
			(ret_err) = AE2FSYS_FTX_PTRINVAL;
			break;
		case EAGAIN:
			(ret_err) = AE2FSYS_FTX_MISMATCH;
			break;
		case EINVAL:
			(ret_err) = AE2FSYS_FTX_INVAL;
			break;
		case ETIMEDOUT:
			(ret_err) = AE2FSYS_FTX_TMOUT;
			break;
		case EINTR:
			(ret_err) = AE2FSYS_FTX_INTERRUPTED;
			break;
		case ECANCELED:
			(ret_err) = AE2FSYS_FTX_CANCELED;
			break;
	}
}

#if	!__ae2f_MACRO_GENERATED
#define	_openbsd_ae2fsys_ftxwake_imp(L, ret_err, prm_uaddr, prm_numthrd)	\
	(void)(ret_err);(void)(prm_uaddr);
#endif

ae2f_MAC((L, )) ae2fsys_ftxwake_one_imp(
		enum AE2FSYS_FTX_	ret_err,
		ae2fsys_ftxel_t* const	prm_uaddr
		)
{
	_openbsd_ae2fsys_ftxwake_imp(L, ret_err, prm_uaddr, 1);
}


/*********************/
#endif
#endif
