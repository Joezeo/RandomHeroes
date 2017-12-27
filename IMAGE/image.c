/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2017.12.27 / 22��33
+
-             �޸�ʱ�䣺2017.12.27 / 22��33
+
-             �ļ����ƣ�image.c
+
-             ģ�飺imageģ�飬����ģ���ͼ���Ȼ���IMAGEʵ����memDc��,��ͨ��DrawImage����
+
-             ���ܣ�imageģ��ͷ�ļ���������������
+
*/
#include "image.h"

/*
+
-			��������
+
*/

PIMAGE
InitImage(HWND _hwnd) {

	PIMAGE _pimage = (PIMAGE)malloc(sizeof(IMAGE));
	if (!_pimage)
		exit(OVERFLOW);

	HDC _hdc = GetDC(_hwnd);

	_pimage->m_memDc = CreateCompatibleDC(_hdc);

	ReleaseDC(_hwnd, _hdc);

	return _pimage;

}
// ��ʼ��IMAGEʵ��


STATUS
FreeImage(PIMAGE _pimage) {

	assert(_pimage != NULL);

	free(_pimage);
	_pimage = NULL;

	return OK;

}
// �ͷ�PIMAGEʵ����Դ


STATUS
DrawImage(const PIMAGE _pimage, HWND _hwnd) {

	HDC                  _hdc;

	_hdc = GetDC(_hwnd);

	BitBlt(_hdc,
		0, 0,
		CLI_WIDTH, CLI_HEIGHT,
		_pimage->m_memDc,
		0, 0,
		SRCCOPY);

	ReleaseDC(_hwnd, _hdc);

	return OK;

}
// ����IMAGEʵ���б����ͼ��
