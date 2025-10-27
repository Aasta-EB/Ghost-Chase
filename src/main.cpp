#include <raylib.h>
#include "Player.h"
#include "Grid.h"
#include "Enemy.h"

// Screen variables
int windowWidth = 1400;
int windowHeight = 700;

// Acsessing classes
Player player;
Grid map;
Enemy enemy;

int main()
{
	// Starting game window
	InitWindow(windowWidth, windowHeight, "Ghost-Chase");
	SetTargetFPS(60);
	
	// Draws map
	map.DrawMap();

	// Sets player spawn position
	player.playerXPosition = windowWidth / 2 - 25;
	player.playerYPosition = windowHeight / 2 - 25;

	// Sets enemy spawn position
	enemy.enemyPosition = { 200, 200 };
	
	// Game while loop
	while (!WindowShouldClose())
	{
		// Starts the drawing of the screen
		BeginDrawing();
		ClearBackground(BLACK);

		// Draws text to show the players box position
		DrawText(TextFormat("( %i", player.boxPositionY), 25, 25, 20, WHITE);
		DrawText(TextFormat(" , %i", player.boxPositionX, " )"), 60, 25, 20, WHITE);
		DrawText(" )", 90, 25, 20, WHITE);

		// Draws player and activates the player controller
		player.DrawPlayer();
		player.PlayerController();

		// Draws enemy
		enemy.DrawEnemy();

		// Draws the grid squares
		map.DrawMap();

		// Ends the drawing of screen
		EndDrawing();
	}

	return 0;
}