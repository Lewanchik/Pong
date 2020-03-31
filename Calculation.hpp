#pragma once
#include "ICalculation.h"
class Calculation : public ICalculation
{
public:
	static Point BallCalculation(Ball& ball, int x, int y);
	static Point PlatformCalculation(Platform &platform);
	static Point BallCalculation(Ball& ball, int x, int y, Platform& platform);
};

