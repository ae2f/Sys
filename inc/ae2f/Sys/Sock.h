/**
 * @file Sock.h
 * Socket type, used for Inet.h
 * */

#ifndef ae2f_Sys_WSock_h
#define ae2f_Sys_WSock_h

#include "./sock/POSIX.auto.h"
#include "./sock/WIN.auto.h"
#include "./sock/_linux.auto.h"

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
 * @fn		ae2fsys_set_sock_blkmode_imp
 * @brief	set a socket's blocking mode
 * @param	ae2fsys_sock_blkmode_t	rdwr_mem
 * @param	const ae2fsys_sock_t	h_sock
 * @param	const bool		c_blkmode
 * @param	enum AE2FSYS_SOCK_	res
 * */
#define ae2fsys_set_sock_blkmode_imp	_ae2fsys_set_sock_blkmode_imp

#endif
