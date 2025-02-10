#include <windows.h>
#include <tchar.h>
#include <time.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("��������� ����������");

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG Msg;
	WNDCLASSEX wcl;
	wcl.cbSize = sizeof(wcl);
	wcl.style = CS_HREDRAW | CS_VREDRAW;
	wcl.lpfnWndProc = WindowProc;
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;
	wcl.hInstance = hInst;
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcl.lpszMenuName = NULL;
	wcl.lpszClassName = szClassWindow;
	wcl.hIconSm = NULL;
	if (!RegisterClassEx(&wcl))
		return 0;
	hWnd = CreateWindowEx(0, szClassWindow, TEXT("������ � ��������"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInst, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	RECT rect;
	GetWindowRect(hWnd, &rect);
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_RETURN:
			MoveWindow(hWnd, 0, 0, 300, 300, true);
			break;
		case VK_UP:
			SetWindowPos(hWnd, nullptr, rect.left, rect.top - 10, 0, 0, SWP_NOSIZE);
			break;
		case VK_DOWN:
			SetWindowPos(hWnd, nullptr, rect.left, rect.top + 10, 0, 0, SWP_NOSIZE);
			break;
		case VK_LEFT:
			SetWindowPos(hWnd, nullptr, rect.left - 10, rect.top, 0, 0, SWP_NOSIZE);
			break;
		case VK_RIGHT:
			SetWindowPos(hWnd, nullptr, rect.left + 10, rect.top, 0, 0, SWP_NOSIZE);
			break;
		default:
			break;
		}
		break;
	case WM_ACTIVATE:
		MoveWindow(hWnd, 0, 0, 300, 300, true);
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

