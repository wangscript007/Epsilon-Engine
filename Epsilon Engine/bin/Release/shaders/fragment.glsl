#version 330 core

out vec4 Color;

uniform sampler2D texture1;
in vec2 texCoords;

void main()
{
	Color = texture(texture1, texCoords);
}