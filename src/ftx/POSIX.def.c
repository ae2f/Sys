#ifndef ae2fsys_ftx_POSIX_auto_h
#define ae2fsys_ftx_POSIX_auto_h


#include <ae2f/Sys.h>
#include <ae2f/Sys/Ftx.core.h>
#include <ae2f/Macro.h>
#include <ae2f/Keys.h>

#if (ae2f_Sys_WIN(!)0 || ae2f_Sys__linux(!)0)
#define N_ae2f_SysFtx_POSIX(a)	a
#define ae2f_SysFtx_POSIX(a)
#else
#define N_ae2f_SysFtx_POSIX(a)
#define ae2f_SysFtx_POSIX(a)	a	
#endif

#if ae2f_SysFtx_POSIX(!)0

#include <pthread.h>
#include <errno.h>
#include <ae2f/c90/StdInt.h>

typedef	int32_t ae2fsys_ftxel_t;

#define _ae2fsys_ftxlibdecl(tprm_export) \
	key_export pthread_mutex_t __ae2f_gSysFtxMtx = PTHREAD_MUTEX_INITIALIZER; \
	key_export pthread_cond_t __ae2f_gSysFtxCnd = PTHREAD_COND_INITIALIZER;


#define _ae2fsys_ftxlibdef(tprm_import) \
	key_extern pthread_mutex_t	__ae2f_gSysFtxMtx; \
	key_extern pthread_cond_t	__ae2f_gSysFtxCnd;

#if !__ae2f_MACRO_GENERATED
_ae2fsys_ftxlibdecl(static);
_ae2fsys_ftxlibdef(static);
#endif

ae2f_MAC((L, )) ae2fsys_ftxwait_imp(
		enum AE2FSYS_FTXWAIT_	ret_err,
		ae2fsys_ftxel_t* const	prm_uaddr,
		const ae2fsys_ftxel_t	prm_val,
		const struct timespec* const pprm_timeout
		)
{
	switch(pthread_mutex_lock(&__ae2f_gSysFtxMtx))
	{
		case 0: 
			(ret_err) = AE2FSYS_FTXWAIT_GOOD;
			break;
		default:
			(ret_err) = AE2FSYS_FTXWAIT_UNKNOWN;
			break;
		case ETIMEDOUT:
			(ret_err) = AE2FSYS_FTXWAIT_TMOUT;
			break;
		case EINVAL:
			(ret_err) = AE2FSYS_FTXWAIT_INVAL;
			break;
		case ENOTRECOVERABLE:
			(ret_err) = AE2FSYS_FTXWAIT_MTXNCOVERABLE;
			break;
		case EOWNERDEAD:
			(ret_err) = AE2FSYS_FTXWAIT_MTXOWNDEAD;
			break;
		case EDEADLK:
			(ret_err) = AE2FSYS_FTXWAIT_MTXBLK;
			break;
		case EPERM:
			(ret_err) = AE2FSYS_FTXWAIT_MTXNOWN;
			break;
		case EFAULT:
			(ret_err) = AE2FSYS_FTXWAIT_PTRINVAL;
			break;
	}

	ae2f_unexpected_else((ret_err)) {
		while(ae2f_expected(!(ret_err)) && *(prm_uaddr) == (prm_val))
		{
			switch(
					((pprm_timeout)
					 ? pthread_cond_timedwait(&__ae2f_gSysFtxCnd, &__ae2f_gSysFtxCnd, pprm_timeout)
					 : pthread_cond_wait(&__ae2f_gSysFtxCnd, &__ae2f_gSysFtxMtx))
			      )
			{
				case 0: 
					(ret_err) = AE2FSYS_FTXWAIT_GOOD;
					break;
				default:
					(ret_err) = AE2FSYS_FTXWAIT_UNKNOWN;
					break;
				case ETIMEDOUT:
					(ret_err) = AE2FSYS_FTXWAIT_TMOUT;
					break;
				case EINVAL:
					(ret_err) = AE2FSYS_FTXWAIT_INVAL;
					break;
				case ENOTRECOVERABLE:
					(ret_err) = AE2FSYS_FTXWAIT_MTXNCOVERABLE;
					break;
				case EOWNERDEAD:
					(ret_err) = AE2FSYS_FTXWAIT_MTXOWNDEAD;
					break;
				case EDEADLK:
					(ret_err) = AE2FSYS_FTXWAIT_MTXBLK;
					break;
				case EPERM:
					(ret_err) = AE2FSYS_FTXWAIT_MTXNOWN;
					break;
				case EFAULT:
					(ret_err) = AE2FSYS_FTXWAIT_PTRINVAL;
					break;
			}
		}

		ae2f_unexpected_else((ret_err)) switch(pthread_mutex_unlock(&__ae2f_gSysFtxMtx))
		{
			case 0: 
				(ret_err) = AE2FSYS_FTXWAIT_GOOD;
				break;
			default:
				(ret_err) = AE2FSYS_FTXWAIT_UNKNOWN;
				break;
			case ETIMEDOUT:
				(ret_err) = AE2FSYS_FTXWAIT_TMOUT;
				break;
			case EINVAL:
				(ret_err) = AE2FSYS_FTXWAIT_INVAL;
				break;
			case ENOTRECOVERABLE:
				(ret_err) = AE2FSYS_FTXWAIT_MTXNCOVERABLE;
				break;
			case EOWNERDEAD:
				(ret_err) = AE2FSYS_FTXWAIT_MTXOWNDEAD;
				break;
			case EDEADLK:
				(ret_err) = AE2FSYS_FTXWAIT_MTXBLK;
				break;
			case EPERM:
				(ret_err) = AE2FSYS_FTXWAIT_MTXNOWN;
				break;
			case EFAULT:
				(ret_err) = AE2FSYS_FTXWAIT_PTRINVAL;
				break;
		}
	}
}

