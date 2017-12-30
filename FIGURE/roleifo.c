/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2017.12.27 / 15��21
+
-             �޸�ʱ�䣺2017.12.30 / 14��48
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
-			��̬����ǰ������
+
*/

/*---------------------------------------------------------------------*/
// ���������ҿ��ƽ�ɫ�ƶ���ؾ�̬����

static STATUS
__moveRole(PROLE, WPARAM, HWND);
// �������ƽ�ɫ�ƶ�,��Ծ

static STATUS
__moveRole_left(PROLE);
// ���·����������ƶ�

static STATUS
__moveRole_right(PROLE);
// ���·�����ң���ǰ�ƶ�

static STATUS
__moveRole_up(PROLE);
// ���·�����ϣ��ı��ɫ�ƶ�״̬Ϊ��Ծ����ʱ����ʼ����RoleJumpProc


/*---------------------------------------------------------------------*/
// ��ɫ��Ծ��ؾ�̬����

static STATUS
__jumpRole(PROLE);
// ��ɫ��Ծ��ʼ

static STATUS
__highRole(PROLE);
// ��ɫ��Ծ������ߴ���״̬

static STATUS
__fallRole(PROLE);
// �жϽ�ɫ��Ծ���

static STATUS
__moveInertia(PROLE);
// �����ɫ��Ծ֮ǰ���������ƶ�״̬�������ǰ�Ĺ����ƶ�


/*---------------------------------------------------------------------*/
// ����̧����ؾ�̬����

static STATUS
__roleMvStatusChange(PROLE, WPARAM, HWND);
// ����̧��ʱ���ı��ɫ���ƶ�״̬


/*---------------------------------------------------------------------*/
// ǰ��/����ʱ����ͼˢ����ؾ�̬����

static STATUS
__mapBoundaryDetermine_Image(PROLE, PIMAGE);
// ��ͼ�߽��ж�����Ҫ�޸�IMAGEģ���m_DrawLocation����
// DrawLoaction�������ڿͻ���������ͼ����ʼλ�ã��Ӷ��ﵽ��ͼˢ�µ�Ч��
// �Լ�ͨ���ж�DrawLocation�������޸�PROLEʵ����m_f(b)mapEndֵ
// ��m_f(b)mapEnd���Ը���ȷ����ɫ�Ŀͻ�������m_clientPos
// ��ɫ�ͻ����������ͼˢ���������
// ��ɫ�ͻ���������__moveRoleʱȷ��






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

	_prole->m_hbmp        = LoadBitmap(_hins, MAKEINTRESOURCE(IDB_REAL_ROLE_BAN));
	_prole->m_status      = 0;
	_prole->m_index       = 0;
	_prole->m_speed       = 5;
	_prole->m_keyDownCnt  = 0;
	_prole->m_maxHeight   = 15;
	_prole->m_curHeight   = 0;
	_prole->m_highStatus  = FALSE;
	_prole->m_moveStatus  = FALSE;
	_prole->m_mvDirection = TRUE;
	_prole->m_fmapRefresh = FALSE;
	_prole->m_bmapRefresh = FALSE;
	_prole->m_fmapEnd     = FALSE;
	_prole->m_bmapEnd     = TRUE;
	
	GetObject(_prole->m_hbmp, sizeof(BITMAP), &_bmp);
	_prole->m_size.cx = (_bmp.bmWidth) / 3;
	_prole->m_size.cy = _bmp.bmHeight / 3;

	_prole->m_pos.x = 0;
	_prole->m_pos.y = CLI_HEIGHT - _prole->m_size.cy - 30;

	_prole->m_clientPos.x = 0;
	_prole->m_clientPos.y = CLI_HEIGHT - _prole->m_size.cy;

	_prole->m_weapon = InitWeapon(_hins, WEAPON_9MM);

	return _prole;

}
// ��ʼ��ROLE�ṹ��ʵ��


STATUS
FreeRole(PROLE _prole) {

	assert(_prole != NULL);

	FreeWeapon(_prole->m_weapon);

	free(_prole);

	return OK;

}
// �ͷ�ROLEʵ����Դ


