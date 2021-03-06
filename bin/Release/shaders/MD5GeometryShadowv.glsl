#version 430 core

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec2 in_texCoord;
layout (location = 2) in vec3 in_normal;
layout (location = 3) in vec3 in_tangent;
layout (location = 4) in vec3 in_bitangent;
layout (location = 5) in vec4 in_weights;
layout (location = 6) in vec4 in_indices;

uniform mat4 mSkinned[150];

out vec3 FragPos;
out vec3 Normal;
out vec2 TexCoords;
out mat3 TBN;
out vec3 wFragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 lightDir;
uniform vec3 viewPos;

uniform mat4 lightSpaceMatrix;

vec3 T;
vec3 B;
vec3 N;
mat3 CreateTBNMatrix(mat3 normalMatrix)
{
     T = normalize(normalMatrix * in_tangent);
     B = normalize(normalMatrix * in_bitangent);
     N = normalize(normalMatrix * in_normal);

    return transpose(mat3(T, B, N));
}

void main()
{

	mat4 matTransform = mSkinned[int(in_indices.x)] * in_weights.x;
	     matTransform += mSkinned[int(in_indices.y)] * in_weights.y;
	     matTransform += mSkinned[int(in_indices.z)] * in_weights.z;

	float finalWeight = 1.0f - ( in_weights.x + in_weights.y + in_weights.z );

	matTransform += mSkinned[int(in_indices.w)] * finalWeight;

	vec4 position = model * matTransform * vec4(in_position, 1.0);

	gl_Position = lightSpaceMatrix * position;
}
