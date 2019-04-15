#pragma once
#include "mge/core/GameObject.hpp"
class AbstractCollider
{
private:
	GameObject* _owner;

public:
	AbstractCollider();
	~AbstractCollider();

	virtual void SetOwner(GameObject* pGameObject);

	int type;

};

