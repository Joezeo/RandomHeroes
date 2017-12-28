/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2017.12.28 / 15��40
+
-             �޸�ʱ�䣺2017.12.28 / 15��40
+
-             �ļ����ƣ�mapifo.c
+
-             ģ�飺mapģ�飬��ͼ�ı༭�����أ�����
+
-             ���ܣ�mapģ��Դ�ļ���������������
+
*/

#include "mapifo.h"

/*
+
-			��̬����ǰ������
+
*/
static STATUS
__LoadFloor(HDC, HDC, HINSTANCE);
// ��ͼ���ص�ש



/*
+
-			��������
+
*/

PMAP
InitMap(HINSTANCE _hins, HWND _hwnd) {

	PMAP _pmap = (PMAP)malloc(sizeof(MAP));
	if (!_pmap)
		exit(OVERFLOW);

	HDC _hdc = GetDC(_hwnd);

	_pmap->m_hbmp[0]  = LoadBitmap(_hins, MAKEINTRESOURCE(IDB_CHAPTER_1));
	_pmap->m_hbmp[1]  = LoadBitmap(_hins, MAKEINTRESOURCE(IDB_CHAPTER_1_RETURN));
	_pmap->m_memDc = CreateCompatibleDC(_hdc);

	ReleaseDC(_hwnd, _hdc);

	return _pmap;

}
// ��ʼ��MAPʵ��


STATUS
FreeMap(PMAP _pmap) {

	assert(_pmap != NULL);

	free(_pmap);
	_pmap = NULL;

	return OK;
	
}
// �ͷ�MAPʵ���ڴ���Դ


STATUS
LoadMap(PMAP _pmap, HWND _hwnd, HINSTANCE _hins) {

	assert(_pmap != NULL);
	assert(_hwnd != NULL);

	HDC                     _hdc;
	HDC                     _tmpDc;
	HBITMAP                 _tmpHbmp;
	BITMAP                  _bmp;
	SHORT                   _index;

	_hdc = GetDC(_hwnd);
	_tmpDc = CreateCompatibleDC(_hdc);
	_tmpHbmp = CreateCompatibleBitmap(_hdc, 3 * CLI_WIDTH, CLI_HEIGHT);

	SelectObject(_pmap->m_memDc, _tmpHbmp);

	GetObject(_pmap->m_hbmp[0], sizeof(BITMAP), &_bmp);

	for (int i = 0; i < 3; i++) {

		if (i % 2 != 0)
			_index = 1;
		else
			_index = 0;

		SelectObject(_tmpDc, _pmap->m_hbmp[_index]);

		TransparentBlt(_pmap->m_memDc,
			i * (CLI_WIDTH), 0,
			CLI_WIDTH, CLI_HEIGHT - 32,
			_tmpDc,
			0, 0, // Դλ��
			_bmp.bmWidth, _bmp.bmHeight,
			SRCCOPY);

	}

	__LoadFloor(_hdc, _pmap->m_memDc, _hins);

	ReleaseDC(_hwnd, _hdc);
	DeleteDC(_tmpDc);
	DeleteObject(_tmpHbmp);

	return OK;

}
// �༭��ͼ����MAPʵ����memDc��


STATUS
DrawMap(PMAP _pmap, PIMAGE _pimage, HWND _hwnd) {

	assert(_pmap != NULL);
	assert(_pimage != NULL);
	assert(_hwnd != NULL);

	HDC                 _hdc;
	HDC                 _tmpDc;

	_hdc     = GetDC(_hwnd);
	_tmpDc   = CreateCompatibleDC(_hdc);

	SelectObject(_pimage->m_memDc, _pimage->m_hBmp);

	SelectObject(_tmpDc, _pmap->m_hbmp);

	BitBlt(_pimage->m_memDc,
		0, 0,
		3 * CLI_WIDTH, CLI_HEIGHT,
		_pmap->m_memDc,
		0, 0,
		SRCCOPY);

	ReleaseDC(_hwnd, _hdc);
	DeleteDC(_tmpDc);

	return OK;


}
// ���ص�ͼ����mapʵ������imageʵ��


/*
+
-			��̬��������
+
*/
static STATUS
__LoadFloor(HDC _hdc, HDC _memDc, HINSTANCE _hins) {

	HBITMAP _total = LoadBitmap(_hins, MAKEINTRESOURCE(IDB_ITEMS_SHEETS));
	HDC     _tmpDc = CreateCompatibleDC(_hdc);

	SelectObject(_tmpDc, _total);

	for (int i = 0; i < 60; i++) {
		
		BitBlt(_memDc,
			i * 32, CLI_HEIGHT - 32,
			32, 32,
			_tmpDc,
			0, 0,
			SRCCOPY);

	}
	return OK;

}
// ��ͼ���ص�ש