/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2017.12.27 / 15��21
+
-             �޸�ʱ�䣺2017.12.27 / 15��21
+
-             �ļ����ƣ�roleifo.h
+
-             ģ�飺roleģ�飬������Ϸ��ɫ��ģ�飬������ɫ�Ŀ��ƣ����ƣ�״̬��
+
-             ���ܣ�roleģ��ͷ�ļ��������ṹ�嶨�壬ͷ�ļ�����������ǰ���������궨��
+
*/
#ifndef __ROLE_IFO_H__
#define __ROLE_IFO_H__

#ifdef __cplusplus
extern "C" {
#endif


/* 
+
-			����ͷ�ļ�
+
*/
#include "../SYS/systc.h"

/*
+
-			�ṹ�嶨��
+
*/

typedef struct {

	HBITMAP m_hbmp;  // ��ɫ��ͼ��
	UINT    m_status;// ��ɫ�ƶ�״̬��0��1��2�ֱ�������ߣ����������£�
	UINT    m_index; // ���ڽ�ɫ�ƶ�״̬�£��ü�����ͼ��(0��1��2����״̬)
	UINT    m_speed; // ��ɫ�ƶ��ٶ�
	SIZE    m_size;  // ��ɫ��С
	POINT   m_pos;   // ��ɫλ��

}ROLE, * PROLE;

/*
+
-			����ǰ������
+
*/

PROLE
InitRole(HINSTANCE);
// ��ʼ��ROLE�ṹ��ʵ��

STATUS
FreeRole(PROLE);
// �ͷ�ROLEʵ����Դ

STATUS
DrawRole(const HWND, const PROLE);
// ������ɫ

STATUS
ControlRole(PROLE, WPARAM);

STATUS
MoveRole(PROLE, WPARAM);
// ��ɫ�ƶ�

#ifdef __cplusplus
}
#endif

#endif // __ROLE_IFO_H__ //
