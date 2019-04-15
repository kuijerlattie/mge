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

}
