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

	HDC     m_memDc;         // ����ģ���ͼ���Ȼ���IMAGEʵ����memDc��

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
