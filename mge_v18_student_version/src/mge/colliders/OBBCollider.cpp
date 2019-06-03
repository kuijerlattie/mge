#include "OBBCollider.h"
#include "mge/core/PhysicsWorld.h"

OBBCollider::OBBCollider(bool bisStatic = false)
{
	isStatic = bisStatic;
}

OBBCollider::~OBBCollider()
{

}

bool OBBCollider::CheckCollision(AbstractCollider* other)
{
	return other->CheckCollision(this);
}

bool OBBCollider::CheckCollision(AABBCollider* other)
{
	return PhysicsWorld::AABBonOBB(other, this);
}

bool OBBCollider::CheckCollision(OBBCollider* other)
{
	return PhysicsWorld::OBBonOBB(this, other);
}

bool OBBCollider::CheckCollision(SphereCollider* other)
{
	return false;
}
