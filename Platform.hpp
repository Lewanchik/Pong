#pragma once
#include "IEntity.hpp"

class Platform : public IEntity
{
public:
    Platform() = default;
    Platform(int dir, int speed);
    ~Platform() = default;

    virtual int		getSpeed() const;
    virtual int		getDirection() const;

    virtual void	setSpeed(int speed);
    virtual void	setDirection(int direction);

private:

    int		__direction;
    int		__speed;
};

