/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2017.12.29 / 17��34
+
-             �޸�ʱ�䣺2017.12.29 / 17��34
+
-             �ļ����ƣ�effect.h
+
-             ģ�飺��Чģ�飬��Ч��ع���
+
-             ���ܣ���Чģ��ͷ�ļ�������ͷ�ļ��������궨�壬�ṹ�嶨�壬����ǰ������
+
*/

#ifndef __EFFECT_H__
#define __EFFECT_H__

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
-			�궨��
+
*/
extern HINSTANCE                 g_hinst;

// HBITMAP
#define ALL_EFFECTS LoadBitmap(g_hinst, MAKEINTRESOURCE(IDB_EFFECTS))

// PCAPEFF
#define P_CAP_EFFECT InitCoordSize()
#define EFF_SIZE P_CAP_EFFECT->m_bmpSize
#define EFF_POS  P_CAP_EFFECT->m_bmpCoord

// ��ЧͼƬ����
#define CNT_EFFECTS 34


/*
+
-			�ṹ�嶨��
+
*/

typedef struct {

	// ����ͼ����һ��bmpͼ�ϣ��������������ڽ�ȡ��Ч
	POINT        m_bmpCoord[CNT_EFFECTS];
	SIZE         m_bmpSize[CNT_EFFECTS];

}CAPTURE_EFFECT, * PCAPEFF;

/*
+
-			����ǰ������
+
*/
PCAPEFF
InitCoordSize();
// CAPTURE_EFFECT�ص�������������ЧͼƬ��ȡ���꣬�ߴ����

#ifdef __cplusplus
}
#endif

#endif // __EFFECT_H__ //
