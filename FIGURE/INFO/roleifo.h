/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2017.12.30 / 17��16
+
-             �޸�ʱ�䣺2017.12.30 / 17��16
+
-             �ļ����ƣ�roleifo.h
+
-             ģ�飺role.ifoģ�飬��ɫ����Ϸ����Ϣ������������Ϣ��������Ϣ����Ǯ��Ϣ�ȵ�
+
-             ���ܣ�role.ifoģ���ͷ�ļ�������ͷ�ļ��������궨�壬�ṹ�嶨�壬����ǰ������
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
#include "../../SYS/systc.h"
#include "../WEAPON/weapon.h"

extern HINSTANCE                 g_hinst;

/*
+
-			�궨��
+
*/
// ��ʱ�ó��������ɫ��Ϸ�Ե���Ϣ��֮���Ϊ���ر���
#define ROLE_INFO LoadRoleInfo()


/*
+
-			�ṹ�嶨��
+
*/
typedef struct {

	WEAPON_TYPE m_weaponType; // ��ɫ��������
	PWEAPON     m_weapon;     // ��ɫ������ͼƬ��Ϣ
	
}ROLE_INFORMATON, * PROLEIFO;

/*
+
-			����ǰ������
+
*/
PROLEIFO
LoadRoleInfo();
// ��ʼ����ɫ����Ϣ

STATUS
FreeRoleInfo(PROLEIFO);
// �ͷ�PROLEIFOռ�õ��ڴ���Դ

#ifdef __cplusplus
}
#endif

#endif // __ROLE_IFO_H__ //
