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

static float degree = 0; //�����ת�Ķ���

//void changeSize(int w, int h)
//{
//	//���¶����ӿ�
//	glViewport(0, 0, w, h);
//
//	//��������ͶӰ�任
//	if (h == 0) h = 1; //���ø�Ϊ0������0�Ĵ���
//	double ratio = 1.0 * w / h;//��߱�
//	glMatrixMode(GL_PROJECTION); //��ǰ������ΪͶӰ����
//	glLoadIdentity(); // ���ͶӰ����
//	gluPerspective(45, ratio, 1, 1000);//����ͶӰ����
//
//	//ģ���ӵ�任
//	glMatrixMode(GL_MODELVIEW);//��ǰ������Ϊģ���ӵ����
//}
//
//void renderScene()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//�����ɫ�������Ȼ���
//	glLoadIdentity();//���ģ���ӵ����
//
//	//�ӵ�任
//	gluLookAt(0.0, 0.0, 5.0,
//		0.0, 0.0, -1.0,
//		0.0f, 1.0f, 0.0f);
//
//	//ģ�ͱ任 ��ת���
//	glRotatef(degree, 0, 1, 1);
//
//	//���Ʋ��
////	glutSolidTeapot(1);
//
//}