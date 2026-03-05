#include <ae2f/Sys/probe.h>
#include <ae2f/pat/allocarr.h>
#include <stdio.h>

#define	PRNT(A)	printf(#A ": %d\n", _AE2FSYS_PROBE_##A)

int main(void);
int main(void) {
	PRNT(APPLE);
	PRNT(BSDI);
	PRNT(FREEBSD); 
	PRNT(LINUX);
	PRNT(NETBSD);
	PRNT(OPENBSD);
	PRNT(UNIX);
	PRNT(WIN32);
	PRNT(WIN64);
	PRNT(WINDOWS);
	return 0;
}
