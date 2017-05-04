#version 330 core

in vec3 ourcolor;
in vec2 TexCoord;

out vec4 color;

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;

vec2 coordtemp;
vec2 coordtemp2;

void main()
{
	coordtemp = vec2(TexCoord.x, 1.0f - TexCoord.y);
	color = mix(texture(ourTexture1, coordtemp), texture(ourTexture2, coordtemp), 0.2);
}