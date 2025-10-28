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

int main()
{
	// Starting game window
	InitWindow(windowWidth, windowHeight, "Ghost-Chase");
	SetTargetFPS(60);
	
	// Draws map
	map.DrawMap();

	// Sets player spawn position
	player.playerXPosition = (13 * 50) + 25;
	player.playerYPosition = (6 * 50) + 25;
	
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

		// Draws the grid squares
		map.DrawMap();

		// Ends the drawing of screen
		EndDrawing();
	}

	return 0;
}