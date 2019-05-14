#pragma once
#include "AbstractCollider.h"
class OBBCollider :
	public AbstractCollider
{
public:
	OBBCollider();
	~OBBCollider();
	bool CheckCollision(AbstractCollider* other) override;
	bool CheckCollision(AABBCollider* other) override;
	bool CheckCollision(OBBCollider* other) override;
	bool CheckCollision(SphereCollider* other) override;
};

