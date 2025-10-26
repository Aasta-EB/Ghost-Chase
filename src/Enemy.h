#pragma once
#include "Vector2d.h"
#include <raylib.h>

class Enemy
{
public: 
	float enemyPositionX;
	float enemyPositionY;

	float enemySize = 20;
	Color enemyColor = YELLOW;

	Vector2d FindEnemyBoxPosition();
	void DrawEnemy();

};

