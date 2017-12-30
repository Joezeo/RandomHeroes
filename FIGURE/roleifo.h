/*
+
-             作者：Joezeo < joezeo@outlook.com >
+
-             创建时间：2017.12.27 / 15：21
+
-             修改时间：2017.12.28 / 14：08
+
-             文件名称：roleifo.h
+
-             模块：role模块，关于游戏角色的模块，包括角色的控制，绘制，状态等
+
-             功能：role模块头文件，包括结构体定义，头文件包含，函数前向声明，宏定义
+
*/
#ifndef __ROLE_IFO_H__
#define __ROLE_IFO_H__

#ifdef __cplusplus
extern "C" {
#endif


/* 
+
-			包含头文件
+
*/
#include "../SYS/systc.h"
#include "../IMAGE/image.h"
#include "./WEAPON/weapon.h"
#include "../EFFECT/effect.h"

/*
+
-			结构体定义
+
*/
typedef struct {

	HBITMAP m_hbmp_forward;   // 角色的图像（向前走时）
	HBITMAP m_hbmp_backward;  // 角色的图像（向后走时）
	SHORT   m_status;         // 角色移动状态（0，1，2分别代表行走，落下，起跳）
	SHORT   m_index;          // 用于角色移动状态下，裁剪人物图像(0，1，2三种状态)
	SHORT   m_speed;          // 角色移动速度
	SHORT   m_keyDownCnt;     // 按键次数，辅助改变角色的图像
	SHORT   m_maxHeight;      // 角色最大跳跃高度
	SHORT   m_curHeight;      // 角色当前跳跃高度
	BOOL    m_mvDirection;    // 角色移动方向，TRUE为向前，FALSE为向后
	BOOL    m_highStatus;     // 跳跃后是否达到最大高度
	BOOL    m_moveStatus;     // 角色是否处于正在移动状态
	BOOL    m_fmapRefresh;    // 角色是否达到地图刷新点(前方)
	BOOL    m_bmapRefresh;    // 角色是否达到地图刷新点(后方)
	BOOL    m_fmapEnd;        // 地图是否达到尽头(前方)
	BOOL    m_bmapEnd;        // 地图是否达到尽头(后方)
	SIZE    m_size;           // 角色大小
	POINT   m_pos;            // 角色在整个地图的位置
	POINT   m_clientPos;      // 角色在客户区的坐标

	PWEAPON m_weapon;      // 角色的武器

}ROLE, * PROLE;

/*
+
-			函数前向声明
+
*/

PROLE
InitRole(HINSTANCE);
// 初始化ROLE结构体实例

STATUS
FreeRole(PROLE);
// 释放ROLE实例资源

STATUS
DrawRole(const HWND, const PROLE, PIMAGE);
// 画出角色

STATUS
ControlRole(PROLE, WPARAM, HWND);
// 角色控制，移动跳跃

STATUS
UnControlRole(PROLE, WPARAM, HWND);
// 按键抬起，角色不受控制时的状态

STATUS
RoleJumpProc(PROLE, HWND);
// 角色跳跃过程，此函数由Timer计时器控制




#ifdef __cplusplus
}
#endif

#endif // __ROLE_IFO_H__ //
