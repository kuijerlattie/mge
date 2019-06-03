#include "AABBCollider.h"
#include "mge/core/PhysicsWorld.h"


AABBCollider::AABBCollider()
{
}


AABBCollider::~AABBCollider()
{
}

bool AABBCollider::CheckCollision(AbstractCollider* other)
{
	return other->CheckCollision(this);
}

bool AABBCollider::CheckCollision(AABBCollider* other)
{
	return PhysicsWorld::AABBonAABB(this, other);
}

bool AABBCollider::CheckCollision(OBBCollider* other)
{
	return PhysicsWorld::AABBonOBB(this, other);
}

bool AABBCollider::CheckCollision(SphereCollider* other)
{
	return false;
}
