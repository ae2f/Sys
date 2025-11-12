
#include <ae2f/Macro.h>

/**
 * @file Futex.auto.h
 * */
#ifndef ae2f_Sys_Futex_auto_h
#include <ae2f/Sys/Ftx.h>
#define ae2f_Sys_Futex_auto_h


#if ae2f_Sys_WIN(!)0

ae2f_MAC() ae2f_SysFtxWait_imp_WIN(
		ae2f_SysFtxEl_t		ramtmp_wait,
		ae2f_SysFtxRet_t	ret_err,
		ae2f_SysFtxEl_t* const	prm_uaddr,
		const ae2f_SysFtxEl_t	prm_val
		const struct timespec * const	pprm_time_opt
		)
{
	(ramtmp_wait) = (prm_val);
	(ret_err) = WaitOnAddress(
			prm_uaddr
			, &(ramtmp_wait)
			, sizeof(ae2f_SysFtxEl_t)
			, (pprm_time_opt) ? (pprm_time_opt)->tv_nsec + (pprm_time_opt)->tv_sec * 1000 : INFINITE
			)
		? ae2f_SysFtxWait_GOOD
		: ae2f_SysFtxWait_TMOUT;
}

ae2f_MAC() ae2f_SysFtxWakeOne_WIN(
		ae2f_SysFtxRet_t	ret_err,
		ae2f_SysFtxEl_t* const	prm_uaddr
		)
{
	WakeByAddressSingle(ae2f_reinterpret_cast(PVOID, uaddr));
	(ret_err) = ae2f_SysFtxWake_GOOD;
}

#endif
#endif
