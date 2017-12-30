/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2017.12.28 / 22��26
+
-             �޸�ʱ�䣺2017.12.30 / 14��46
+
-             �ļ����ƣ�weapon.h
+
-             ģ�飺����ģ�飬������ع��ܣ���Ϣ
+
-             ���ܣ�����ģ��ͷ�ļ�������ͷ�ļ��������궨�壬��������ȵ�
+
*/

#ifndef __WEAPON_H__
#define __WEAPON_H__

#ifdef __cplusplus
extern "C" {
#endif

/* 
+
-			����ͷ�ļ�
+
*/
#include "../../SYS/systc.h"


/*
+
-			�ṹ�嶨��
+
*/
typedef enum {

	WEAPON_9MM = 110,

}WEAPON_TYPE;

typedef struct {

	HBITMAP     m_weaponHbmp;

}WEAPON, * PWEAPON;

/*
+
-			����ǰ������
+
*/
PWEAPON
InitWeapon(HINSTANCE, WEAPON_TYPE);
// ��ʼ��WEAPONʵ��

STATUS
FreeWeapon(PWEAPON);
// �ͷ������ڴ���Դ

STATUS
DrawWeapon(PWEAPON, HDC, HDC, POINT);
// ���ݽ�ɫ����λ�û�������


#ifdef __cplusplus
}
#endif

#endif // __WEAPON_H__ //