STATUS
DrawRole(const HWND _hwnd, const PROLE _prole, PIMAGE _pimage) {

	assert(_hwnd != NULL);
	assert(_prole != NULL);
	assert(_pimage != NULL);

	HDC               _hdc;
	HDC               _tmpDc;

	/*------------------------------------------------------------------------------*/

	// ��ͼˢ�¹��� //
	__mapBoundaryDetermine_Image(_prole, _pimage);

	/*------------------------------------------------------------------------------*/


	_hdc = GetDC(_hwnd);

	_tmpDc = CreateCompatibleDC(_hdc);

	SelectObject(_pimage->m_memDc, _pimage->m_hBmp);

	SelectObject(_tmpDc, _prole->m_hbmp);

	TransparentBlt(_pimage->m_memDc,
		_prole->m_pos.x, _prole->m_pos.y,
		_prole->m_size.cx, _prole->m_size.cy,
		_tmpDc,
		(_prole->m_size.cx)*(_prole->m_index),	// ����ü�
		(_prole->m_size.cy)*(_prole->m_status), // ����ü�
		_prole->m_size.cx, _prole->m_size.cy,
		RGB(255, 255, 255));

	/*------------------------------------------------------------------------------*/

	// ��������
	DrawWeapon(_prole->m_weapon, _hdc, _pimage->m_memDc, _prole->m_pos);

	// ������Ч
	// DrawEffect(_hdc, _pimage->m_memDc, _prole->m_pos, 1);

	/*------------------------------------------------------------------------------*/

	ReleaseDC(_hwnd, _hdc);
	DeleteDC(_tmpDc);

	return OK;

}
// ������ɫ


STATUS
ControlRole(PROLE _prole, WPARAM _wParam, HWND _hwnd) {

	assert(_prole != NULL);
	assert(_hwnd != NULL);

	if(_prole->m_highStatus == 0)
		_prole->m_keyDownCnt++;

	__moveRole(_prole, _wParam, _hwnd);

	return OK;

}
// ��ɫ���ƣ��ƶ���Ծ


STATUS
UnControlRole(PROLE _prole, WPARAM _wParam, HWND _hwnd) {

	assert(_prole != NULL);

	__roleMvStatusChange(_prole, _wParam, _hwnd);

	return OK;

}
// ����̧�𣬽�ɫ���ܿ���ʱ��״̬


STATUS
RoleJumpProc(PROLE _prole, HWND _hwnd) {

	assert(_prole != NULL);
	assert(_hwnd != NULL);

	if (_prole->m_status == 0)
		return OK;

	__moveInertia(_prole);

	// ��Ծ��û�дﵽ���߶�
	if (!(_prole->m_highStatus) && _prole->m_status == 2) {

		__jumpRole(_prole);

	}
	if (_prole->m_curHeight == _prole->m_maxHeight && _prole->m_status == 2) {

		__highRole(_prole);

	}
	else if (_prole->m_highStatus) {

		__fallRole(_prole);

	}

	InvalidateRect(_hwnd, NULL, TRUE);

	return OK;

}
// ��ɫ��Ծ���̣��˺�����Timer��ʱ������






/*
+
-			��̬��������
+
*/

/*---------------------------------------------------------------------*/
// ���������ҿ��ƽ�ɫ�ƶ���ؾ�̬����

static STATUS
__moveRole(PROLE _prole, WPARAM _wParam, HWND _hwnd) {

	assert(_prole != NULL);

	switch (_wParam) {

	case VK_LEFT: // ��Ϊ�����

		__moveRole_left(_prole);

		break;

	case VK_RIGHT: // ��Ϊ��ǰ��

		__moveRole_right(_prole);

		break;

	case VK_UP: // ��Ծ

		__moveRole_up(_prole);

		break;

	}

	// ��ɫ���߶���Ч��
	if (_prole->m_keyDownCnt >= 5 && _prole->m_status == 0) {

		_prole->m_index++;
		_prole->m_keyDownCnt = 0;

	}
	if (_prole->m_index == 3) {

		_prole->m_index = 0;

	}

	InvalidateRect(_hwnd, NULL, TRUE);

	return OK;

}
// �������ƽ�ɫ�ƶ�,��Ծ

