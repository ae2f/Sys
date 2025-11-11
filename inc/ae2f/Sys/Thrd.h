/**
 * @file Thrd.h
 * Detach is not implemented since I do not know a way to do this without 3rd object.
 * */

#ifndef ae2f_Sys_Thrd_h
#define ae2f_Sys_Thrd_h

#include "./Thrd.core.h"
#include "./Thrd.auto.h"


/** @brief Return type for thread. */
typedef _ae2f_SysThrdRes_t ae2f_SysThrdRes_t;


/** @brief Parameters for thread */
typedef _ae2f_SysThrdPrm_t ae2f_SysThrdPrm_t;


/** @brief Thread ID */
typedef _ae2f_SysThrdID_t ae2f_SysThrdID_t;

/** @brief Thread starting function type */
typedef ae2f_SysThrdRes_t ae2f_SysThrdFn_t(ae2f_SysThrdPrm_t);



/** @brief 
 * enum values related to thread. \n
 * 't follows C11 thread standard.
 * */
typedef enum ae2f_eSysThrd_t {
	/** Good */
	ae2f_eSysThrdSuccess,

	/** Out of host memory */
	ae2f_eSysThrdMemOut,

	/** Timeout */
	ae2f_eSysThrdTmOut,

	ae2f_eSysThrdBusy,
	ae2f_eSysThrdErr,
} ae2f_eSysThrd_t;

/** 
 * @brief A thread. 
 * @warning
 * This structure's size could vary for implementation.
 * */
typedef struct 
{
	/** thread id */
	ae2f_SysThrdID_t	m_id;

	/** stack ptr (linux only) */
	ae2f_Sys__linux(_ae2f_SysThrdStckPtr_t	m_stck;)

	/** stack size (linux only) */
	ae2f_Sys__linux(size_t	m_stcksz;)
} ae2f_SysThrd;

#endif

#ifdef ae2f_Sys_Thrd_auto_h

#ifndef _ae2f_SysThrdMk_imp
typedef char _ae2f_SysThrdMk_imp_NOT_FOUND[-1];
#endif

#ifndef _ae2f_SysThrdJoin_imp
typedef char _ae2f_SysThrdJoin_imp_NOT_FOUND[-1];
#endif

#ifndef _ae2f_SysThrdYield_imp
typedef char _ae2f_SysThrdYield_imp_NOT_FOUND[-1];
#endif

#ifndef _ae2f_SysThrdSleep_imp
typedef char _ae2f_SysThrdSleep_imp_NOT_FOUND[-1];
#endif

#endif
