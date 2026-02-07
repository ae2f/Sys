/**
 * @file Inet.h
 * @author dalmurii
 * @brief startup code for inet
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef ae2f_Inet_h
#define ae2f_Inet_h

#include "./Sock.h"
#include "./inet/POSIX.auto.h"
#include "./inet/WIN.auto.h"

/**
 * @typedef	ae2fsys_mkinet_t
 * @brief
 * 	Type for `ae2f_SysInetMk` as library constructor
 *
 * @see ae2fsys_initinet_imp
 * @see ae2fsys_declmkinet
 * */
#define	ae2fsys_mkinet_t	ae2fsys_mkinet_t

/**
 * @def		ae2fsys_declmkinet
 * @tparam prm_vname
 * 	A name of the variable declared.
 *
 * @see ae2fsys_initinet_imp
 * */
#define ae2fsys_declmkinet	_ae2fsys_declmkinet

/**
 * @fn	ae2fsys_initinet_imp
 * @brief 
 *	Wrapper of WSAStartup.		\n
 *	Does nothing on POSIX.		\n
 *	See `ae2fsys_stopinet_imp` for cleanup.
 *
 * @details
 *	You would be able to use POSIX inet functions(sockets) after this.	\n
 *	POSIX has fallback, which is just initiallising `ret` as 0.
 *
 * @param	enum AE2FSYS_INET_		ret
 * @param	const ae2fsys_inet_version_t	c_inet_version	\n
 *	Required version of socket library.
 *
 * @param[out]	ae2fsys_mkinet_t* ae2f_restrict	wr_inetdata	\n
 * 	Valid output pointer for winsocket data.
 *
 * @see ae2fsys_stopinet_imp
 * 
 * */
#define	ae2fsys_initinet_imp	_ae2fsys_initinet_imp

/**
 * @fn ae2fsys_stopinet_imp
 * @brief 
 * 	Wrapper of WSACleanup	\n
 * 	Cleanup library initialised by `ae2fsys_initinet_imp`.
 *
 * @param	enum AE2FSYS_INET_	ret
 *
 * @see ae2fsys_initinet_imp
 * */
#define	ae2fsys_stopinet_imp	_ae2fsys_stopinet_imp


#endif
