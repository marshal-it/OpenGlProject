#version 330 core
out vec4 color;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos; //将光源的坐标在全局变量中传入到接收光照物体的片段着色器中

uniform vec3 viewPos; //将玩家视觉坐标在全局变量中传入到接收光照物体的片段着色器中

in vec3 Normal; //接收顶点着色器传入的法线向量
in vec3 FragPos; //接收顶点着色器传入的片段坐标
in vec2 TexCoords;//从接收顶点着色器传入的纹理坐标

//灯光信息
struct Light
{
	vec3 position;
	vec3 direction;
	float cutOff; //内锥
	float outerCutOff; //外锥
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

uniform Light light;

struct Material
{
	sampler2D diffuse; //反射贴图
	sampler2D specular; //高光
	sampler2D emission; //自发光
	float shininess; //散射半径
};

uniform Material material;


/*
	为创建聚光的平滑边，我们希望去模拟的聚光有一个内圆锥和外圆锥。
	我们可以把内圆锥设置为前面部分定义的圆锥，
	我们希望外圆锥从内边到外边逐步的变暗。
*/

void main()
{
	//计算光源和物体之间的向量
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);

	float theta = dot(lightDir, normalize(-light.direction));

	//计算散射颜色(漫反射)
	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 diffuse = (diff * vec3(texture(material.diffuse, TexCoords))) * light.diffuse; //31

	//计算光源与玩家视角之间的向量
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);

	//计算高光颜色
	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);
	vec3 specular = (spec * vec3(texture(material.specular, TexCoords))) * light.specular;

	//计算环境光
	vec3 ambient = vec3(texture(material.diffuse, TexCoords)) * light.ambient;
	//ambient = ambient + vec3(texture(material.emission, TexCoords));
//	ambient = ambient + vec3(texture(material.emission, TexCoords)) * light.ambient; //这里乘于光源的环境光是为了中和自身的光（也可以不相乘）

	//计算内锥与外锥的弧度差
	float epsilon = light.cutOff - light.outerCutOff;
	float intensity = clamp((theta - light.outerCutOff)/epsilon, 0.0f, 1.0f); // 衰减过程，（光线弧度和外锥弧度差）/（锥与外锥的弧度差） （1 - 0的过程）

	//光照组合
	//优化
	diffuse *=intensity;
	specular*=intensity;

	vec3 result = ambient + diffuse + specular;
	color = vec4(result, 1.0f);

	//if(theta>light.cutOff)
	//{
	//	//如果在聚光范围内（则执行环境光，反射，高光）
	//	vec3 result = ambient + diffuse + specular;
	//	color = vec4(result, 1.0f);
	//}
	//else
	//{
	//	//如果超出点聚光范围（则执行环境光效果）
	//	color = vec4(ambient, 1.0f);
	//}
}
