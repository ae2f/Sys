/**
 * @brief Ftx-Linux.h
 * */

#ifndef ae2f_Sys_Ftx_LINUX_h
#define ae2f_Sys_Ftx_LINUX_h

#include "../Sys.h"

#if ae2f_Sys__linux(!)0

#include <linux/futex.h>
#include <sys/syscall.h>
#include <errno.h>
#include <unistd.h>

#include "./Ftx.core.h"
#include "./Ftx-_linux.auto.h"

#define	_ae2f_SysFtxEl__linux	int

#define ae2f_SysFtxLibDefine__linux(tprm_export)
#define ae2f_SysFtxLibDeclare__linux(tprm_import)

#endif

#endif
