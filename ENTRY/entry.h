/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2017.12.27 / 12��54
+
-             �޸�ʱ�䣺2017.12.27 / 12��54
+
-             �ļ����ƣ�entry.h
+
-             ģ�飺entryģ�飬��������ڣ���Ϸ�����߼����ƣ���Ϣ���д���
+
-             ���ܣ�entryģ��ͷ�ļ��������궨�壬�ṹ�嶨�壬����ǰ������
+
*/

#ifndef __ENTRY_H__
#define __ENTRY_H__

#ifdef __cplusplus
extern "C" {
#endif

/*
+
-			ͷ�ļ�����
+
*/
#include <windows.h>
#include <assert.h>
#include "../RandomHeroes/resource.h"


/*
+
-			�궨��
+
*/

#define CLI_HEIGHT 384		// �ͻ����߶�
#define CLI_WIDTH  640		// �ͻ������


/*
+
-			�ṹ�嶨��
+
*/
typedef struct {

	UINT    m_cliHeight;
	UINT    m_cliWidth;

}SYSTEM, SYS, * PSYS;


/*
+
-			����ǰ����
+
*/

LRESULT CALLBACK 
WndProc(HWND, UINT, WPARAM, LPARAM);
// gameWin ������Ϣ������

VOID
InitSystem(PSYS);
// ��ʼ���ṹ�� SYSTEM

#ifdef __cplusplus
}
#endif

#endif // __ENTRY_H__ //
