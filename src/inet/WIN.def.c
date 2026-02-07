#ifndef	ae2fsys_inet_WIN_auto_h
#define ae2fsys_inet_WIN_auto_h

#include <ae2f/Sys.h>

#if ae2f_Sys_WIN(!)0

#include <windows.h>
#include <ae2f/Keys.h>
#include <ae2f/Macro.h>
#include <ae2f/Sys/Inet.core.h>

typedef WSADATA	ae2fsys_mkinet_t;
typedef	WORD	ae2fsys_inet_version_t;

#define	_ae2fsys_declmkinet(L_name)	\
	ae2fsys_mkinet_t	L_name[1]

ae2f_MAC() ae2fsys_initinet_imp(
		enum AE2FSYS_INET_		ret,
		const ae2fsys_inet_version_t	c_inet_version,
		ae2fsys_mkinet_t* ae2f_restrict	wr_inetdata
		)
{
	switch(WSAStartup(c_inet_version, wr_inetdata))
	{
		case 0:
			(ret) = AE2FSYS_INET_GOOD;
			break;
		case WSASYSNOTREADY:
			(ret) = AE2FSYS_INET_NREADY;
			break;
		case WSAVERNOTSUPPORTED:
			(ret) = AE2FSYS_INET_NSUPPORT;
			break;
		case WSAEINPROGRESS:
			(ret) = AE2FSYS_INET_BLKED;
			break;
		case WSAEPROCLIM:
			(ret) = AE2FSYS_INET_PROCLMT;
			break;
		case WSAEFAULT:
			(ret) = AE2FSYS_INET_PTRINVAL;
			break;
		default:
			(ret) = AE2FSYS_INET_UNKNOWN;
			break;
	}
}

ae2f_MAC() ae2fsys_stopinet_imp(
		enum AE2FSYS_INET_	ret
		)
{
	switch(WSACleanup()) {
		case 0:
			(ret) = AE2FSYS_INET_GOOD;
			break;
		case WSAEINPROGRESS:
			(ret) = AE2FSYS_INET_BLKED;
			break;
		case WSAENETDOWN:
			(ret) = AE2FSYS_INET_NETDOWN;
			break;
		case WSANOTINITIALISED:
			(ret) = AE2FSYS_INET_NOINIT;
			break;
		default:
			(ret) = AE2FSYS_INET_UNKNOWN;
			break;
	}
}

#endif
#endif
