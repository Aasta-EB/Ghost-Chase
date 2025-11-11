#include <raylib.h>
#include "Player.h"
#include "Grid.h"
#include "Enemy.h"

float boxSize = 50;
int playerSize = 1; 

// Screen variables
static int windowWidth = 1400;
static int windowHeight = 700;

// Acsessing classes
static Player player = { 0 };
static Vector2 offset = { 0 };


Grid map;


static void InitGame()
{
	player.framesCounter = 0;
	player.gameOver = false;

	player.counterTail = 1;
	player.allowMove = false;

	offset.x = windowWidth % int(map.boxSize);
	offset.y = windowHeight % int(map.boxSize);

	for (int i = 0; i < playerSize; i++)
	{
		player.position = Vector2{ 1400 / 2, 700 / 2 };
		player.size = Vector2{ boxSize, boxSize };
		player.speed = Vector2{ boxSize, 0 };

		if (i == 0) player.color = DARKBLUE;
		else player.color = BLUE;
	}

	for (int i = 0; i < playerSize; i++)
	{
		player.playerPosition = Vector2{ 0.0f, 0.0f };
	}
}



void DrawGame()
{
	BeginDrawing();

	ClearBackground(BLACK);

	if (!player.gameOver)
	{
		// Draw grid lines
		for (int i = 0; i < windowWidth / boxSize + 1; i++)
		{
			DrawLineV(Vector2{ boxSize * i + offset.x / 2, offset.y / 2 }, Vector2{ boxSize * i + offset.x / 2, windowHeight - offset.y / 2 }, LIGHTGRAY);
		}

		for (int i = 0; i < windowHeight / boxSize + 1; i++)
		{
			DrawLineV(Vector2{ offset.x / 2, boxSize * i + offset.y / 2 }, Vector2{ windowWidth - offset.x / 2, boxSize * i + offset.y / 2 }, LIGHTGRAY);
		}
		map.DrawMap();

		// Draw Player
		for (int i = 0; i < player.counterTail; i++) DrawRectangleV(player.position, player.size, player.color);
	}

	EndDrawing();
}

void UpdateDrawFrame()
{
	player.UpdateGame();
	DrawGame();
}

int main()
{
	// Starting game window
	InitWindow(windowWidth, windowHeight, "Ghost-Chase");

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