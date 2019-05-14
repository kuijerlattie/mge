#pragma once
#include "mge/core/GameObject.hpp"

class AABBCollider;
class OBBCollider;
class SphereCollider;

class AbstractCollider
{
private:
	GameObject* _owner;

public:
	AbstractCollider();
	~AbstractCollider();

	virtual void SetOwner(GameObject* pGameObject);
	virtual GameObject* GetOwner();

	virtual bool CheckCollision(AbstractCollider* other);
	virtual bool CheckCollision(AABBCollider* other);
	virtual bool CheckCollision(OBBCollider* other);
	virtual bool CheckCollision(SphereCollider* other);

};

