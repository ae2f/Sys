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
	return ae2f_reinterpret_cast(ae2f_SysThrdRes_t, 3);
}

int main() {
	ae2f_eSysThrd_t		ret_stat = 0;
	ae2f_SysThrd		ret_thrd;

	ae2f_SysThrdRes_t	ret_rtn;

	ret_rtn = 0;

	puts("Thread main is starting");

#if 1
	_ae2f_SysThrdMk_imp(
			ret_stat
			, ret_thrd
			, AThreadNotifier
			, NULL
			, 1024 * 1024 * 4
			);
#else
	{ 
		(ret_thrd).m_stck.m_void = mmap(
				((void *)0)
				, ((ret_thrd).m_stcksz = ( (1024 * 1024 * 4) + sizeof(_ae2f_SysThrdRunnerPrm_t) + sizeof(void*) ) ) 
				, 0x1 | 0x2 , 0x02 | 0x20000 | 0x20 
				, -1
				, 0 
				); 
		if(((void *) -1) == (ret_thrd).m_stck.m_void || !(ret_thrd).m_stck.m_void) { 
			(ret_stat) = ae2f_eSysThrdMemOut; 
			(ret_thrd).m_stck.m_void = ((void *)0); 
		} else { 
			(ret_thrd).m_stck.m_prm->m_arg = (((void *)0)); 
			(ret_thrd).m_stck.m_prm->m_fn = (AThreadNotifier); 
			(ret_thrd).m_stck.m_prm->m_stcksz = (ret_thrd).m_stcksz; 
			{ 
				pid_t v_child = -1, v_parent = -1; 
				int v_pidfd = -1; 
				struct clone_args v_args; 
				v_args.stack = ((__u64)((ret_thrd).m_stck.m_prm)); 
				v_args.tls = ((ptrdiff_t)((ret_thrd).m_stck.m_prm))  & 0; 
				v_args.stack_size = (1024 * 1024 * 4); 
				v_args.flags = CLONE_VM; 
				v_args.exit_signal = SIGCHLD; 
				v_args.child_tid = ((__u64)(&v_child))  & 0; 
				v_args.pidfd = ((__u64)(&v_pidfd))  & 0; 
				v_args.parent_tid = ((__u64)(&v_parent))  & 0; 
				switch(((ret_thrd).m_id) = syscall(435, &v_args, 64)) { 
					case 0: 
						puts("Z");
						// syscall(60, 0); 
						break;
					default: 
						sleep(1); 
						puts("Hello? This is parent"); 
						// syscall(60, 0); 
						break;
					case -1: 
						puts("syscall has doomed."); 
						printf("%d\n", (*__errno_location ())); 
						printf("%d\n", ((ret_thrd).m_id)); 
						syscall(60, 0); ; 
				} 

				puts("good"); 
				syscall(60, 0); 

				((ret_thrd).m_id) = clone(
					((ae2f_SysThrdFn_t*)(_ae2f_SysThrdRunner))  
					, (((ret_thrd).m_stck.m_char)) 
					, (0x00000100 | 0x00000200 | 0x00000400 | 0x00000800 | 0x00010000 | 0x00040000) 
					, ((ret_thrd).m_stck.m_prm) 
					); 

				if(((ret_thrd).m_id) == -1) { 
					(ret_stat) = ae2f_eSysThrdErr; 
				} else if(((ret_thrd).m_id) == 0) { 
					syscall(60, 0); 
				} else { 
					(ret_stat) = ae2f_eSysThrdSuccess; 
				} 
			}; 

			if(ret_stat != ae2f_eSysThrdSuccess) { 
				munmap( 
						(ret_thrd).m_stck.m_void 
						, (ret_thrd).m_stcksz 
						); 

				(ret_thrd).m_stck.m_void = ((void *)0); 
			} 
		} 
	}

#endif

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
