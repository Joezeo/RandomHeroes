/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2018.1.23 / 20��25
+
-             �޸�ʱ�䣺2018.1.23 / 20��25
+
-             �ļ����ƣ�stage.c
+
-             ģ�飺stage�ؿ�ģ�飬�����ؿ��ĵ�����Ϣ(֮���ѵ�ͼ��ϢҲ�������)
+
-             ���ܣ�stage�ؿ�ģ��Դ�ļ������������Ķ��壬�Լ���̬�����Ķ���
+
*/

#include "stage.h"

PSTAGE
InitStage() {

	PSTAGE _pstage = (PSTAGE)malloc(sizeof(STAGE));
	if (!_pstage)
		exit(OVERFLOWED);

	_pstage->m_stageIfo = one;

	return _pstage;

}
// ��ʼ��stageģ��ʵ��


STATUS
FreeStage(PSTAGE _pstage) {

	assert(_pstage != NULL);

	free(_pstage);
	_pstage = NULL;

	return OK;

}
// �ͷ�stageʵ���ڴ���Դ