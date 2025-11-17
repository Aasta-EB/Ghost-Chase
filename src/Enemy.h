#pragma once
#include "raylib.h"
#include "Grid.h"
#include "Vector2d.h"
#include <random>

class Enemy
{
public:

	Grid map;

	Vector2d position = { 15 * 50,10 * 50 };
	Vector2d size = { 50,50 };
	Color color = YELLOW;
	Vector2d speed = { map.boxSize, 0 };

	Vector2d enemyPosition = { 0 };
	Vector2 enemyDirection = { 1,0 };

	Vector2d visualPosition;

	int counterTail = 1;
	int framesCounter = 0;

	bool collisionLeft = false;
	bool collisionRight = true;
	bool collisionUp = false;
	bool collisionDown = false;

	void CollisionCheck();

	void EnemyMovement();

	void DrawEnemy();
};
