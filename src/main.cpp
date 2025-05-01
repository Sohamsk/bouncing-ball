#include <ball.hpp>
#include <iostream>
#include <raylib.h>

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
	ball.initBall(40, angle, magnitude, RED, screenWidth, screenHeight);

	InitWindow(screenWidth, screenHeight, "Bouncing ball");

	while (!WindowShouldClose()) {
		float delta = GetFrameTime();
		ball.updateBall(delta, screenWidth, screenHeight);
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawCircleV(ball.location, ball.radius, ball.color);
		EndDrawing();
	}
	CloseWindow();
}
