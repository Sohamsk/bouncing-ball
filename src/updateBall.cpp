#include <ball.hpp>
#include <cmath>

const double g = 981;

double toRadian(double degree) { return degree / 180 * PI; }

void Ball::initBall(float radius, float angle, float magnitude, Color color,
		    int screenWidth, int screenHeight) {
	this->location = Vector2{screenWidth / 2.0f, screenHeight / 2.0f};
	velocity = Vector2{float(magnitude * cos(toRadian(angle))),
			   float(magnitude * sin(toRadian(angle)))};
	this->color = color;
	this->radius = radius;
}

void Ball::updateBall(float delta, int screenWidth, int screenHeight) {
	// handle gravity
	this->velocity.y += g * delta;

	this->location.x += this->velocity.x * delta;
	this->location.y += this->velocity.y * delta;

	// clamp the ball
	if (this->location.x + this->radius >= screenWidth) {
		this->velocity.x = -this->velocity.x;
		this->location.x = screenWidth - this->radius;
	} else if (this->location.x - this->radius <= 0) {
		this->velocity.x = -this->velocity.x;
		this->location.x = 0 + this->radius;
	}
	if (this->location.y + this->radius >= screenHeight) {
		this->velocity.y = -this->velocity.y;
		this->location.y = screenHeight - this->radius;
	} else if (this->location.y - this->radius <= 0) {
		this->velocity.y = -this->velocity.y;
		this->location.y = this->radius;
	}
}
