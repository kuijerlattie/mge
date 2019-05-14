#pragma once

#include "mge/core/World.hpp"
#include "mge/util/CubeSpawner.h"
#include "mge/core/PhysicsWorld.h"

class World;

class Statics
{
public:
	static Statics& getInstance()
	{
		static Statics instance; 
		return instance;
	}
	Statics();
	~Statics();

	World* WORLD;
	CubeSpawner* CUBESPAWNER;
	PhysicsWorld* PHYSICS;
};

