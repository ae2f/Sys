/**
 * @file Inet-POSIX.h
 * @brief implementation set for Inet.h, for POSIX (non windows) mode.
 * */

#ifndef ae2f_Sys_Inet_POSIX_h
#define ae2f_Sys_Inet_POSIX_h

#include "./Inet.h"

#if ae2f_Sys_WIN(!)1

#include <arpa/inet.h>
#include <unistd.h>

/**
 * @typedef ae2f_SysInetMkData_POSIX
 * @brief
 * Dummy Inet API Data (Unused)
 * */
typedef ae2f_Sys_unused_t	ae2f_SysInetMkData_POSIX;

/**
 * @def ae2f_SysInetMkData_DEC_POSIX(a)
 * @brief Dummy ae2f_SysInetMkData_POSIX initialiser
 * */
#define ae2f_SysInetMkData_DEC_POSIX(a)

/**
 * @brief
 * Dummy library startup code. (Unused) 
 * */
#define ae2f_SysInetMk_POSIX(a, b)	ae2f_SysInetMk_GOOD

/// @brief
/// Dummy library release function.
#define ae2f_SysInetDel_POSIX()		ae2f_SysInetDel_GOOD

/** 
 * @brief since for windowsm for closing socket, closesocket is recommended. 
 * */
#define closesocket		close

#endif

#endif
