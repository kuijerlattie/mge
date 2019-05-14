#pragma once
#include "AbstractCollider.h"
class AABBCollider :
	public AbstractCollider
{
public:
	AABBCollider();
	~AABBCollider();
	bool CheckCollision(AbstractCollider* other) override;
	bool CheckCollision(AABBCollider* other) override;
	bool CheckCollision(OBBCollider* other) override;
	bool CheckCollision(SphereCollider* other) override;
};

