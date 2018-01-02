/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2018.1.2 / 20��41
+
-             �޸�ʱ�䣺2018.1.2 / 20��41
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
CreateBullet(POINT);
// ��̬����������һ���ӵ����


static BOOL
EmptyBullets(const PBULLETS);
// �ж��ӵ������Ƿ�Ϊ��

/*
+
-			��������
+
*/

PBULLETS
InitBulletslk() {

	PBULLETS _pbullets = (PBULLETS)malloc(sizeof(BULLETS));
	if (!_pbullets)
		exit(OVERFLOW);

	_pbullets->m_head        = NULL;
	_pbullets->m_tail        = NULL;
	_pbullets->m_cnt         = 0;
	_pbullets->m_maxDistance = CLI_WIDTH;
	_pbullets->m_speed       = BULLET_SPEED;

	return _pbullets;

}
// ��ʼ���ӵ�����


STATUS
AddBullet(PBULLETS _pbullets, POINT _pos) {

	assert(_pbullets != NULL);

	PBULLET _newBullet = CreateBullet(_pos);

	if (EmptyBullets(_pbullets)) {

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

	PBULLET _tmp   = _pbullets->m_head;

	if (EmptyBullets(_pbullets))
		return OK;

	while (_tmp != NULL) {

		DrawEffect(_hdc, _memDc, _tmp->m_pos, 7);
		_tmp = _tmp->m_next;

	}
	
	return OK;

}
// �����ӵ������е��ӵ�


STATUS
BulletsTimerProc(const PBULLETS _pbullets) {

	assert(_pbullets != NULL);

	PBULLET _tmp = _pbullets->m_head;

	while (_tmp != NULL) {

		_tmp->m_pos.x += _pbullets->m_speed;
		_tmp = _tmp->m_next;

	}

	return OK;

}
// �����ӵ��ļ�ʱ�����̺��������������ӵ�λ��ˢ�£�λ���ж��ȣ�

/*
+
-			��̬��������
+
*/

static PBULLET
CreateBullet(POINT _pos) {

	PBULLET _pbullet = (PBULLET)malloc(sizeof(NODE));
	if (!_pbullet)
		exit(OVERFLOW);

	_pbullet->m_pos     = _pos;
	_pbullet->m_dstance = 0;
	_pbullet->m_next    = NULL;
	_pbullet->m_pre     = NULL;

	return _pbullet;

}
// ��̬����������һ���ӵ����


static BOOL
EmptyBullets(const PBULLETS _pbullets) {

	assert(_pbullets != NULL);

	if (_pbullets->m_cnt == 0)
		return TRUE;

	return FALSE;

}
// �ж��ӵ������Ƿ�Ϊ��