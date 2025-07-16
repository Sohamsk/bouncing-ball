#ifndef BALL_HPP
#define BALL_HPP

#include <raylib.h>

class Ball {
	Vector2 location;
	Vector2 velocity;
	float radius;
	Color color;

      public:
	void updateBall(float delta, int screenWidth, int screenHeight);
	void initBall(float radius, float angle, float magnitude, Color color,
		      int screenWidth, int screenHeight);
	void drawBall();
};
#endif
