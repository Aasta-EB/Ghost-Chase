#include <raylib.h>
#include "Player.h"

int windowWidth = 1440;
int windowHeight = 800;

Player player;


int main()
{
	InitWindow(windowWidth, windowHeight, "Ghost-Chase");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		player.DrawPlayer(windowWidth/2, windowHeight/2);


		EndDrawing();
	}

	return 0;
}