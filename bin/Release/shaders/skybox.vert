#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 UV;
layout(location = 2) in vec3 normal;
layout(location = 3) in vec3 tangent;
layout(location = 4) in vec3 bitangent;
out vec3 TexCoords;
out vec2 TexCoord;
out mat3 TBN;
uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;
out vec3 FragPos;
vec3 T;
vec3 B;
vec3 N;
mat3 CreateTBNMatrix(mat3 normalMatrix)
{
     T = normalize(normalMatrix * tangent);
     B = normalize(normalMatrix * bitangent);
     N = normalize(normalMatrix * normal);

    return transpose(mat3(T, B, N));
}

void main()
{
    vec4 pos = projection * view * model * vec4(position, 1.0);
    FragPos = vec3(view * model * vec4(position, 1.0));
    gl_Position = pos.xyww;
    gl_Position.z = clamp(pos.w, 0.0, 0.99999999999999999999);
    gl_Position.w = clamp(pos.w, 0.0, 0.99999999999999999999);
    TexCoords = position;
    TexCoord = UV;

    mat3 normalMatrix = transpose(inverse(mat3(model)));
  	TBN = CreateTBNMatrix(normalMatrix);
}
