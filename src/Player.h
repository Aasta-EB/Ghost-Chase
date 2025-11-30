#pragma once
#include <raylib.h>
#include "Vector2d.h"
#include "Grid.h"
#include "Enemy.h"

class Player
{
public:

	// Grid class and variables
	Grid map;

	// Enemy class and variables
	Enemy enemy;

	// Player variables
	Vector2d position;
	Vector2d size;
	Vector2d speed;
	Color color = PINK;
	Vector2d playerDirection = { 1,0 };
	Vector2d centrePlayerPosition = { position.x + 25, position.y + 25 };
	int playerScore = 0;
	int framesCounter = 0;
	int framesCounterDivider = 10; 

	// Player collision variables
	bool collisionLeft = false;
	bool collisionRight = false;
	bool collisionUp = false;
	bool collisionDown = false;
	

	// Game state variables
	int gameState = 1; // 1 = Start window, 2 = Game on, 3 = Game Paused, 4 = Game Won, 5 = Game Over

	// Player functions
	void CollisionCheck();

	// Updates player each frame
	void UpdatePlayer();

	// Drawing of player
	void DrawPlayer();
};
