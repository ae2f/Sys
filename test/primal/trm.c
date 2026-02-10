#include <stdio.h>

#include <ae2f/Sys/Trm.h>
#include <ae2f/Sys/Thrd.h>

int main(void) {
	long			SLEEPRET;
	struct timespec		REQ, REM;
	ae2fsys_trmpos_t	W, H;
	_ae2fsys_get_trm_size_simple_imp(L, W, H);

	printf("%d %d\n", (int)W, (int)H);

	REQ.tv_nsec = 2000000000u;
	REQ.tv_sec = 0;

	REM = REQ;

	_ae2fsys_sleep_thrd_imp(SLEEPRET, &REQ, &REM);

	_ae2fsys_clear_trm_simple_imp(L);

	_ae2fsys_trm_goto_simple_imp(L, 4, 2);
	printf("terminal goto 4, 2");

	_ae2fsys_trm_goto_simple_imp(L, 1, 1);
	printf("terminal goto 1, 1");

	(void)SLEEPRET;

	return 0;
}
