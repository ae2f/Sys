#ifndef ae2f_Sys_WSock_auto_h
#define ae2f_Sys_WSock_auto_h

#include <ae2f/Sys/WSock.h>
#include <ae2f/Macro.h>

#if ae2f_Sys_WIN(!)0

typedef u_long ae2f_SysWSockUBlock_t;

/** Turns a socket into unblock mode */
ae2f_MAC() ae2f_SysWSockUBlock(ae2f_SysWSockNBlock_t ref_mem, const ae2f_SysWSock_t prm_sock, int res)
{
    (ref_mem) = 1;
    if (ioctlsocket((prm_sock), FIONBIO, &(ref_mem)) != 0) {
        (res) = -1;
    }
    (res) = 0;
}

#else

#include <fcntl.h>
#include <unistd.h>

typedef int ae2f_SysWSockUBlock_t;

/** Turns a socket into unblock mode */
ae2f_MAC() ae2f_SysWSockUBlock(ae2f_SysWSockUBlock_t ref_mem, const ae2f_SysWSock_t prm_sock, int res)
{
	(ref_mem) = fcntl(prm_sock, F_GETFL, 0);                                           

	if ((ref_mem) == -1) {                                                       
		(res) = -1;                                                             
	} else {
		/* Add non-blocking flag */                                              
		(ref_mem) |= O_NONBLOCK;                                                   
		if (fcntl((prm_sock), F_SETFL, (ref_mem)) == -1) {                                 
			(res) = -1;                                                           
		} else                                                                   
			(res) = 0;                                                            
	}
}

#endif

#endif
