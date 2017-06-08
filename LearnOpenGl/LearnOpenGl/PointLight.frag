#version 330 core
out vec4 color;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos; //����Դ��������ȫ�ֱ����д��뵽���չ��������Ƭ����ɫ����

uniform vec3 viewPos; //������Ӿ�������ȫ�ֱ����д��뵽���չ��������Ƭ����ɫ����

in vec3 Normal; //���ն�����ɫ������ķ�������
in vec3 FragPos; //���ն�����ɫ�������Ƭ������
in vec2 TexCoords;//�ӽ��ն�����ɫ���������������

//�ƹ���Ϣ
struct Light
{
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float constant;
	float linear;
	float quadratic;
};

uniform Light light;

struct Material
{
	sampler2D diffuse; //������ͼ
	sampler2D specular; //�߹�
	sampler2D emission; //�Է���
	float shininess; //ɢ��뾶
};

uniform Material material;

void main()
{
	//�����Դ������֮�������
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);

	//������Դ��Ƭ������ľ���
	float distance = length(light.position - FragPos);
	float attenuation = 1.0f/(light.constant + light.linear * distance + light.quadratic * (distance*distance));


	//����ɢ����ɫ(������)
	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 diffuse = (diff * vec3(texture(material.diffuse, TexCoords))) * light.diffuse; //31
	diffuse *=attenuation;

	//�����Դ������ӽ�֮�������
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);

	//����߹���ɫ
	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);
	vec3 specular = (spec * vec3(texture(material.specular, TexCoords))) * light.specular;
	specular *=attenuation;

	//���㻷����
	vec3 ambient = vec3(texture(material.diffuse, TexCoords)) * light.ambient;
	ambient = ambient + vec3(texture(material.emission, TexCoords));
	ambient *=attenuation;
//	ambient = ambient + vec3(texture(material.emission, TexCoords)) * light.ambient; //������ڹ�Դ�Ļ�������Ϊ���к�����Ĺ⣨Ҳ���Բ���ˣ�

	//�������
	vec3 result = ambient + diffuse + specular;
	color = vec4(result, 1.0f);
}
