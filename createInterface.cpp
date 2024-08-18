#include "headers.h"

HWND hEdit;
std::array<HWND, 20> buttonsHWND = {};
std::array<const wchar_t*, 20> buttonSymbols = {
    L"(\0", L")\0", L".\0", L"<--\0",
    L"1\0", L"2\0", L"3\0", L"+\0",
    L"4\0", L"5\0", L"6\0", L"-\0",
    L"7\0", L"8\0", L"9\0", L"*\0",
    L"C\0", L"0\0", L"=\0", L"/\0"
};

void createInterface(HWND hwnd) {
    int buttonWidth = 110, buttonHeight = 50, xStart = 12, yStart = 150;

    hEdit = CreateWindowExW(
        0, L"EDIT",
        NULL,
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT,
        10, 10, 445, 130,
        hwnd,
        (HMENU)1,
        (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
        NULL
    );

    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 4; i++) {
            int buttonID = 2 + i + j * 4;
            HWND hButton = CreateWindowExW(
                0,
                L"BUTTON",
                buttonSymbols.at(i + j * 4),
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                xStart + i * buttonWidth,
                yStart + j * buttonHeight,
                buttonWidth,
                buttonHeight,
                hwnd,
                (HMENU)buttonID,
                NULL,
                NULL
            );
            buttonsHWND.at(i + j * 4) = hButton;
        }
    }
}
