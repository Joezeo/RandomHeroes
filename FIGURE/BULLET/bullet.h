/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2018.1.2 / 20��41
+
-             �޸�ʱ�䣺2018.1.2 / 20��41
+
-             �ļ����ƣ�bullet.h
+
-             ģ�飺�ӵ�ģ�飬�ӵ����������棬�ӵ���ع���
+
-             ���ܣ��ӵ�ģ��ͷ�ļ�������ͷ�ļ��������ṹ�嶨�壬����ǰ������
+
*/

#ifndef __BULLET_H__
#define __BULLET_H__

#ifdef __cplusplus
extern "C" {
#endif


/* 
+
-			����ͷ�ļ�
+
*/
#include "../../SYS/systc.h"
#include "../../EFFECT/effect.h" // ��ALL_EFFECTS�н�ȡ�ӵ�ͼ��


/*
+
-			�궨��
+
*/
#define BULLET_SPEED 10;


/*
+
-			�ṹ�嶨��
+
*/
// �ӵ���㶨��
typedef struct NODE {

	POINT m_pos;
	UINT  m_dstance;        // �ӵ��Ѿ����еľ���

	struct NODE * m_next;
	struct NODE * m_pre;

}NODE, * PNODE, * PBULLET;

// �ӵ���������
typedef struct {

	PBULLET m_head;
	PBULLET m_tail;

	UINT    m_cnt;          // �ӵ�������ӵ�е��ӵ�����
	UINT    m_maxDistance;  // �ӵ����е�������
	UINT    m_speed;        // �ӵ����е��ٶ�

}BULLETS, * PBULLETS;

/*
+
-			����ǰ������
+
*/

PBULLETS
InitBulletslk();
// ��ʼ���ӵ�����

STATUS
AddBullet(PBULLETS, POINT);
// ���ӵ�����������һ���ӵ�

STATUS
DrawBullets(const PBULLETS, HDC, HDC);
// �����ӵ������е��ӵ�

STATUS
BulletsTimerProc(const PBULLETS);
// �����ӵ��ļ�ʱ�����̺��������������ӵ�λ��ˢ�£�λ���ж��ȣ�

#ifdef __cplusplus
}
#endif

#endif // __BULLET_H__ //