#include "headers.h"

void addText(HWND hEdit, const wchar_t* newText) {
	int len = GetWindowTextLength(hEdit);
	wchar_t* buffer = new wchar_t[len + wcslen(newText) + 1];
	GetWindowText(hEdit, buffer, len + 1);
	wcscat_s(buffer, len + wcslen(newText) + 1, newText);
	SetWindowText(hEdit, buffer);
	delete[] buffer;
}