#pragma once
#include "TextureRect.h"
#include "Ball.hpp"
#include "Platform.hpp"
#include "Window.hpp"

class ICalculation
{
public:
	virtual Point BallCalculation(Ball&, int, int);
	virtual Point PlatformCalculation(Platform&);
};