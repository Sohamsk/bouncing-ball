#include <raylib.h>

struct Ball {
	Vector2 location;
	Vector2 velocity;
	float radius;
	Color color;
};

int main() {
	const int screenWidth = 1280;
	const int screenHeight = 720;

	Ball ball;
	ball.location = Vector2{screenWidth / 2.0f, screenHeight / 2.0f};
	ball.color = RED;
	ball.radius = 40;

	InitWindow(screenWidth, screenHeight, "Bouncing ball");

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawCircleV(ball.location, ball.radius, ball.color);
		EndDrawing();
	}
	CloseWindow();
}
