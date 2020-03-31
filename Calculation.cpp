#include "Calculation.hpp"

Point Calculation::BallCalculation(Ball &ball, int x, int y)
{
	Point point;
	int speed = ball.getSpeed();

	if (y - speed < 0 || y + BALL_HEIGHT > WINDOW_H - speed)
		ball.setDirection(360 - ball.getDirection());
	point.x = static_cast<int>(std::round(speed * (std::cos(ball.getDirection() * M_PI / 180))));
	point.y = static_cast<int>(std::round(speed * (std::sin(ball.getDirection() * M_PI / 180))));
	return point;
}

Point Calculation::BallCalculation(Ball& ball, int x, int y, Platform& platform)
{
	Point point = {0, 0};
	int speedBall = ball.getSpeed();
	int speedPlatform = platform.getSpeed();

	if (platform.getDirection() > 180)
		ball.setDirection(180 - ball.getDirection() + 15);
	else
		ball.setDirection(180 - ball.getDirection() - 15);
	point.x = static_cast<int>(std::round(speedBall * (std::cos(ball.getDirection() * M_PI / 180))));
	point.y = static_cast<int>(std::round(speedBall * (std::sin(ball.getDirection() * M_PI / 180))));
	return point;
}

Point Calculation::PlatformCalculation(Platform &platform)
{
	Point point = {0, 0};
	int speed = platform.getSpeed();
	int dir = platform.getDirection();

	point.x = speed * (int)std::round(std::cos(dir * M_PI / 180));
	point.y = speed * (int)std::round(std::sin(dir * M_PI / 180));
	return point;
}