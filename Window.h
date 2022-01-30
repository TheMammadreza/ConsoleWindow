#pragma once

#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class Window
{
private:
	const wchar_t* CLASS_NAME = L"The Window Class";
	const HINSTANCE HANDLE_INSTANCE;
	const DWORD WINDOW_STYLE = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

	HWND handleWindow;
public:
	Window();
	~Window();

	bool ProcessMessages();
};