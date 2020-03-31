#pragma once
#include "IEntity.hpp"



class Ball : public IEntity
{
public:
    Ball() = default;
    Ball(int direction, int speed);
    ~Ball() = default;

    virtual int		getSpeed() const;
    virtual int		getDirection() const;

    virtual void	setSpeed(int speed);
    virtual void	setDirection(int direction);

private:
	int		__direction;
	int		__speed;
};

