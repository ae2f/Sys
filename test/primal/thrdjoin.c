#include <ae2f/Sys/Thrd.h>
#include <ae2f/Cast.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <c89atomic.h>


int A = 0;


ae2fsys_thrdfn_t AThreadNotifier;

ae2fsys_thrdres_t AThreadNotifier(ae2fsys_thrdprm_t prm) {
	struct timespec	req, rem;
	register long		done;


	(void)prm; /** ignore */

	req.tv_sec = 0;
	req.tv_nsec = 4000;

	printf("Thread child is starting\n");

	ae2fsys_sleep_thrd_imp(done, &req, &rem);

	(void)done;
	A = 1;

	printf("Thread child is ending\n");
	return ae2f_reinterpret_cast(ae2fsys_thrdres_t, 3);
}

int main(void) {
	enum AE2FSYS_THRD_	ret_stat = 0;
	ae2fsys_thrd		ret_thrd0, ret_thrd1;

	ae2fsys_thrdres_t	ret_rtn;
	register union {
		void*			m_v;
		ae2fsys_tid_t		m_id;
	} id_for_printf;


	ret_rtn = 0;

	puts("Thread main is starting");

#if 1
	ae2fsys_mk_thrd_imp(
			ret_stat
			, ret_thrd0
			, AThreadNotifier
			, NULL
			, 1024 * 1024
			);

	ae2fsys_mk_thrd_imp(
			ret_stat
			, ret_thrd1
			, AThreadNotifier
			, NULL
			, 1024 * 1024
			);
#else
#endif

	puts("Thread main has made a thread");
	printf("ret_stat: %u\n", ae2f_reinterpret_cast(unsigned int, ret_stat));


	ae2fsys_join_thrd_imp(
			L
			, ret_stat
			, ret_rtn
			, ret_thrd0
			);

	id_for_printf.m_id = (ret_thrd0).m_id;

	printf(
			"Thread main joined %p with retval %d\n"
			, id_for_printf.m_v
			, ae2f_static_cast(int, ret_rtn)
			);

	ae2fsys_join_thrd_imp(
			L
			, ret_stat
			, ret_rtn
			, ret_thrd1
			);


	id_for_printf.m_id = (ret_thrd1).m_id;

	printf(
			"Thread main joined %p with retval %d\n"
			, id_for_printf.m_v
			, ae2f_static_cast(int, ret_rtn)
			);



	puts("Thread main is ending");

	assert(A == 1);
	puts("GOOD");

	return 0;
}
