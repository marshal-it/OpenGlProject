#pragma once

#include <iostream>
#include <cmath>

// GLEW
#define GLEW_STATIC
#include <GLEW/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// Other Libs
#include <SOIL/SOIL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"

//顶点
struct Vertex
{
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

//纹理贴图
struct Texture
{
	GLuint id;
	string type;
};

//定义网格
class Mesh
{
public:
	vector<Vertex> vertices; //顶点数据
	vector<GLuint> indices; //顶点索引
	vector<Texture> textures; //纹理贴图数据
	Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures);
	void Draw(Shader shader);
protected:
private:
	GLuint VAO, VBO, EBO;
	void setupMesh();
};