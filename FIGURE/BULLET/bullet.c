/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2018.1.2 / 20��41
+
-             �޸�ʱ�䣺2018.1.5 / 12��20
+
-             �ļ����ƣ�bullet.c
+
-             ģ�飺�ӵ�ģ�飬�ӵ��������棬�ӵ���ع���
+
-             ���ܣ��ӵ�ģ��Դ�ļ���������������
+
*/

#include "bullet.h"

/*
+
-			��̬����ǰ������
+
*/
static PBULLET
__createBullet(POINT, BOOL);
// ��̬����������һ���ӵ����


static BOOL
__emptyBullets(const PBULLETS);
// �ж��ӵ������Ƿ�Ϊ��


static STATUS
__changeBullets_Pos_Distance(PBULLETS);
// �ı��ӵ���λ�ã����о���


static PBULLET
__checkBulletsPos(const PBULLETS);
// ����ӵ�λ�ã���������Ѿ��ﵽ�����о�����ӵ����򷵻�����ӵ�����λ��


static STATUS
__freeBullet(PBULLETS, PBULLET);
// ��̬�������ͷŴ˵�ַ���ӵ������ڴ���Դ


static HDC
__loadBulletImage(HDC);
// �����ӵ���ͼƬ������HDC�У������䷵��


static STATUS
__drawBullet(HDC, HDC, POINT);
// ���������ӵ�






/*
+
-			��������
+
*/

PBULLETS
InitBulletslk() {

	PBULLETS _pbullets = (PBULLETS)malloc(sizeof(BULLETS));
	if (!_pbullets)
		exit(OVERFLOWED);

	_pbullets->m_head        = NULL;
	_pbullets->m_tail        = NULL;
	_pbullets->m_cnt         = 0;
	_pbullets->m_maxDistance = CLI_WIDTH;
	_pbullets->m_speed       = BULLET_SPEED;

	return _pbullets;

}
// ��ʼ���ӵ�����


STATUS
FreeBulletslk(PBULLETS _pbullets) {

	assert(_pbullets != NULL);

	PBULLET _pre = NULL;
	PBULLET _cur = NULL;

	if (!__emptyBullets(_pbullets)) {

		_cur = _pbullets->m_head;

		while (_cur != NULL) {

			_pre = _cur->m_next;
			__freeBullet(_pbullets, _cur);
			_cur = _pre;

		}

	}

	free(_pbullets);
	_pbullets = NULL;

	return OK;

}
// �ͷ��ӵ������Լ������ӵ������ڴ���Դ


STATUS
AddBullet(PBULLETS _pbullets, POINT _pos, BOOL _direction) {

	assert(_pbullets != NULL);

	POINT   _initialPos;

	// �ӵ���ʼλ�ã�����ɫλ�ü���ǹ��λ��ƫ�� //
	if (_direction) {

		_initialPos.x = _pos.x + BULLET_FORWARD_INITIAL_POS_OFFSET_X;
		_initialPos.y = _pos.y + BULLET_FORWARD_INITIAL_POS_OFFSET_Y;

	}
	else {

		_initialPos.x = _pos.x + BULLET_BACKWARD_INITIAL_POS_OFFSET_X;
		_initialPos.y = _pos.y + BULLET_BACKWARD_INITIAL_POS_OFFSET_Y;

	}


	PBULLET _newBullet = __createBullet(_initialPos, _direction);

	if (__emptyBullets(_pbullets)) {

		_pbullets->m_head = _newBullet;
		_pbullets->m_tail = _newBullet;

		goto ending;

	}
	else {

		_pbullets->m_tail->m_next = _newBullet;
		_newBullet->m_pre         = _pbullets->m_tail;
		_pbullets->m_tail         = _newBullet;

		goto ending;

	}

ending:
	_pbullets->m_cnt++;

	return OK;

}
// ���ӵ����������һ���ӵ�


STATUS
DrawBullets(const PBULLETS _pbullets, HDC _hdc, HDC _memDc) {

	assert(_pbullets != NULL);
	assert(_hdc != NULL);
	assert(_memDc != NULL);

	if (__emptyBullets(_pbullets))
		return OK;

	int     _result;
	int     _flag = 0;

	HDC     _tmpDc = __loadBulletImage(_hdc);
	
	PBULLET _tmp   = _pbullets->m_head;

	POINT   _centerPt;
	_centerPt.x = 20 / 2;
	_centerPt.y = 8 / 2;

	while (_tmp != NULL) {

		if (!_tmp->m_bltMvDirction) {

			_result = RotateDc(_hdc, 180, _centerPt);
			_flag   = 1;

		}

		__drawBullet(_tmpDc, _memDc, _tmp->m_pos);

		if (_flag) {

			RestoreRotateDc(_hdc, _result);
			_flag = 0;

		}

		_tmp = _tmp->m_next;

	}

	DeleteDC(_tmpDc);
	
	return OK;

}
// �����ӵ������е��ӵ�


