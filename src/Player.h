#pragma once
#include <raylib.h>
#include "Vector2d.h"
#include "Grid.h"
#include "Enemy.h"

class Player
{
public:

	// Player variables
	Vector2d position;
	Vector2d size;
	Vector2d speed;
	Color color = PINK;
	Vector2d playerDirection = { 1,0 };
	Vector2d centrePlayerPosition = { position.x + 25, position.y + 25 };
	bool collisionLeft = false;
	bool collisionRight = false;
	bool collisionUp = false;
	bool collisionDown = false;
	int playerScore = 0;

	// Grid class and variables
	Grid map;

	// Enemy class and variables
	Enemy enemy;

	// Game state variables
	int framesCounter = 0;
	int gameState = 1;

	// Player functions
	void CollisionCheck();

	// Updates player each frame
	void UpdatePlayer();

	// Drawing of player
	void DrawPlayer();
};
