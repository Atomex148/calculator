#include "headers.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            createInterface(hwnd);
            break;
        }

        case WM_DESTROY: {
            PostQuitMessage(0);
            return 0;
            break;
        }

        case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            if (wmId >= 2 && wmId < 2 + buttonSymbols.size()) {
                if (wmId == 5) deleteLastSymbol(hEdit);
                else if (wmId == 18) SetWindowTextW(hEdit, L"");
                else if (wmId == 20) calculate(hEdit);
                else addText(hEdit, buttonSymbols.at(wmId - 2));
            }
            
        }

        default: return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}