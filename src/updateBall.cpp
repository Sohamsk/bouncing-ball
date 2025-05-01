#include <ball.hpp>
#include <cmath>

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
	this->location.x += this->velocity.x * delta;
	this->location.y += this->velocity.y * delta;

	if (this->location.x + this->radius >= screenWidth ||
	    this->location.x - this->radius <= 0) {
		this->velocity.x = -this->velocity.x;
	}
	if (this->location.y + this->radius >= screenHeight ||
	    this->location.y - this->radius <= 0) {
		this->velocity.y = -this->velocity.y;
	}
}
