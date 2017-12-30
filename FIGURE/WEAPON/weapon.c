/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2017.12.28 / 22��26
+
-             �޸�ʱ�䣺2017.12.30 / 14��45
+
-             �ļ����ƣ�weapon.c
+
-             ģ�飺����ģ�飬������ع��ܣ���Ϣ
+
-             ���ܣ�����ģ��ͷ�ļ���������������
+
*/

#include "weapon.h"

PWEAPON
InitWeapon(HINSTANCE _hins, WEAPON_TYPE _type) {

	PWEAPON _pweapon = (PWEAPON)malloc(sizeof(WEAPON));
	if (!_pweapon)
		exit(OVERFLOW);

	_pweapon->m_weaponHbmp = LoadBitmap(_hins, MAKEINTRESOURCE(_type));

	return _pweapon;

}
// ��ʼ��WEAPONʵ��


STATUS
FreeWeapon(PWEAPON _pweapon) {

	assert(_pweapon != NULL);

	free(_pweapon);
	_pweapon = NULL;

	return OK;

}
// �ͷ������ڴ���Դ


STATUS
DrawWeapon(PWEAPON _pweapon, HDC _hdc, HDC _memDc, POINT _rolePos) {

	assert(_pweapon != NULL);
	assert(_hdc != NULL);
	assert(_memDc != NULL);

	HDC            _tmpDc;
	BITMAP         _bmp;

	_tmpDc = CreateCompatibleDC(_hdc);
	GetObject(_pweapon->m_weaponHbmp, sizeof(BITMAP), &_bmp);

	SelectObject(_tmpDc, _pweapon->m_weaponHbmp);

	TransparentBlt(_memDc,
		_rolePos.x + 10, _rolePos.y + 7,
		_bmp.bmWidth, _bmp.bmHeight,
		_tmpDc,
		0, 0,
		_bmp.bmWidth, _bmp.bmHeight,
		RGB(255, 255, 255));

	DeleteDC(_tmpDc);

	return OK;

}
// ���ݽ�ɫ����λ�û�������
