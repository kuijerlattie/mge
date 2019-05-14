#include "AABBCollider.h"



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
	return false;
}

bool AABBCollider::CheckCollision(OBBCollider* other)
{
	return false;
}

bool AABBCollider::CheckCollision(SphereCollider* other)
{
	return false;
}
