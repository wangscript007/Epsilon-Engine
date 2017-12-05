#pragma once
#include <Types.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <ParticleRenderer.h>
#include <random>
#include <Types.h>
#include <chrono>
#include <Texture.h>
#include <atomic>
#include <thread>
#include <omp.h>

class ParticleProxy {
public:
    ParticleProxy(unsigned int id, MINMAX_POINTS limits, double numparts) : ID(id), ParticlesLimits(limits), m_NumParticles(numparts) {}

    virtual ~ParticleProxy() {}

    virtual void Simulate(float, glm::vec3) {
    }

    virtual void Render() {}

    double m_NumParticles;
    std::vector<glm::mat4> m_ParticlePositions;
    GLuint quadVAO, quadVBO;
    std::shared_ptr<ParticleRenderer> m_ParticleRenderer;

private:
protected:

    std::random_device rd;
    std::default_random_engine generator;
    MINMAX_POINTS ParticlesLimits;
    unsigned int ID;
    //std::vector<Particle> Particles;

protected:

    glm::vec3 GenerateRandomParticle() {

        std::uniform_real_distribution<GLfloat> HorizonalLimit(ParticlesLimits.MIN_X, ParticlesLimits.MAX_X);
        std::uniform_real_distribution<GLfloat> VerticalLimit(ParticlesLimits.MIN_Y, ParticlesLimits.MAX_Y);
        std::uniform_real_distribution<GLfloat> ZLimit(ParticlesLimits.MIN_Z, ParticlesLimits.MAX_Z);
        generator.seed(std::chrono::system_clock::now().time_since_epoch().count());

        return glm::vec3(
                   HorizonalLimit  (generator),
                   VerticalLimit   (generator),
                   ZLimit          (generator)
               );
    }

    virtual void InitializeProxy() {
    }
};

class MistParticleProxy : public ParticleProxy {

public:
    MistParticleProxy(unsigned int id, MINMAX_POINTS limits, double numparts) : ParticleProxy(id, limits, numparts) {

        ID = id;
        ParticlesLimits = limits;
        m_NumParticles = numparts;

        InitializeProxy();

        m_ParticleRenderer = (std::shared_ptr<ParticleRenderer>) new ParticleRenderer(ID, m_NumParticles, m_ParticlePositions);
    }

    virtual ~MistParticleProxy() {}

    void Simulate() {}

    virtual void Render() {
        m_ParticleRenderer->UpdateParticleRenderer(m_ParticlePositions);

        m_ParticleRenderer->Render();
    }
};

class SmokeParticleProxy : public ParticleProxy {
public:
    SmokeParticleProxy(unsigned int id, MINMAX_POINTS limits, double numparts) : ParticleProxy(id, limits, numparts) {
        ID = id;
        ParticlesLimits = limits;
        m_NumParticles = numparts;

        InitializeProxy();

        m_ParticleRenderer = (std::shared_ptr<ParticleRenderer>) new ParticleRenderer(ID, m_NumParticles, m_ParticlePositions);
    }

    virtual ~SmokeParticleProxy() {}

    std::vector<Particle> Particles;

    void Simulate(float deltaTime, glm::vec3 camPos) {

        deltaTime = glm::clamp(deltaTime, 0.0f, 0.064f);

        this->calculateDistancetoCamera(camPos);

        this->sortParticles();

        #pragma omp simd
        for(unsigned int i = 0; i < Particles.size(); i++) {

            if(Particles[i].getPosition().y > ParticlesLimits.MAX_X) {
                //cout  << deltaTime << endl;
                Particles[i].setLife(-1.0);
            }
            if(Particles[i].getLife() < 0.0) {
                Particles[i].resetPosition();
                Particles[i].resetLife();
            }

            Particles[i].setSpeed(glm::vec3(0.0, 9.81, 0.0));
            Particles[i].m_Position.y = Particles[i].m_Position.y + 9.81 * deltaTime;

            Particles[i].setLife(Particles[i].getLife() - deltaTime);

        }

        for(int i = 0; i < m_NumParticles; i++) {
            glm::mat4 modelPos = glm::mat4();
            modelPos = translate(modelPos, Particles[i].getPosition());
            m_ParticlePositions[i] = modelPos;
        }
    }

