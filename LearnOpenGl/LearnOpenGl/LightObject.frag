#version 330 core
out vec4 color;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos; //将光源的坐标在全局变量中传入到接收光照物体的片段着色器中

uniform vec3 viewPos; //将玩家视觉坐标在全局变量中传入到接收光照物体的片段着色器中

in vec3 Normal; //接收顶点着色器传入的法线向量
in vec3 FragPos; //接收顶点着色器传入的片段坐标


void main()
{
	//计算光源和物体之间的向量
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);

	//计算散射颜色
	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 diffuse = diff * lightColor;

	//计算光源与玩家视角之间的向量
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);

	//计算高光颜色
	float specularStrength = 0.5f; //影响系数
	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), 32);
	vec3 specular = specularStrength * spec * lightColor;

	float ambientStrength = 0.1f; //影响系数
	vec3 ambient = ambientStrength * lightColor;

	//光照组合
	vec3 result = (ambient + diffuse + specular)* objectColor;
	color = vec4(result, 1.0f);
//    color = vec4(lightColor * objectColor, 1.0f);
}
