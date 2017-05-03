#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

out vec3 ourColor; //向片段着色器输出一个颜色
out vec4 pointPosition;

uniform vec2 offset;

void main()
{
    gl_Position = vec4(position.x+offset.x, position.y+offset.y,position.z, 1.0);
	ourColor = color; //将ourColor设置为我们从顶点数据那里得到的输入颜色
	pointPosition = gl_Position; //将顶点位置设置为输入颜色
}