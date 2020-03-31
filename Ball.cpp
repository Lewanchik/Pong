#include "Ball.hpp"

Ball::Ball(int direction, int speed)
{
	__direction = direction;
	__speed = speed;
}

int Ball::getDirection() const
{
	return __direction;
}

int Ball::getSpeed() const
{
	return __speed;
}

void Ball::setDirection(int direction)
{
	__direction = direction;
}

void Ball::setSpeed(int speed)
{
	__speed = speed;
}
