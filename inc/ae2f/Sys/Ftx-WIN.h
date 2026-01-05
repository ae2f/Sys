/**
 * @brief Ftx-WIN.h
 * */

#ifndef ae2f_Sys_Ftx_WIN_h
#define ae2f_Sys_Ftx_WIN_h

#include "./Ftx.h"

#if ae2f_Sys_WIN(!)0

#include <windows.h>

#define ae2f_SysFtxLibDefine_WIN(tprm_export)
#define ae2f_SysFtxLibDeclare_WIN(tprm_import)


#define	_ae2f_SysFtxEl_WIN	volatile LONG

#endif

#endif
