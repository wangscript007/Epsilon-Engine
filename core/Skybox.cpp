///========= Copyright Survtech, All rights reserved. ============//
///
/// Purpose:
///
///=============================================================================

#include <pch.hpp>
#include <SOIL.h>
#include <Skybox.h>
#include <SkyboxData.h>
#include <ResourceManager.h>

#include <glm/glm.hpp>

namespace Epsilon
{

    Skybox::Skybox(std::string SkyboxTex)
    {
        skydome = (std::shared_ptr<Model>)new Model("models/sphere.eml", glm::vec3(0, 0, 0));
    }

    void Skybox::Render(std::shared_ptr<Camera> &camera, std::shared_ptr<Shader> SkyShader, float exposure, bool state)
    {
        glDepthFunc(GL_LEQUAL);
        SkyShader->Use();
        glUniform1f(glGetUniformLocation(SkyShader->getProgramID(), "exposure"), exposure);
        glUniform1f(glGetUniformLocation(SkyShader->getProgramID(), "time"), glfwGetTime());
        glUniform1i(glGetUniformLocation(SkyShader->getProgramID(), "renderDepth"), state);
        skydome->DrawNoTexture();
        glCache::glUseProgram(0);
        glDepthFunc(GL_LESS);
    }
} // namespace Epsilon
