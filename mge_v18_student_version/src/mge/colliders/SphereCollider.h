#pragma once
#include "AbstractCollider.h"
class SphereCollider :
	public AbstractCollider
{
public:
	SphereCollider();
	~SphereCollider();
	bool CheckCollision(AbstractCollider* other) override;
	bool CheckCollision(AABBCollider* other) override;
	bool CheckCollision(OBBCollider* other) override;
	bool CheckCollision(SphereCollider* other) override;
};