    void calculateDistancetoCamera(glm::vec3 camPosition) {
        for(auto &p: Particles) {
            p.setDistancetoCamera(glm::length(p.getPosition() - camPosition));
        }
    }

    void sortParticles() {
        std::sort(Particles.begin(), Particles.end());
    }

    void InitializeProxy() {

        std::uniform_real_distribution<GLfloat> HorizonalLimit(ParticlesLimits.MIN_X, ParticlesLimits.MAX_X);
        std::uniform_real_distribution<GLfloat> VerticalLimit(ParticlesLimits.MIN_Y, ParticlesLimits.MAX_Y);
        std::uniform_real_distribution<GLfloat> ZLimit(ParticlesLimits.MIN_Z, ParticlesLimits.MAX_Z);


        std::uniform_real_distribution<GLfloat> xDir(0.5, 1.0);
        std::uniform_real_distribution<GLfloat> yDir(0.0, 1.0);
        std::uniform_real_distribution<GLfloat> zDir(0.5, 1.0);

        generator.seed(std::chrono::system_clock::now().time_since_epoch().count());

        //#pragma omp simd
        for(unsigned int i = 0; i < m_NumParticles; ++i) {

            glm::vec3 CurrentParticlePosition(
                HorizonalLimit  (generator),
                ParticlesLimits.MIN_Y,
                ZLimit          (generator)
            );

            glm::vec3 CurrentParticleDirection(
                xDir(generator),
                yDir(generator),
                zDir(generator)
            );

            Particles.push_back(Particle(CurrentParticlePosition, 1.0, 50.0, ParticlesLimits));
            Particles.back().m_Direction = CurrentParticleDirection;
            //std::cout << "Particle #" << i << ": X: " << Particles[i].getPosition().x << " Y: " << Particles[i].getPosition().y << " Z: " << Particles[i].getPosition().z << std::endl;
        }

        for(auto &p: Particles) {
            glm::mat4 modelPos = glm::mat4();
            modelPos = translate(modelPos, p.getPosition());
            m_ParticlePositions.push_back(modelPos);
        }
    }

    virtual void Render() {
        m_ParticleRenderer->UpdateParticleRenderer(m_ParticlePositions);

        m_ParticleRenderer->Render();
    }
};

class RainParticleProxy : public ParticleProxy {
public:
    RainParticleProxy(unsigned int id, MINMAX_POINTS limits, double numparts) : ParticleProxy(id, limits, numparts) {

        ID = id;
        ParticlesLimits = limits;
        m_NumParticles = numparts;

        InitializeProxy();

        m_ParticleRenderer = (std::shared_ptr<ParticleRenderer>) new ParticleRenderer(ID, m_NumParticles, m_ParticlePositions);

    }

    void calculateDistancetoCamera(glm::vec3 camPosition) {

        //#pragma omp simd
        for(auto &p: Particles) {
            p.setDistancetoCamera(glm::length(p.getPosition() - camPosition));
        }
    }

    void sortParticles() {
        std::sort(Particles.begin(), Particles.end());
    }

    std::vector<Particle> Particles;

    void InitializeProxy() {

        std::uniform_real_distribution<GLfloat> HorizonalLimit(ParticlesLimits.MIN_X, ParticlesLimits.MAX_X);
        std::uniform_real_distribution<GLfloat> VerticalLimit(ParticlesLimits.MIN_Y, ParticlesLimits.MAX_Y);
        std::uniform_real_distribution<GLfloat> ZLimit(ParticlesLimits.MIN_Z, ParticlesLimits.MAX_Z);
        generator.seed(std::chrono::system_clock::now().time_since_epoch().count());

        //#pragma omp simd
        for(unsigned int i = 0; i < m_NumParticles; ++i) {

            glm::vec3 CurrentParticlePosition(
                HorizonalLimit  (generator),
                VerticalLimit   (generator),
                ZLimit          (generator)
            );

<<<<<<< HEAD
            Particles.push_back(Particle(CurrentParticlePosition, 1.0, 50.0, ParticlesLimits));

=======
            Particles.push_back(Particle(CurrentParticlePosition, 1.0, 0.5, ParticlesLimits));
            //std::cout << "Particle #" << i << ": X: " << Particles[i].getPosition().x << " Y: " << Particles[i].getPosition().y << " Z: " << Particles[i].getPosition().z << std::endl;
>>>>>>> 8928179c2403e3f904d84e0da64b9c95b44f0d03
        }

        for(auto &p: Particles) {
            glm::mat4 modelPos = glm::mat4();
            modelPos = translate(modelPos, p.getPosition());
            m_ParticlePositions.push_back(modelPos);
        }
    }

