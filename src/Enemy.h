#pragma once
#include "raylib.h"
#include "Grid.h"
#include "Vector2d.h"
#include <random>

class Enemy
{
public:

	Grid map;

	// Enemy variables
	Vector2d position;
	Color color = YELLOW;
	Vector2d speed = { map.boxSize, 0 };
	Vector2d enemyDirection = { 1,0 };
	Vector2d visualPosition;
	int framesCounter = 0;
	int framesCounterDivider = 10;

	// Enemy collision variables
	bool collisionLeft = false;
	bool collisionRight = true;
	bool collisionUp = false;
	bool collisionDown = false;
	bool justChangedDirection = false;

	// Enemy hint variables
	float dropHintTimer = 10.f;
	bool enemyHintExsists = false;
	Vector2d enemyHintPosition = { 50, 50 };

	// Enemy functions
	// Drop hint function
	void GetHintPosition(Vector2d inPosition);
	
	void DrawDropHint(Vector2d inPlayerPosition);

	// Finds a random enemy direction
	Vector2d RandomEnemyDirection();

	// Finds a "random" enemy spawn point
	Vector2d RandomEnemyPosition();

	// Enemy collision check
	void CollisionCheck(Vector2d inPlayerPosition);

	// Continuos enemy movement
	void EnemyMovement(Vector2d inPlayerPosition);

	// Draw enemy function
	void DrawEnemy(Vector2d inPlayerPosition);
};
