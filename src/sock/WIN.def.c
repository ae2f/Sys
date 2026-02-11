#ifndef ae2f_Sys_sock_WIN_auto_h
#define ae2f_Sys_sock_WIN_auto_h

#include <ae2f/Sys.h>

#if ae2f_Sys_WIN(!)0

#include <windows.h>
#include <ae2f/Sys/Sock.core.h>
#include <ae2f/Cast.h>
#include <ae2f/Keys.h>

typedef	SOCKET	ae2fsys_sock_t;
typedef u_long	ae2fsys_sock_blkmode_t;


#define	AE2FSYS_SOCK_INVL	INVALID_SOCKET

ae2f_MAC() ae2fsys_set_sock_blkmode_imp(
		ae2fsys_sock_blkmode_t	rdwr_mem,
		const ae2fsys_sock_t	h_sock,
		const bool		c_blkmode,
		enum AE2FSYS_SOCK_	res
		)
{
	(rdwr_mem) = ae2f_reinterpret_cast(ae2fsys_sock_blkmode_t, !!(c_blkmode));
	(res) = ae2f_reinterpret_cast(enum AE2FSYS_SOCK_, -(!!ioctlsocket(
					(h_sock)
					, ae2f_static_cast(long, FIONBIO)
					, &(rdwr_mem)))
			);
}

#else

#endif
#endif
