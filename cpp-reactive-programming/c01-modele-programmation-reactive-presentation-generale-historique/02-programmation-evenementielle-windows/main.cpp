#include <windows.h>
// Prototype de la fonction de gestion des événements
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
// Point d'entrée de la fonction principale de l'API Windows
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    MSG msg = {0};
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
    wc.lpszClassName = "minwindowsapp";
    if (!RegisterClass(&wc))
        return 1;
    if (!CreateWindow(wc.lpszClassName,
                      "Application Windows minimale",
                      WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                      0, 0, 640, 480, 0, 0, hInstance, NULL))
        return 2;
    while (GetMessage(&msg, NULL, 0, 0) > 0)
        DispatchMessage(&msg);
    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CLOSE:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}