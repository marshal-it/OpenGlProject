#version 330 core
out vec4 color;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos; //����Դ��������ȫ�ֱ����д��뵽���չ��������Ƭ����ɫ����

uniform vec3 viewPos; //������Ӿ�������ȫ�ֱ����д��뵽���չ��������Ƭ����ɫ����

in vec3 Normal; //���ն�����ɫ������ķ�������
in vec3 FragPos; //���ն�����ɫ�������Ƭ������

//�ƹ���Ϣ
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
	vec3 ambient; //������
	vec3 diffuse; //�����
	vec3 specular; //�߹�
	float shininess; //ɢ��뾶
};

uniform Material material;

void main()
{
	//�����Դ������֮�������
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);

	//����ɢ����ɫ(������)
	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 diffuse = (diff * material.diffuse)* light.diffuse; //31

	//�����Դ������ӽ�֮�������
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);

	//����߹���ɫ
	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);
	vec3 specular = (spec * material.specular) * light.specular;

	//���㻷����
	vec3 ambient = material.ambient * light.ambient;

	//�������
	vec3 result = ambient + diffuse + specular;
	color = vec4(result, 1.0f);
}
