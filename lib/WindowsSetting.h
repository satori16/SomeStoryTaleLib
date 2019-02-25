#pragma once

#if _WIN32

#include <Windows.h>

bool InitializeDisplayMode() {//after windows10 th?
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hOut == INVALID_HANDLE_VALUE)
	{
		return false;
	}

	DWORD dwMode = 0;
	if (!GetConsoleMode(hOut, &dwMode))
	{
		return false;
	}

	dwMode |= 4;//ENABLE_VIRTUAL_TERMINAL_PROCESSING;//this is after win10 th2 update.
	if (!SetConsoleMode(hOut, dwMode))
	{
		return false;
	}
	return true;

}

#else 

bool InitializeDisplayMode() {
	return true;
}

#endif