    virtual ~RainParticleProxy() {}

    void Simulate(float deltaTime, glm::vec3 camPos) {

        deltaTime = glm::clamp(deltaTime, 0.0f, 0.064f);

        this->calculateDistancetoCamera(camPos);

        this->sortParticles();

        // std::vector<std::thread> th;

        //#pragma omp
        // for(int t = 0; t < 8; t++)
        // {   th.emplace_back([&]()
        // {
        #pragma omp simd
        for(unsigned int i = 0; i < Particles.size(); i++) {

            if(Particles[i].getPosition().y < ParticlesLimits.MIN_Y) {
                //cout  << deltaTime << endl;
                Particles[i].setLife(-1.0);
            }
            if(Particles[i].getLife() <= 0.0) {
                Particles[i].resetPosition();
                Particles[i].resetLife();
            }

            Particles[i].setSpeed(glm::vec3(0.0, -9.81, 0.0));
            Particles[i].m_Position.y = Particles[i].m_Position.y + -9.81 * deltaTime;

            Particles[i].setLife(Particles[i].getLife() - deltaTime);

        }

        for(int i = 0; i < m_NumParticles; i++) {
            glm::mat4 modelPos = glm::mat4();
            modelPos = translate(modelPos, Particles[i].getPosition());
            m_ParticlePositions[i] = modelPos;
        }
    }

    virtual void Render() {
        m_ParticleRenderer->UpdateParticleRenderer(m_ParticlePositions);

        m_ParticleRenderer->Render();
    }

};

class SnowParticleProxy : public ParticleProxy {
public:
    SnowParticleProxy(unsigned int id, MINMAX_POINTS limits, double numparts) : ParticleProxy(id, limits, numparts) {

        ID = id;
        ParticlesLimits = limits;
        m_NumParticles = numparts;

        InitializeProxy();

        m_ParticleRenderer = (std::shared_ptr<ParticleRenderer>) new ParticleRenderer(ID, m_NumParticles, m_ParticlePositions);
    }

    virtual ~SnowParticleProxy() {}

    void sortParticles() {
        std::sort(Particles.begin(), Particles.end());
    }

    void calculateDistancetoCamera(glm::vec3 camPosition) {
        //#pragma omp simd
        for(auto &p: Particles) {
            p.setDistancetoCamera(glm::length(p.getPosition() - camPosition));
        }
    }

    std::vector<Particle> Particles;

    void Simulate(float deltaTime, glm::vec3 camPos) {

        deltaTime = glm::clamp(deltaTime, 0.0f, 0.064f);

        this->calculateDistancetoCamera(camPos);

        this->sortParticles();
        #pragma omp simd
        for(unsigned int i = 0; i < Particles.size(); i++) {

            if(Particles[i].getPosition().y < ParticlesLimits.MIN_Y) {
                Particles[i].setLife(-1.0);
            }
            if(Particles[i].getLife() < 0.0) {
                Particles[i].resetPosition();
                Particles[i].resetLife();
            }

            Particles[i].setSpeed(glm::vec3(0.0, -9.81, 0.0));
            Particles[i].m_Position.y = Particles[i].m_Position.y + -2.81 * deltaTime;
            Particles[i].m_Position.x += glm::sin(Particles[i].m_Position.y) * deltaTime;
            Particles[i].m_Position.z += glm::cos(Particles[i].m_Position.y) * deltaTime * 2.0;
            //glm::vec3 pos = glm::vec3(Particles[i].m_Position.x, Particles[i].m_Position.y, Particles[i].m_Position.z);
            //Particles[i].m_Position += FractionalBrownianMotion(pos) * glm::vec3(1.0f,deltaTime, 1.0f);

            Particles[i].setLife(Particles[i].getLife() - deltaTime);

        }

        #pragma omp simd
        for(int i = 0; i < Particles.size(); i++) {
            glm::mat4 modelPos = glm::mat4();
            modelPos = translate(modelPos, Particles[i].getPosition());
            m_ParticlePositions[i] = modelPos;
        }
    }

