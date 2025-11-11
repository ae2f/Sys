/**
 * @file Sys.h
 * Determines which host it is using
 * */
#ifndef ae2f_Sys_h
#define ae2f_Sys_h


#define ae2f_SysHosted(...) __VA_ARGS__
#define ae2f_SysNHosted(...)

#define ae2f_Sys_WIN64		ae2f_SysNHosted
#define ae2f_Sys_WIN32		ae2f_SysNHosted
#define ae2f_Sys__APPLE__	ae2f_SysNHosted
#define ae2f_Sys__linux		ae2f_SysNHosted
#define ae2f_Sys__unix		ae2f_SysNHosted
#define ae2f_Sys__posix		ae2f_SysNHosted
#define ae2f_Sys_WIN		ae2f_SysNHosted

#if	defined(_WIN64) && (_WIN64)
#undef	ae2f_Sys_WIN64	
#define ae2f_Sys_WIN64		ae2f_SysHosted
#undef	ae2f_Sys_WIN
#define ae2f_Sys_WIN		ae2f_SysHosted
#elif	defined(_WIN32) && (_WIN32)
#undef	ae2f_Sys_WIN32
#define ae2f_Sys_WIN32		ae2f_SysHosted
#undef	ae2f_Sys_WIN
#define ae2f_Sys_WIN		ae2f_SysHosted
#elif	defined(__APPLE__) && (__APPLE__)
#undef	ae2f_Sys__APPLE__	
#define	ae2f_Sys__APPLE__	ae2f_SysHosted
#elif	defined(__linux) && (__linux)
#undef	ae2f_Sys__linux
#define	ae2f_Sys__linux		ae2f_SysHosted
#elif	defined(__unix) && (__unix)
#undef	ae2f_Sys__unix	
#define	ae2f_Sys__unix		ae2f_SysHosted
#elif	defined(__posix) && (__posix)
#undef	ae2f_Sys__posix	
#define	ae2f_Sys__posix		ae2f_SysHosted

#else
typedef char ae2f_Sys_ASSERT_NO_HOST_DETECTED[-1];
#endif



#define N_ae2f_Sys_WIN64	ae2f_SysHosted
#define N_ae2f_Sys_WIN32	ae2f_SysHosted
#define N_ae2f_Sys__APPLE__	ae2f_SysHosted
#define N_ae2f_Sys__linux	ae2f_SysHosted
#define N_ae2f_Sys__unix	ae2f_SysHosted
#define N_ae2f_Sys__posix	ae2f_SysHosted
#define N_ae2f_Sys_WIN		ae2f_SysHosted


#if	defined(_WIN64) && (_WIN64)
#undef	N_ae2f_Sys_WIN64	
#define N_ae2f_Sys_WIN64	ae2f_SysNHosted
#undef	N_ae2f_Sys_WIN
#define N_ae2f_Sys_WIN		ae2f_SysNHosted
#elif	defined(_WIN32) && (_WIN32)
#undef	N_ae2f_Sys_WIN32
#define N_ae2f_Sys_WIN32	ae2f_SysNHosted
#undef	N_ae2f_Sys_WIN
#define N_ae2f_Sys_WIN		ae2f_SysNHosted
#elif	defined(__APPLE__) && (__APPLE__)
#undef	N_ae2f_Sys__APPLE__	
#define	N_ae2f_Sys__APPLE__	ae2f_SysNHosted
#elif	defined(__linux) && (__linux)
#undef	N_ae2f_Sys__linux
#define	N_ae2f_Sys__linux	ae2f_SysNHosted
#elif	defined(__unix) && (__unix)
#undef	N_ae2f_Sys__unix	
#define	N_ae2f_Sys__unix	ae2f_SysNHosted
#elif	defined(__posix) && (__posix)
#undef	N_ae2f_Sys__posix	
#define	N_ae2f_Sys__posix	ae2f_SysNHosted

#else
typedef char ae2f_Sys_ASSERT_NO_HOST_DETECTED[-1];
#endif

/**
 * @typedef ae2f_Sys_unused_t
 * @brief Type which is unused 
 * */
typedef char ae2f_Sys_unused_t;

#endif
