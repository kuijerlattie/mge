#include "OBBCollider.h"

OBBCollider::OBBCollider()
{

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
	return false;
}

bool OBBCollider::CheckCollision(OBBCollider* other)
{
	return false;
}

bool OBBCollider::CheckCollision(SphereCollider* other)
{
	return false;
}
