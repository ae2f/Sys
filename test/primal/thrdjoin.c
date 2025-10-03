#include <ae2f/Sys/Thrd.h>
#include <stdio.h>
#include <time.h>

ae2f_SysThrdRes_t AThreadNotifier(ae2f_SysThrdPrm_t prm) {
	struct timespec	req, rem;
	int		done;

	req.tv_sec = 0;
	req.tv_nsec = 4000;

	printf("Thread child is starting\n");

	_ae2f_SysThrdSleep_imp(done, &req, &rem);

	printf("Thread child is ending\n");
	return 3;
}

int main() {
	ae2f_eSysThrd_t		ret_stat = 0;
	ae2f_SysThrd		ret_thrd;
	ret_thrd.m_id = -1;

	ae2f_SysThrdRes_t	ret_rtn;

	ret_rtn = 0;

	puts("Thread main is starting");

	_ae2f_SysThrdMk_imp(
			ret_stat
			, ret_thrd
			, AThreadNotifier
			, NULL
			, 1024 * 1024
			);
#if ae2f_Sys__linux(!)0

	puts("This is an information specificly for linux.");
	printf("Stack size: %lu\n", (ret_thrd).m_stcksz);
	printf("Stack ptr: %p\n", (ret_thrd).m_stck.m_void);
	printf("Stack top: %p\n", (ret_thrd).m_stck.m_char + (ret_thrd).m_stcksz);

	unless(ret_thrd.m_stck.m_void) {
		puts("ERROR: Allocation has failed");
	}

	puts("This is the end of section for linux");

	printf("ftxptr: %p\n", &(ret_thrd).m_stck.m_prm->m_done);
#endif

	puts("Thread main has made a thread");
	printf("ret_stat: %d\n", ret_stat);


	_ae2f_SysThrdJoin_imp(
			ret_stat
			, ret_rtn
			, ret_thrd
			);

	printf(
			"Thread main joined %d with retval %d\n"
			, (ret_thrd).m_id, ret_rtn);


	puts("Thread main is ending");

	return 0;
}
