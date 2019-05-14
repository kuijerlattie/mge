#include <iostream>
#include <string>

#include "glm.hpp"

#include "mge/core/Renderer.hpp"

#include "mge/core/Mesh.hpp"
#include "mge/core/World.hpp"
#include "mge/core/Texture.hpp"
#include "mge/core/Light.hpp"
#include "mge/core/Camera.hpp"
#include "mge/core/GameObject.hpp"

#include "mge/materials/AbstractMaterial.hpp"
#include "mge/materials/ColorMaterial.hpp"
#include "mge/materials/TextureMaterial.hpp"

#include "mge/behaviours/RotatingBehaviour.hpp"
#include "mge/behaviours/KeysBehaviour.hpp"
#include "mge/behaviours/CameraBehaviour.hpp"

#include "mge/util/DebugHud.hpp"

#include "mge/config.hpp"
#include "mge/MGEDemo.hpp"
#include "mge/util/Statics.h"

//construct the game class into _window, _renderer and hud (other parts are initialized by build)
MGEDemo::MGEDemo() :AbstractGame(), _hud(0)
{
}

void MGEDemo::initialize() {
	//setup the core part
	AbstractGame::initialize();

	//setup the custom part so we can display some text
	std::cout << "Initializing HUD" << std::endl;
	_hud = new DebugHud(_window);
	std::cout << "HUD initialized." << std::endl << std::endl;
}

//build the game _world
void MGEDemo::_initializeScene()
{
	//SCENE SETUP

	//add camera first (it will be updated last)
	Camera* camera = new Camera("camera", glm::vec3(0, 0, 10));
	_world->add(camera);
	_world->setMainCamera(camera);

	int max = 5;
	int min = -5;

	srand(time(NULL));

	for (int i = 0; i < 100; i++)
	{
		float rx = fmod(((float)rand() / (float)100), 10);
		float ry = fmod(((float)rand() / (float)100), 10);
		float rz = fmod(((float)rand() / (float)100), 10);
		rx -= 5;
		ry -= 5;
		rz -= 5;
		//std::cout << "rx = " << rx << " ry = " << ry << " rz = " << rz << std::endl;
		CubeSpawner::SpawnCube(glm::vec3(rx, ry, rz));
	}

	camera->setBehaviour(new KeysBehaviour(glm::vec3(0,0,1)));

}

void MGEDemo::_render() {
	AbstractGame::_render();
	_updateHud();
}

void MGEDemo::_updateHud() {
	std::string debugInfo = "";
	debugInfo += std::string("FPS:") + std::to_string((int)_fps) + "\n";

	_hud->setDebugInfo(debugInfo);
	_hud->draw();
}



MGEDemo::~MGEDemo()
{
	//dtor
}
