/**
 * @file Futex.auto.h
 * */
#ifndef ae2f_Sys_Futex_auto_h
#include <ae2f/Sys/Ftx.h>
#define ae2f_Sys_Futex_auto_h

#include <ae2f/Macro.h>

#if ae2f_Sys_WIN(!)0

ae2f_MAC() ae2f_SysFtxWait(
		ae2f_SysFtxRet_t	ret_err,
		ae2f_SysFtxEl_t* const	prm_uaddr,
		const int		prm_val
		)
{
	int v_val = (prm_val);
	(ret_err) = !WaitOnAddress(prm_uaddr, &(v_val), sizeof(int), INFINITE);
}

ae2f_MAC() ae2f_SysFtxWakeOne(
		ae2f_SysFtxRet_t	ret_err,
		ae2f_SysFtxEl_t* const	prm_uaddr
		)
{
	WakeByAddressSingle(ae2f_reinterpret_cast(PVOID, uaddr));
	(ret_err) = 0;
}

#elif ae2f_Sys__linux(!)0

ae2f_MAC() ae2f_SysFtxWait(
		ae2f_SysFtxRet_t	ret_err,
		ae2f_SysFtxEl_t* const	prm_uaddr,
		const int		prm_val
		)
{
	(ret_err) = syscall(SYS_futex, prm_uaddr, FUTEX_WAIT, prm_val, NULL, NULL, 0);
}

ae2f_MAC() ae2f_SysFtxWake(
		ae2f_SysFtxRet_t	ret_err,
		ae2f_SysFtxEl_t* const	prm_uaddr,
		const int		prm_numthrd
		)
{
	(ret_err) = syscall(SYS_futex, prm_uaddr, FUTEX_WAKE, prm_numthrd, NULL, NULL, 0);
}

ae2f_MAC() ae2f_SysFtxWakeOne(ae2f_SysFtxRet_t ret_err, ae2f_SysFtxEl_t* const prm_uaddr)	{
	_ae2f_SysFtxWake(ret_err, prm_uaddr, 1);
}

#else

static pthread_mutex_t __ae2f_sSysFtxMtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t __ae2f_sSysFtxCnd = PTHREAD_COND_INITIALIZER;

ae2f_MAC() ae2f_SysFtxWait(
		ae2f_SysFtxRet_t	ret_err,
		ae2f_SysFtxEl_t* const	prm_uaddr,
		const int		prm_val
		)
{

	if(pthread_mutex_lock(&__ae2f_sSysFtxMtx))
	{
		errno = EAGAIN;
		(ret_err) = -1;
	} else do {
		while(*(prm_uaddr) == (v))
		{
			if(pthread_cond_wait(&__ae2f_sSysFtxCnd, &__ae2f_sSysFtxMtx))
			{
				errno = EAGAIN;
				(ret_err) = -1;
				break;
			}
		}

		if((ret_err)) break;

		if(pthread_mutex_unlock(&__ae2f_sSysFtxMtx))
		{
			errno = EAGAIN;
			(ret_err) = -1;
			break;
		}

		(ret_err) = 0;
	} while(0);
}

ae2f_MAC() ae2f_SysFtxWakeOne(ae2f_SysFtxRet_t ret_err, ae2f_SysFtxEl_t* const prm_uaddr)
{
	if(pthread_mutex_lock(&__ae2f_sSysFtxMtx))
	{
		errno = EAGAIN;
		(ret_err) = -1;
	} else do {
		if(pthread_cond_signal(&(__ae2f_sSysFtxMtx))) {
			errno = EAGAIN;
			(ret_err) = -1;
			break;
		}

		if(pthread_mutex_unlock(&(__ae2f_sSysFtxMtx))) {
			errno = EAGAIN;
			(ret_err) = -1;
			break;
		}

		(ret_err) = 0;
	} while(0);
}

#endif

#endif
