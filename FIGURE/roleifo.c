/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2017.12.27 / 15��21
+
-             �޸�ʱ�䣺2017.12.27 / 15��21
+
-             �ļ����ƣ�roleifo.c
+
-             ģ�飺roleģ�飬������Ϸ��ɫ��ģ�飬������ɫ�Ŀ��ƣ����ƣ�״̬��
+
-             ���ܣ�roleģ��Դ�ļ���������������
+
*/

#include "roleifo.h"

/*
+
-			��������
+
*/

PROLE
InitRole(HINSTANCE _hins) {

	PROLE _prole = (PROLE)malloc(sizeof(ROLE));

	if (!_prole)
		exit(OVERFLOW);

	BITMAP            _bmp;

	_prole->m_hbmp   = LoadBitmap(_hins, MAKEINTRESOURCE(IDB_REAL_ROLE_BAN));
	_prole->m_status = 0;
	_prole->m_index = 0;
	_prole->m_speed = 5;
	
	GetObject(_prole->m_hbmp, sizeof(BITMAP), &_bmp);
	_prole->m_size.cx = (_bmp.bmWidth) / 3;
	_prole->m_size.cy = _bmp.bmHeight / 3;

	_prole->m_pos.x = 0;
	_prole->m_pos.y = CLI_HEIGHT - _prole->m_size.cy;

	return _prole;

}
// ��ʼ��ROLE�ṹ��ʵ��


STATUS
FreeRole(PROLE _prole) {

	assert(_prole != NULL);

	free(_prole);

	return OK;

}
// �ͷ�ROLEʵ����Դ


STATUS
DrawRole(const HWND _hwnd, const PROLE _prole) {

	assert(_hwnd != NULL);
	assert(_prole != NULL);

	HDC               _memDc;
	HDC               _winDc;
	HDC               _tmpDc;
	HBITMAP           _tmpHbm;

	_winDc  = GetDC(_hwnd);
	_memDc  = CreateCompatibleDC(_winDc);
	_tmpDc  = CreateCompatibleDC(_winDc);
	_tmpHbm = CreateCompatibleBitmap(_winDc, _prole->m_size.cx, _prole->m_size.cy);

	SelectObject(_memDc, _tmpHbm);

	SelectObject(_tmpDc, _prole->m_hbmp);

	TransparentBlt(_memDc,
		0, 0,
		_prole->m_size.cx, _prole->m_size.cy,
		_tmpDc,
		(_prole->m_size.cx)*(_prole->m_index),	// ����ü�
		(_prole->m_size.cy)*(_prole->m_status), // ����ü�
		_prole->m_size.cx, _prole->m_size.cy,
		RGB(0, 0, 0));

	BitBlt(_winDc,
		_prole->m_pos.x, _prole->m_pos.y,
		_prole->m_size.cx, _prole->m_size.cy,
		_memDc,
		0, 0,
		SRCCOPY);

	ReleaseDC(_hwnd, _winDc);
	DeleteDC(_tmpDc);
	DeleteDC(_memDc);
	DeleteObject(_tmpHbm);

	return OK;

}
// ������ɫ


STATUS
MoveRole(PROLE _prole, WPARAM _wParam) {

	assert(_prole != NULL);

	switch (_wParam) {

	case VK_LEFT:

		_prole->m_pos.x -= _prole->m_speed;

		break;

	case VK_RIGHT:

		_prole->m_pos.x += _prole->m_speed;

		break;

	}

	_prole->m_index++;

	if (_prole->m_index == 3) {

		_prole->m_index = 0;

	}

}
// ��ɫ�ƶ