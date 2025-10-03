/**
 * @file MAlloc.h
 * Simple memory allocation. (same as malloc. process independent)	\n
 * Uses the length of the memory for freeing.
 *
 * ae2f_SysMAlloc
 * ae2f_SysFree
 * */
#ifndef ae2f_Sys_MAlloc_h
#define ae2f_Sys_MAlloc_h

#include <ae2f/Cast.h>
#include "../Sys.h"
#include "./PgAlloc.auto.h"

#if ae2f_Sys_WIN(!)0
#else
#include <sys/mman.h>
#include <unistd.h>
#endif

#endif
