#include "win32main.hpp"

#include "core.hpp"
#include "logger/logger.hpp"

// name of the window class we will register with the OS
constexpr wchar window_class_name[] = L"raytrace_renderer";
constexpr wchar window_title[] = L"Raytrace Renderer";

LRESULT win32_procedure(HWND window, UINT message, WPARAM wparam, LPARAM lparam) {

	LRESULT result = 0;

	switch (message)
	{
	case WM_CLOSE: {
		if (MessageBox(window, L"Are you sure you want to quit?", window_title, MB_OKCANCEL) == IDOK) {
			DestroyWindow(window);
		}
	}break;

	case WM_DESTROY: {
		PostQuitMessage(0);
	}break;

	case WM_PAINT: {
		PAINTSTRUCT ps;
		HDC device_context = BeginPaint(window, &ps);

		int x = 0;
		int y = 0;
		int width = ps.rcPaint.right - ps.rcPaint.left;
		int height = ps.rcPaint.bottom - ps.rcPaint.top;

		PatBlt(
			device_context,
			x, y, width, height,
			BLACKNESS
		);

		EndPaint(window, &ps);
	}break;

	default: {
		result = DefWindowProc(window, message, wparam, lparam);
	}break;
	}

	return result;
}

// win32 apps entry point
int WINAPI wWinMain(
	HINSTANCE process,
	HINSTANCE prev_instance,
	PWSTR cmd_args,
	int show_code) {

	// unused vars
	(void)prev_instance;
	(void)cmd_args;

	// creating and registering a window class
	WNDCLASS window_class = {};
	window_class.style = CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
	window_class.lpfnWndProc = win32_procedure;
	window_class.hInstance = process;
	window_class.lpszClassName = window_class_name;

	ATOM window_class_id = RegisterClass(&window_class);
	if (window_class_id == 0) {
		LOG_ERROR("failed to register window class");
		return 1;
	}

	// instantiating registered window class and showing it
	HWND window = CreateWindowEx(
		0,
		window_class_name,
		window_title,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		nullptr, nullptr,
		process,
		nullptr
	);

	if (window == nullptr) {
		LOG_ERROR("failed to create window");
		return 1;
	}

	ShowWindow(window, show_code);

	// handling windowsOS message loop
	MSG message = {};
	while (GetMessage(&message, window, 0, 0) > 0) {
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	DWORD rc = GetLastError();
	if (rc != 0) {
		LOG_ERROR("error code: " + rc);
		return 1;
	}

	return 0;
}
