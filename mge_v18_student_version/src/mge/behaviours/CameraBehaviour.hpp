#ifndef CAMERABEHAVIOUR_HPP
#define CAMERABEHAVIOUR_HPP

#include "mge/behaviours/AbstractBehaviour.hpp"

class CameraBehaviour : public AbstractBehaviour
{
public:
	//move speed is in units per second, turnspeed in degrees per second
	CameraBehaviour(GameObject * target, float distance = 5, float rotationSpeed = 45, float minTilt = 1.0f, float maxTilt = 90.0f);
	virtual ~CameraBehaviour();
	virtual void update(float pStep);

private:
	GameObject * _target;

	float _distance;
	float _rotation = 0.0f;
	float _rotationSpeed;
	float _tilt = 0.0f;
	float _minTilt;
	float _maxTilt;

};

#endif // CAMERABEHAVIOUR_HPP
