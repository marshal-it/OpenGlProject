#version 330 core
out vec4 color;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos; //����Դ��������ȫ�ֱ����д��뵽���չ��������Ƭ����ɫ����

uniform vec3 viewPos; //������Ӿ�������ȫ�ֱ����д��뵽���չ��������Ƭ����ɫ����

in vec3 Normal; //���ն�����ɫ������ķ�������
in vec3 FragPos; //���ն�����ɫ�������Ƭ������


void main()
{
	//�����Դ������֮�������
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);

	//����ɢ����ɫ
	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 diffuse = diff * lightColor;

	//�����Դ������ӽ�֮�������
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);

	//����߹���ɫ
	float specularStrength = 0.5f; //Ӱ��ϵ��
	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), 32);
	vec3 specular = specularStrength * spec * lightColor;

	float ambientStrength = 0.1f; //Ӱ��ϵ��
	vec3 ambient = ambientStrength * lightColor;

	//�������
	vec3 result = (ambient + diffuse + specular)* objectColor;
	color = vec4(result, 1.0f);
//    color = vec4(lightColor * objectColor, 1.0f);
}
