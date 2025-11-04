#include <ae2f/Sys/Inet.h>


int main() {
	{
		ae2f_eSysInetMk	mk;
		switch(mk) {
			case ae2f_SysInetMk_LMT:
			case ae2f_SysInetMk_GOOD:
			case ae2f_SysInetMk_BLKED:
			case ae2f_SysInetMk_NREADY:
			case ae2f_SysInetMk_NSUPPORT:
			case ae2f_SysInetMk_PTRINVAL:
				break;
		}
	}

	{
		ae2f_eSysInetDel del;
		switch(del) {
			case ae2f_SysInetDel_GOOD:
			case ae2f_SysInetDel_BLKED:
			case ae2f_SysInetDel_NINIT:
			case ae2f_SysInetDel_NETDOWN:
				break;
		}
	}

	return 0;
}
