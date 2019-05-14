#include "PhysicsWorld.h"



PhysicsWorld::PhysicsWorld()
{
}


PhysicsWorld::~PhysicsWorld()
{
}

void PhysicsWorld::RegisterCollider(AbstractCollider* pCollider)
{
	_colliders.push_back(pCollider);
}

void PhysicsWorld::Tick()
{
	std::cout << "physicstick" << std::endl;
	for (int i = _colliders.size() - 1; i >= 0; i--)
	{
		for (int j = _colliders.size() - 1; j >= 0; j--)
		{
			if (_colliders[i]->CheckCollision(_colliders[j]))
			{
				//has collision;
			}
		}
	}
}

bool PhysicsWorld::AABBonAABB(AABBCollider* colliderA, AABBCollider* colliderB)
{
	return false;
}

bool PhysicsWorld::AABBonOBB(AABBCollider* colliderA, OBBCollider* colliderB)
{
	return false;
}

bool PhysicsWorld::OBBonOBB(OBBCollider* colliderA, OBBCollider* colliderB)
{
	glm::vec3 ACenter = colliderA->GetOwner()->getWorldPosition(); // object's pos = collider center
	//glm::mat4 oneTransform = glm::scale(one->getWorldTransform(), glm::vec3(0.2, 0.2, 0.2) /2);// one->_halfSize); // scaling for halfsize
	//glm::mat4 oneTransform = glm::scale(one->getWorldTransform(), glm::vec3(0.2, 0.2, 0.2) / 2);// one->_halfSize); // scaling for halfsize
	glm::mat4 ATransform = colliderA->GetOwner()->getWorldTransform();// one->_halfSize); // scaling for halfsize
	glm::vec3 BCenter = colliderB->GetOwner()->getWorldPosition();
	//glm::mat4 otherTransform = glm::scale(other->getWorldTransform(), glm::vec3(0.2, 0.2, 0.2) / 2);// other->_halfSize);
	glm::mat4 BTransform = colliderB->GetOwner()->getWorldTransform();// other->_halfSize);

	for (int a = 0; a < 3; a++) {
		glm::vec3 l = glm::vec3(ATransform[a]); // one axis to project on
		float tl = std::abs(glm::dot(l, BCenter) - glm::dot(l, ACenter)); // center distance
		float ra = std::abs(glm::dot(l, glm::vec3(ATransform[0]))) + std::abs(glm::dot(l, glm::vec3(ATransform[1]))) + std::abs(glm::dot(l, glm::vec3(ATransform[2])));
		float rb = std::abs(glm::dot(l, glm::vec3(BTransform[0]))) + std::abs(glm::dot(l, glm::vec3(BTransform[1]))) + std::abs(glm::dot(l, glm::vec3(BTransform[2])));
		float penetration = (ra + rb) - tl;

		if (penetration <= 0) { // no overlap
			//one->set(false); // for render
			//other->set(false);
			return false;
		}

	}
	for (int b = 0; b < 3; b++) {
		glm::vec3 l = glm::vec3(BTransform[b]); // other axis to project on
		float tl = std::abs(glm::dot(l, BCenter) - glm::dot(l, ACenter)); // center distance
		float ra = std::abs(glm::dot(l, glm::vec3(ATransform[0]))) + std::abs(glm::dot(l, glm::vec3(ATransform[1]))) + std::abs(glm::dot(l, glm::vec3(ATransform[2])));
		float rb = std::abs(glm::dot(l, glm::vec3(BTransform[0]))) + std::abs(glm::dot(l, glm::vec3(BTransform[1]))) + std::abs(glm::dot(l, glm::vec3(BTransform[2])));
		float penetration = (ra + rb) - tl;

		if (penetration <= 0) { // no overlap
			//one->set(false); // for render
			//other->set(false);
			return false;
		}
	}
	for (int a = 0; a < 3; a++) {
		glm::vec3 aAxis = glm::vec3(ATransform[a]);
		for (int b = 0; b < 3; b++) {
			glm::vec3 bAxis = glm::vec3(BTransform[b]);
			if (aAxis != bAxis) {
				glm::vec3 l = glm::cross(aAxis, bAxis); // has flaw when axis are same, result in (0,0,0), solved by if
				float tl = std::abs(glm::dot(l, BCenter) - glm::dot(l, ACenter)); // center distance
				float ra = std::abs(glm::dot(l, glm::vec3(ATransform[0]))) + std::abs(glm::dot(l, glm::vec3(ATransform[1]))) + std::abs(glm::dot(l, glm::vec3(ATransform[2])));
				float rb = std::abs(glm::dot(l, glm::vec3(BTransform[0]))) + std::abs(glm::dot(l, glm::vec3(BTransform[1]))) + std::abs(glm::dot(l, glm::vec3(BTransform[2])));
				float penetration = (ra + rb) - tl;

				if (penetration <= 0) { // no overlap
					//one->set(false); // for render
					//other->set(false);
					return false;
				}
			}
		}
	}
	return true;
}


