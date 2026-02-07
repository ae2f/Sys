/**
 * @file 	inet.c
 * @brief	test of inet startup
 * */

#include <ae2f/Sys/Inet.h>
#include <assert.h>
#include <stdio.h>

int main(void);
int main(void) {
	enum AE2FSYS_INET_	RET;

	ae2fsys_declmkinet(MKINET);
	ae2fsys_initinet_imp(RET, MAKEWORD(2, 2), MKINET);

	printf("ae2fsys_initinet_imp: %u\n", RET);
	assert(!RET);

	ae2fsys_stopinet_imp(RET);

	printf("ae2fsys_initinet_imp: %u\n", RET);
	assert(!RET);

	return 0;
}
