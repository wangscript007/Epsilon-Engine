#pragma once
#include <Physics/Physics.h>
#include <Physics/PhysicObject.h>

namespace Epsilon
{
	namespace Physics
	{

		class CubePhysicObject : public PhysicObject
		{
		public:
			CubePhysicObject() = default;
			virtual ~CubePhysicObject() {}

		public:
			virtual btRigidBody_ptr addObject(float /* Position X */, float /* Position Y */, float /* Position Z */, float /* Mass */, float /* Size*/)
			{
				return nullptr;
			}

			virtual btRigidBody_ptr addObject(glm::vec3 /* Position */, float /* Mass */, MIN_MAX_POINTS /* Bounding Box */, glm::vec3 /* Scale*/);

		private:
			float m_Size = 1.0f;
			float m_Mass = 0.0f;
			glm::vec3 m_Position = glm::vec3(0.0f, 0.0f, 0.0f);

			std::shared_ptr<btBoxShape> CubeShape;
			std::shared_ptr<btMotionState> motionState;
			std::shared_ptr<btCompoundShape> m_ColShape;

			virtual btRigidBody_ptr addObject(float /* Radius */, float /* Mass */)
			{
				return nullptr;
			}
			virtual btRigidBody_ptr addObject(std::vector<glm::vec3> /* Vertices */, std::vector<unsigned int> /* Indices */, float)
			{
				return nullptr;
			}
			virtual btRigidBody_ptr addObject(glm::vec3 /* Position */, float /* Mass */, float /* Size */)
			{
				return nullptr;
			}
		};
	} // namespace Physics
} // namespace Epsilon
