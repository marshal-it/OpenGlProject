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
////创建顶点缓冲对象去管理这些顶点数据的内存
//GLuint VBO[2], VAO;
//GLuint shaderProgram;
//GLuint shaderProgram2; //第二个着色器程序
//
////纹理贴图
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
//unsigned char* Load_Texture(const char* filename); //加载图片
//void Draw_Texture(); //渲染纹理
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
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //配置GLFW
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//
//	//创建一个窗口对象
//	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
//	if (window == nullptr)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//	//GLEW用来管理OpenGL的函数指针，初始化GLEW
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
//	//渲染窗口的尺寸大小
//	int width, height;
//	glfwGetFramebufferSize(window, &width, &height);
//	glViewport(0, 0, width, height);
//
//	//注册按键监听事件
//	glfwSetKeyCallback(window, key_callback);
//
//	//加载着色器
//	//Load_Shader("test.vert", "test2.frag");
//
////	Shader ourShader("test.vert", "test2.frag");
//
//	Shader ourShader("textcoord.vert", "textcoord.frag");
//
//	//处理VAO, VBO
//	//draw_Triggle3();
//	//Draw_Rectangular();
//	draw_elements();
//	Draw_Texture();
//
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//线框模式
//
//	//循环绘制
//	while (!glfwWindowShouldClose(window))
//	{
//		//检查事件
//		glfwPollEvents();
//		
//		//渲染指令
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		//激活着色程序对象
//		//在glUseProgram函数调用之后，每个着色器调用和渲染调用都会使用这个程序对象（也就是之前写的着色器)
//		//glUseProgram(shaderProgram);
//		ourShader.Use();
//
//		////改变着色器中的Uniform值
//		//{
//		//	GLfloat timeValue = glfwGetTime();
//		//	GLfloat greenValue = (sin(timeValue) / 2) + 0.5;
//		//	GLint vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
//		//	glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
//		//}
//		
//		//改变定点参数实现偏移
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
//		//绑定纹理
//		//glActiveTexture(GL_TEXTURE0);
//		//glBindTexture(GL_TEXTURE_2D, texture1);
//		//glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture"), 0);
//
//		//glBindVertexArray(VAO);
//
//		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//	//	glDrawArrays(GL_TRIANGLE_STRIP, 0, 6); //根据顶点数组进行渲染
//	//	glDrawArrays(GL_TRIANGLES, 0, 3); //根据顶点数组进行渲染
//
//		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);//使用当前绑定的索引缓冲对象中的索引进行绘制
//
//	//	glBindVertexArray(0);
//
//		//交换缓冲
//		glfwSwapBuffers(window);
//
//	}
//	//删除顶点数组对象和顶点缓存对象
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
//	//////////////////////////编译着色器////////////////////////////////
//	//顶点着色部分
//	GLuint vertexShader;
//	vertexShader = glCreateShader(GL_VERTEX_SHADER);
//
//	//读取顶点着色代码
//	const GLchar* VertCode = textFileRead(vert);
//
//	glShaderSource(vertexShader, 1, &VertCode, NULL);
//	glCompileShader(vertexShader);
//
//	//判断是否编译成功
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
//	//片段着色部分
//	GLuint fragmentShader;
//	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//
//	//读取片段着色代码
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
//	///////////////////////////	着色器程序////////////////////////////////////////
//	shaderProgram = glCreateProgram();
//
//	//将着色shader合并，并链接到着色程序
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
//	///////////////////////////着色器程序2//////////////////////////////////////
//	//片段着色部分2
//	GLuint fragmentShader2;
//	fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
//
//	//读取片段着色代码
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
//	//将着色shader合并，并链接到着色程序
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
//	//在把着色器对象链接到程序对象以后，记得删除着色器对象，我们不再需要它们
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
//	//配置绑定
//	glGenTextures(1, &texture1);
//	glBindTexture(GL_TEXTURE_2D, texture1);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	//生成纹理
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
//	////生成纹理
//	//image = Load_Texture("container.png");
//	//SOIL_free_image_data(image);
//	//glBindTexture(GL_TEXTURE_2D, 0);
//
//}
//
//void draw_elements()
//{
//	//四个顶点，两个三角
//	GLfloat vertices[] = {
//		//     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
//		0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // 右上
//		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,   // 右下
//	   -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,   // 左下
//	   -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f    // 左上
//	};
//
//	//顶点索引
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
//	//顶点坐标
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//
//	//颜色信息
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//
//	//纹理坐标
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
//
//	glBindVertexArray(0);
//
//	/*
//	glGenVertexArrays(1, &VAO); //顶点数组对象
//	glBindVertexArray(VAO); //绑定顶点数组对象
//
//	glGenBuffers(1, &VBO[0]); //分配缓冲ID和初始化顶点缓存对象(Vertext Buffer)
//
//	//把顶点数组复制到缓冲中供OpenGl使用
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);//绑定缓冲类型
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	GLuint EBO;
//	glGenBuffers(1, &EBO);
//	//绑定EBO，将顶点索引复制到缓冲区
//	//GL_ELEMENT_ARRAY_BUFFER为缓冲目标，指明从索引缓冲渲染
//	//当目标是GL_ELEMENT_ARRAY_BUFFER的时候，VAO会储存glBindBuffer的函数调用
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	//通过glVertexAttribPointer设置的顶点属性配置
//	//通过glVertexAttribPointer调用与顶点属性关联的顶点缓冲对象。
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//
//	//解除绑定
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//	*/
//}
//
//void draw_Triggle()
//{
//	//定义顶点数据
//	GLfloat vertices[] = {
//		-0.9f, -0.5f, 0.0f,  // Left 
//		-0.0f, -0.5f, 0.0f,  // Right
//		-0.45f, 0.5f, 0.0f,  // Top 
//	};
//
//	glGenVertexArrays(1, &VAO); //顶点数组对象
//	glBindVertexArray(VAO); //绑定顶点数组对象
//
//	glGenBuffers(2, VBO); //分配缓冲ID和初始化顶点缓存对象(Vertext Buffer)
//
//	//把顶点数组复制到缓冲中供OpenGl使用
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);//绑定缓冲类型
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	//通过glVertexAttribPointer设置的顶点属性配置
//	//通过glVertexAttribPointer调用与顶点属性关联的顶点缓冲对象。
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//
//	//绑定VBO2缓冲类型
//	GLfloat vertices2[] = {
//		0.0f, -0.5f, 0.0f,  // Left
//		0.9f, -0.5f, 0.0f,  // Right
//		0.45f, 0.5f, 0.0f   // Top 
//	};
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);//绑定缓冲类型
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
//	//定义顶点数据
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
//	glGenVertexArrays(1, &VAO); //顶点数组对象
//	glBindVertexArray(VAO); //绑定顶点数组对象
//
//	glGenBuffers(1, &VBO[0]); //分配缓冲ID和初始化顶点缓存对象(Vertext Buffer)
//
//	//把顶点数组复制到缓冲中供OpenGl使用
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);//绑定缓冲类型
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	//通过glVertexAttribPointer设置的顶点属性配置
//	//通过glVertexAttribPointer调用与顶点属性关联的顶点缓冲对象。
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//
//	//解除绑定
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//}
//
//void draw_Triggle3()
//{
//	//定义顶点数据
//	GLfloat vertices[] = {
//		// 位置              // 颜色
//		0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,   // 右下
//		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,   // 左下
//		0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f    // 顶部
//	};
//
//
//	glGenVertexArrays(1, &VAO); //顶点数组对象
//	glBindVertexArray(VAO); //绑定顶点数组对象
//
//	glGenBuffers(1, &VBO[0]); //分配缓冲ID和初始化顶点缓存对象(Vertext Buffer)
//
//	//把顶点数组复制到缓冲中供OpenGl使用
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);//绑定缓冲类型
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	//通过glVertexAttribPointer设置的顶点属性配置
//	//通过glVertexAttribPointer调用与顶点属性关联的顶点缓冲对象。
//	//位置属性
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//
//	//对于每个顶点来说，位置顶点属性在前，所以它的偏移量是0。颜色属性紧随位置数据之后，所以偏移量就是3 * sizeof(GLfloat)，用字节来计算就是12字节
//	//颜色属性（偏移1个属性单位(位置属性含有3个字段)，因为位置属性在前）
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//
//	//解除绑定
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//}
//
//void Draw_Rectangular()
//{
//	//顶点数据
//	GLfloat vertices[] = {
//		0.5f, 0.5f, 0.0f,   // 右上角
//		0.5f, -0.5f, 0.0f,  // 右下角
//		-0.5f, -0.5f, 0.0f, // 左下角
//		-0.5f, 0.5f, 0.0f   // 左上角
//	};
//
//	//顶点索引
//	GLuint indices[] = {
//		0,1,3,
//		1,2,3
//	};
//
//	glGenVertexArrays(1, &VAO); //顶点数组对象
//	glBindVertexArray(VAO); //绑定顶点数组对象
//
//	glGenBuffers(1, &VBO[0]); //分配缓冲ID和初始化顶点缓存对象(Vertext Buffer)
//
//	//把顶点数组复制到缓冲中供OpenGl使用
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);//绑定缓冲类型
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	GLuint EBO;
//	glGenBuffers(1, &EBO);
//	//绑定EBO，将顶点索引复制到缓冲区
//	//GL_ELEMENT_ARRAY_BUFFER为缓冲目标，指明从索引缓冲渲染
//	//当目标是GL_ELEMENT_ARRAY_BUFFER的时候，VAO会储存glBindBuffer的函数调用
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	//通过glVertexAttribPointer设置的顶点属性配置
//	//通过glVertexAttribPointer调用与顶点属性关联的顶点缓冲对象。
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//
//	//解除绑定
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//}