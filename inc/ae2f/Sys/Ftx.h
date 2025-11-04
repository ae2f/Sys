/** 
 * @file Ftx.h
 * System call which makes thread wait until certain memory changes.
 * */

#ifndef ae2f_Sys_Futex_h
#define ae2f_Sys_Futex_h

#include "../Sys.h"

#if (ae2f_Sys_WIN(!)0 || ae2f_Sys__linux(!)0)
#define N_ae2f_SysFtx_POSIX(...)	__VA_ARGS__
#define ae2f_SysFtx_POSIX(...)
#else
#define N_ae2f_SysFtx_POSIX(...)
#define ae2f_SysFtx_POSIX(...)		__VA_ARGS__
#endif

#include "./Ftx.core.h"

#define _ae2f_SysFtxEl_t	\
	ae2f_Sys_WIN(_ae2f_SysFtxEl_WIN)	\
	ae2f_Sys__linux(_ae2f_SysFtxEl__linux)	\
	ae2f_SysFtx_POSIX(_ae2f_SysFtxEl_POSIX)	\


/** @brief Futex address element type. */
typedef _ae2f_SysFtxEl_t	ae2f_SysFtxEl_t;

#define _ae2f_SysFtxRet_t				\
	ae2f_Sys_WIN(_ae2f_SysFtxRet_WIN)		\
	ae2f_Sys__linux(_ae2f_SysFtxRet__linux)		\
	ae2f_SysFtx_POSIX(_ae2f_SysFtxRet_POSIX)	\

#define ae2f_SysFtxLibDeclare(tprm_import)				\
	ae2f_Sys_WIN(ae2f_SysFtxLibDeclare_WIN(tprm_import))		\
ae2f_Sys__linux(ae2f_SysFtxLibDeclare__linux(tprm_import))		\
ae2f_SysFtx_POSIX(ae2f_SysFtxLibDeclare_POSIX(tprm_import))

#define ae2f_SysFtxLibDefine(tprm_export)	\
	ae2f_Sys_WIN(ae2f_SysFtxLibDefine_WIN(tprm_export))		\
ae2f_Sys__linux(ae2f_SysFtxLibDeclare__linux(tprm_export))		\
ae2f_Sys_POSIX(ae2f_SysFtxLibDeclare_POSIX(tprm_export))

/**
 * @def _ae2f_SysFtxWaitWithTmOut
 * */
#define _ae2f_SysFtxWaitWithTmOut(ramtmp_wait, ret_err, pprm_uaddr, prm_val, pprm_tm_opt)		\
	ae2f_Sys_WIN(_ae2f_SysFtxWait_imp_WIN(ramtmp_wait, ret_err, pprm_uaddr, prm_val, pprm_tm_opt))	\
ae2f_Sys__linux(_ae2f_SysFtxWait_imp__linux(ramtmp_wait, ret_err, pprm_uaddr, prm_val, pprm_tm_opt))	\
ae2f_SysFtx_POSIX(_ae2f_SysFtxWait_imp_POSIX(ramtmp_wait, ret_err, pprm_uaddr, prm_val, pprm_tm_opt))

#define _ae2f_SysFtxWait(ret_err, pprm_uaddr, prm_val)	{				\
	ae2f_Sys_WIN(ae2f_SysFtxEl_t	v_ftxwait);					\
	_ae2f_SysFtxWaitWithTmOut(v_ftxwait, ret_err, pprm_uaddr, prm_val, NULL);	\
}

#define _ae2f_SysFtxWakeOne(ret_err, pprm_uaddr)	\
	ae2f_Sys_WIN(_ae2f_SysFtxWakeOne_WIN(ret_err, pprm_uaddr))	\
ae2f_Sys__linux(_ae2f_SysFtxWakeOne__linux(ret_err, pprm_uaddr))	\
ae2f_SysFtx_POSIX(_ae2f_SysFtxWake_POSIX(ret_err, pprm_uaddr))	\


#endif
