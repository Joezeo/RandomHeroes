/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2017.12.27 / 22��33
+
-             �޸�ʱ�䣺2017.12.27 / 22��33
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
#include "../SYS/systc.h"


/*
+
-			�ṹ�嶨��
+
*/
typedef struct {

	HDC     m_memDc;         // ����ģ���ͼ���Ȼ���IMAGEʵ����memDc��,��ͨ��DrawImage����

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

#ifdef __cplusplus
}
#endif

#endif // __IMAGE_H__ //
