#pragma once
#include <vector>

class IEntity
{
public:
	virtual			~IEntity() = default;
	virtual int		getSpeed() const = 0;
	virtual int		getDirection() const = 0;

	virtual void	setSpeed(int) = 0;
	virtual void	setDirection(int) = 0;
};
