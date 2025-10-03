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


#if	_WIN64
#undef	ae2f_Sys_WIN64	
#define ae2f_Sys_WIN64		ae2f_SysHosted
#undef	ae2f_Sys_WIN
#define ae2f_Sys_WIN		ae2f_SysHosted
#elif	_WIN32
#undef	ae2f_Sys_WIN32
#define ae2f_Sys_WIN32		ae2f_SysHosted
#undef	ae2f_Sys_WIN
#define ae2f_Sys_WIN		ae2f_SysHosted
#elif	__APPLE__
#undef	ae2f_Sys__APPLE__	
#define	ae2f_Sys__APPLE__	ae2f_SysHosted
#elif	__linux
#undef	ae2f_Sys__linux
#define	ae2f_Sys__linux		ae2f_SysHosted
#elif	__unix
#undef	ae2f_Sys__unix	
#define	ae2f_Sys__unix		ae2f_SysHosted
#elif	__posix
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


#if	_WIN64
#undef	N_ae2f_Sys_WIN64	
#define N_ae2f_Sys_WIN64	ae2f_SysNHosted
#undef	N_ae2f_Sys_WIN
#define N_ae2f_Sys_WIN		ae2f_SysNHosted
#elif	_WIN32
#undef	N_ae2f_Sys_WIN32
#define N_ae2f_Sys_WIN32	ae2f_SysNHosted
#undef	N_ae2f_Sys_WIN
#define N_ae2f_Sys_WIN		ae2f_SysNHosted
#elif	__APPLE__
#undef	N_ae2f_Sys__APPLE__	
#define	N_ae2f_Sys__APPLE__	ae2f_SysNHosted
#elif	__linux
#undef	N_ae2f_Sys__linux
#define	N_ae2f_Sys__linux	ae2f_SysNHosted
#elif	__unix
#undef	N_ae2f_Sys__unix	
#define	N_ae2f_Sys__unix	ae2f_SysNHosted
#elif	__posix
#undef	N_ae2f_Sys__posix	
#define	N_ae2f_Sys__posix	ae2f_SysNHosted

#else
typedef char ae2f_Sys_ASSERT_NO_HOST_DETECTED[-1];
#endif

#endif
