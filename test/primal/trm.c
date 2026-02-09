#include <ae2f/Sys/Trm.h>
#include <ae2f/Sys/Thrd.h>

int main(void) {
	long			SLEEPRET;
	struct timespec		REQ, REM;
	ae2fsys_trmpos_t	W, H;
	_ae2fsys_get_trm_size_imp(L, W, H);
	printf("%d %d", W, H);

	REQ.tv_nsec = 0;
	REM.tv_sec = 1;

	_ae2fsys_sleep_thrd_imp(SLEEPRET, &REQ, &REM);

	_ae2fsys_clear_trm();
	_ae2fsys_trm_goto((ae2fsys_trmpos_t)4, (ae2fsys_trmpos_t)2);
	printf("terminal goto 4, 2");

	_ae2fsys_trm_goto((ae2fsys_trmpos_t)1, (ae2fsys_trmpos_t)1);
	printf("terminal goto 1, 1");

	(void)SLEEPRET;

	return 0;
}
