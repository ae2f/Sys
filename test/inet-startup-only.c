/**
 * @file 	inet-startup-only.c
 * @brief	test of inet startup
 * */

#include <ae2f/Sys/Inet.h>
#include <ae2f/c90/StdInt.h>
#include <assert.h>
#include <stdio.h>

int main(void);
int main(void) {
	enum AE2FSYS_INET_	RET;

	ae2fsys_declmkinet(MKINET);
	ae2fsys_initinet_imp(RET, MAKEWORD(2, 2), MKINET);

	printf("ae2fsys_initinet_imp: %d\n", (int_leastenum_t)RET);
	assert(!RET);

	ae2fsys_stopinet_imp(RET);

	printf("ae2fsys_initinet_imp: %d\n", (int_leastenum_t)RET);
	assert(!RET);

	return 0;
}
