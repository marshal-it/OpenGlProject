
/*
#version version_number

in type_in_variable_name;
in type_in_variable_name;

out type out_variable_name;

uniform type uniform_name;

int main()
{
	//�������벢����һЩͼ�β���
	//....
	//���������Ľ�����������
	out_variable_name = weird_stuff_we_processed;
}
*/

#version 330 core
layout (location = 0) in vec3 position; // position����������λ��ֵΪ0

out vec4 vertexColor; // ΪƬ����ɫ��ָ��һ����ɫ���

void main()
{
    gl_Position = vec4(position, 1.0); // ע��������ΰ�һ��vec3��Ϊvec4�Ĺ������Ĳ���
    vertexColor = vec4(0.5f, 1.0f, 0.0f, 1.0f); // �������������Ϊ����ɫ
}