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
