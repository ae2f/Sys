#ifndef	ae2fsys_ftx_h
#define	ae2fsys_ftx_h

#include "./.ftx/syscall.h"
#include "./.ftx/futex.h"
#include "./.ftx/pthread.h"
#include "./.ftx/waitonaddr.h"

#define	ae2fsys_ftxwake_one_imp _ae2fsys_ftxwake_one_imp
#define	ae2fsys_ftxwait_imp	_ae2fsys_ftxwait_imp
#define	ae2fsys_ftxel_t		ae2fsys_ftxel_t

#endif
