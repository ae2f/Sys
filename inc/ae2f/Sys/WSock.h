/**
 * @file WSock.h
 * Websocket, used for Inet.h
 * */

#ifndef ae2f_Sys_WSock_h
#define ae2f_Sys_WSock_h

#include "../Sys.h"
#include "./Inet.h"

#if ae2f_Sys_WIN(!)0
#include <windows.h>
#include <winsock2.h>

#define ae2f_SysWSock SOCKET
#else
#define ae2f_SysWSock int
#endif

typedef ae2f_SysWSock ae2f_SysWSock_t;

#endif
