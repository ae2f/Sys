/** 
 * @file Ftx.h
 * System call which makes thread wait until certain memory changes.
 * */

#ifndef ae2fsys_ftx_h
#define ae2fsys_ftx_h

#include "./ftx/POSIX.auto.h"
#include "./ftx/WIN.auto.h"
#include "./ftx/_linux.auto.h"

#define	ae2fsys_ftxwake_one_imp _ae2fsys_ftxwake_one_imp
#define	ae2fsys_ftxwait_imp	_ae2fsys_ftxwait_imp
#define	ae2fsys_ftxel_t		ae2fsys_ftxel_t

#endif
