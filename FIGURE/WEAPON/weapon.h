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
-			�궨��
+
*/
// ��ɫ��ǰ��ʱ������ͼ������ڽ�ɫͼ���ƫ����
#define FORWARD_WEAPON_X_OFFSET 10
#define FORWARD_WEAPON_Y_OFFSET 7

// ��ɫ�����ʱ������ͼ������ڽ�ɫͼ���ƫ����
#define BACKWARD_WEAPON_X_OFFSET -41
#define BACKWARD_WEAPON_Y_OFFSER 7



/*
+
-			�ṹ�嶨��
+
*/
typedef enum {

	WEAPON_9MM        = 200,
	WEAPON_9MM_RETURN = 201,

}WEAPON_TYPE;

typedef struct {

	HBITMAP     m_weaponHbmp_forward;
	HBITMAP     m_weaponHbmp_backward;

}WEAPON, * PWEAPON;

/*
+
-			����ǰ������
+
*/
PWEAPON
LoadWeapon(HINSTANCE, WEAPON_TYPE);
// ��ʼ��WEAPONʵ��

STATUS
FreeWeapon(PWEAPON);
// �ͷ������ڴ���Դ

STATUS
DrawWeapon(PWEAPON, HDC, HDC, POINT, BOOL);
// ���ݽ�ɫ����λ�û�������


#ifdef __cplusplus
}
#endif

#endif // __WEAPON_H__ //