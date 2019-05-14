#include "SphereCollider.h"

SphereCollider::SphereCollider()
{
}

SphereCollider::~SphereCollider()
{
}

bool SphereCollider::CheckCollision(AbstractCollider* other)
{
	return other->CheckCollision(this);
}

bool SphereCollider::CheckCollision(AABBCollider* other)
{
	return false;
}

bool SphereCollider::CheckCollision(OBBCollider* other)
{
	return false;
}

bool SphereCollider::CheckCollision(SphereCollider* other)
{
	return false;
}
