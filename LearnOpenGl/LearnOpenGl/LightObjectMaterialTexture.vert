#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;

//直接在程序中控制，uniform为全局变量
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

//out用于传入到片段着色器
out vec3 Normal; //顶点计算法线向量
out vec3 FragPos; //计算片段坐标
out vec2 TexCoords; //纹理坐标

void main()
{
    gl_Position = projection * view * model * vec4(position, 1.0f);
	FragPos = vec3(model * vec4(position, 1.0f));
	Normal = normal;
	TexCoords = texCoords;
}