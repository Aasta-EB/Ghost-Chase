#pragma once
#include "raylib.h"
#include "Grid.h"
#include "Vector2d.h"
#include <random>

class Enemy
{
public:

	Grid map;

	Vector2d position;
	Vector2d size = { 50,50 };
	Color color = YELLOW;
	Vector2d speed = { map.boxSize, 0 };

	Vector2d enemyPosition = { 0 };
	Vector2 enemyDirection = { 1,0 };

	Vector2d visualPosition;

	int framesCounter = 0;

	bool collisionLeft = false;
	bool collisionRight = true;
	bool collisionUp = false;
	bool collisionDown = false;

	float distanceToPlayer = 100;

	bool run = false;

	void EnemyEscape();

	void CollisionCheck();

	void EnemyMovement();

	void DrawEnemy();
};
