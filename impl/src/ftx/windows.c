/** 
 * @file	windows.c 
 * @brief	WaitOnAddress | WakeByAddressSingle
 * */

#ifndef	ae2fsys_ftx_windows_h
#define	ae2fsys_ftx_windows_h
#include <ae2f/Sys/.ftx/core.h>
#if	_AE2FSYS_FTX_WINDOWS

/***********************************/

#include <windows.h>
#include <ae2f/pat/macrofunc.h>

typedef	volatile LONG ae2fsys_ftxel_t;

ae2f_MAC((L, )) ae2fsys_ftxwait_imp(
		enum AE2FSYS_FTXWAIT_		ret_err,
		ae2fsys_ftxel_t* const		prm_uaddr,
		const ae2f_SysFtxEl_t		prm_val
		const struct timespec * const	pprm_time_opt
		)
{
	ae2fsys_ftxel_t L = (prm_val);
	switch((ret_err) = WaitOnAddress(
			prm_uaddr
			, L
			, sizeof(ae2f_SysFtxEl_t)
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
