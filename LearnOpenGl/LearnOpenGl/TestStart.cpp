////GLEW
//#define GLEW_STATIC
//#include <GLEW/glew.h>
////GLFW
//#include <GLFW/glfw3.h>
////SOIL
//#include <SOIL/SOIL.h>
//
//#include <iostream>
//#include <stdio.h>
//#include "textfile.h"
//#include "Shader.h"
//using namespace std;
//
////�������㻺�����ȥ������Щ�������ݵ��ڴ�
//GLuint VBO[2], VAO;
//GLuint shaderProgram;
//GLuint shaderProgram2; //�ڶ�����ɫ������
//
////������ͼ
//GLuint texture1;
//GLuint texture2;
//
//static GLint Frames = 0;
//static GLint T0 = 0;
//
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//void draw_Triggle();
//void draw_Triggle2();
//void draw_Triggle3();
//void draw_elements();
//
//unsigned char* Load_Texture(const char* filename); //����ͼƬ
//void Draw_Texture(); //��Ⱦ����
//
//void Load_Shader(char* vert, char* flag);
//void Draw_Rectangular();
//
//int main()
//{
//	if (!glfwInit())
//	{
//		fprintf(stderr, "ERROR: could not start GLFW3\n");
//		return 1;
//	}
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //����GLFW
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//
//	//����һ�����ڶ���
//	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
//	if (window == nullptr)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//	//GLEW��������OpenGL�ĺ���ָ�룬��ʼ��GLEW
//	glewExperimental = GL_TRUE;
//	if (glewInit() != GLEW_OK)
//	{
//		std::cout << "Failed to initialize GLFW" << std::endl;
//		return -1;
//	}
//
//	//get version info
//	const GLubyte* render = glGetString(GL_RENDERER);
//	const GLubyte* version = glGetString(GL_VERSION);
//
//	printf("Render : %s\n", render);
//	printf("OpenGl version supported %s\n", version);
//
//	//glEnable(GL_DEPTH_TEST);
//	//glDepthFunc(GL_LESS);
//
//	//��Ⱦ���ڵĳߴ��С
//	int width, height;
//	glfwGetFramebufferSize(window, &width, &height);
//	glViewport(0, 0, width, height);
//
//	//ע�ᰴ�������¼�
//	glfwSetKeyCallback(window, key_callback);
//
//	//������ɫ��
//	//Load_Shader("test.vert", "test2.frag");
//
////	Shader ourShader("test.vert", "test2.frag");
//
//	Shader ourShader("textcoord.vert", "textcoord.frag");
//
//	//����VAO, VBO
//	//draw_Triggle3();
//	//Draw_Rectangular();
//	draw_elements();
//	Draw_Texture();
//
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//�߿�ģʽ
//
//	//ѭ������
//	while (!glfwWindowShouldClose(window))
//	{
//		//����¼�
//		glfwPollEvents();
//		
//		//��Ⱦָ��
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		//������ɫ�������
//		//��glUseProgram��������֮��ÿ����ɫ�����ú���Ⱦ���ö���ʹ������������Ҳ����֮ǰд����ɫ��)
//		//glUseProgram(shaderProgram);
//		ourShader.Use();
//
//		////�ı���ɫ���е�Uniformֵ
//		//{
//		//	GLfloat timeValue = glfwGetTime();
//		//	GLfloat greenValue = (sin(timeValue) / 2) + 0.5;
//		//	GLint vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
//		//	glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
//		//}
//		
//		//�ı䶨�����ʵ��ƫ��
//		//{
//		//	/*	GLfloat timeValue = glfwGetTime();
//		//		GLfloat greenValue = (sin(timeValue) / 2) + 0.5;*/
//		//	GLint vertexColorLocation = glGetUniformLocation(ourShader.Program, "offset");
//		//	glUniform2f(vertexColorLocation, -0.0f, -0.0f);
//		//}
//
//		glBindTexture(GL_TEXTURE_2D, texture1);
//		glBindVertexArray(VAO);
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//		glBindVertexArray(0);
//
//		//������
//		//glActiveTexture(GL_TEXTURE0);
//		//glBindTexture(GL_TEXTURE_2D, texture1);
//		//glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture"), 0);
//
//		//glBindVertexArray(VAO);
//
//		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//	//	glDrawArrays(GL_TRIANGLE_STRIP, 0, 6); //���ݶ������������Ⱦ
//	//	glDrawArrays(GL_TRIANGLES, 0, 3); //���ݶ������������Ⱦ
//
//		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);//ʹ�õ�ǰ�󶨵�������������е��������л���
//
//	//	glBindVertexArray(0);
//
//		//��������
//		glfwSwapBuffers(window);
//
//	}
//	//ɾ�������������Ͷ��㻺�����
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(2, VBO);
//
//	glfwTerminate();
//	return 0;
//}
//
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//	{
//		glfwSetWindowShouldClose(window, GL_TRUE);
//	}
//}
//
//void Load_Shader(char* vert, char* flag)
//{
//	//////////////////////////������ɫ��////////////////////////////////
//	//������ɫ����
//	GLuint vertexShader;
//	vertexShader = glCreateShader(GL_VERTEX_SHADER);
//
//	//��ȡ������ɫ����
//	const GLchar* VertCode = textFileRead(vert);
//
//	glShaderSource(vertexShader, 1, &VertCode, NULL);
//	glCompileShader(vertexShader);
//
//	//�ж��Ƿ����ɹ�
//	GLint success;
//	GLchar infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//
//	if (!success)
//	{
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	//Ƭ����ɫ����
//	GLuint fragmentShader;
//	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//
//	//��ȡƬ����ɫ����
//	const GLchar* FragCode = textFileRead(flag);
//
//	glShaderSource(fragmentShader, 1, &FragCode, NULL);
//	glCompileShader(fragmentShader);
//
//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	///////////////////////////	��ɫ������////////////////////////////////////////
//	shaderProgram = glCreateProgram();
//
//	//����ɫshader�ϲ��������ӵ���ɫ����
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//	}
//
//	///////////////////////////��ɫ������2//////////////////////////////////////
//	//Ƭ����ɫ����2
//	GLuint fragmentShader2;
//	fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
//
//	//��ȡƬ����ɫ����
//	const GLchar* FragCode2 = textFileRead("test2.frag");
//
//	glShaderSource(fragmentShader2, 1, &FragCode2, NULL);
//	glCompileShader(fragmentShader2);
//
//	glGetShaderiv(fragmentShader2, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(fragmentShader2, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	shaderProgram2 = glCreateProgram();
//	//����ɫshader�ϲ��������ӵ���ɫ����
//	glAttachShader(shaderProgram2, vertexShader);
//	glAttachShader(shaderProgram2, fragmentShader2);
//	glLinkProgram(shaderProgram2);
//
//	glGetProgramiv(shaderProgram2, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(shaderProgram2, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//	}
//
//	//�ڰ���ɫ���������ӵ���������Ժ󣬼ǵ�ɾ����ɫ���������ǲ�����Ҫ����
//	glDeleteShader(fragmentShader2);
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//
//}
//
//unsigned char* Load_Texture(const char* filename)
//{
//	int width, height;
//	unsigned char* image = SOIL_load_image(filename, &width, &height, 0, SOIL_LOAD_RGB);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
//	glGenerateMipmap(GL_TEXTURE_2D);
//
//	return image;
//}
//
//void Draw_Texture()
//{
//	//���ð�
//	glGenTextures(1, &texture1);
//	glBindTexture(GL_TEXTURE_2D, texture1);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	//��������
//	unsigned char* image = Load_Texture("container.jpg");
//	SOIL_free_image_data(image);
//	glBindTexture(GL_TEXTURE_2D, 0);
//
//	//////////////////////////////////////////////////////////////////////////
//
//	//glGenTextures(1, &texture2);
//	//glBindTexture(GL_TEXTURE_2D, texture2);
//
//	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	////��������
//	//image = Load_Texture("container.png");
//	//SOIL_free_image_data(image);
//	//glBindTexture(GL_TEXTURE_2D, 0);
//
//}
//
//void draw_elements()
//{
//	//�ĸ����㣬��������
//	GLfloat vertices[] = {
//		//     ---- λ�� ----       ---- ��ɫ ----     - �������� -
//		0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // ����
//		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,   // ����
//	   -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,   // ����
//	   -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f    // ����
//	};
//
//	//��������
//	GLuint indices[] = {
//		0, 1, 3, // First Triangle
//		1, 2, 3
//	};
//
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//
//	glGenBuffers(1, &VBO[0]);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	GLuint EBO;
//	glGenBuffers(1, &EBO);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	//��������
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//
//	//��ɫ��Ϣ
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//
//	//��������
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
//
//	glBindVertexArray(0);
//
//	/*
//	glGenVertexArrays(1, &VAO); //�����������
//	glBindVertexArray(VAO); //�󶨶����������
//
//	glGenBuffers(1, &VBO[0]); //���仺��ID�ͳ�ʼ�����㻺�����(Vertext Buffer)
//
//	//�Ѷ������鸴�Ƶ������й�OpenGlʹ��
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);//�󶨻�������
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	GLuint EBO;
//	glGenBuffers(1, &EBO);
//	//��EBO���������������Ƶ�������
//	//GL_ELEMENT_ARRAY_BUFFERΪ����Ŀ�ָ꣬��������������Ⱦ
//	//��Ŀ����GL_ELEMENT_ARRAY_BUFFER��ʱ��VAO�ᴢ��glBindBuffer�ĺ�������
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	//ͨ��glVertexAttribPointer���õĶ�����������
//	//ͨ��glVertexAttribPointer�����붥�����Թ����Ķ��㻺�����
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//
//	//�����
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//	*/
//}
//
//void draw_Triggle()
//{
//	//���嶥������
//	GLfloat vertices[] = {
//		-0.9f, -0.5f, 0.0f,  // Left 
//		-0.0f, -0.5f, 0.0f,  // Right
//		-0.45f, 0.5f, 0.0f,  // Top 
//	};
//
//	glGenVertexArrays(1, &VAO); //�����������
//	glBindVertexArray(VAO); //�󶨶����������
//
//	glGenBuffers(2, VBO); //���仺��ID�ͳ�ʼ�����㻺�����(Vertext Buffer)
//
//	//�Ѷ������鸴�Ƶ������й�OpenGlʹ��
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);//�󶨻�������
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	//ͨ��glVertexAttribPointer���õĶ�����������
//	//ͨ��glVertexAttribPointer�����붥�����Թ����Ķ��㻺�����
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//
//	//��VBO2��������
//	GLfloat vertices2[] = {
//		0.0f, -0.5f, 0.0f,  // Left
//		0.9f, -0.5f, 0.0f,  // Right
//		0.45f, 0.5f, 0.0f   // Top 
//	};
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);//�󶨻�������
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(1);
//
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//}
//
//void draw_Triggle2()
//{
//	//���嶥������
//	GLfloat vertices[] = {
//		// First triangle
//		-0.9f, -0.5f, 0.0f,  // Left 
//		-0.0f, -0.5f, 0.0f,  // Right
//		-0.45f, 0.5f, 0.0f,  // Top 
//		// Second triangle
//		0.0f, -0.5f, 0.0f,  // Left
//		0.9f, -0.5f, 0.0f,  // Right
//		0.45f, 0.5f, 0.0f   // Top 
//	};
//
//
//	glGenVertexArrays(1, &VAO); //�����������
//	glBindVertexArray(VAO); //�󶨶����������
//
//	glGenBuffers(1, &VBO[0]); //���仺��ID�ͳ�ʼ�����㻺�����(Vertext Buffer)
//
//	//�Ѷ������鸴�Ƶ������й�OpenGlʹ��
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);//�󶨻�������
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	//ͨ��glVertexAttribPointer���õĶ�����������
//	//ͨ��glVertexAttribPointer�����붥�����Թ����Ķ��㻺�����
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//
//	//�����
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//}
//
//void draw_Triggle3()
//{
//	//���嶥������
//	GLfloat vertices[] = {
//		// λ��              // ��ɫ
//		0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,   // ����
//		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,   // ����
//		0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f    // ����
//	};
//
//
//	glGenVertexArrays(1, &VAO); //�����������
//	glBindVertexArray(VAO); //�󶨶����������
//
//	glGenBuffers(1, &VBO[0]); //���仺��ID�ͳ�ʼ�����㻺�����(Vertext Buffer)
//
//	//�Ѷ������鸴�Ƶ������й�OpenGlʹ��
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);//�󶨻�������
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	//ͨ��glVertexAttribPointer���õĶ�����������
//	//ͨ��glVertexAttribPointer�����붥�����Թ����Ķ��㻺�����
//	//λ������
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//
//	//����ÿ��������˵��λ�ö���������ǰ����������ƫ������0����ɫ���Խ���λ������֮������ƫ��������3 * sizeof(GLfloat)�����ֽ����������12�ֽ�
//	//��ɫ���ԣ�ƫ��1�����Ե�λ(λ�����Ժ���3���ֶ�)����Ϊλ��������ǰ��
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//
//	//�����
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//}
//
//void Draw_Rectangular()
//{
//	//��������
//	GLfloat vertices[] = {
//		0.5f, 0.5f, 0.0f,   // ���Ͻ�
//		0.5f, -0.5f, 0.0f,  // ���½�
//		-0.5f, -0.5f, 0.0f, // ���½�
//		-0.5f, 0.5f, 0.0f   // ���Ͻ�
//	};
//
//	//��������
//	GLuint indices[] = {
//		0,1,3,
//		1,2,3
//	};
//
//	glGenVertexArrays(1, &VAO); //�����������
//	glBindVertexArray(VAO); //�󶨶����������
//
//	glGenBuffers(1, &VBO[0]); //���仺��ID�ͳ�ʼ�����㻺�����(Vertext Buffer)
//
//	//�Ѷ������鸴�Ƶ������й�OpenGlʹ��
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);//�󶨻�������
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	GLuint EBO;
//	glGenBuffers(1, &EBO);
//	//��EBO���������������Ƶ�������
//	//GL_ELEMENT_ARRAY_BUFFERΪ����Ŀ�ָ꣬��������������Ⱦ
//	//��Ŀ����GL_ELEMENT_ARRAY_BUFFER��ʱ��VAO�ᴢ��glBindBuffer�ĺ�������
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	//ͨ��glVertexAttribPointer���õĶ�����������
//	//ͨ��glVertexAttribPointer�����붥�����Թ����Ķ��㻺�����
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//
//	//�����
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//}