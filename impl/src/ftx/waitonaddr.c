/** 
 * @file	waitonaddr.c 
 * @brief	win32
 * */

#ifndef	ae2fsys_ftx_waitonaddr_h
#define	ae2fsys_ftx_waitonaddr_h
#include <ae2f/Sys/.ftx/core.h>
#if	_AE2FSYS_FTX_WAITONADDR

/***********************************/

#include <windows.h>
#include <ae2f/Keys.h>
#include <ae2f/pat/macrofunc.h>

typedef	volatile LONG ae2fsys_ftxel_t;

ae2f_MAC((L, )) ae2fsys_ftxwait_imp(
		enum AE2FSYS_FTXWAIT_		ret_err,
		ae2fsys_ftxel_t* const		prm_uaddr,
		const ae2fsys_ftxel_t		prm_val,
		const struct timespec * const	pprm_time_opt
		)
{
	LONG L = (prm_val);
	switch(WaitOnAddress(
			prm_uaddr
			, &L
			, sizeof(ae2fsys_ftxel_t)
			, (pprm_time_opt)
			? (pprm_time_opt)->tv_nsec + (pprm_time_opt)->tv_sec * 1000 
			: INFINITE
			)
		? 0
		: GetLastError())
	{
		case 0:
			(ret_err) = AE2FSYS_FTX_GOOD;
			break;
		case ERROR_TIMEOUT:
			(ret_err) = AE2FSYS_FTX_TMOUT;
			break;
		default:
			(ret_err) = AE2FSYS_FTX_UNKNOWN;
	}
}

ae2f_MAC((L, )) ae2fsys_ftxwake_one_imp(
		enum AE2FSYS_FTX_	ret_err,
		ae2fsys_ftxel_t* const	prm_uaddr
		)
{
	WakeByAddressSingle(ae2f_reinterpret_cast(PVOID, prm_uaddr));
	(ret_err) = AE2FSYS_FTX_GOOD;
}


/***********************************/

#endif
#endif
