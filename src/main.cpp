#include <raylib.h>
#include "Player.h"
#include "Grid.h"
#include "Enemy.h" 

// Acsessing classes _________________________________________________________________________________________________________________________________________________________
static Player player = { 0 };
Grid map;

// Initiates game ____________________________________________________________________________________________________________________________________________________________
static void InitGame()
{
	player.framesCounter = 0;
	player.gameOver = false;

	player.counterTail = 1;
	player.allowMove = false;

	map.offset.x = map.windowWidth % int(map.boxSize);
	map.offset.y = map.windowHeight % int(map.boxSize);

	for (int i = 0; i < player.playerSize; i++)
	{
		player.position = Vector2{ 1400 / 2, 700 / 2 };
		player.size = Vector2{ map.boxSize, map.boxSize };
		player.speed = Vector2{ map.boxSize, 0 };

		if (i == 0) player.color = DARKBLUE;
		else player.color = BLUE;
	}

	for (int i = 0; i < player.playerSize; i++)
	{
		player.playerPosition = Vector2{ 0.0f, 0.0f };
	}
}

// Updates each frame ________________________________________________________________________________________________________________________________________________________
void UpdateDrawFrame()
{
	player.UpdateGame();
	player.DrawGame();
}

int main()
{
	// Starting game window
	InitWindow(map.windowWidth, map.windowHeight, "Ghost-Chase");

	InitGame();

	SetTargetFPS(60);

	// Draws map
	map.DrawMap();

	// Game while loop
	while (!WindowShouldClose())
	{
		UpdateDrawFrame();
	}
	CloseWindow();

	return 0;
}