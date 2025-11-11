/**
 * @file Futex-_linux.auto.h
 * */
#ifndef ae2f_Sys_Futex_linux__auto_h
#include <ae2f/Sys/Ftx-_linux.h>
#define ae2f_Sys_Futex_linux__auto_h

#include <ae2f/Cast.h>
#include <ae2f/Macro.h>

#include <errno.h>

#if ae2f_Sys__linux(!)0

/**
 * @brief
 * @retval ae2f_eSysFtxWait
 * */
ae2f_MAC(unused_0, ) ae2f_SysFtxWait_imp__linux(
		ae2f_eSysFtxWait		ret_err,
		ae2f_SysFtxEl_t* const		prm_uaddr,
		const int			prm_val,
		const struct timespec * const	pprm_time_opt
		)
{
	(ret_err) = syscall(SYS_futex, prm_uaddr, FUTEX_WAIT, prm_val, pprm_time_opt, NULL, 0) == -1 ? 
		ae2f_static_cast(ae2f_eSysFtxWait, (errno)) : 
		ae2f_SysFtxWait_GOOD
		;
}

ae2f_MAC() ae2f_SysFtxWake__linux(
		ae2f_eSysFtxWake	ret_err,
		ae2f_SysFtxEl_t* const	prm_uaddr,
		const int		prm_numthrd
		)
{
	(ret_err) = ae2f_static_cast(
			ae2f_eSysFtxWake
			, syscall(SYS_futex, prm_uaddr, FUTEX_WAKE, prm_numthrd, NULL, NULL, 0)
			);
}

ae2f_MAC() ae2f_SysFtxWakeOne__linux(ae2f_eSysFtxWake ret_err, ae2f_SysFtxEl_t* const prm_uaddr) {
	_ae2f_SysFtxWake__linux(ret_err, prm_uaddr, 1);
}

#endif
#endif
