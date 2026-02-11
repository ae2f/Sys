/**
 * @file Sock.h
 * Socket type, used for Inet.h
 * */

#ifndef ae2f_Sys_WSock_h
#define ae2f_Sys_WSock_h

#include "./sock/POSIX.auto.h"
#include "./sock/WIN.auto.h"
#include "./sock/_linux.auto.h"

#include <ae2f/Cast.h>
#include <ae2f/Keys.h>

/** 
 * @typedef	ae2fsys_sock_t
 * @brief	A socket handle
 * */
#define	ae2fsys_sock_t			ae2fsys_sock_t

/**
 * @typedef	h_ae2fsys_sock_t
 * @brief	A socket handle
 * */
#define	h_ae2fsys_sock_t		ae2fsys_sock_t

/**
 * @typedef	ae2fsys_sock_blkmode_t
 * @brief	a type to store the block mode
 * */
#define	ae2fsys_sock_blkmode_t		ae2fsys_sock_blkmode_t

/**
 * @fn		
 * void ae2fsys_set_sock_blkmode_imp(
 * 	ae2fsys_sock_blkmode_t&	rdwr_mem,
 * 	const ae2fsys_sock_t	h_sock,
 * 	const bool		c_blkmode,
 * 	enum AE2FSYS_SOCK_&	res
 * )
 * @brief	set a socket's blocking mode
 * @param	rdwr_mem
 * @param	h_sock
 * @param	c_blkmode
 * @param	res
 * */
#define ae2fsys_set_sock_blkmode_imp	_ae2fsys_set_sock_blkmode_imp


/**
 * @fn	bool ae2fsys_checksock_naive(ae2fsys_sock_t h_sock);
 * @brief	
 * returns if `h_sock` is valid.	\n
 * Naive, cross-platform option.
 * */
#define	ae2fsys_checksock_naive(h_sock)	\
	((h_sock) != AE2FSYS_SOCK_INVL	\
	&& ae2f_expected(ae2f_reinterpret_cast(int, h_sock) >= 0))

#endif
