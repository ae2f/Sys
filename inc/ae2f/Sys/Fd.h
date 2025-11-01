/**
 * @file Fd.h
 * @brief File descriptor
 * */

#ifndef ae2f_Sys_Fd_h
#define ae2f_Sys_Fd_h

#include "../Sys.h"
#if ae2f_Sys_WIN(!)0
#include <windows.h>
#else
#include <unistd.h>
#endif

/**
 * @typedef	ae2f_SysFd_t
 * @brief	
 * */
typedef ae2f_Sys_WIN(HANDLE) N_ae2f_Sys_WIN(int)	ae2f_SysFd_t;
#define ae2f_SysFdStdIn ae2f_Sys_WIN(GetStdHandle(STD_INPUT_HANDLE))	N_ae2f_Sys_WIN(STDIN_FILENO)
#define ae2f_SysFdStdOut ae2f_Sys_WIN(GetStdHandle(STD_OUTPUT_HANDLE))	N_ae2f_Sys_WIN(STDOUT_FILENO)
#define ae2f_SysFdStdErr ae2f_Sys_WIN(GetStdHandle(STD_ERROR_HANDLE))	N_ae2f_Sys_WIN(STDERR_FILENO)

#endif
