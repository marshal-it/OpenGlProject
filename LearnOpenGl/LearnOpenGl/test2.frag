#version 330 core
in vec3 ourColor;
out vec4 color;

//从顶点着色器中得到顶点位置
in vec4 pointPosition;

void main()
{
   // color = vec4(ourColor, 1.0f);
   color = pointPosition;//将顶点位置赋值给片段颜色
}