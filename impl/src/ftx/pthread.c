/**
 * @file	pthread.c
 * @brief	futex is not possible. pthread fallback.
 *
 * @def	AE2FSYS_FTX_OTHERS_LIB_STATIC
 * @brief	The global mutex & cv will be static. 
 *
 * @def	AE2FSYS_FTX_OTHERS_LIB_INIT
 * @brief	The global mutex & cv will be initiated.
 *
 * @def	AE2FSYS_FTX_OTHERS_LIB_DYLINK
 * @brief	The global mutex & cv will be treated linked or declared as dynamic link.
 * */

#ifndef	ae2fsys_ftx_pthread_h
#define	ae2fsys_ftx_pthread_h
#include <ae2f/Sys/.ftx/core.h>


#if	_AE2FSYS_FTX_PTHREAD

/**********************/

#include <pthread.h>
#include <ae2f/Keys.h>
#include <ae2f/cc.h>

#ifndef	AE2FSYS_FTX_PTHREAD_LIB_STATIC
#define	AE2FSYS_FTX_PTHREAD_LIB_STATIC		0
#endif

#ifndef	AE2FSYS_FTX_PTHREAD_LIB_DYLINK
#define	AE2FSYS_FTX_PTHREAD_LIB_DYLINK	0
#endif

#ifndef	AE2FSYS_FTX_PTHREAD_LIB_INIT
#define	AE2FSYS_FTX_PTHREAD_LIB_INIT	0
#endif

#if	AE2FSYS_FTX_PTHREAD_LIB_STATIC
#define	S_EXTERN	ae2f_unused static
#elif	AE2FSYS_FTX_PTHREAD_LIB_INIT
#define	S_EXTERN	ae2f_WhenCXX(extern "C")
#else
#define	S_EXTERN	ae2f_extern
#endif

#if	AE2FSYS_FTX_PTHREAD_LIB_INIT
#define	S_INIT(a)		a
#else
#define S_INIT(a)
#endif

#if	AE2FSYS_FTX_PTHREAD_LIB_DYLINK
#if		AE2FSYS_FTX_PTHREAD_LIB_EXTERN_INIT
#define	S_LINK	ae2f_impl
#else
#define S_LINK	ae2f_decl
#endif		/***/
#else
#define	S_LINK
#endif


S_EXTERN S_LINK pthread_mutex_t g_ae2fsys_ftx_mtx_pthread S_INIT(= PTHREAD_MUTEX_INITIALIZER);
S_EXTERN S_LINK pthread_cond_t g_ae2fsys_ftx_cnd_pthread S_INIT(= PTHREAD_COND_INITIALIZER);

#undef	S_EXTERN
#undef	S_LINK
#undef	S_INIT


typedef	int ae2fsys_ftxel_t;

#include <ae2f/pat/macrofunc.h>
#include <errno.h>

ae2f_MAC((L, )) ae2fsys_ftxwait_imp(
		enum AE2FSYS_FTX_	ret_err,
		ae2fsys_ftxel_t* const	prm_uaddr,
		const ae2fsys_ftxel_t	prm_val,
		const struct timespec* const pprm_timeout
		)
{
	switch(pthread_mutex_lock(&g_ae2fsys_ftx_mtx_pthread))
	{
		case 0: 
			(ret_err) = AE2FSYS_FTX_GOOD;
			break;
		default:
			(ret_err) = AE2FSYS_FTX_UNKNOWN;
			break;
		case ETIMEDOUT:
			(ret_err) = AE2FSYS_FTX_TMOUT;
			break;
		case EINVAL:
			(ret_err) = AE2FSYS_FTX_INVAL;
			break;
		case ENOTRECOVERABLE:
			(ret_err) = AE2FSYS_FTX_MTXNCOVERABLE;
			break;
		case EOWNERDEAD:
			(ret_err) = AE2FSYS_FTX_MTXOWNDEAD;
			break;
		case EDEADLK:
			(ret_err) = AE2FSYS_FTX_MTXBLK;
			break;
		case EPERM:
			(ret_err) = AE2FSYS_FTX_MTXNOWN;
			break;
		case EFAULT:
			(ret_err) = AE2FSYS_FTX_PTRINVAL;
			break;
	}

	ae2f_unexpected_else((ret_err)) {
		while(ae2f_expected(!(ret_err)) && *(prm_uaddr) == (prm_val))
		{
			switch(
					((pprm_timeout)
					 ? pthread_cond_timedwait(
						 &g_ae2fsys_ftx_cnd_pthread
						 , &g_ae2fsys_ftx_mtx_pthread
						 , pprm_timeout)
					 : pthread_cond_wait(
						 &g_ae2fsys_ftx_cnd_pthread
						 , &g_ae2fsys_ftx_mtx_pthread))
			      )
			{
				case 0: 
					(ret_err) = AE2FSYS_FTX_GOOD;
					break;
				default:
					(ret_err) = AE2FSYS_FTX_UNKNOWN;
					break;
				case ETIMEDOUT:
					(ret_err) = AE2FSYS_FTX_TMOUT;
					break;
				case EINVAL:
					(ret_err) = AE2FSYS_FTX_INVAL;
					break;
				case ENOTRECOVERABLE:
					(ret_err) = AE2FSYS_FTX_MTXNCOVERABLE;
					break;
				case EOWNERDEAD:
					(ret_err) = AE2FSYS_FTX_MTXOWNDEAD;
					break;
				case EDEADLK:
					(ret_err) = AE2FSYS_FTX_MTXBLK;
					break;
				case EPERM:
					(ret_err) = AE2FSYS_FTX_MTXNOWN;
					break;
				case EFAULT:
					(ret_err) = AE2FSYS_FTX_PTRINVAL;
					break;
			}
		}

		ae2f_unexpected_else((ret_err)) switch(pthread_mutex_unlock(&g_ae2fsys_ftx_mtx_pthread))
		{
			case 0: 
				(ret_err) = AE2FSYS_FTX_GOOD;
				break;
			default:
				(ret_err) = AE2FSYS_FTX_UNKNOWN;
				break;
			case ETIMEDOUT:
				(ret_err) = AE2FSYS_FTX_TMOUT;
				break;
			case EINVAL:
				(ret_err) = AE2FSYS_FTX_INVAL;
				break;
			case ENOTRECOVERABLE:
				(ret_err) = AE2FSYS_FTX_MTXNCOVERABLE;
				break;
			case EOWNERDEAD:
				(ret_err) = AE2FSYS_FTX_MTXOWNDEAD;
				break;
			case EDEADLK:
				(ret_err) = AE2FSYS_FTX_MTXBLK;
				break;
			case EPERM:
				(ret_err) = AE2FSYS_FTX_MTXNOWN;
				break;
			case EFAULT:
				(ret_err) = AE2FSYS_FTX_PTRINVAL;
				break;
		}
	}
}

