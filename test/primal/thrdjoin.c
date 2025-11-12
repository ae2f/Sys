#include <ae2f/Sys/Thrd.h>
#include <ae2f/Cast.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>


int A = 0;

ae2f_SysThrdRes_t AThreadNotifier(ae2f_SysThrdPrm_t);

ae2f_SysThrdRes_t AThreadNotifier(ae2f_SysThrdPrm_t prm) {
	struct timespec	req, rem;
	register long		done;


	(void)prm; /** ignore */

	req.tv_sec = 0;
	req.tv_nsec = 4000;

	printf("Thread child is starting\n");

	_ae2f_SysThrdSleep_imp(done, &req, &rem);

	(void)done;
	A = 1;

	printf("Thread child is ending\n");
	return ae2f_reinterpret_cast(ae2f_SysThrdRes_t, 3);
}

int main(void) {
	register ae2f_eSysThrd_t	ret_stat = 0;
	ae2f_SysThrd		ret_thrd0, ret_thrd1;

	ae2f_SysThrdRes_t	ret_rtn;

	ret_rtn = 0;

	puts("Thread main is starting");

#if 1
	_ae2f_SysThrdMk_imp(
			ret_stat
			, ret_thrd0
			, AThreadNotifier
			, NULL
			, 1024 * 1024
			);

	_ae2f_SysThrdMk_imp(
			ret_stat
			, ret_thrd1
			, AThreadNotifier
			, NULL
			, 1024 * 1024
			);
#else
#endif

	puts("Thread main has made a thread");
	printf("ret_stat: %u\n", ae2f_static_cast(unsigned int, ret_stat));


	_ae2f_SysThrdJoin_imp(
			ret_stat
			, ret_rtn
			, ret_thrd0
			);

	printf(
			"Thread main joined %d with retval %d\n"
			, ae2f_static_cast(int, (ret_thrd0).m_id)
			, ae2f_static_cast(int, ret_rtn)
			);

	_ae2f_SysThrdJoin_imp(
			ret_stat
			, ret_rtn
			, ret_thrd1
			);

	printf(
			"Thread main joined %u with retval %d\n"
			, ae2f_static_cast(unsigned int, (ret_thrd1).m_id)
			, ae2f_static_cast(int, ret_rtn)
			);



	puts("Thread main is ending");

	assert(A == 1);
	puts("GOOD");

	return 0;
}
