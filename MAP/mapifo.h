/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2017.12.28 / 15��40
+
-             �޸�ʱ�䣺2017.12.28 / 15��40
+
-             �ļ����ƣ�mapifo.h
+
-             ģ�飺mapģ�飬��ͼ�ı༭�����أ����ơ�
+
-             ���ܣ�mapģ��ͷ�ļ�������ͷ�ļ��������궨�壬����ǰ������
+
*/

#ifndef __MAP_IFO_H__
#define __MAP_IFO_H__

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

/*
+
-			�ṹ�嶨��
+
*/
typedef struct {

	HBITMAP       m_hbmp[2];    // ��ͼԴBmpͼ��
	HDC	          m_memDc;		// ��ͼ���������Ϸ���memDc�У���ͨ��DrawMap����Imageģ��

}MAP, * PMAP;

/*
+
-			����ǰ������
+
*/

PMAP
InitMap(HINSTANCE, HWND);
// ��ʼ��MAPʵ��

STATUS
FreeMap(PMAP);
// �ͷ�MAPʵ���ڴ���Դ

STATUS
LoadMap(PMAP, HWND);
// �༭��ͼ����MAPʵ����memDc��

STATUS
DrawMap(PMAP, PIMAGE, HWND);
// ���ص�ͼ����mapʵ������imageʵ��

#ifdef __cplusplus
}
#endif

#endif // __MAP_IFO_H__ //