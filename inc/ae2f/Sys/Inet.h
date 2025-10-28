/**
 * @file Inet.h
 * @author ae2f
 * @brief 
 * @date 2025-02-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef ae2f_Inet_h
#define ae2f_Inet_h

#include <ae2f/Cast.h>
#include "../Sys.h"
#include "./WSock.h"

#if ae2f_Sys_WIN(!)0
#include <winsock2.h>

/// @brief
/// Inetet API Data
#define ae2f_SysInetMkData WSADATA

/// @brief
/// Library startup code. \n
/// Notice it is for Windows, not Linux.
///
/// For releasing, see @ref ae2f_InetDel.
/// 
/// # see WSAStartup on Microsoft documentation
/// @param[in] wVersionRequired {WORD}
/// @param[out] lpWSAData {LPWSADATA}
#define ae2f_SysInetMk(wVersionRequired, lpWSAData) WSAStartup(wVersionRequired, lpWSAData)

/// @brief
/// Library release function.
#define ae2f_SysInetDel WSACleanup

/** 
 * @brief
 * [G]et Last [Err]or
 * */
#define ae2f_SysInetGErr()	WSAGetLastError()

#else

#include <arpa/inet.h>
#include <unistd.h>

/// @brief
/// Dummy Inetet API Data
#define ae2f_SysInetMkData int8_t

/// @brief
/// Library startup code. \n
/// Notice it is for Windows, not Linux.
///
/// For releasing, see @ref ae2f_InetDel.
///
/// Linux needs no startup for Inetet api. It will always success.
#define ae2f_SysInetMk(a, b) ((void)0)

/// @brief
/// Library release function.
#define ae2f_SysInetDel() 0

/** 
 * @brief
 * [G]et Last [Err]or
 * */
#define ae2f_SysInetGErr()	WSAGetLastError()

/** @brief since for windowsm for closing socket, closesocket is recommended. */
#define closesocket		close

#endif

#endif
