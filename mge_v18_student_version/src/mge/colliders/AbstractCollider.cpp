#include "AbstractCollider.h"


AbstractCollider::AbstractCollider()
{
}


AbstractCollider::~AbstractCollider()
{
}

void AbstractCollider::SetOwner(GameObject * pGameObject)
{
	_owner = pGameObject;
}

GameObject* AbstractCollider::GetOwner()
{
	return _owner;
}

bool AbstractCollider::CheckCollision(AbstractCollider* other) { return other->CheckCollision(this); }
bool AbstractCollider::CheckCollision(AABBCollider* other) { return false; }
bool AbstractCollider::CheckCollision(OBBCollider* other) { return false; }
bool AbstractCollider::CheckCollision(SphereCollider* other) { return false; }
