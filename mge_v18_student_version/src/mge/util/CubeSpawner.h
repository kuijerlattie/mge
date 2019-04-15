#pragma once
#include "glm.hpp"

class CubeSpawner
{
public:
	CubeSpawner();
	~CubeSpawner();

	static void CubeSpawner::SpawnCube(glm::vec3 position, bool isStatic = true);
};

