#include <raylib.h>

int windowWidth = 1440;
int windowHeight = 800;


int main()
{
	InitWindow(windowWidth, windowHeight, "Ghost-Chase");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);


		EndDrawing();
	}

	return 0;
}