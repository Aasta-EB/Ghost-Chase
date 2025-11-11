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
Vector2 playerDirection = { 1,0 };

bool collisionLeft = false; 
bool collisionRight = false; 
bool collisionUp = false; 
bool collisionDown = false; 

Grid map;

void CollisionCheck()
{
	int playerPositionX = player[0].position.x / 50;
	int playerPositionY = player[0].position.y / 50;

	if (playerDirection.x == 1)
	{
		playerPositionX = (player[0].position.x + 50) / 50;
		playerPositionY = player[0].position.y / 50;
		
		if (map.map[playerPositionY][playerPositionX] == 1)
		{
			collisionRight = true;
		}
		else
		{
			collisionRight = false;
		}
	}
	if (playerDirection.x == -1)
	{
		playerPositionX = (player[0].position.x - 50) / 50;
		playerPositionY = player[0].position.y / 50;
		if (map.map[playerPositionY][playerPositionX] == 1)
		{
			collisionLeft = true;
		}
		else
		{
			collisionLeft = false;
		}
	}
	if (playerDirection.y == -1)
	{
		playerPositionX = player[0].position.x / 50;
		playerPositionY = (player[0].position.y - 50) / 50;
		if (map.map[playerPositionY][playerPositionX] == 1)
		{
			collisionUp = true;
		}
		else
		{
			collisionUp = false;
		}
	}
	if (playerDirection.y == 1)
	{
		playerPositionX = player[0].position.x / 50;
		playerPositionY = (player[0].position.y + 50) / 50;
		if (map.map[playerPositionY][playerPositionX] == 1)
		{
			collisionDown = true;
		}
		else
		{
			collisionDown = false;
		}
	}
	std::cout << playerPositionX << " , " << playerPositionY << "\n";
}

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
		player[i].position = Vector2{ 1400 / 2, 700 / 2 };
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

		if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D) && allowMove)
		{
			CollisionCheck();
			if (playerDirection.x == 0 || playerDirection.x == -1 && collisionRight == false)
			{
				player[0].speed = Vector2{ SQUARE_SIZE, 0 };
				allowMove = false;
				playerDirection = { 1,0 };
			}
			else if (playerDirection.x == 1 && collisionRight == false)
			{
				player[0].speed = Vector2{ SQUARE_SIZE, 0 };
				allowMove = false;
				playerDirection = { 1,0 };
			}
		}
		if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A) && allowMove)
		{
			CollisionCheck();
			if (playerDirection.x == 0 || playerDirection.x == 1 && collisionLeft == false)
			{
				player[0].speed = Vector2{ -SQUARE_SIZE, 0 };
				allowMove = false;
				playerDirection = { -1,0 };
			}
			else if (playerDirection.x == -1 && collisionLeft == false)
			{
				player[0].speed = Vector2{ -SQUARE_SIZE, 0 };
				allowMove = false;
				playerDirection = { -1,0 };
			}
		}
		if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W) && allowMove)
		{
			CollisionCheck();
			if (playerDirection.y == 0 || playerDirection.y == -1 && collisionUp == false)
			{
				player[0].speed = Vector2{ 0, -SQUARE_SIZE };
				allowMove = false;
				playerDirection = { 0,-1 };
			}
			else if (playerDirection.y == -1 && collisionUp == false)
			{
				player[0].speed = Vector2{ 0, -SQUARE_SIZE };
				allowMove = false;
				playerDirection = { 0,-1 };
			}
		}
		if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S) && allowMove)
		{
			CollisionCheck();
			if (playerDirection.y == 0 || playerDirection.y == 1 && collisionDown == false)
			{
				player[0].speed = Vector2{ 0, SQUARE_SIZE };
				allowMove = false;
				playerDirection = { 0,1 };
			}
			else if (playerDirection.y == 1 && collisionDown == false)
			{
				player[0].speed = Vector2{ 0, SQUARE_SIZE };
				allowMove = false;
				playerDirection = { 0,1 };
			}
		}

		// Player movement
		for (int i = 0; i < counterTail; i++) playerPosition[i] = player[i].position;

		if ((framesCounter % 10) == 0)
		{
			for (int i = 0; i < counterTail; i++)
			{
				if (i == 0)
				{
					CollisionCheck();
					if (collisionRight == false && collisionLeft == false && collisionUp == false && collisionDown == false)
					{
						player[0].position.x += player[0].speed.x;
						player[0].position.y += player[0].speed.y;
						allowMove = true;
					}
					else if (playerDirection.x == 1 && collisionRight == false)
					{
						player[0].position.x += player[0].speed.x;
						player[0].position.y += player[0].speed.y;
						allowMove = true;
					}
					else if (playerDirection.x == -1 && collisionLeft == false)
					{
						player[0].position.x += player[0].speed.x;
						player[0].position.y += player[0].speed.y;
						allowMove = true;
					}
					else if (playerDirection.y == -1 && collisionUp == false)
					{
						player[0].position.x += player[0].speed.x;
						player[0].position.y += player[0].speed.y;
						allowMove = true;
					}
					else if (playerDirection.y == 1 && collisionDown == false)
					{
						player[0].position.x += player[0].speed.x;
						player[0].position.y += player[0].speed.y;
						allowMove = true;
					}

				}
				else
				{
					player[i].position = playerPosition[i - 1];
				}
			}
		}

		framesCounter++;
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

		// Draw Player
		for (int i = 0; i < counterTail; i++) DrawRectangleV(player[i].position, player[i].size, player[i].color);
	}

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