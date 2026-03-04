/**
 * @file	others.c
 * */

#ifndef	ae2fsys_sock_others_h
#define	ae2fsys_sock_others_h

#include <ae2f/Sys/.sock/core.h>

#if	AE2FSYS_INET_OTHERS

/************************/

#include <fcntl.h>
#include <unistd.h>
#include <ae2f/pat/macrofunc.h>
#include <ae2f/c90/StdBool.h>

typedef int ae2fsys_sock_t;
typedef int ae2fsys_sock_blkmode_t;

/** type invalid */
#define	AE2FSYS_SOCK_INVL	(-1)


ae2f_MAC() ae2fsys_set_sock_blkmode_imp(
		ae2fsys_sock_blkmode_t	rdwr_mem,
		const ae2fsys_sock_t	h_sock,
		const bool		c_blkmode,
		enum AE2FSYS_SOCK_	res
		)
{
	(rdwr_mem) = fcntl(h_sock, F_GETFL, 0);
	(res) = !((rdwr_mem) ^ (int)-1)
		? -1 
		: -(!(fcntl(
						(h_sock)
						, F_SETFL, ((rdwr_mem) 
							| (!!(c_blkmode) * O_NONBLOCK))
						) ^ (int)-1));
}

/************************/

#endif

#endif
