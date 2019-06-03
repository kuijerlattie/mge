#pragma once
#include <vector>
#include "mge/colliders/AbstractCollider.h"
#include "mge/colliders/AABBCollider.h"
#include "mge/colliders/OBBCollider.h"

class PhysicsWorld
{
public:
	PhysicsWorld();
	~PhysicsWorld();

	void RegisterCollider(AbstractCollider* pCollider);
	void Tick();
	static bool AABBonAABB(AABBCollider* colliderA, AABBCollider* colliderB);
	static bool AABBonOBB(AABBCollider* colliderA, OBBCollider* colliderB);
	static bool OBBonOBB(OBBCollider* colliderA, OBBCollider* colliderB);
private:
	std::vector<AbstractCollider*> _colliders;

};

