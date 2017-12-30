/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2017.12.27 / 12��54
+
-             �޸�ʱ�䣺2017.12.30 / 15��50
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
HINSTANCE                 g_hinst;

/*
-
+			���������������
-
*/
int WINAPI 
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){

	static char szWndClassName[] = TEXT("gameWin");

	HWND                  hwnd;
	MSG                   msg;
	WNDCLASS              wndclass;

	g_hinst = hInstance;

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
		MessageBox(NULL, TEXT("ע��ʧ��"), TEXT("����"), MB_ICONERROR);
		return 0;
	}

	// �ɿͻ�����С��ȡ���ڴ�С //
	RECT	rect;
	SetRect(&rect, 0, 0, CLI_WIDTH, CLI_HEIGHT);
	AdjustWindowRect(&rect,
		WS_OVERLAPPEDWINDOW,
		FALSE);

	hwnd = CreateWindow(
		szWndClassName,		                  //windows class name
		TEXT("Random Heroes"),			      //windows caption	
		WS_OVERLAPPEDWINDOW ^ WS_MAXIMIZEBOX,    //windows style
		CW_USEDEFAULT,		                  //intial x position
		CW_USEDEFAULT,		                  //intial y position
		rect.right - rect.left,		          //intial x size
		rect.bottom - rect.top,		          //intial y size
		NULL,				                  //parent wnidow handle
		NULL,				                  //window menu handle
		hInstance,			                  //program instance handle
		NULL);				                  //creation paramenter

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
-			��Ϣ�����߼�����
+
*/

LRESULT CALLBACK 
WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) {

	static PMAP                    pmap;
	static PSYS                    psys;
	static PROLECFG                prole;
	static PIMAGE                  pimage;

	switch (message) {

	case WM_CREATE:
		
		psys   = InitSystem();
		prole  = InitRole(g_hinst);
		pimage = InitImage(hwnd);
		pmap   = InitMap(g_hinst, hwnd);

		LoadMap(pmap, hwnd,  g_hinst);

		SetTimer(hwnd, ID_TIMER, 20, NULL);

		break;

	case WM_PAINT:

		DrawMap(pmap, pimage, hwnd);
		DrawRole(hwnd, prole, pimage);
		DrawImage(pimage, hwnd);

		break;

	case WM_KEYDOWN:

		ControlRole(prole, wparam, hwnd);

		break;

	case WM_KEYUP:

		UnControlRole(prole, wparam, hwnd);

		break;

	case WM_TIMER:

		RoleJumpProc(prole, hwnd);

		break;

	case WM_ERASEBKGND:

		return TRUE;

	case WM_DESTROY:

		FreeSystem(psys);
		FreeRole(prole);
		FreeImage(pimage);
		FreeMap(pmap);
		FreeCapEffct(P_CAP_EFFECT);

		KillTimer(hwnd, ID_TIMER);

		PostQuitMessage(0);

		break;

	}

	return DefWindowProc(hwnd, message, wparam, lparam);

}
