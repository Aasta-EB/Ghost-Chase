#pragma once
#include <raylib.h>
#include "Vector2d.h"
#include <random>
class Enemy
{
public: 

	int enemyDirection;
	int enemySpeed = 100;
	int enemySize = 20;
	Color enemyColor = YELLOW;

	Vector2d enemyPosition;
	bool enemyHitWall = false;

	void EnemyMovement();
	void DrawEnemy();


};

