#pragma once
#include "Vector2d.h"
#include <raylib.h>
#include "grid.h"
#include <random>

class Enemy
{
public: 
	float enemyPositionX;
	float enemyPositionY;

	float enemySize = 20;
	Color enemyColor = YELLOW;

	int enemyBoxPositionX;
	int enemyBoxPositionY;

	Grid box;
	bool enemyHitBox;
	Vector2d enemyDirection = { 0, 0 };


	void FindEnemyBoxPosition(Vector2d inEnemyPosition);
	void EnemyMovement(Vector2d inEnemyPosition);
	void DrawEnemy();

};

