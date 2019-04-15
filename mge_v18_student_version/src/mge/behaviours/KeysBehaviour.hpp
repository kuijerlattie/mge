#ifndef KEYSBEHAVIOUR_HPP
#define KEYSBEHAVIOUR_HPP

#include "mge/behaviours/AbstractBehaviour.hpp"
#include "glm.hpp"

/**
 * KeysBehaviour allows you to move an object using the keyboard in its own local space.
 * Left right turns, forward back moves.
 */
class KeysBehaviour : public AbstractBehaviour
{
	public:
	    //move speed is in units per second, turnspeed in degrees per second
		KeysBehaviour(glm::vec3 forward, float moveSpeed = 5, float turnSpeed = 45);
		virtual ~KeysBehaviour();
		virtual void update( float pStep );

    private:
        float _moveSpeed;
        float _turnSpeed;
		glm::vec3 _forward;
};

#endif // KEYSBEHAVIOUR_HPP
