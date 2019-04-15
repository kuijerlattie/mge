#include "mge/behaviours/CameraBehaviour.hpp"
#include "mge/core/GameObject.hpp"
#include <SFML/Window/Keyboard.hpp>

CameraBehaviour::CameraBehaviour(GameObject * target, float distance, float rotationSpeed, float minTilt, float maxTilt) : AbstractBehaviour() {
	_target = target;
	_distance = distance;
	_rotationSpeed = rotationSpeed;
	_minTilt = minTilt;
	_maxTilt = maxTilt;
	_tilt = 1.0f;
}

CameraBehaviour::~CameraBehaviour() {}

void CameraBehaviour::update(float pStep)
{
	//reset transform
	_owner->setTransform(glm::mat4());
	
	//set position to be equal to the target
	_owner->setLocalPosition(_target->getLocalPosition());

	//zoom
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) _distance += 1 * pStep;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) _distance -= 1 * pStep;
	
	//rotate
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) _rotation -= _rotationSpeed * pStep;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) _rotation += _rotationSpeed * pStep;

	//tilt
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) _tilt += 10 * pStep;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) _tilt -= 10 * pStep;
	
	//limit tilt
	if (_tilt > _maxTilt) _tilt = _maxTilt;
	else if (_tilt < _minTilt) _tilt = _minTilt;

	//rotate then tilt (order is important)
	_owner->rotate(glm::radians(_rotation), glm::vec3(0, 1, 0));
	_owner->rotate(glm::radians(_tilt), glm::vec3(-1, 0, 0)); //negative axis to flip the tiltsign
	
	//move camera back to the proper distance
	_owner->translate(glm::vec3(0.0f, 0.0f, _distance));
}
