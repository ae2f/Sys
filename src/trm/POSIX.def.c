/** @file POSIX.def.c */

#ifndef	ae2fsys_trm_POSIX_DEF_c
#define ae2fsys_trm_POSIX_DEF_c

#include <ae2f/Sys.h>

#if	ae2f_Sys_WIN(!)1

#include <ae2f/Sys/Trm.core.h>
#include <ae2f/Macro.h>
#include <ae2f/Keys.h>

#include <stdio.h>

#include <unistd.h>
#include <sys/ioctl.h>

#define	ae2fsys_is_trm_tty()	\
	(_isatty(_fileno(stdout)) || _isatty(_fileno(stderr)))

typedef	int ae2fsys_trmpos_t;

ae2f_MAC()	ae2fsys_clear_trm_simple_imp(void)
{
	printf("\x1B[2J\x1B[H");
	fflush(stdout);
}

ae2f_MAC((L, ))	ae2fsys_trm_goto_simple_imp(
		const ae2fsys_trmpos_t	c_col,
		const ae2fsys_trmpos_t	c_row
		)
{
	if((c_col) && (c_row)) {
		printf("\x1B[%d;%dH", (c_row), (c_col));
		fflush(stdout);
	}
}

ae2f_MAC((L, )) ae2fsys_get_trm_size_simple_imp(
		ae2fsys_trmpos_t	r_cols,
		ae2fsys_trmpos_t	r_rows
		)
{
	struct winsize	L$$WINSZ;


	(r_cols) = (r_rows) = 0u;

	if(isatty(STDOUT_FILENO) && !ioctl(STDOUT_FILENO, TIOCGWINSZ, &L$$WINSZ)) {
		(r_cols) = (L$$WINSZ.ws_col)
			& ~((L$$WINSZ.ws_col) >> ((sizeof(L$$WINSZ.ws_col) << 3) - 1));

		(r_rows) = (L$$WINSZ.ws_row)
			& ~((L$$WINSZ.ws_col) >> ((sizeof(L$$WINSZ.ws_col) << 3) - 1));
	}

	else if(isatty(STDERR_FILENO) && !ioctl(STDERR_FILENO, TIOCGWINSZ, &L$$WINSZ)) {
		(r_cols) = (L$$WINSZ.ws_col)
			& ~((L$$WINSZ.ws_col) >> ((sizeof(L$$WINSZ.ws_col) << 3) - 1));

		(r_rows) = (L$$WINSZ.ws_row)
			& ~((L$$WINSZ.ws_col) >> ((sizeof(L$$WINSZ.ws_col) << 3) - 1));
	}

	else if(isatty(STDIN_FILENO) && !ioctl(STDIN_FILENO, TIOCGWINSZ, &L$$WINSZ)) {
		(r_cols) = (L$$WINSZ.ws_col)
			& ~((L$$WINSZ.ws_col) >> ((sizeof(L$$WINSZ.ws_col) << 3) - 1));

		(r_rows) = (L$$WINSZ.ws_row)
			& ~((L$$WINSZ.ws_col) >> ((sizeof(L$$WINSZ.ws_col) << 3) - 1));
	}
}

#endif
#endif
