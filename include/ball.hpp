#ifndef BALL_HPP
#define BALL_HPP

#include <raylib.h>

class Ball {
      public:
	Vector2 location;
	Vector2 velocity;
	float radius;
	Color color;

	void updateBall(float delta, int screenWidth, int screenHeight);
	void initBall(float radius, float angle, float magnitude, Color color,
		      int screenWidth, int screenHeight);
};
#endif
