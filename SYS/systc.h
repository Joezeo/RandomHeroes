/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2017.12.27 / 15��18
+
-             �޸�ʱ�䣺2017.12.27 / 15��18
+
-             �ļ����ƣ�systc.h
+
-             ģ�飺systemģ�飬��Ϸ��ϵͳ���ܣ�״̬�붨�壬�����ļ����������ģ��
+
-             ���ܣ�systemģ��ͷ�ļ��������궨�壬ͷ�ļ��������ṹ�嶨�壬����ǰ������
+
*/
#ifndef __SYSTC_H__
#define __SYSTC_H__

#ifdef __cplusplus
extern "C" {
#endif

/*
+
-			ͷ�ļ�����
+
*/
#include <assert.h>
#include <stdlib.h>
#include <windows.h>
#include "../RandomHeroes/resource.h"
#pragma comment(lib,"msimg32.lib")
#pragma comment(lib,"winmm.lib")


/*
+
-			�궨��
+
*/

#define CLI_HEIGHT 384		// �ͻ����߶�
#define CLI_WIDTH  640		// �ͻ������

// ״̬�붨��
#define OK         1
#define FAILD     -1
#define OVERFLOW  -2

typedef int STATUS;


/*
+
-			�ṹ�嶨��
+
*/
typedef struct {

	UINT    m_cliHeight;
	UINT    m_cliWidth;

}SYSTEM, SYS, *PSYS;


/*
+
-			����ǰ����
+
*/

STATUS
InitSystem(PSYS);
// ��ʼ���ṹ�� SYSTEM

#ifdef __cplusplus
}
#endif

#endif // __SYSTC_H__