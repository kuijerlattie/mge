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
	for (int i = _colliders.size - 1; i >= 0; i--)
	{
		for (int j = _colliders.size - 1; j >= 0; j--)
		{
			switch (_colliders[i]->type)
			{
			case 1:
				//aabb
				break;
			case 2:
				//obb
				break;
			default:
				break;
			}
		}
	}
}

bool PhysicsWorld::AABBonAABB(AABBCollider* colliderA, AABBCollider* colliderB)
{

}

bool PhysicsWorld::AABBonOBB(AABBCollider* colliderA, OBBCollider* colliderB)
{

}

bool PhysicsWorld::OBBonOBB(OBBCollider* colliderA, OBBCollider* colliderB)
{

}


