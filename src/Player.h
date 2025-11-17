#pragma once
#include <raylib.h>
#include "Vector2d.h"
#include "Grid.h"
#include "Enemy.h"
#include "Vector2d.h"

class Player
{
public:

	// Player variables
	Vector2d position;
	Vector2d size;
	Vector2d speed;
	Color color = PINK;
	Vector2d playerDirection = { 1,0 };
	Vector2d playerPosition = { 0 };

	Vector2d centrePlayerPosition = { position.x + 25, position.y + 25 };

	// Grid class and variables
	Grid map;

	Enemy enemy;

	bool collisionLeft = false;
	bool collisionRight = false;
	bool collisionUp = false;
	bool collisionDown = false;

	bool gameOver = true;
	bool gamePaused = false;
	bool allowMove = false;

	int framesCounter = 0;

	int playerSize = 1;

	void CollisionCheck();

	void UpdateGame();

	void DrawPlayer();
};
