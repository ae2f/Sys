#ifndef	ae2fsys_thrd_h
#define	ae2fsys_thrd_h

#include "./.thrd/linux.h"
#include "./.thrd/windows.h"
#include "./.thrd/pthread.h"

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
