#version 330 core
in vec3 ourColor;
out vec4 color;

//�Ӷ�����ɫ���еõ�����λ��
in vec4 pointPosition;

void main()
{
   // color = vec4(ourColor, 1.0f);
   color = pointPosition;//������λ�ø�ֵ��Ƭ����ɫ
}