static STATUS
__moveRole_left(PROLE _prole) {

	assert(_prole != NULL);

	// ��ɫ����Ծ״̬���������Ч
	if (_prole->m_status != 0)
		return OK;

	// �����ɫ���ƶ�״̬��ΪTRUE���ڰ��°������ΪTRUE
	if (!(_prole->m_moveStatus))
		_prole->m_moveStatus = TRUE;

	// �����ɫ�ƶ�����Ϊ��ǰ�����������ı�Ϊ���
	if (_prole->m_mvDirection)
		_prole->m_mvDirection = FALSE;

	// �����ɫ����ߣ����Ҵﵽ��ǰ����ͼˢ�µ㣬��ת����ΪFALSE
	if (_prole->m_fmapRefresh)
		_prole->m_fmapRefresh = FALSE;

	// ������ͼˢ�µ������
	if (_prole->m_clientPos.x <= CLI_WIDTH / 4) {

		_prole->m_bmapRefresh = TRUE;

	}

	if (_prole->m_pos.x > 0) {

		_prole->m_pos.x -= _prole->m_speed;

		// �����ɫû�����ͼˢ�µ㣬���ߵ�ͼ����󷽾�ͷ������m_clientPos.x > 0
		// ��ʱ�Ÿı��ɫ�Ŀͻ�������
		if (!(_prole->m_bmapRefresh)
			|| (_prole->m_clientPos.x > 0 && _prole->m_bmapEnd))
			_prole->m_clientPos.x -= _prole->m_speed;

	}

	return OK;

}
// ���·����������ƶ�

static STATUS
__moveRole_right(PROLE _prole) {

	assert(_prole != NULL);

	// ��ɫ����Ծ״̬���������Ч
	if (_prole->m_status != 0)
		return OK;

	// �����ɫ���ƶ�״̬��ΪTRUE���ڰ��°������ΪTRUE
	if (!(_prole->m_moveStatus))
		_prole->m_moveStatus = TRUE;

	// �����ɫ�ƶ�����Ϊ��󣬰��������ı�Ϊ��ǰ
	if (!(_prole->m_mvDirection))
		_prole->m_mvDirection = TRUE;

	// �����ɫ��ǰ�ߣ����Ҵﵽ�˺󷽵�ͼˢ�µ㣬��ת����ΪFALSE
	if (_prole->m_bmapRefresh)
		_prole->m_bmapRefresh = FALSE;

	// ����ǰ��ͼˢ�µ������
	if (_prole->m_clientPos.x >= CLI_WIDTH / 3 * 2) {

		_prole->m_fmapRefresh = TRUE;

	}

	if (_prole->m_pos.x <= 3 * CLI_WIDTH - _prole->m_size.cx) {

		_prole->m_pos.x += _prole->m_speed;

		// �����ɫû�����ͼˢ�µ㣬���ߵ�ͼ����ǰ������ͷ������m_clientPos.x < CLI_WIDTH
		// ��ʱ�Ÿı��ɫ�Ŀͻ�������
		if (!(_prole->m_fmapRefresh)
			|| (_prole->m_clientPos.x < CLI_WIDTH && _prole->m_fmapEnd))
			_prole->m_clientPos.x += _prole->m_speed;

	}

	return OK;

}
// ���·�����ң���ǰ�ƶ�

static STATUS
__moveRole_up(PROLE _prole) {

	assert(_prole != NULL);

	if (_prole->m_status != 1) {

		_prole->m_status = 2; // �л���ɫΪ����״̬
		_prole->m_index = 0;

	}

	return OK;

}
// ���·�����ϣ��ı��ɫ�ƶ�״̬Ϊ��Ծ����ʱ����ʼ����RoleJumpProc


/*---------------------------------------------------------------------*/
// ��ɫ��Ծ��ؾ�̬���� 

static STATUS
__jumpRole(PROLE _prole) {

	assert(_prole != NULL);

	if (_prole->m_curHeight < 2)
		_prole->m_index = 0;
	else
		_prole->m_index = 1;

	_prole->m_pos.y -= 10;
	_prole->m_curHeight += 1;

	return OK;

}
// ��ɫ��Ծ��ʼ

static STATUS
__highRole(PROLE _prole) {

	assert(_prole != NULL);

	_prole->m_index      = 2;
	_prole->m_highStatus = TRUE;
	_prole->m_status = 1;
	
	return OK;

}
// ��ɫ��Ծ������ߴ���״̬

static STATUS
__fallRole(PROLE _prole) {

	assert(_prole != NULL);

	if (_prole->m_curHeight > 3)
		_prole->m_index = 0;
	else if (_prole->m_curHeight > 2)
		_prole->m_index = 1;
	else
		_prole->m_index = 2;

	_prole->m_pos.y += 10;
	_prole->m_curHeight -= 1;

	if (_prole->m_curHeight == 0) {

		_prole->m_status     = 0;
		_prole->m_index      = 0;
		_prole->m_highStatus = FALSE;
		_prole->m_moveStatus = FALSE;

	}

	return OK;

}
// �жϽ�ɫ��Ծ���

