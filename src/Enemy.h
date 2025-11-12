#pragma once
#include "raylib.h"

class Enemy
{
public: 

	Vector2 position = { 1400 / 2,700 / 2 };
	Vector2 size = { 50,50 };
	Color color = YELLOW;

	void EnemyMovement();

	void DrawEnemy();

};

