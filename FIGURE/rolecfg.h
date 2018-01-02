/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2017.12.27 / 15��21
+
-             �޸�ʱ�䣺2017.12.28 / 14��08
+
-             �ļ����ƣ�rolecfg.h
+
-             ģ�飺role.configģ�飬������Ϸ��ɫ�Ŀ���ģ�飬������ɫ�Ŀ��ƣ����ƣ�״̬��
+
-             ���ܣ�role.configģ��ͷ�ļ��������ṹ�嶨�壬ͷ�ļ�����������ǰ���������궨��
+
*/
#ifndef __ROLE_CFG_H__
#define __ROLE_CFG_H__

#ifdef __cplusplus
extern "C" {
#endif


/* 
+
-			����ͷ�ļ�
+
*/
#include "../SYS/systc.h"
#include "../IMAGE/image.h"
#include "../EFFECT/effect.h"
#include "./INFO/roleifo.h"
#include "./BULLET/bullet.h"

/*
+
-			�ṹ�嶨��
+
*/
typedef struct {

	HBITMAP m_hbmp_forward;   // ��ɫ��ͼ����ǰ��ʱ��
	HBITMAP m_hbmp_backward;  // ��ɫ��ͼ�������ʱ��
	SHORT   m_status;         // ��ɫ�ƶ�״̬��0��1��2�ֱ�������ߣ����£�������
	SHORT   m_index;          // ���ڽ�ɫ�ƶ�״̬�£��ü�����ͼ��(0��1��2����״̬)
	SHORT   m_speed;          // ��ɫ�ƶ��ٶ�
	SHORT   m_keyDownCnt;     // ���������������ı��ɫ��ͼ��
	SHORT   m_maxHeight;      // ��ɫ�����Ծ�߶�
	SHORT   m_curHeight;      // ��ɫ��ǰ��Ծ�߶�
	BOOL    m_mvDirection;    // ��ɫ�ƶ�����TRUEΪ��ǰ��FALSEΪ���
	BOOL    m_highStatus;     // ��Ծ���Ƿ�ﵽ���߶�
	BOOL    m_moveStatus;     // ��ɫ�Ƿ��������ƶ�״̬
	BOOL    m_fmapRefresh;    // ��ɫ�Ƿ�ﵽ��ͼˢ�µ�(ǰ��)
	BOOL    m_bmapRefresh;    // ��ɫ�Ƿ�ﵽ��ͼˢ�µ�(��)
	BOOL    m_fmapEnd;        // ��ͼ�Ƿ�ﵽ��ͷ(ǰ��)
	BOOL    m_bmapEnd;        // ��ͼ�Ƿ�ﵽ��ͷ(��)
	SIZE    m_size;           // ��ɫ��С
	POINT   m_pos;            // ��ɫ��������ͼ��λ��
	POINT   m_clientPos;      // ��ɫ�ڿͻ���������

	PROLEIFO m_roleifo;       // ��ɫ��Ϸ����Ϣ���������ȼ�����ɫ����Ǯ�������ȵȣ�
	PBULLETS m_pbullets;      // �ӵ�����

}ROLE_CONFIG, * PROLECFG;

/*
+
-			����ǰ������
+
*/

PROLECFG
InitRole(HINSTANCE);
// ��ʼ��ROLE�ṹ��ʵ��

STATUS
FreeRole(PROLECFG);
// �ͷ�ROLEʵ����Դ

STATUS
DrawRole(const HWND, const PROLECFG, PIMAGE);
// ������ɫ����ɫ��������ɫ�����Ч

STATUS
ControlRole(PROLECFG, WPARAM, HWND);
// ��ɫ���ƣ��ƶ���Ծ

STATUS
UnControlRole(PROLECFG, WPARAM, HWND);
// ����̧�𣬽�ɫ���ܿ���ʱ��״̬

STATUS
RoleTimerProc(PROLECFG, HWND);
// ��ɫ��صļ�ʱ�����̺�����������Ծ���ӵ���






#ifdef __cplusplus
}
#endif

#endif // __ROLE_CFG_H__ //
