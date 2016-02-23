#include <ShadowMapping.h>
#include <iostream>
#include <cmath>

void ShadowMap::SetupShadowMap()
{
    glGenFramebuffers(1, &this->m_ShadowFBO);
    // - Create depth texture
    glGenTextures(1, &m_ShadowTexture);
    glBindTexture(GL_TEXTURE_2D, m_ShadowTexture);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT32F, this->m_SHADOW_WIDTH, this->m_SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
GLfloat borderColor[] = { 1.0, 1.0, 1.0, 1.0 };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    glBindFramebuffer(GL_FRAMEBUFFER, this->m_ShadowFBO);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_ShadowTexture, 0);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
            std::cout << "Framebuffer not complete!" << std::endl;

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glBindTexture(GL_TEXTURE_2D, 0);

}

void ShadowMap::SetupShadowMatrices()
{
        float quantizationStep = 1.0f / (float)this->m_SHADOW_WIDTH;

        m_lightProjection = glm::ortho(-65.0f, 65.0f, -65.0f, 65.0f, -20.0f, 80.0f + quantizationStep);// glm::perspective(glm::radians(90.0f), 16.0f / 9.0f, 0.5f, 100.0f);

        m_lightView = glm::lookAt(this->m_POSITION + quantizationStep, -this->m_DIRECTION + this->m_POSITION + quantizationStep, glm::vec3(1.0));
        //m_lightView = glm::lookAt(this->m_POSITION, this->m_POSITION + this->m_DIRECTION, glm::vec3(1.0));
        m_lightSpaceMatrix = m_lightProjection * m_lightView;
}