    glm::vec3 FractionalBrownianMotion(glm::vec3 q) {

        auto hash = [](glm::vec3 p3) -> glm::vec3 {
            p3 = glm::fract(p3 + glm::vec3(0.3, 0.1, 0.1));
            p3+= glm::dot(p3, glm::vec3(p3.y, p3.x, p3.z)+glm::vec3(19.19));
            return glm::fract((glm::vec3(p3.x, p3.x, p3.y) + glm::vec3(p3.y, p3.x, p3.x))*glm::vec3(p3.z, p3.y, p3.x));
        };

        auto noise = [&]( glm::vec3 x ) -> glm::vec3 {
            glm::vec3 p = glm::floor(x);
            glm::vec3 f = glm::fract(x);
            f = f*f*(3.0f-2.0f*f);

            return glm::mix(glm::mix(glm::mix( hash(p+glm::vec3(0,0,0)),
            hash(p+glm::vec3(1,0,0)),f.x),
            glm::mix( hash(p+glm::vec3(0,1,0)),
            hash(p+glm::vec3(1,1,0)),f.x),f.y),
            glm::mix(glm::mix( hash(p+glm::vec3(0,0,1)),
            hash(p+glm::vec3(1,0,1)),f.x),
            glm::mix( hash(p+glm::vec3(0,1,1)),
            hash(p+glm::vec3(1,1,1)),f.x),f.y),f.z);
        };

        const glm::mat3 m = glm::mat3(   0.00,  0.80,  0.60,
                                         -0.80,  0.36, -0.48,
                                         -0.60, -0.48,  0.64 );

        glm::vec3    f  = 0.5000f*noise( q );
        q = m*q*2.01f;
        f += 0.2500f*noise( q );
        q = m*q*2.02f;
        f += 0.1250f*noise( q );
        q = m*q*2.03f;
        f += 0.0625f*noise( q );
        q = m*q*2.04f;
        f += 0.03125f*noise( q );
        q = m*q*2.05f;
        f += 0.015625f*noise( q );
        q = m*q*2.06f;
        return glm::vec3(f);

    }


    void InitializeProxy() {

        std::uniform_real_distribution<GLfloat> HorizonalLimit(ParticlesLimits.MIN_X, ParticlesLimits.MAX_X);
        std::uniform_real_distribution<GLfloat> VerticalLimit(ParticlesLimits.MIN_Y, ParticlesLimits.MAX_Y);
        std::uniform_real_distribution<GLfloat> ZLimit(ParticlesLimits.MIN_Z, ParticlesLimits.MAX_Z);
        generator.seed(std::chrono::system_clock::now().time_since_epoch().count());

        //#pragma omp simd
        for(int i = 0; i < m_NumParticles; i++) {

            glm::vec3 CurrentParticlePosition(
                HorizonalLimit  (generator),
                VerticalLimit   (generator),
                ZLimit          (generator)
            );

            Particles.push_back(Particle(CurrentParticlePosition, 1.0, 5000.0, ParticlesLimits));
        }

        for(auto &p: Particles) {
            glm::mat4 modelPos = glm::mat4();
            modelPos = translate(modelPos, p.getPosition());
            m_ParticlePositions.push_back(modelPos);
        }
    }

    virtual void Render() {
        m_ParticleRenderer->UpdateParticleRenderer(m_ParticlePositions);

        m_ParticleRenderer->Render();
    }
};
