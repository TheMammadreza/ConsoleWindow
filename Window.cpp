#include "Window.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

Window::Window() : HANDLE_INSTANCE(GetModuleHandle(nullptr))
{
	WNDCLASS windowClass = {};
	windowClass.lpszClassName = CLASS_NAME;
	windowClass.hInstance = HANDLE_INSTANCE;
	windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	windowClass.hCursor = LoadCursor(NULL, IDC_HAND);
	// Control all messages by assigning WindowProc
	windowClass.lpfnWndProc = WindowProc;

	RegisterClass(&windowClass);

	RECT rect;
	SetRect(&rect, 200, 200, 840, 680);

	AdjustWindowRect(&rect, WINDOW_STYLE, false);

	handleWindow = CreateWindowEx(0, CLASS_NAME, L"Title", WINDOW_STYLE, rect.left, rect.top,
		rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, HANDLE_INSTANCE, NULL);

	ShowWindow(handleWindow, SW_SHOW);
}

Window::~Window()
{
	UnregisterClass(CLASS_NAME, HANDLE_INSTANCE);
}

bool Window::ProcessMessages()
{
	MSG msg = {};
	while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE)) {
		if (msg.message == WM_QUIT) {
			return false;
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return true;
}