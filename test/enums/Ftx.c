/** 
 * @file Ftx.c 
 * @brief Enum duplication check.
 * */

#include <ae2f/Sys/Ftx.h>

int main() {
	{
		ae2f_eSysFtxWait wait = ae2f_SysFtxWait_GOOD;
		switch(wait) {
			case ae2f_SysFtxWait_GOOD:
			case ae2f_SysFtxWait_INVAL:
			case ae2f_SysFtxWait_PTRINVAL:
			case ae2f_SysFtxWait_TMOUT:
			case ae2f_SysFtxWait_MTXNCOVERABLE:
			case ae2f_SysFtxWait_INTERRUPTED:
			case ae2f_SysFtxWait_MISMATCH:
			case ae2f_SysFtxWait_NO_IMP:
			case ae2f_SysFtxWait_MTXBLK:
			case ae2f_SysFtxWait_MTXOWNDEAD:
			case ae2f_SysFtxWait_MTXNOWN:
				break;
		}
	}

	{
		ae2f_eSysFtxWake wake = ae2f_SysFtxWake_GOOD;
		switch(wake) {
			case ae2f_SysFtxWake_GOOD:
			case ae2f_SysFtxWake_INVAL:
			case ae2f_SysFtxWake_NO_IMP:
			case ae2f_SysFtxWake_PTRINVAL:
			case ae2f_SysFtxWake_MTXBLK:
			case ae2f_SysFtxWake_MTXNOWN:
			case ae2f_SysFtxWake_MTXOWNDEAD:
			case ae2f_SysFtxWake_MTXNCOVERABLE:
				break;
		}
	}

	return 0;
}
