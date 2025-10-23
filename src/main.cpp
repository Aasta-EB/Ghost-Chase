#include <raylib.h>
#include "Player.h"
#include "Grid.h"
#include "Enemy.h"

int windowWidth = 1400;
int windowHeight = 700;

int main()
{
	Player player;
	Grid square;
	Grid map;

	InitWindow(windowWidth, windowHeight, "Ghost-Chase");
	SetTargetFPS(60);
	
	map.DrawMap();

	player.playerXPosition = windowWidth / 2;
	player.playerYPosition = windowHeight / 2;
	

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		DrawText("(", 100, 100, 20, WHITE);

		player.DrawPlayer();
		player.PlayerController();

		map.DrawMap();


		EndDrawing();
	}

	return 0;
}