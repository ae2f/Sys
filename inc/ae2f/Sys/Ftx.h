/** 
 * @file Ftx.h
 * System call which makes thread wait until certain memory changes.
 * */

#ifndef ae2f_Sys_Futex_h
#define ae2f_Sys_Futex_h

#include "./Ftx.core.h"
#include "./Ftx.auto.h"

/** @brief Futex address element type. */
typedef _ae2f_SysFtxEl_t	ae2f_SysFtxEl_t;

/** 
 * @brief 
 * State for futex operation.
 *
 * 0 would be succesful.
 * others would be error.
 * */
typedef _ae2f_SysFtxRet_t	ae2f_SysFtxRet_t;

#endif
