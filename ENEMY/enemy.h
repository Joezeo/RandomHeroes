/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2018.1.23 / 19��56
+
-             �޸�ʱ�䣺2018.1.23 / 19��56
+
-             �ļ����ƣ�enemy.h
+
-             ģ�飺enemy����ģ�飬��Ϸ������ع���
+
-             ���ܣ�����ģ��ͷ�ļ�������ͷ�ļ��������궨�壬����ǰ��������
+
*/
#ifndef __ENEMY_H__
#define __ENEMY_H__

#ifdef __cplusplus
extern "C" {
#endif


/* 
+
-			����ͷ�ļ�
+
*/
#include "../SYS/systc.h"
#include "../RandomHeroes/resource.h"


/*
+
-			�ṹ�嶨��
+
*/

typedef struct {

	/*
	**���˵�λ�����ݴӱ����ļ��н��б���
	*/
	POINT   m_enemyPos;
	HBITMAP m_enemyHbmp;

}ENEMY, * PENEMY;


/*
+
-			����ǰ������
+
*/
PENEMY
GetEnemy(POINT);
// ��ʼ�����ˣ�ͨ��λ���������ɵ���

STATUS
FreeEnemy(PENEMY);
// �ͷŵ���ʵ����ռ���ڴ棬�ͷ���Դ

STATUS
GetEnemyPosIfo();
// �ӱ����ļ��л�ȡ���˵�λ����Ϣ


#ifdef __cplusplus
}
#endif

#endif // __ENEMY_H__ //