static STATUS
__moveInertia(PROLE _prole) {

	assert(_prole != NULL);

	if (!(_prole->m_moveStatus)) {

		return OK;

	}

	if (_prole->m_mvDirection 
		&& _prole->m_pos.x <= 3 * CLI_WIDTH - _prole->m_size.cx) {

		_prole->m_pos.x += _prole->m_speed;

		// �����ɫû�����ͼˢ�µ㣬���ߵ�ͼ����ǰ������ͷ������m_clientPos.x < CLI_WIDTH
		// ��ʱ�Ÿı��ɫ�Ŀͻ�������
		if (!(_prole->m_fmapRefresh)
			|| (_prole->m_clientPos.x < CLI_WIDTH && _prole->m_fmapEnd))
			_prole->m_clientPos.x += _prole->m_speed;

	}	
	else if (!(_prole->m_mvDirection)
		&& _prole->m_pos.x > 0) {

		_prole->m_pos.x -= _prole->m_speed;

		// �����ɫû�����ͼˢ�µ㣬���ߵ�ͼ����󷽾�ͷ������m_clientPos.x > 0
		// ��ʱ�Ÿı��ɫ�Ŀͻ�������
		if (!(_prole->m_bmapRefresh)
			|| (_prole->m_clientPos.x > 0 && _prole->m_bmapEnd))
			_prole->m_clientPos.x -= _prole->m_speed;
	}
		

	return OK;

}
// �����ɫ��Ծ֮ǰ���������ƶ�״̬�������ǰ�Ĺ����ƶ�


/*---------------------------------------------------------------------*/
// ����̧����ؾ�̬����

static STATUS
__roleMvStatusChange(PROLE _prole, WPARAM _wparam, HWND _hwnd) {

	assert(_prole != NULL);

	if (_prole->m_status != 0)
		return OK;

	switch (_wparam) {

	case VK_LEFT:

		// �˴�û�� break;

	case VK_RIGHT:

		_prole->m_moveStatus = FALSE;
		_prole->m_index      = 0; // ����̧��ʱ���ı�����ͼ��Ϊ0

		InvalidateRect(_hwnd, NULL, TRUE);

		break;

	}

	return OK;

}
// ����̧��ʱ���ı��ɫ���ƶ�״̬


/*---------------------------------------------------------------------*/
// ǰ��/����ʱ����ͼˢ����ؾ�̬����

static STATUS
__mapBoundaryDetermine_Image(PROLE _prole, PIMAGE _pimage) {

	assert(_prole != NULL);
	assert(_pimage != NULL);

	// �����ɫ�����˵�ͼˢ�´�������û��Խ�����_pimage��m_drawLocation����
	// ��ͼλ����ǰ�ƶ�
	if (_prole->m_fmapRefresh && _pimage->m_drawLocation < 2 * CLI_WIDTH
		&& _prole->m_moveStatus)
		_pimage->m_drawLocation += _prole->m_speed;
	if (_prole->m_bmapRefresh && _pimage->m_drawLocation > 0
		&& _prole->m_moveStatus)
		_pimage->m_drawLocation -= _prole->m_speed;


	// �����ͼ�ﵽǰ���߽磬m_fmapEnd = TRUE
	if (_pimage->m_drawLocation == 2 * CLI_WIDTH)
		_prole->m_fmapEnd = TRUE;
	else
		_prole->m_fmapEnd = FALSE;

	// �����ͼ�ﵽ�󷽱߽磬m_bmapEnd = TRUE
	if (_pimage->m_drawLocation == 0)
		_prole->m_bmapEnd = TRUE;
	else
		_prole->m_bmapEnd = FALSE;

	return OK;

}
// ��ͼ�߽��ж�����Ҫ�޸�IMAGEģ���m_DrawLocation����
// DrawLoaction�������ڿͻ���������ͼ����ʼλ�ã��Ӷ��ﵽ��ͼˢ�µ�Ч��
// �Լ�ͨ���ж�DrawLocation�������޸�PROLEʵ����m_f(b)mapEndֵ
// ��m_f(b)mapEnd���Ը���ȷ����ɫ�Ŀͻ�������m_clientPos
// ��ɫ�ͻ����������ͼˢ���������
// ��ɫ�ͻ���������__moveRoleʱȷ��
