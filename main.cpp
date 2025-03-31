#include <cmath>
#include <iostream>
#include <raylib.h>

struct Ball {
	Vector2 location;
	Vector2 velocity;
	float radius;
	Color color;
};

double toRadian(double degree) { return degree / 180 * PI; }

int main() {
	const int screenWidth = 1280;
	const int screenHeight = 720;

	float angle;
	float magnitude;

	std::cout << "Enter angle of the ball: ";
	std::cin >> angle;
	std::cout << "Enter the speed of the ball: ";
	std::cin >> magnitude;

	Ball ball;
	ball.location = Vector2{screenWidth / 2.0f, screenHeight / 2.0f};
	ball.velocity = Vector2{float(magnitude * cos(toRadian(angle))),
				float(magnitude * sin(toRadian(angle)))};
	ball.color = RED;
	ball.radius = 40;

	InitWindow(screenWidth, screenHeight, "Bouncing ball");

	while (!WindowShouldClose()) {
		float delta = GetFrameTime();
		ball.location.x += ball.velocity.x * delta;
		ball.location.y += ball.velocity.y * delta;

		if (ball.location.x + ball.radius >= screenWidth ||
		    ball.location.x - ball.radius <= 0) {
			ball.velocity.x = -ball.velocity.x;
		}
		if (ball.location.y + ball.radius >= screenHeight ||
		    ball.location.y - ball.radius <= 0) {
			ball.velocity.y = -ball.velocity.y;
		}
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawCircleV(ball.location, ball.radius, ball.color);
		EndDrawing();
	}
	CloseWindow();
}
