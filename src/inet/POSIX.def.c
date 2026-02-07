#ifndef	ae2fsys_inet_POSIX_auto_h
#define	ae2fsys_inet_POSIX_auto_h

#include <ae2f/Sys.h>

#if	ae2f_Sys_WIN(!)1

#include <ae2f/Macro.h>
#include <ae2f/cc.h>
#include <ae2f/c90/StdInt.h>
#include <ae2f/Sys/Inet.core.h>

#include <arpa/inet.h>
#include <unistd.h>

typedef void	ae2fsys_mkinet_t;
typedef	u8_fast	ae2fsys_inet_version_t;

#define	_ae2fsys_declmkinet(L_name)

ae2f_MAC() POSIX_ae2fsys_initinet_imp(
		enum AE2FSYS_INET_		ret
		)
{
	(ret) = AE2FSYS_INET_GOOD;
}

#define	_ae2fsys_initinet_imp(ret, c_inet_version, wr_inetdata)	\
	_POSIX_ae2fsys_initinet_imp(ret)

#define	_ae2fsys_stopinet_imp(ret)	\
	_POSIX_ae2fsys_initinet_imp(ret)

#define	closesocket	close

#endif
#endif
