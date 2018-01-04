/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2017.12.27 / 22��33
+
-             �޸�ʱ�䣺2018.01.04 / 12��21
+
-             �ļ����ƣ�image.h
+
-             ģ�飺imageģ�飬����ģ���ͼ���Ȼ���IMAGEʵ����memDc��,��ͨ��DrawImage����
+
-             ���ܣ�imageģ��ͷ�ļ��������ṹ�嶨�壬ͷ�ļ�����������ǰ������
+
*/
#ifndef __IMAGE_H__
#define __IMAGE_H__

#ifdef __cplusplus
extern "C" {
#endif


/* 
+
-			����ͷ�ļ�
+
*/
#include <math.h>
#include "../SYS/systc.h"


/*
+
-			�ṹ�嶨��
+
*/
typedef struct {

	HBITMAP m_hBmp;          // �ڴ���ݻ���
	HDC     m_memDc;         // ����ģ���ͼ���Ȼ���IMAGEʵ����memDc��,��ͨ��DrawImage����
	UINT    m_drawLocation;  // ����ͼʱ��λ��

}IMAGE, * PIMAGE;

/*
+
-			����ǰ������
+
*/

PIMAGE
InitImage(HWND);
// ��ʼ��IMAGEʵ��

STATUS
FreeImage(PIMAGE);
// �ͷ�PIMAGEʵ����Դ

STATUS
DrawImage(const PIMAGE, HWND);
// ����IMAGEʵ���б����ͼ��

inline int
RotateDc(HDC, int, POINT);
// ��תHDC��ʹ��HDC���ͼ����ת

inline STATUS
RestoreRotateDc(HDC, int);
// �ָ���ת���HDC

#ifdef __cplusplus
}
#endif

#endif // __IMAGE_H__ //
