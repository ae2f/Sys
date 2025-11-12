/**
 * @file Inet-Win.h
 * */

#ifndef ae2f_Sys_Inet_WIN_h
#define ae2f_Sys_Inet_WIN_h

#include "./Inet.h"

#if ae2f_Sys_WIN(!)0

#include <windows.h>

/**
 * @def ae2f_SysInetMkData_WIN
 * @brief
 * Inet API data for windows
 * */
#define ae2f_SysInetMkData_WIN WSADATA

/** 
 * @def ae2f_SysInetMkData_DEC_WIN(prm_name)
 * @brief declare a wsadata optionally
 * */
#define ae2f_SysInetMkData_DEC_WIN(prm_name)	WSADATA prm_name[1]

/**
 * @def ae2f_SysInetMk_WIN(wVersionRequired, lpWSAData)
 * @brief
 * Library startup code. \n
 *
 * For releasing, see @ref ae2f_InetDel.
 *
 * # see WSAStartup on Microsoft documentation
 * @param[in]	wVersionRequired	{const WORD}
 * @param[out]	lpWSAData		{WSADATA*}
 */
#define ae2f_SysInetMk_WIN(wVersionRequired, lpWSAData)	\
	ae2f_reinterpret_cast(ae2f_eSysInet, WSAStartup(wVersionRequired, lpWSAData))

/**
 * @def ae2f_SysInetDel_WIN
 * @brief
 * Library release function.
 */
#define ae2f_SysInetDel_WIN()	\
	ae2f_reinterpret_cast(ae2f_eSysInet, WSACleanup())

#endif
#endif
