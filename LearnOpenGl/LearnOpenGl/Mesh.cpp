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
	//��ʼ�������������
	glGenVertexArrays(1, &this->VAO);
	//��ʼ�����㻺��
	glGenBuffers(1, &this->VBO);
	//��ʼ��������������
	glGenBuffers(1, &this->EBO);

	//��VAO
	glBindVertexArray(this->VAO);

	//��VBO
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, this->vertices.size()*sizeof(Vertex),
		&this->vertices[0], GL_STATIC_DRAW);

	//��EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size()*sizeof(GLuint),
		&this->indices[0], GL_STATIC_DRAW);

	//���ö�������ָ��
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

	//���÷���ָ��
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Normal));

	//���ö�����������
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, TexCoords));
}

void Mesh::Draw(Shader shader)
{

}
