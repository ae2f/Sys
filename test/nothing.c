#include <ae2f/Sys/probe.h>
#include <ae2f/pat/allocarr.h>
#include <stdio.h>

int main(void);
int main(void) {
	printf("WIN32: %d\n", _AE2FSYS_PROBE_WIN32);
	printf("WIN64: %d\n", _AE2FSYS_PROBE_WIN64);
	printf("WINDOWS: %d\n", _AE2FSYS_PROBE_WINDOWS);
	printf("LINUX: %d\n", _AE2FSYS_PROBE_LINUX);
	return 0;
}
