#include "headers.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"CalculatorWND";

    RegisterClass(&wc);

    HWND hwnd = CreateWindowExW( 0, L"CalculatorWND", L"Calculator", WS_OVERLAPPEDWINDOW & ~(WS_THICKFRAME | WS_MAXIMIZEBOX),
                                CW_USEDEFAULT, CW_USEDEFAULT, 480, 460,
                                NULL, NULL, hInstance, NULL );
    if (hwnd == NULL) {
        return -1;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
