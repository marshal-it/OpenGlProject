#version 330 core
out vec4 color;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos; //将光源的坐标在全局变量中传入到接收光照物体的片段着色器中

uniform vec3 viewPos; //将玩家视觉坐标在全局变量中传入到接收光照物体的片段着色器中

in vec3 Normal; //接收顶点着色器传入的法线向量
in vec3 FragPos; //接收顶点着色器传入的片段坐标

//灯光信息
struct Light
{
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

uniform Light light;

struct Material
{
	vec3 ambient; //环境光
	vec3 diffuse; //反射光
	vec3 specular; //高光
	float shininess; //散射半径
};

uniform Material material;

void main()
{
	//计算光源和物体之间的向量
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);

	//计算散射颜色(漫反射)
	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 diffuse = (diff * material.diffuse)* light.diffuse; //31

	//计算光源与玩家视角之间的向量
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);

	//计算高光颜色
	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);
	vec3 specular = (spec * material.specular) * light.specular;

	//计算环境光
	vec3 ambient = material.ambient * light.ambient;

	//光照组合
	vec3 result = ambient + diffuse + specular;
	color = vec4(result, 1.0f);
}
