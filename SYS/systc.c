/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2017.12.27 / 15��18
+
-             �޸�ʱ�䣺2017.12.27 / 15��18
+
-             �ļ����ƣ�systc.c
+
-             ģ�飺systemģ�飬��Ϸ��ϵͳ���ܣ�״̬�붨�壬�����ļ����������ģ��
+
-             ���ܣ�systemģ��ͷ�ļ���������������
+
*/
#include "systc.h"

/*
+
-			��������
+
*/

PSYS
InitSystem() {

	PSYS _psys = (PSYS)malloc(sizeof(SYS));

	_psys->m_cliHeight   = CLI_HEIGHT;
	_psys->m_cliWidth    = CLI_WIDTH;

	return _psys;

}
// ��ʼ���ṹ�� SYSTEM


STATUS
FreeSystem(PSYS _psys) {

	assert(_psys != NULL);

	free(_psys);
	_psys = NULL;

	return OK;

}
// �ͷ�SYSʵ���ڴ���Դ
