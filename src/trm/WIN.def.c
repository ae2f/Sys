/** @file WIN.def.c */

#ifndef ae2fsys_trm_WIN_def_c
#define ae2fsys_trm_WIN_def_c

#include <ae2f/Sys.h>

#if	ae2f_Sys_WIN(!)0
#include <ae2f/Sys/Trm.core.h>
#include <ae2f/Macro.h>
#include <windows.h>

#define	ae2fsys_is_trm_tty()	\
	(_isatty(_fileno(stdout)) || _isatty(_fileno(stderr)))


typedef	SHORT ae2fsys_trmpos_t;

/** currently no implementation available on windows */

#endif
#endif
