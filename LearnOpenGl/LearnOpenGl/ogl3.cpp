//////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
//GLEW
#define GLEW_STATIC
#include <GLEW/glew.h>
//GLFW
#include <GLFW/glfw3.h>
#include <iostream>
#include "textfile.h"

using namespace std;

#define printOpenGLError() printOglError(_FILE_, _LINE_)

static float degree = 0; //茶壶旋转的度数

//void changeSize(int w, int h)
//{
//	//重新定义视口
//	glViewport(0, 0, w, h);
//
//	//重新设置投影变换
//	if (h == 0) h = 1; //放置高为0产生除0的错误
//	double ratio = 1.0 * w / h;//宽高比
//	glMatrixMode(GL_PROJECTION); //当前矩阵设为投影矩阵
//	glLoadIdentity(); // 清空投影矩阵
//	gluPerspective(45, ratio, 1, 1000);//重设投影矩阵
//
//	//模型视点变换
//	glMatrixMode(GL_MODELVIEW);//当前矩阵设为模型视点矩阵
//}
//
//void renderScene()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//清空颜色缓存和深度缓存
//	glLoadIdentity();//清空模型视点矩阵
//
//	//视点变换
//	gluLookAt(0.0, 0.0, 5.0,
//		0.0, 0.0, -1.0,
//		0.0f, 1.0f, 0.0f);
//
//	//模型变换 旋转茶壶
//	glRotatef(degree, 0, 1, 1);
//
//	//绘制茶壶
////	glutSolidTeapot(1);
//
//}