STATUS
BulletsTimerProc(PBULLETS _pbullets, HWND _hwnd) {

	assert(_pbullets != NULL);

	if (__emptyBullets(_pbullets))
		return OK;

	PBULLET _rec = NULL;

	// �ı��ӵ���λ�ã����о��� //
	__changeBullets_Pos_Distance(_pbullets);

	// ����ӵ�λ�� //
	_rec = __checkBulletsPos(_pbullets);

	// ���_rec!=NULL �ͷŸý���ڴ���Դ //
	if (_rec != NULL) {

		__freeBullet(_pbullets, _rec);

	}

	// �����Ļ���ػ棬�ﵽ����Ч�� //
	InvalidateRect(_hwnd, NULL, TRUE);

	return OK;

}
// �����ӵ��ļ�ʱ�����̺��������������ӵ�λ��ˢ�£�λ���ж��ȣ�





/*
+
-			��̬��������
+
*/

static PBULLET
__createBullet(POINT _pos, BOOL _direction) {

	PBULLET _pbullet = (PBULLET)malloc(sizeof(NODE));
	if (!_pbullet)
		exit(OVERFLOWED);

	_pbullet->m_pos           = _pos;
	_pbullet->m_dstance       = 0;
	_pbullet->m_bltMvDirction = _direction;
	_pbullet->m_next          = NULL;
	_pbullet->m_pre           = NULL;

	return _pbullet;

}
// ��̬����������һ���ӵ����


static BOOL
__emptyBullets(const PBULLETS _pbullets) {

	assert(_pbullets != NULL);

	if (_pbullets->m_cnt == 0)
		return TRUE;

	return FALSE;

}
// �ж��ӵ������Ƿ�Ϊ��


static STATUS
__changeBullets_Pos_Distance(PBULLETS _pbullets) {

	assert(_pbullets != NULL);

	if (__emptyBullets(_pbullets))
		return OK;

	PBULLET _tmp = _pbullets->m_head;

	while (_tmp != NULL) {

		if(_tmp->m_bltMvDirction)
			_tmp->m_pos.x += _pbullets->m_speed;
		else
			_tmp->m_pos.x -= _pbullets->m_speed;

		_tmp->m_dstance += _pbullets->m_speed;
		_tmp = _tmp->m_next;

	}

	return OK;

}
// �ı��ӵ���λ�ã����о���


static PBULLET
__checkBulletsPos(const PBULLETS _pbullets) {

	assert(_pbullets != NULL);

	if (__emptyBullets(_pbullets))
		return NULL;

	PBULLET _tmp = _pbullets->m_head;

	while (_tmp != NULL) {

		if (_tmp->m_dstance >= _pbullets->m_maxDistance)
			return _tmp;

		_tmp = _tmp->m_next;

	}

	return NULL;

}
// ����ӵ�λ�ã���������Ѿ��ﵽ�����о�����ӵ����򷵻�����ӵ�����λ��


static STATUS
__freeBullet(PBULLETS _pbullets, PBULLET _pbullet) {

	assert(_pbullets != NULL);
	assert(_pbullet != NULL);

	if (_pbullets->m_head == _pbullets->m_tail) {

		free(_pbullet);
		_pbullet = NULL;

		_pbullets->m_head = NULL;
		_pbullets->m_tail = NULL;

		goto ending;

	}
	else if (_pbullets->m_head == _pbullet) {

		_pbullets->m_head = _pbullet->m_next;

		free(_pbullet);
		_pbullet = NULL;

		goto ending;

	}

ending:
	_pbullets->m_cnt--;

	return OK;

}
// ��̬�������ͷŴ˵�ַ���ӵ������ڴ���Դ


static HDC
__loadBulletImage(HDC _hdc) {

	assert(_hdc != NULL);

	HDC       _memDc   = CreateCompatibleDC(_hdc);
	HBITMAP   _tmpHbmp = CreateCompatibleBitmap(_hdc,
												(EFF_SIZE + 7)->cx, (EFF_SIZE + 7)->cy);

	SelectObject(_memDc, _tmpHbmp);

	POINT  _pos;
	_pos.x = 0;
	_pos.y = 0;

	DrawEffect(_hdc, _memDc, _pos, 7);

	DeleteObject(_tmpHbmp);

	return _memDc;

}
// �����ӵ���ͼƬ������HDC�У������䷵��


static STATUS
__drawBullet(HDC _tmpDc, HDC _memDc, POINT _pos) {

	assert(_tmpDc != NULL);
	assert(_memDc != NULL);

	TransparentBlt(_memDc,
		_pos.x, _pos.y,
		(EFF_SIZE + 7)->cx, (EFF_SIZE + 7)->cy,
		_tmpDc,
		0, 0,
		(EFF_SIZE + 7)->cx, (EFF_SIZE + 7)->cy,
		RGB(0, 0, 0));

	return OK;

}
// ���������ӵ