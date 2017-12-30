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
LoadWeapon(HINSTANCE _hins, WEAPON_TYPE _type) {

	PWEAPON _pweapon = (PWEAPON)malloc(sizeof(WEAPON));
	if (!_pweapon)
		exit(OVERFLOW);

	_pweapon->m_weaponHbmp_forward  = LoadBitmap(_hins, MAKEINTRESOURCE(_type));
	_pweapon->m_weaponHbmp_backward = LoadBitmap(_hins, MAKEINTRESOURCE(_type + 1));

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
DrawWeapon(PWEAPON _pweapon, HDC _hdc, HDC _memDc,
	POINT _rolePos, BOOL _mvDirection) {

	assert(_pweapon != NULL);
	assert(_hdc != NULL);
	assert(_memDc != NULL);

	HDC            _tmpDc;
	BITMAP         _bmp;
	POINT          _weaponPos;

	_tmpDc = CreateCompatibleDC(_hdc);

	if (_mvDirection) {

		_weaponPos.x = _rolePos.x + FORWARD_WEAPON_X_OFFSET;
		_weaponPos.y = _rolePos.y + FORWARD_WEAPON_Y_OFFSET;

		SelectObject(_tmpDc, _pweapon->m_weaponHbmp_forward);

	}
	else {

		_weaponPos.x = _rolePos.x + BACKWARD_WEAPON_X_OFFSET;
		_weaponPos.y = _rolePos.y + BACKWARD_WEAPON_Y_OFFSER;

		SelectObject(_tmpDc, _pweapon->m_weaponHbmp_backward);

	}

	GetObject(_pweapon->m_weaponHbmp_forward, sizeof(BITMAP), &_bmp);

	TransparentBlt(_memDc,
		_weaponPos.x, _weaponPos.y,
		_bmp.bmWidth, _bmp.bmHeight,
		_tmpDc,
		0, 0,
		_bmp.bmWidth, _bmp.bmHeight,
		RGB(255, 255, 255));

	DeleteDC(_tmpDc);

	return OK;

}
// ���ݽ�ɫ����λ�û�������
