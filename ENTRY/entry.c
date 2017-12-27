/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2017.12.27 / 12��54
+
-             �޸�ʱ�䣺2017.12.27 / 12��54
+
-             �ļ����ƣ�entry.c
+
-             ģ�飺entryģ�飬��������ڣ���Ϸ�����߼����ƣ���Ϣ���д���
+
-             ���ܣ�entryģ��Դ�ļ��������������壬�߼����ƣ���Ϣ����
+
*/

#include "entry.h"

/*
+
-			ȫ�ֱ���������
+
*/
SYS                       g_sys;
HINSTANCE                 g_hinst;

/*
-
+			���������������
-
*/
int WINAPI 
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){

	static char szWndClassName[] = "gameWin";

	HWND                  hwnd;
	MSG                   msg;
	WNDCLASS              wndclass;

	g_hinst = hInstance;

	InitSystem(&g_sys);

	wndclass.style         = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc   = WndProc;
	wndclass.cbClsExtra    = 0;
	wndclass.cbWndExtra    = 0;
	wndclass.hInstance     = hInstance;
	wndclass.hIcon         = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));
	wndclass.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName  = NULL;
	wndclass.lpszClassName = szWndClassName;

	if (!RegisterClass(&wndclass)) {
		MessageBox(NULL, "ע��ʧ��", "����", MB_ICONERROR);
		return 0;
	}

	// �ɿͻ�����С��ȡ���ڴ�С //
	RECT	rect;
	SetRect(&rect, 0, 0, CLI_WIDTH, CLI_HEIGHT);
	AdjustWindowRect(&rect,
		WS_OVERLAPPEDWINDOW,
		FALSE);

	hwnd = CreateWindow(
		szWndClassName,		            //windows class name
		"Joezeo",			            //windows caption	
		WS_OVERLAPPEDWINDOW,            //windows style
		CW_USEDEFAULT,		            //intial x position
		CW_USEDEFAULT,		            //intial y position
		rect.right - rect.left,		    //intial x size
		rect.bottom - rect.top,		    //intial y size
		NULL,				            //parent wnidow handle
		NULL,				            //window menu handle
		hInstance,			            //program instance handle
		NULL);				            //creation paramenter

	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;

}

/*
+
-			��������
+
*/

LRESULT CALLBACK 
WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) {

	HDC                            hdc;
	PAINTSTRUCT                    ps;
	RECT                           rect;

	switch (message) {

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		EndPaint(hwnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	}

	return DefWindowProc(hwnd, message, wparam, lparam);

}


VOID
InitSystem(PSYS _psys) {

	assert(_psys != NULL);

	_psys->m_cliHeight = CLI_HEIGHT;
	_psys->m_cliWidth  = CLI_WIDTH;

}