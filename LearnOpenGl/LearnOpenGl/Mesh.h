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

//����
struct Vertex
{
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

//������ͼ
struct Texture
{
	GLuint id;
	string type;
};

//��������
class Mesh
{
public:
	vector<Vertex> vertices; //��������
	vector<GLuint> indices; //��������
	vector<Texture> textures; //������ͼ����
	Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures);
	void Draw(Shader shader);
protected:
private:
	GLuint VAO, VBO, EBO;
	void setupMesh();
};