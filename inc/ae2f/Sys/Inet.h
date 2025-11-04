/**
 * @file Inet.h
 * @author dalmurii
 * @brief 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef ae2f_Inet_h
#define ae2f_Inet_h

#include "../Sys.h"
#include "./WSock.h"

#include "./Inet-WIN.h"
#include "./Inet-POSIX.h"

#define _ae2f_SysInetMkData				\
	N_ae2f_Sys_WIN(ae2f_SysInetMkData_POSIX)	\
	ae2f_Sys_WIN(ae2f_SysInetMkData_WIN)

/**
 * @typedef ae2f_SysInetMkData_t
 * @brief Type for `ae2f_SysInetMk` as library constructor
 * @see ae2f_SysInetMk
 * @see ae2f_SysInetMkData_DEC
 * */
typedef _ae2f_SysInetMkData ae2f_SysInetMkData;

/**
 * @enum ae2f_eSysInetMk_WIN
 * */
typedef enum {
	/**
	 * @brief Operation succeed
	 * */
	ae2f_SysInetMk_GOOD = 0,

	/**
	 * @brief System is not ready.
	 * @see https://learn.microsoft.com/en-us/windows/win32/winsock/windows-sockets-error-codes-2 
	 * */
	ae2f_SysInetMk_NREADY	ae2f_Sys_WIN(= WSASYSNOTREADY),

	/**
	 * @brief System does not support this version.	<ae2f_SysInetMk::prm_VerReq>
	 * @see ae2f_SysInetMk
	 * @see https://learn.microsoft.com/en-us/windows/desktop/WinSock/windows-sockets-error-codes-2
	 * */
	ae2f_SysInetMk_NSUPPORT	ae2f_Sys_WIN(= WSAVERNOTSUPPORTED),

	/**
	 * @brief Blocked by Windows Sockets 1.1 operations.
	 * @see https://learn.microsoft.com/en-us/windows/desktop/WinSock/windows-sockets-error-codes-2
	 * */
	ae2f_SysInetMk_BLKED	ae2f_Sys_WIN(= WSAEINPROGRESS),

	/**
	 * @brief Exceeded Socket task limit.
	 * @see https://learn.microsoft.com/en-us/windows/desktop/WinSock/windows-sockets-error-codes-2
	 * */
	ae2f_SysInetMk_LMT	ae2f_Sys_WIN(= WSAEPROCLIM),

	/**
	 * @brief Invalid pointer.	<ae2f_SysInetMk::pret_WSAData>
	 * @see ae2f_SysInetMk
	 * @see https://learn.microsoft.com/en-us/windows/desktop/WinSock/windows-sockets-error-codes-2
	 * */
	ae2f_SysInetMk_PTRINVAL	ae2f_Sys_WIN(= WSAEFAULT),


} ae2f_eSysInetMk;

typedef enum {
	ae2f_SysInetDel_GOOD = 0,
	ae2f_SysInetDel_NINIT		ae2f_Sys_WIN(= WSANOTINITIALISED),
	/**
	 * @brief Network is down.
	 * @see https://learn.microsoft.com/en-us/windows/win32/winsock/windows-sockets-error-codes-2
	 * */
	ae2f_SysInetDel_NETDOWN	ae2f_Sys_WIN(= WSAENETDOWN),


	/**
	 * @brief Blocked by Windows Sockets 1.1 operations.
	 * @see https://learn.microsoft.com/en-us/windows/desktop/WinSock/windows-sockets-error-codes-2
	 * */
	ae2f_SysInetDel_BLKED		ae2f_Sys_WIN(= WSAEINPROGRESS),
} ae2f_eSysInetDel;

/**
 * @def ae2f_SysInetMkData_DEC
 * @brief Optionally declares a variable.
 * @tparam prm_vname A name of the variable declared.
 * @see ae2f_SysInetMk
 * */
#define ae2f_SysInetMkData_DEC(prm_vname)			\
	ae2f_Sys_WIN(ae2f_SysInetMkData_DEC_WIN(prm_vname))	\
	N_ae2f_Sys_WIN(ae2f_SysInetMkData_DEC_POSIX(prm_vname))

/**
 * @def ae2f_SysInetMk(prm_VerReq, pret_WSAData)
 * @brief 
 * Wrapper of WSAStartup.		\n
 * Does nothing on POSIX.		\n
 * See ae2f_SysInetDel for cleanup.
 *
 * @details
 * You would be able to use POSIX inet functions(sockets) after this.
 *
 * @returns ae2f_eSysInetMk
 *
 * @param prm_VerReq	<prm>		\n
 * Type: const WORD			\n
 * Brief: Required version of socket library.	\n
 * See: 
 *
 * @param[out] pret_WSAData	<opt> <ptr>	\n
 * Type: ae2f_SysInetMkData_t*			\n
 * Brief: Output pointer for winsocket data.	\n
 *
 * @see ae2f_SysInetDel
 * 
 * */
#define ae2f_SysInetMk(prm_VerReq, pret_WSAData)			\
	ae2f_Sys_WIN(ae2f_SysInetMk_WIN(prm_VerReq, pret_WSAData))	\
	N_ae2f_Sys_WIN(ae2f_SysInetMk_POSIX(prm_VerReq, pret_WSAData))

/**
 * @def ae2f_SysInetDel
 * @brief Wrapper of WSACleanup	\n
 * Cleanup library initialised by ae2f_SysInetMk.
 *
 * @returns ae2f_eSysInetDel
 *
 * @see ae2f_SysInetMk
 * */
#define ae2f_SysInetDel()			\
	ae2f_Sys_WIN(ae2f_SysInetDel_WIN())	\
	N_ae2f_Sys_WIN(ae2f_SysInetDel_POSIX())


#endif
