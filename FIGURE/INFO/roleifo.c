/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2017.12.30 / 17��16
+
-             �޸�ʱ�䣺2017.12.30 / 17��16
+
-             �ļ����ƣ�roleifo.c
+
-             ģ�飺role.ifoģ�飬��ɫ����Ϸ����Ϣ������������Ϣ��������Ϣ����Ǯ��Ϣ�ȵ�
+
-             ���ܣ�role.ifoģ��Դ�ļ������������Ķ���
+
*/

#include "roleifo.h"

/*
+
-			��������
+
*/

PROLEIFO
LoadRoleInfo() {

	PROLEIFO _proleifo = (PROLEIFO)malloc(sizeof(ROLE_INFORMATON));
	if (!_proleifo)
		exit(OVERFLOW);

	_proleifo->m_weaponType = WEAPON_9MM;
	_proleifo->m_weapon = LoadWeapon(g_hinst, _proleifo->m_weaponType);

	return _proleifo;

}
// ��ʼ����ɫ����Ϣ


STATUS
FreeRoleInfo(PROLEIFO _proleifo) {

	assert(_proleifo != NULL);

	free(_proleifo);
	_proleifo = NULL;

	return OK;

}
// �ͷ�PROLEIFOռ�õ��ڴ���Դ