ae2f_MAC((L, )) ae2fsys_ftxwake_one_imp(
		enum AE2FSYS_FTX_ ret_err, 
		ae2f_unused ae2fsys_ftxel_t* const prm_uaddr)
{
	switch(pthread_mutex_lock(&g_ae2fsys_ftx_mtx_pthread))
	{
		case EFAULT:
			(ret_err) = AE2FSYS_FTX_PTRINVAL;
			break;
		case ENOTRECOVERABLE:
			(ret_err) = AE2FSYS_FTX_MTXNCOVERABLE;
			break;
		case EOWNERDEAD:
			(ret_err) = AE2FSYS_FTX_MTXOWNDEAD;
			break;
		case EDEADLK:
			(ret_err) = AE2FSYS_FTX_MTXBLK;
			break;
		case EPERM:
			(ret_err) = AE2FSYS_FTX_MTXNOWN;
			break;
		case 0:
			(ret_err) = AE2FSYS_FTX_GOOD;
			break;
		default:
			(ret_err) = AE2FSYS_FTX_UNKNOWN;
			break;
	}

	ae2f_unexpected_else((ret_err)) {
		switch(pthread_cond_signal(&(g_ae2fsys_ftx_cnd_pthread))) {
			case EFAULT:
				(ret_err) = AE2FSYS_FTX_PTRINVAL;
				break;
			case ENOTRECOVERABLE:
				(ret_err) = AE2FSYS_FTX_MTXNCOVERABLE;
				break;
			case EOWNERDEAD:
				(ret_err) = AE2FSYS_FTX_MTXOWNDEAD;
				break;
			case EDEADLK:
				(ret_err) = AE2FSYS_FTX_MTXBLK;
				break;
			case EPERM:
				(ret_err) = AE2FSYS_FTX_MTXNOWN;
				break;
			case 0:
				(ret_err) = AE2FSYS_FTX_GOOD;
				break;
			default:
				(ret_err) = AE2FSYS_FTX_UNKNOWN;
				break;
		}

		ae2f_unexpected_else((ret_err)) switch(pthread_mutex_unlock(&(g_ae2fsys_ftx_mtx_pthread))) {
			case EFAULT:
				(ret_err) = AE2FSYS_FTX_PTRINVAL;
				break;
			case ENOTRECOVERABLE:
				(ret_err) = AE2FSYS_FTX_MTXNCOVERABLE;
				break;
			case EOWNERDEAD:
				(ret_err) = AE2FSYS_FTX_MTXOWNDEAD;
				break;
			case EDEADLK:
				(ret_err) = AE2FSYS_FTX_MTXBLK;
				break;
			case EPERM:
				(ret_err) = AE2FSYS_FTX_MTXNOWN;
				break;
			case 0:
				(ret_err) = AE2FSYS_FTX_GOOD;
				break;
			default:
				(ret_err) = AE2FSYS_FTX_UNKNOWN;
				break;
		}

	} while(0);
}

/**********************/

#endif
#endif
