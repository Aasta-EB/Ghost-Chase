#include <raylib.h>
#include "Player.h"
#include "Grid.h"
#include "Enemy.h"

int windowWidth = 1400;
int windowHeight = 700;

Player player;
Grid square;
Grid map; 


int main()
{
	InitWindow(windowWidth, windowHeight, "Ghost-Chase");
	SetTargetFPS(60);
	
	map.DrawMap();

	player.playerXPosition = windowWidth / 2;
	player.playerYPosition = windowHeight / 2;
	

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		player.DrawPlayer();
		player.PlayerController();

		map.DrawMap();


		EndDrawing();
	}

	return 0;
}