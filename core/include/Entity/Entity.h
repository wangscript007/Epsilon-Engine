#pragma once

#include <Component.h>
#include <iostream>
#include <glm/glm.hpp>
#include <typeinfo>
#include <memory>
#include <ResourceManager.h>
#include <Physics/CollisionInfo.h>

class EntityTemplate
{

    using Component_ptr = std::shared_ptr<Component::Component>;

public:
    EntityTemplate(std::shared_ptr<ResourceManager> rm, glm::vec3 pos, glm::vec3 sc, glm::quat rot);

    void addComponent(Component_ptr t)
    {
        switch (t->Type)
        {
        case Component::MODELCOMPONENT:
            mHasModel = true;
            break;
        case Component::PHYSICCOMPONENT:
        {
            mHasPhysicComponent = true;
            m_Position = glm::vec3(t->m_PhysicsWorldPosition.getX(), t->m_PhysicsWorldPosition.getY(), t->m_PhysicsWorldPosition.getZ());
            m_PrevPosition = m_Position;
            break;
        }
        case Component::PLAYERCOMPONENT:
            mHasPlayerComponent = true;
            break;
        case Component::CLOTHCOMPONENT:
            mHasClothComponent = true;
            break;
        case Component::MOVEMENTCOMPONENT:
            mHasMovementComponent = true;
            break;
        default: 
            std::cout << " not added component" << std::endl;
            break;
        }

        ComponentList.push_back(std::move(t));
        this->ID = ComponentList.size();

        CollInfo.setName("Entity_" + std::string(Helpers::to_hex(toHash())));
    }

    void Update();
    void Render();

    void RenderShadows()
    {
        for (unsigned int i = 0; i < ComponentList.size(); ++i)
            ComponentList.at(i)->RenderShadows();
    }

private:
    bool mHasPlayerComponent = false;
    bool mHasModel = false;
    bool mHasPhysicComponent = false;
    bool mHasClothComponent = false;
    bool mHasMovementComponent = false;
    int mID;
    std::string modelPath;
    std::unordered_map<uint8_t, Component_ptr> ComponentList;

public:
    glm::vec3 getPosition()
    {
        if (hasPhysicComponent)
        {
            for (unsigned int i = 0; i < ComponentList.size(); ++i)
            {
                if (ComponentList.at(i)->Type == Component::PHYSICCOMPONENT)
                {
                    btVector3 v3 = ComponentList.at(i)->m_PhysicsWorldPosition;
                    return glm::vec3(v3.getX(), v3.getY(), v3.getZ());
                }
                continue;
            }
        }
        else
        {
            return m_Position;
        }
    }

    glm::vec3 getPrevPosition()
    {
        if (hasPhysicComponent)
        {
            for (unsigned int i = 0; i < ComponentList.size(); ++i)
            {
                if (ComponentList.at(i)->Type == Component::PHYSICCOMPONENT)
                {
                    btVector3 v3 = ComponentList.at(i)->m_LastPhysicsWorldPosition;
                    return glm::vec3(v3.getX(), v3.getY(), v3.getZ());
                }
                continue;
            }
        }
        else
        {
            return m_Position;
        }
    }

    glm::vec3 getScale()
    {
        return m_Scale;
    }

    glm::vec3 getPrevScale()
    {
        return m_PrevScale;
    }

    glm::quat getRotation()
    {
        if (hasPhysicComponent)
        {
            for (unsigned int i = 0; i < ComponentList.size(); ++i)
            {
                if (ComponentList.at(i)->Type == Component::PHYSICCOMPONENT)
                {

                    btQuaternion q = ComponentList.at(i)->m_PhysicsWorldRotation;
                    return glm::quat(q.getW(), q.getX(), q.getY(), q.getZ());
                }
                continue;
            }
        }
        else
            return m_Rotation;
    }

    glm::quat getPrevRotation()
    {
        if (hasPhysicComponent)
        {
            for (unsigned int i = 0; i < ComponentList.size(); ++i)
            {
                if (ComponentList.at(i)->Type == Component::PHYSICCOMPONENT)
                {
                    btQuaternion q = ComponentList.at(i)->m_LastPhysicsWorldRotation;
                    return glm::quat(q.getW(), q.getX(), q.getY(), q.getZ());
                }
                continue;
            }
        }
        else
        {
            return m_PrevRotation;
        }
    }

    MIN_MAX_POINTS getBoundingBox()
    {

        if (this->hasModel)
        {
            return resourceManager->getModelBoundingBox(modelPath);
        }
        else if (this->hasClothComponent)
        {
            for (unsigned int i = 0; i < ComponentList.size(); ++i)
            {
                if (ComponentList.at(i)->Type == Component::CLOTHCOMPONENT)
                {
                    btSoftBody *cloth = std::static_pointer_cast<Physics::ClothPhysicObject>(std::static_pointer_cast<Component::ClothComponent>(ComponentList[i])->RigidBodyPointer)->m_BodyCloth.get();

                    btVector3 aabbMin, aabbMax;
                    cloth->getAabb(aabbMin, aabbMax);

                    MIN_MAX_POINTS BB;
                    BB.MAX_X = aabbMax.x();
                    BB.MAX_Y = aabbMax.y();
                    BB.MAX_Z = aabbMax.z();
                    BB.MIN_X = aabbMin.x();
                    BB.MIN_Y = aabbMin.y();
                    BB.MIN_Z = aabbMin.z();

                    return BB;
                }
                continue;
            }
        }
        /*
        BB.MIN_X *= this->getScale().x; BB.MAX_X *= this->getScale().x;
        BB.MIN_Y *= this->getScale().y; BB.MAX_Y *= this->getScale().y;
        BB.MIN_Z *= this->getScale().z; BB.MAX_Z *= this->getScale().z;*/
    }

    long toHash()
    {
        return std::hash<float>{}(m_Position.x + m_Position.y + m_Position.z + ID);
    }

    void setShader(std::string sh)
    {
        if (hasModel)
        {
            for (auto &c : ComponentList)
            {
                if (c->Type == Component::MODELCOMPONENT)
                {
                    (std::static_pointer_cast<Component::RenderComponent>(c))->setShader(sh);
                }
                continue;
            }
        }
    }

private:
    glm::vec3 m_Position;
    glm::vec3 m_Scale;
    glm::quat m_Rotation;

    glm::vec3 m_PrevPosition;
    glm::vec3 m_PrevScale;
    glm::quat m_PrevRotation;

    std::shared_ptr<ResourceManager> resourceManager;

protected:
};