ae2f_MAC((L, )) ae2fsys_ftxwake_one_imp(
		enum AE2FSYS_FTXWAIT_ ret_err, 
		ae2fsys_ftxel_t* const prm_uaddr)
{
	switch(pthread_mutex_lock(&__ae2f_gSysFtxMtx))
	{
		case EFAULT:
			(ret_err) = AE2FSYS_FTXWAKE_PTRINVAL;
			break;
		case ENOTRECOVERABLE:
			(ret_err) = AE2FSYS_FTXWAIT_MTXNCOVERABLE;
			break;
		case EOWNERDEAD:
			(ret_err) = AE2FSYS_FTXWAIT_MTXOWNDEAD;
			break;
		case EDEADLK:
			(ret_err) = AE2FSYS_FTXWAKE_MTXBLK;
			break;
		case EPERM:
			(ret_err) = AE2FSYS_FTXWAKE_MTXNOWN;
			break;
		case 0:
			(ret_err) = AE2FSYS_FTXWAKE_GOOD;
			break;
		default:
			(ret_err) = AE2FSYS_FTXWAKE_UNKNOWN;
			break;
	}

	ae2f_unexpected_else((ret_err)) {
		switch(pthread_cond_signal(&(__ae2f_gSysFtxMtx))) {
			case EFAULT:
				(ret_err) = AE2FSYS_FTXWAKE_PTRINVAL;
				break;
			case ENOTRECOVERABLE:
				(ret_err) = AE2FSYS_FTXWAIT_MTXNCOVERABLE;
				break;
			case EOWNERDEAD:
				(ret_err) = AE2FSYS_FTXWAIT_MTXOWNDEAD;
				break;
			case EDEADLK:
				(ret_err) = AE2FSYS_FTXWAKE_MTXBLK;
				break;
			case EPERM:
				(ret_err) = AE2FSYS_FTXWAKE_MTXNOWN;
				break;
			case 0:
				(ret_err) = AE2FSYS_FTXWAKE_GOOD;
				break;
			default:
				(ret_err) = AE2FSYS_FTXWAKE_UNKNOWN;
				break;
		}

		ae2f_unexpected_else((ret_err)) switch(pthread_mutex_unlock(&(__ae2f_gSysFtxMtx))) {
			case EFAULT:
				(ret_err) = AE2FSYS_FTXWAKE_PTRINVAL;
				break;
			case ENOTRECOVERABLE:
				(ret_err) = AE2FSYS_FTXWAIT_MTXNCOVERABLE;
				break;
			case EOWNERDEAD:
				(ret_err) = AE2FSYS_FTXWAIT_MTXOWNDEAD;
				break;
			case EDEADLK:
				(ret_err) = AE2FSYS_FTXWAKE_MTXBLK;
				break;
			case EPERM:
				(ret_err) = AE2FSYS_FTXWAKE_MTXNOWN;
				break;
			case 0:
				(ret_err) = AE2FSYS_FTXWAKE_GOOD;
				break;
			default:
				(ret_err) = AE2FSYS_FTXWAKE_UNKNOWN;
				break;
		}

	} while(0);
}


#endif
#endif
