#include <ae2f/Sys/Inet.h>
#include <assert.h>


int main(void) {
	{
		ae2f_eSysInetMk	mk = ae2f_SysInetMk_GOOD;
		switch(mk) {
			case ae2f_SysInetMk_LMT:
			case ae2f_SysInetMk_GOOD:
			case ae2f_SysInetMk_BLKED:
			case ae2f_SysInetMk_NREADY:
			case ae2f_SysInetMk_NSUPPORT:
			case ae2f_SysInetMk_PTRINVAL:
				break;

			default: assert(0);
		}
	}

	{
		ae2f_eSysInetDel del = ae2f_SysInetDel_GOOD;
		switch(del) {
			case ae2f_SysInetDel_GOOD:
			case ae2f_SysInetDel_BLKED:
			case ae2f_SysInetDel_NINIT:
			case ae2f_SysInetDel_NETDOWN:
				break;

			default: assert(0);
		}
	}

	return 0;
}
