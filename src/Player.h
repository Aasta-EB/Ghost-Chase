#pragma once
#include <raylib.h>
#include "Vector2d.h"
#include "Grid.h"

class Player
{
public:

	// Player variables
	Vector2 position;
	Vector2 size;
	Vector2 speed;
	Color color; 
	Vector2 playerDirection = { 1,0 };
	Vector2 playerPosition = { 0 };
	
	// Grid class and variables
	Grid map;

	bool collisionLeft = false;
	bool collisionRight = false;
	bool collisionUp = false;
	bool collisionDown = false;

	bool gameOver = false;
	bool allowMove = false;

	int counterTail = 0;
	int framesCounter = 0;

	void CollisionCheck();

	void UpdateGame();
		
};

