#version 330 core
in vec4 vertexColor; // �Ӷ�����ɫ�����������������������ͬ��������ͬ��

out vec4 color; // Ƭ����ɫ������ı����������������������ͱ�����vec4

uniform vec4 ourColor; //��OpenGl����������趨�������

void main()
{
    color = ourColor;
}