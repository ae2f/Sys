/**
 * @file Thrd.h
 * @brief Non-detachable thread
 * */

#ifndef ae2fsys_Thrd_h
#define ae2fsys_Thrd_h

#include "./thrd/WIN.auto.h"
#include "./thrd/_linux.auto.h"
#include "./thrd/POSIX.auto.h"

/**
 * @typedef	ae2fsys_thrdres_t
 * @brief	Return type for a thread.
 * */
#define	ae2fsys_thrdres_t	ae2fsys_thrdres_t

/**
 * @typedef	ae2fsys_thrdprm_t
 * @brief	Parameters for a thread
 * */
#define	ae2fsys_thrdprm_t	ae2fsys_thrdprm_t

/**
 * @typedef	ae2fsys_tid_t
 * @brief	Thread ID 
 * */
#define	ae2fsys_tid_t		ae2fsys_tid_t

/**
 * @typedef	ae2fsys_thrdfn_t
 * @brief Thread starting function type 
 * */
#define	ae2fsys_thrdfn_t	ae2fsys_thrdfn_t

/** 
 * @typedef	ae2fsys_thrd
 * @brief	A thread. 
 * @warning
 * 		This structure's size could vary for implementation.
 * */
#define	ae2fsys_thrd		ae2fsys_thrd

#define	ae2fsys_mk_thrd_imp	_ae2fsys_mk_thrd_imp
#define	ae2fsys_join_thrd_imp	_ae2fsys_join_thrd_imp
#define	ae2fsys_yield_thrd_imp	_ae2fsys_yield_thrd_imp
#define	ae2fsys_sleep_thrd_imp	_ae2fsys_sleep_thrd_imp

#endif
