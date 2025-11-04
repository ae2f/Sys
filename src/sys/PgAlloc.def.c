/**
 * @file PgAlloc_auto_h
 * */

#ifndef ae2f_Sys_PgAlloc_auto_h
#define ae2f_Sys_PgAlloc_auto_h

#include <ae2f/Sys/PgAlloc.h>
#include <ae2f/Macro.h>

#if ae2f_Sys_WIN(!)0


ae2f_MAC() ae2f_SysPgAlloc_imp(
		void*		ret_mem,
		void* const	prm_addr,
		const size_t	prm_req_sz
		)
{
	(ret_mem) = VirtualAlloc(
			prm_addr
			, prm_req_sz
			, MEM_COMMIT
			, PAGE_EXECUTE_READWRITE
			);
}

#else

/** @brief Allocate a memory */
ae2f_MAC() ae2f_SysPgAlloc_imp(
		void*		ret_mem,
		void* const	prm_addr,
		const size_t	prm_req_sz
		)
{
	(ret_mem) = mmap(
			prm_addr
			, prm_req_sz
			, PROT_READ | PROT_WRITE
			, MAP_PRIVATE | MAP_ANONYMOUS
			, -1, 0
			);

	if((ret_mem) == MAP_FAILED)
	{
		(ret_mem) = NULL;
	}
}

ae2f_MAC() ae2f_SysPgFree_imp(
		void* const	prm_mem,
		const size_t	prm_memsz 
		)
{
	munmap(prm_mem, prm_memsz);
}

#endif



#endif
