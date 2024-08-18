#pragma once
#include <windows.h>
#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <iomanip>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void createInterface(HWND hwnd), addText(HWND hEdit, const wchar_t* newText),
	 deleteLastSymbol(HWND hEdit), calculate(HWND hEdit);
double calculateInBrackets(std::wstring& equation);

extern std::array<const wchar_t*, 20> buttonSymbols;
extern std::array<HWND, 20> buttonsHWND;
extern HWND hEdit;