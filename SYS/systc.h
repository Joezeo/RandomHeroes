/*
+
-             作者：Joezeo < joezeo@outlook.com >
+
-             创建时间：2017.12.27 / 15：18
+
-             修改时间：2017.12.27 / 15：18
+
-             文件名称：systc.h
+
-             模块：system模块，游戏主系统功能，状态码定义，所有文件都需包括此模块
+
-             功能：system模块头文件，包括宏定义，头文件包含，结构体定义，函数前向声明
+
*/
#ifndef __SYSTC_H__
#define __SYSTC_H__

#ifdef __cplusplus
extern "C" {
#endif

/*
+
-			头文件包含
+
*/
#pragma comment(lib,"msimg32.lib")
#pragma comment(lib,"winmm.lib")

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "../RandomHeroes/resource.h"

extern HINSTANCE             g_hinst;


/*
+
-			宏定义
+
*/

#define CLI_HEIGHT         384		// 客户区高度
#define CLI_WIDTH          640		// 客户区宽度
#define ID_TIMER           1        // TIMER计时器ID
#define TYPE_CNT_OF_WEAPON 14       // 武器种类数

// 状态码定义
#define OK         1
#define FAILD     -1
#define OVERFLOWED  -2

typedef int STATUS;


/*
+
-			结构体定义
+
*/
typedef struct {

	UINT    m_cliHeight;
	UINT    m_cliWidth;

}SYSTEM, SYS, *PSYS;


/*
+
-			函数前向定义
+
*/

PSYS
InitSystem();
// 初始化结构体 SYSTEM

STATUS
FreeSystem(PSYS);
// 释放SYS实例内存资源

#ifdef __cplusplus
}
#endif

#endif // __SYSTC_H__