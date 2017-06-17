///========= Copyright Survtech, All rights reserved. ============//
///
/// Purpose:
///
///=============================================================================

#ifndef POSTPROCESS_H_INCLUDED
#define POSTPROCESS_H_INCLUDED

#include <GL/glew.h>
#include <Shader.h>
#include <camera.h>
#include <vector>
#include <ShadowMapping.h>
#include <memory>
#include <Texture.h>
#include <OpenGL/FrameBuffer.h>

class PostProcess
{
public:

    PostProcess();

    virtual ~PostProcess(){
        //std::cout << "Deleted PostProcess" << std::endl;
    }

public:

    /**
        Attaches the off-screen rendering buffer
    */
    void beginOffScreenrendering(void);

    /**
        Disattaches the off-screen rendering buffer
    */
    void endOffScreenRendering(void);

    /**
        Render the output from the G-Buffer
    */
    void ShowFrame(glm::vec3, bool & hdr, std::shared_ptr<Camera>& cam, float exposure, std::unique_ptr<ShadowMap>&);

    /**
        Calculates the screen space ambient occlusion
        from the geometry
    */
    void applySSAO(std::shared_ptr<Camera>& cam);

    /**
        Render the post process image to the screen
        after the post-process effects has been applied
    */
    void ShowPostProcessImage(float exposure, GLuint, glm::vec3 Sun, std::shared_ptr<Camera>& cam);

    GLuint getSceneTexture()
    {
        return hdrFBO->getRenderTargetHandler("colorBuffer");
    }

public:

    GLuint colorBuffer;
    GLuint depthBuffer;
    std::shared_ptr<FrameBuffer<std::string> > hdrFBO;
    std::unique_ptr<Shader> shader;

    float m_exposure;
private:

    /**
        loads the shaders used for render off-screen
        and post process affects
    */
    void LoadOffscreensShaders(void);

    /**
        Creates the framebuffer objects and attaches the proper textures
    */
    void SetupFramebuffer(void);

    /**
        Renders a quad that fills the screen
    */
    void RenderQuad(void);

    /**
        Lerp function to interpolate values
    */
    float lerp(float y1,float y2,float mu);

    /**
        Creates the GBuffer and attaches the proper textures
    */
    void SetupGBuffer(void);

    /**
        Creates the SSAO framebuffer and attaches the proper textures
    */
    void setupSSAO(void);

    /**
        Creates the SSR framebuffer and attaches the proper textures
    */
    void setupSSR(void);

    /**
        SSR
    */
    void SSRPass(std::shared_ptr<Camera>& cam);
    void setupDownSampledSSR();
    void DownSampleSSR(double);

    /**
        Blurs and image using a Gaussian Blur shader
    */
    GLuint blurImage(GLuint Buffer);

    /**
        Set up buffers for blurring
    */
    void SetupPingPongFBO(void);

    /**
        Set up buffers for blurring
    */
    void SetupPingPongDOF(void);

    /**
        gets the luminicense from a texture
    */
    GLfloat applyAutoAxposure(GLuint Buffer);

    void SetupMotionBlur();

    void MotionBlur(float);

    GLuint blurSSR(GLuint);
    void setupPingPongSSR();

    GLuint GetPixel(GLuint);

private:
    GLuint SSAOwidth;
    GLuint SSAOheight;
    GLuint MotionBlurBuffer;
    GLuint MotionBlurFBO;
    GLuint SSRFBO;
    GLuint SSRTexture;
    GLuint pingpongSSRFBO[2];
    GLuint pingpongSSRT[2];
    GLuint DownSamplerFBO;
    GLuint DownSampledTexture;
    GLuint SinglePixelColorBuffer;
    GLuint gExtraComponents;
    bool SSROn;
    bool m_MotionBlur;
    bool lightShafts;

    GLuint ssaoFBO;
    GLuint ssaoBlurFBO;
    GLuint rboDepth;
    GLuint rDepth;
    GLuint gDepth;
    GLuint quadVAO = 0;
    GLuint quadVBO;
    GLuint sampler;
    GLuint intermediateFBO;
    GLuint DepthTexture;
    GLuint lowresFBO;
    float lastDepth;
    GLuint lowresTex;
    GLuint pingpongFBO[2];
    GLuint pingpongColorbuffers[2];
    GLuint pingpongDOF[2];
    GLuint pingpongColorbuffersDOF[2];
    GLuint DOFBuffer;
    glm::vec3 Sun;
    std::vector<glm::vec3> ssaoNoise;
    GLenum attachment_type;
    int width, height;
    float exposureTime;
    std::unique_ptr<Shader> SSAO;
    std::unique_ptr<Shader> blurSSAO;
    std::unique_ptr<Shader> finalImage;
    std::unique_ptr<Shader> blurBloom;
    std::unique_ptr<Shader> ScreenSpaceReflectionShader;
    std::unique_ptr<Shader> blurSSRShader;
    std::unique_ptr<Shader> PassThroughShader;
    std::unique_ptr<Shader> MotionBlurShader;
    std::vector<glm::vec3> LightPositions;
    /// G-Buffer texture samplers
    std::vector<glm::vec3> ssaoKernel;
    GLuint noiseTexture;
    GLuint brightColorBuffer;
    GLuint gBuffer;
    GLuint gAlbedoSpec;
    GLuint gPosition;
    GLuint gNormal;
    GLuint gLowResDepth;
    GLuint gExpensiveNormal;
    GLuint ssaoColorBuffer;
    GLuint ssaoColorBufferBlur;
    GLuint gWorldSpacePosition;
    GLuint gLightAccumulation;
    std::shared_ptr<eTexture> lensColor;
    std::shared_ptr<eTexture> lensDirt;
    std::shared_ptr<eTexture> lensStar;

};

#endif // POSTPROCESS_H_INCLUDED
