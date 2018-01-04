/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2017.12.27 / 22��33
+
-             �޸�ʱ�䣺2018.01.04 / 12��21
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
		exit(OVERFLOWED);

	HDC _hdc = GetDC(_hwnd);

	_pimage->m_memDc        = CreateCompatibleDC(_hdc);
	_pimage->m_hBmp         = CreateCompatibleBitmap(_hdc, 3 * CLI_WIDTH, CLI_HEIGHT);
	_pimage->m_drawLocation = 0;

	SelectObject(_pimage->m_memDc, _pimage->m_hBmp);

	ReleaseDC(_hwnd, _hdc);

	return _pimage;

}
// ��ʼ��IMAGEʵ��


STATUS
FreeImage(PIMAGE _pimage) {

	assert(_pimage != NULL);

	DeleteObject(_pimage->m_hBmp);
	DeleteDC(_pimage->m_memDc);

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
		_pimage->m_drawLocation, 0,
		SRCCOPY);

	ReleaseDC(_hwnd, _hdc);

	return OK;

}
// ����IMAGEʵ���б����ͼ��


inline int
RotateDc(HDC _hdc, int _iAngle, POINT _centerPt) {

	assert(_hdc != NULL);

	int _nGraphicsMode = SetGraphicsMode(_hdc, GM_ADVANCED);
	
	XFORM _xfrom;

	if (_iAngle != 0) {

		double _fangle = (double)_iAngle / 180 * 3.1415926;

		_xfrom.eM11 = (float)cos(_fangle);
		_xfrom.eM12 = (float)sin(_fangle);
		_xfrom.eM21 = (float)-sin(_fangle);
		_xfrom.eM22 = (float)cos(_fangle);
		_xfrom.eDx  = (float)(_centerPt.x - cos(_fangle) * _centerPt.x
								+ sin(_fangle) * _centerPt.y);
		_xfrom.eDy  = (float)(_centerPt.y - cos(_fangle) * _centerPt.y
								- sin(_fangle) * _centerPt.x);

		SetWorldTransform(_hdc, &_xfrom);

	}

	return _nGraphicsMode;

}
// ��תHDC��ʹ��HDC���ͼ����ת


inline STATUS
RestoreRotateDc(HDC _hdc, int _nGraphicsMode) {

	assert(_hdc != NULL);

	XFORM _xform;

	_xform.eM11 = (float)1.0;
	_xform.eM12 = (float)0;
	_xform.eM21 = (float)0;
	_xform.eM22 = (float)1.0;
	_xform.eDx  = (float)0;
	_xform.eDy  = (float)0;

	SetWorldTransform(_hdc, &_xform);
	SetGraphicsMode(_hdc, _nGraphicsMode);

	return OK;

}
// �ָ���ת���HDC
