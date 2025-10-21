#include <raylib.h>
#include "Player.h"
#include "Grid.h"
#include "Enemy.h"

int windowWidth = 1400;
int windowHeight = 700;

Player player;
Grid square;


int main()
{
	InitWindow(windowWidth, windowHeight, "Ghost-Chase");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		player.DrawPlayer();

		square.DrawRectangles({200, 200});


		EndDrawing();
	}

	return 0;
}