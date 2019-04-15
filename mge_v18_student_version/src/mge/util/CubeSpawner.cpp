#include "CubeSpawner.h"
#include "Statics.h"
#include "mge/core/Mesh.hpp"
#include "mge/materials/ColorMaterial.hpp"
#include "mge/config.hpp"

Mesh* cubeMesh;
AbstractMaterial* blueColorMat;

CubeSpawner::CubeSpawner()
{
}


CubeSpawner::~CubeSpawner()
{
}

void CubeSpawner::SpawnCube(glm::vec3 position, bool isStatic)
{
	if (cubeMesh == NULL)
	{
		cubeMesh = Mesh::load(config::MGE_MODEL_PATH + "cube_flat.obj");
		blueColorMat = new ColorMaterial(glm::vec3(0, 0, 1));
	}
	GameObject* cube = new GameObject("Cube", position);
	cube->scale(glm::vec3(0.1f, 0.1f, 0.1f));
	cube->setMesh(cubeMesh);
	cube->setMaterial(blueColorMat);
	Statics::getInstance().WORLD->add(cube);
}
