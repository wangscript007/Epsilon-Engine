#pragma once
#include <Physics/Physics.h>
#include <Physics/PhysicObject.h>

namespace Physics {

	class TriangleMeshPhysicObject : public PhysicObject {
		public:
			TriangleMeshPhysicObject() = default;
			virtual ~TriangleMeshPhysicObject() {}

		public:
			virtual std::shared_ptr<btRigidBody> addObject(std::vector<glm::vec3> /* Vertices */, std::vector<unsigned int> /* Indices */, glm::vec3 /* Position */,float /* Mass */) {
				return nullptr;
			}

			virtual std::shared_ptr<btRigidBody> addObject(std::vector<glm::vec3> /* Vertices */, std::vector<unsigned int> /* Indices */, float Scaling);

		private:

			float m_Mass = 0.0f;
			glm::vec3 m_Position = glm::vec3(0.0f, 0.0f, 0.0f);

			std::shared_ptr<btMotionState> motionState;
			std::shared_ptr<btCollisionShape> TriangleMeshShape;
			std::shared_ptr<btTriangleMesh> trimesh;

		private:
			virtual std::shared_ptr<btRigidBody> addObject(float /* Radius */, float /* Mass */) {
				return nullptr;
			}
			virtual std::shared_ptr<btRigidBody> addObject(glm::vec3 /* Position */, float /* Mass */, float /* Size */) {
				return nullptr;
			}
			virtual std::shared_ptr<btRigidBody> addObject(glm::vec3 /* Position */, float /* Mass */, MIN_MAX_POINTS /* Bounding Box */, float /* Scale*/) {
				return nullptr;
			}
			virtual std::shared_ptr<btRigidBody> addObject(float /* Position X */, float /* Position Y */, float /* Position Z */, float /* Mass */, float /* Size*/) {
				return nullptr;
			}
	};
}
