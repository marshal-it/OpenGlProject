
/*
#version version_number

in type_in_variable_name;
in type_in_variable_name;

out type out_variable_name;

uniform type uniform_name;

int main()
{
	//处理输入并进行一些图形操作
	//....
	//输出处理过的结果到输出变量
	out_variable_name = weird_stuff_we_processed;
}
*/

#version 330 core
layout (location = 0) in vec3 position; // position变量的属性位置值为0

out vec4 vertexColor; // 为片段着色器指定一个颜色输出

void main()
{
    gl_Position = vec4(position, 1.0); // 注意我们如何把一个vec3作为vec4的构造器的参数
    vertexColor = vec4(0.5f, 1.0f, 0.0f, 1.0f); // 把输出变量设置为暗红色
}