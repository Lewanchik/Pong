#include "Platform.hpp"

Platform::Platform(int dir, int speed)
{
	__direction = dir;
	__speed = speed;
}

int Platform::getDirection() const
{
	return __direction;
}

int Platform::getSpeed() const
{
	return __speed;
}

void Platform::setDirection(int direction)
{
	__direction = direction;
}

void Platform::setSpeed(int speed)
{
	__speed = speed;
}
