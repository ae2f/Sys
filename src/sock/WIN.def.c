#ifndef ae2f_Sys_sock_WIN_auto_h
#define ae2f_Sys_sock_WIN_auto_h

#include <ae2f/Sys.h>

#if ae2f_Sys_WIN(!)0

#include <windows.h>
#include <ae2f/Sys/Sock.core.h>

typedef	SOCKET	ae2fsys_sock_t;
typedef u_long	ae2fsys_sock_blkmode_t;

ae2f_MAC() ae2fsys_set_sock_blkmode_imp(
		ae2fsys_sock_blkmode_t	rdwr_mem,
		const ae2fsys_sock_t	h_sock,
		const bool		c_blkmode,
		enum AE2FSYS_SOCK_	res
		)
{
	(rdwr_mem) = !!(c_blkmode);
	(res) = -(!!ioctlsocket((h_sock), FIONBIO, &(rdwr_mem)));
}

#else

#endif
#endif
