/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2018.1.23 / 19��56
+
-             �޸�ʱ�䣺2018.1.23 / 19��56
+
-             �ļ����ƣ�enemy.c
+
-             ģ�飺enemy����ģ�飬��Ϸ������ع���
+
-             ���ܣ�����ģ��Դ�ļ������������Ķ��壬��̬��������������
+
*/
#include "enemy.h"

PENEMY
GetEnemy(POINT _enemyPos) {

	PENEMY _penemy = (PENEMY)malloc(sizeof(ENEMY));
	if (!_penemy)
		exit(OVERFLOWED);

	_penemy->m_enemyPos = _enemyPos;

	/*
	**��ʱδ������˵�ͼ��
	*/

	return _penemy;

}
// ��ʼ�����ˣ�ͨ��λ���������ɵ���


STATUS
FreeEnemy(PENEMY _penemy) {

	assert(_penemy != NULL);

	free(_penemy);
	_penemy = NULL;

	return OK;

}
// �ͷŵ���ʵ����ռ���ڴ棬�ͷ���Դ


STATUS
GetEnemyPosIfo() {


	return OK;

}
// �ӱ����ļ��л�ȡ���˵�λ����Ϣ