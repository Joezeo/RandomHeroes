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

STATUS
InitSystem(PSYS _psys) {

	assert(_psys != NULL);

	_psys->m_cliHeight = CLI_HEIGHT;
	_psys->m_cliWidth = CLI_WIDTH;

	return OK;

}