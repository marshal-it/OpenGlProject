#include "Mesh.h"


Mesh::Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures)
{
	this->vertices = vertices;
	this->indices = indices;
	this->textures = textures;
	this->setupMesh();
}

void Mesh::setupMesh()
{
	//初始化顶点数组对象
	glGenVertexArrays(1, &this->VAO);
	//初始化顶点缓冲
	glGenBuffers(1, &this->VBO);
	//初始化顶点索引缓冲
	glGenBuffers(1, &this->EBO);

	//绑定VAO
	glBindVertexArray(this->VAO);

	//绑定VBO
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, this->vertices.size()*sizeof(Vertex),
		&this->vertices[0], GL_STATIC_DRAW);

	//绑定EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size()*sizeof(GLuint),
		&this->indices[0], GL_STATIC_DRAW);

	//设置顶点坐标指针
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

	//设置法线指针
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Normal));

	//设置顶点纹理坐标
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, TexCoords));
}

void Mesh::Draw(Shader shader)
{

}
