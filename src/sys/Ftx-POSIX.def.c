#ifndef ae2f_Sys_Ftx_POSIX_auto_h

#include <ae2f/Keys.h>
#if ae2f_conddef(__ae2f_MACRO_GENERATED)
#else
#include <ae2f/Sys/Ftx.h>
#endif

#define ae2f_Sys_Ftx_POSIX_auto_h
#if ae2f_SysFtx_POSIX(!)0

#if __ae2f_MACRO_GENERATED
#else
#include <ae2f/Macro.h>
ae2f_SysFtxLibDeclare_POSIX(static);
ae2f_SysFtxLibDefine_POSIX(static);
#endif

ae2f_MAC(UNUSED, ) ae2f_SysFtxWait_imp_POSIX(
		ae2f_eSysFtxWait	ret_err,
		ae2f_SysFtxEl_t* const	prm_uaddr,
		const int		prm_val,
		const struct timespec* const pprm_timeout
		)
{
	if((ret_err) = pthread_mutex_lock(&__ae2f_gSysFtxMtx));
	else do {
		while(*(prm_uaddr) == (v))
		{
			if((ret_err) = (pprm_timeout) 
					? pthread_cond_timedwait(&__ae2f_gSysFtxCnd, &__ae2f_gSysFtxCnd, pprm_timeout)
					: pthread_cond_wait(&__ae2f_gSysFtxCnd, &__ae2f_gSysFtxMtx))
			{
				break;
			}
		}

		if((ret_err)) break;

		if((ret_err) = pthread_mutex_unlock(&__ae2f_gSysFtxMtx))
		{
			break;
		}

		(ret_err) = ae2f_SysFtxWait_GOOD;
	} while(0);
}

ae2f_MAC() ae2f_SysFtxWakeOne(ae2f_eSysFtxWake ret_err, ae2f_SysFtxEl_t* const prm_uaddr)
{
	if((ret_err) = pthread_mutex_lock(&__ae2f_gSysFtxMtx))
	else do {
		if((ret_err) = pthread_cond_signal(&(__ae2f_gSysFtxMtx))) {
			break;
		}

		if((ret_err) = pthread_mutex_unlock(&(__ae2f_gSysFtxMtx))) {
			break;
		}

		(ret_err) = ae2f_SysFtxWake_GOOD;
	} while(0);
}


#endif
#endif
