#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <pch.hpp>
#include <Texture.h>
#include <Renderer/Model.h>
#include <Water.hpp>
#include <Renderer/Terrain.h>
#include <Grass.h>
#include <Shader.h>
#include <CubeMap.h>
#include <Helpers.hpp>
#include <Physics/Physics.h>
#include <Audio/Audio.h>
namespace Epsilon
{
    class ResourceManager
    {
    public:
        ResourceManager(const ResourceManager &) = delete;

        static ResourceManager &Get()
        {
            return instance;
        }

        virtual ~ResourceManager()
        {
            Destroy();
        }

        void Destroy()
        {
            for (std::map<std::string, std::shared_ptr<eTexture>>::iterator itr = TextureList.begin(); itr != TextureList.end(); itr++)
            {
                //GLuint tex = itr->second->getTextureID();
                itr->second->Destroy();
            }

            for (std::map<std::string, Model>::iterator itr = ModelList.begin(); itr != ModelList.end(); itr++)
            {
                itr->second.Destroy();
            }
            
            std::cout << "Deleted Resource Manager" << std::endl;
        }

        std::string requestTexture(const std::string& texPath);

        std::string requestModel(const std::string& modelPath, glm::vec3 Pos, glm::vec3 scs, glm::quat rot);

        void useModel(const std::string& modelPath, std::shared_ptr<Shader> shader, glm::vec3);

        void useModel(const std::string& modelPath, GLuint shader, glm::vec3);

        MIN_MAX_POINTS getModelBoundingBox(const std::string& modelPath);

        void setModelVisibility(const std::string& path, bool visibility);

        glm::quat getModelRotation(const std::string& path);

        glm::vec3 getModelPosition(const std::string& path);

        glm::vec3 getModelScale(const std::string& path);

        //void setModelUniforms(const std::string&, std::shared_ptr<Shader>, glm::vec3, glm::vec3, glm::quat, std::shared_ptr<Camera>);

        void setModelUniforms(const std::string& path, std::shared_ptr<Shader> shader, glm::vec3, glm::vec3, glm::quat, glm::vec3, glm::vec3, glm::quat, std::shared_ptr<Camera> cam);

        void destroyAllModels();

        GLuint useTexture(const std::string& texPath);

        void bindTexture(const std::string& texPath);

        void addTextureToQueue(const std::string& texture);

        void loadQueuedTextures();

        std::string requestShader(const std::string& shaderPathv, const std::string& shaderPathf, const std::string& name);

        void destroyAllTextures();

        std::shared_ptr<Shader> useShader(const std::string& shaderPath);

        GLuint getShaderID(const std::string& shaderPath);

        std::shared_ptr<Shader> getShader(const std::string& shaderPath);

        bool requestCubeMap(int CubeMapID, glm::vec3 Position);

        int NearestCubeMap(glm::vec3 TestingPoint);

        GLuint useCubeMap(int ID);

        int requestTextureUsage(const std::string&);

        void resetTextureUsage(const std::string&);

        bool addCubemap(std::shared_ptr<CubeMap>, glm::vec3);

        Model getModel(const std::string& modelPath);

        std::shared_ptr<Physics::Physics> getPhysicsWorld()
        {
            return m_PhysicsWorld;
        }

        uint32_t getNearestCubemapIndex(glm::vec3 pos)
        {
            return mCubemapIndex.at(NearestCubeMap(pos));
        }

        uint32_t getNumCubemaps() {
            return mCubemapIndex.size();
        }

        float timestep;

        bool cubemapsLoaded = false;
    private:
        ResourceManager()
        {
            m_PhysicsWorld = std::make_shared<Physics::Physics>();
        }

        static ResourceManager instance;

        std::shared_ptr<Physics::Physics> m_PhysicsWorld;

        std::shared_ptr<IO::Audio::Audio> m_AudioSystem;

        std::map<int, std::shared_ptr<CubeMap>> CubeMapList;

        std::vector<int> mCubemapIndex;

        std::map<std::string, std::shared_ptr<eTexture>> TextureList;
        std::map<std::string, Water> WaterPlanesList;
        std::map<std::string, Terrain> TerrainList;
        std::map<std::string, Model> ModelList;
        std::map<std::string, std::shared_ptr<Shader>> ShadersList;
        std::vector<glm::vec3> CubeMapPositions;

        /*!
    Temp Variables
    */
        std::vector<std::string> TextureQueue;

        unsigned int modelCounter;
        unsigned int textureCounter;
    };
} // namespace Epsilon
#endif // RESOURCEMANAGER_H
