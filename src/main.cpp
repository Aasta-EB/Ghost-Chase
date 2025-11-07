#include <raylib.h>
#include "Player.h"
#include "Grid.h"
#include "Enemy.h"


#define PLAYER_LENGHT 1
#define SQUARE_SIZE 50

// Screen variables
static int windowWidth = 1400;
static int windowHeight = 700;

static int framesCounter = 0;
static bool gameOver = false;

// Acsessing classes
static Player player[PLAYER_LENGHT] = { 0 };
static Vector2 playerPosition[PLAYER_LENGHT] = { 0 };
static bool allowMove = false; 
static Vector2 offset = { 0 };
static int counterTail = 0; 

Grid map;

static void InitGame()
{
	framesCounter = 0;
	gameOver = false;

	counterTail = 1;
	allowMove = false;

	offset.x = windowWidth % SQUARE_SIZE;
	offset.y = windowHeight % SQUARE_SIZE;

	for (int i = 0; i < PLAYER_LENGHT; i++)
	{
		player[i].position = Vector2{ offset.x / 2, offset.y / 2 };
		player[i].size = Vector2{ SQUARE_SIZE, SQUARE_SIZE };
		player[i].speed = Vector2{ SQUARE_SIZE, 0 };

		if (i == 0) player[i].color = DARKBLUE;
		else player[i].color = BLUE;
	}

	for (int i = 0; i < PLAYER_LENGHT; i++)
	{
		playerPosition[i] = Vector2{ 0.0f, 0.0f };
	}
}

void UpdateGame()
{
	if (!gameOver)
	{
		// Player control
		if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D) && (player[0].speed.x == 0) && allowMove)
		{
			player[0].speed = Vector2{ SQUARE_SIZE, 0 };
			allowMove = false;
		}
		if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A) && (player[0].speed.x == 0) && allowMove)
		{
			player[0].speed = Vector2{ -SQUARE_SIZE, 0 };
			allowMove = false;
		}
		if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W) && (player[0].speed.y == 0) && allowMove)
		{
			player[0].speed = Vector2{ 0, -SQUARE_SIZE };
			allowMove = false;
		}
		if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S) && (player[0].speed.y == 0) && allowMove)
		{
			player[0].speed = Vector2{ 0, SQUARE_SIZE };
			allowMove = false;
		}

		// Snake movement
		for (int i = 0; i < counterTail; i++) playerPosition[i] = player[i].position;

		if ((framesCounter % 10) == 0)
		{
			for (int i = 0; i < counterTail; i++)
			{
				if (i == 0)
				{
					player[0].position.x += player[0].speed.x;
					player[0].position.y += player[0].speed.y;
					allowMove = true;
				}
				else player[i].position = playerPosition[i - 1];
			}
		}

		// Collision with yourself
		for (int i = 1; i < counterTail; i++)
		{
			if ((player[0].position.x == player[i].position.x) && (player[0].position.y == player[i].position.y)) gameOver = true;
		}

		framesCounter++;
	}
	else
	{
		if (IsKeyPressed(KEY_ENTER))
		{
			InitGame();
			gameOver = false;
		}
	}
}

void DrawGame()
{
	BeginDrawing();

	ClearBackground(BLACK);

	if (!gameOver)
	{
		// Draw grid lines
		for (int i = 0; i < windowWidth / SQUARE_SIZE + 1; i++)
		{
			DrawLineV(Vector2{ SQUARE_SIZE * i + offset.x / 2, offset.y / 2 }, Vector2{ SQUARE_SIZE * i + offset.x / 2, windowHeight - offset.y / 2 }, LIGHTGRAY);
		}

		for (int i = 0; i < windowHeight / SQUARE_SIZE + 1; i++)
		{
			DrawLineV(Vector2{ offset.x / 2, SQUARE_SIZE * i + offset.y / 2 }, Vector2{ windowWidth - offset.x / 2, SQUARE_SIZE * i + offset.y / 2 }, LIGHTGRAY);
		}
		map.DrawMap();

		// Draw snake
		for (int i = 0; i < counterTail; i++) DrawRectangleV(player[i].position, player[i].size, player[i].color);
	}
	else DrawText("PRESS [ENTER] TO PLAY AGAIN", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2, GetScreenHeight() / 2 - 50, 20, GRAY);

	EndDrawing();
}

void UpdateDrawFrame()
{
	UpdateGame();
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