int main(void);

/** global lock initiation for others(posix) */
#define	AE2FSYS_FTX_OTHERS_LIB_INIT	1


#include <ae2f/Sys/.ftx/others.h>
#include <ae2f/Sys/Thrd.h>

#include <stdio.h>


static ae2fsys_thrdres_t	waker(ae2f_unused ae2fsys_thrdprm_t uaddr) {
	ae2f_unused long	STAT;
	ae2f_unused enum AE2FSYS_FTX_ FTXSTAT;
	struct timespec REQ;
	struct timespec REM;


	REM.tv_nsec	= 0;
	REM.tv_sec	= 0;

	puts("[wake]\t1s delay");
	REQ.tv_sec	= 0;
	REQ.tv_nsec	= 30000000;
	puts("[wake]\t1s delay done");
	_ae2fsys_sleep_thrd_imp(STAT, &REQ, &REM);
	_ae2fsys_ftxwake_one_imp(L, FTXSTAT, (ae2fsys_ftxel_t*)uaddr);
	return (ae2fsys_thrdres_t)0;
}

static ae2fsys_thrdres_t	waiter(ae2f_unused ae2fsys_thrdprm_t uaddr) {
	ae2f_unused enum AE2FSYS_FTX_ FTXSTAT;
	puts("[wait]\twaiting");
	_ae2fsys_ftxwait_imp(L, FTXSTAT, (ae2fsys_ftxel_t*)uaddr, 0, 0);
	puts("[wait]\twaiting done");
	return (ae2fsys_thrdres_t)0;
}


int main(void)
{
	ae2f_unused enum AE2FSYS_THRD_	THRD_RET;
	ae2f_unused ae2fsys_thrdres_t	THRD_VAL;
	ae2fsys_thrd	TD_WAITER, TD_WAKER;
	ae2fsys_thrdprm_t	U = 0;
	_ae2fsys_mk_thrd_imp(THRD_RET, TD_WAITER, waiter, &U, 1 << 20);
	_ae2fsys_mk_thrd_imp(THRD_RET, TD_WAKER, waker, &U, 1 << 20);

	_ae2fsys_join_thrd_imp(L, THRD_RET, THRD_VAL, TD_WAITER);
	_ae2fsys_join_thrd_imp(L, THRD_RET, THRD_VAL, TD_WAKER);
	return 0;
}
