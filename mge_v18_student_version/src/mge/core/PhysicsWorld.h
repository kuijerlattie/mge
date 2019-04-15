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
private:
	std::vector<AbstractCollider*> _colliders;
	bool AABBonAABB(AABBCollider* colliderA, AABBCollider* colliderB);
	bool AABBonOBB(AABBCollider* colliderA, OBBCollider* colliderB);
	bool OBBonOBB(OBBCollider* colliderA, OBBCollider* colliderB);

};

