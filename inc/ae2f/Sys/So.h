/**
 * @file So.h
 * @brief Call and export for 
 * */


#ifndef ae2f_Sys_So_h
#define ae2f_Sys_So_h

#include "../Sys.h"

/** 
 * @brief 
 * Exporting a specific function as dynamic link library(or so).
 *
 * @details
 * For posix, gcc/clang/tcc is expected.
 * */
#define ae2f_SysSoExFn	\
	N_ae2f_Sys_WIN(__attribute__((visibility("default")))) \
	ae2f_Sys_WIN(__declspec(dllexport))

/** @brief Calling a specific function which has been dynamically linked. */
#define ae2f_SysSoCall	\
	ae2f_Sys_WIN(__declspec(dllimport))

#endif
