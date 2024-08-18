#include "headers.h"

void deleteLastSymbol(HWND hEdit) {
	int len = GetWindowTextLength(hEdit);
	if (len == 0) return;
	wchar_t* buffer = new wchar_t[len];
	GetWindowText(hEdit, buffer, len);
	SetWindowText(hEdit, buffer);
	delete[] buffer;
}