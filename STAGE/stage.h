/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2018.1.23 / 20��25
+
-             �޸�ʱ�䣺2018.1.23 / 20��25
+
-             �ļ����ƣ�stage.h
+
-             ģ�飺stage�ؿ�ģ�飬�����ؿ��ĵ�����Ϣ(֮���ѵ�ͼ��ϢҲ�������)
+
-             ���ܣ�stage�ؿ�ģ��ͷ�ļ�������ͷ�ļ��İ������궨�壬���������
+
*/

#ifndef __STAGE_H__
#define __STAGE_H__

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

/*
**�ؿ����˵�����
*/
#define ENEMY_CNT_STAGE_1 10;


/*
+
-			�ṹ�嶨��
+
*/
typedef enum {

	one = 1,
	two,
	three,
	four,
	five,

}STAGEIFO;

typedef struct {

	STAGEIFO m_stageIfo;

}STAGE, * PSTAGE;


/*
+
-			����ǰ������
+
*/
PSTAGE
InitStage();
// ��ʼ��stageģ��ʵ��

STATUS
FreeStage(PSTAGE);
// �ͷ�stageʵ���ڴ���Դ

#ifdef __cplusplus
}
#endif

#endif // __STAGE_H__ //
