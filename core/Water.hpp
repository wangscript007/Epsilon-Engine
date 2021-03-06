///========= Copyright Survtech, All rights reserved. ============//
///
/// Purpose:
///
///=============================================================================

#ifndef WATER_H_INCLUDED
#define WATER_H_INCLUDED

#include <pch.hpp>
#include <Core.hpp>
#include <Renderer/Model.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Shader.h>
#include <Texture.h>
#include <camera.h>
namespace Epsilon {
class Water{

public:

    Water(glm::vec3 position, float scale);

public:

    void GenerateReflection(std::shared_ptr<Camera> cam);
    void GenerateRefraction(std::shared_ptr<Camera> cam);
    void FinishWatercomputation(void);
    void RenderWater(std::shared_ptr<Camera> cam, GLuint colorBuffer, glm::vec3 lightDir, GLuint depthTexture, GLuint);

public:
    float scale;
    glm::vec3 position;

    double getActiveClip()
    {
        return ActiveClip;
    }

    void setActiveClip(double t)
    {
        ActiveClip = t;
    }

private:

    void LoadTextures(void);
    void LoadShaders(void);
    void CreateReflectionFBO(void);
    void CreateRefractionFBO(void);
    void GeneratePlane(void);
    void GenerateModelViewProjection(std::shared_ptr<Camera> cam);
    void GeneratevertexArray();


private:

    GLuint colorTexture;
    GLuint normalTexture;
    GLuint dispTexture;
    GLuint DuDvTexture;
    GLuint foamTexture;
    GLuint diffuseTexture;

    GLuint reflectionTexture;
    GLuint refractionTexture;
    GLuint refractionDepthTexture;

    GLuint refractionRBO;
    GLuint reflectionRBO;

    GLuint refractionFBO;
    GLuint reflectionFBO;

    GLint refractionWidth;
    GLint refractionHeight;

    GLint reflectionWidth;
    GLint reflectionHeight;

    GLuint ReflectionResoulution;
    GLuint RefractionResoulution;

    GLuint VAO;
    GLuint VBO;
    GLuint EBO;

    std::shared_ptr<Shader> shader;
    std::shared_ptr<Model> m_Model;

    glm::mat4 MVP;
    double ActiveClip;

};
}

#endif /// WATER_H_INCLUDED
