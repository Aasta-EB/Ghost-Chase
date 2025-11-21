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

	float dropTimer = 5.f; 

	int framesCounter = 0;

	bool collisionLeft = false;
	bool collisionRight = true;
	bool collisionUp = false;
	bool collisionDown = false;

	float distanceToPlayer = 100;

	bool runUp = false;
	bool runDown = false;
	bool runLeft = false;
	bool runRight = false; 

	void DrawDropHint();

	void EnemyEscape(Vector2d inPlayerPosition);

	void CollisionCheck(Vector2d inPlayerPosition);

	void EnemyMovement(Vector2d inPlayerPosition);

	void DrawEnemy(Vector2d inPlayerPosition);
};
