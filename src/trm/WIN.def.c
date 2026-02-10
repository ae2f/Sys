/** @file WIN.def.c */

#ifndef ae2fsys_trm_WIN_def_c
#define ae2fsys_trm_WIN_def_c

#include <ae2f/Sys.h>

#if	ae2f_Sys_WIN(!)0
#include <ae2f/Sys/Trm.core.h>
#include <ae2f/Macro.h>
#include <ae2f/Keys.h>
#include <windows.h>

#define	ae2fsys_is_trm_tty()	\
	(_isatty(_fileno(stdout)) || _isatty(_fileno(stderr)))


typedef	SHORT ae2fsys_trmpos_t;

ae2f_MAC() WIN_ae2fsys_getconsolehandle_imp(
		HANDLE	ret 
		) 
{
	(ret) = GetStdHandle(STD_OUTPUT_HANDLE);
	ae2f_unexpected_but_if((ret) == INVALID_HANDLE_VALUE || !(ret))
	{
		(ret) = GetStdHandle(STD_ERROR_HANDLE);
	}
	ae2f_unexpected_but_if((ret) == INVALID_HANDLE_VALUE || !(ret))
	{
		(ret) = GetStdHandle(STD_INPUT_HANDLE);
	}

	if((ret) == INVALID_HANDLE_VALUE)
		(ret) = 0;
}

#if	!__ae2f_MACRO_GENERATED
#define	L	void
#define	_WIN_ae2fsys_getconsolehandle_imp	WIN_ae2fsys_getconsolehandle_imp
#endif

ae2f_MAC() ae2fsys_clear_trm_simple_imp(L) {
	HANDLE				L$$CONSOLE;
	CONSOLE_SCREEN_BUFFER_INFO	L$$CSBI;
	_WIN_ae2fsys_getconsolehandle_imp(L$$CONSOLE);

	ae2f_expected_if(
			L$$CONSOLE && 
			GetConsoleScreenBufferInfo(
				L$$CONSOLE
				, &L$$CSBI
				))
	{
		DWORD	L$$CONSOLE_SIZE
			= ae2f_static_cast(DWORD, L$$CSBI.dwSize.X) 
			* ae2f_static_cast(DWORD, L$$CSBI.dwSize.Y); /**/

		DWORD	L$$CHAR_WRIT;
		COORD	L$$SCREEN = {0, 0};

		if(FillConsoleOutputCharacterA(
				L$$CONSOLE
				, (TCHAR)' '
				, L$$CONSOLE_SIZE
				, L$$SCREEN
				, &L$$CHAR_WRIT
				)

			&& FillConsoleOutputAttribute(
					L$$CONSOLE
					, L$$CSBI.wAttributes
					, L$$CONSOLE_SIZE
					, L$$SCREEN
					, &L$$CHAR_WRIT
					)
			&& SetConsoleCursorPosition(
					L$$CONSOLE
					, L$$SCREEN
					))
		{
			/** error must be computed */
		}
	}
}

ae2f_MAC((L, )) ae2fsys_trm_goto_simple_imp(
		const ae2fsys_trmpos_t c_col,
		const ae2fsys_trmpos_t c_row
		)
{
	HANDLE	L$$CONSOLE;
	_WIN_ae2fsys_getconsolehandle_imp(L$$CONSOLE);

	if(L$$CONSOLE && (c_col) >= 1 && (c_row) >= 1)
	{
		COORD	L$$POS;
		L$$POS.X = (c_col) - 1;
		L$$POS.Y = (c_row) - 1;

		SetConsoleCursorPosition(L$$CONSOLE, L$$POS);
	}
}

ae2f_MAC((L, )) ae2fsys_get_trm_size_simple_imp(
		ae2fsys_trmpos_t r_cols,
		ae2fsys_trmpos_t r_rows
		)
{
	HANDLE				L$$CONSOLE;
	CONSOLE_SCREEN_BUFFER_INFO	L$$CSBI;

	(r_cols) = (r_rows) = 0;

	_WIN_ae2fsys_getconsolehandle_imp(L$$CONSOLE);

	if(L$$CONSOLE && GetConsoleScreenBufferInfo(L$$CONSOLE, &L$$CSBI))
	{
		(r_cols) = ae2f_static_cast(
				SHORT, L$$CSBI.srWindow.Right - L$$CSBI.srWindow.Left + 1
				);
		(r_rows) = ae2f_static_cast(
				SHORT, L$$CSBI.srWindow.Bottom - L$$CSBI.srWindow.Top + 1
				)
			;
	}
}

#endif
#endif
