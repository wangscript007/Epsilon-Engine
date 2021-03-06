#pragma once

#include <pch.hpp>
#include <glm/glm.hpp>
#include <EpsilonMemory.h>
#include <Types.h>

#include <btBulletDynamicsCommon.h>
#include <BulletSoftBody/btSoftBodyRigidBodyCollisionConfiguration.h>
#include <btBulletCollisionCommon.h>

#include <BulletCollision/CollisionDispatch/btGhostObject.h>
#include <BulletDynamics/Character/btKinematicCharacterController.h>
#include <BulletDynamics/Featherstone/btMultiBodyDynamicsWorld.h>
#include <BulletSoftBody/btSoftRigidDynamicsWorld.h>
#include <BulletDynamics/Featherstone/btMultiBodyConstraintSolver.h>
#include <LinearMath/btTransform.h>
#include <BulletSoftBody/btSoftBodyHelpers.h>

namespace Epsilon
{
	namespace Physics
	{
		class CollisionInfo;

		using btRigidBody_ptr = std::shared_ptr<btRigidBody>;

		class Physics
		{
		public:
			Physics();

			~Physics()
			{
			}

			void Update(float);

			std::shared_ptr<btSoftRigidDynamicsWorld> getSoftDynamicsWorld();

			std::string getCollisionObjectName(btVector3 rayPosition, btVector3 rayTarget);
			glm::vec3 getCollisionPosition(btVector3 rayPosition, btVector3 rayTarget);

			std::shared_ptr<btBroadphaseInterface> broadphase;
			std::shared_ptr<btSoftBodyWorldInfo> softBodyWorldInfo;

			double getTimeStep() { return mTimeStep; }

		private:
			std::shared_ptr<btCollisionWorld> world;
			std::shared_ptr<btDispatcher> dispatcher;
			std::shared_ptr<btCollisionConfiguration> collisionConfig;
			std::shared_ptr<btConstraintSolver> solver;

			double mTimeStep = 0.0;

		protected:
		};
	} // namespace Physics
} // namespace Epsilon
