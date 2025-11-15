#pragma once
#include "raylib.h"
#include "Grid.h"
#include <random>

class Enemy
{
public: 
	
	Grid map;

	Vector2 position = { 1400 / 2,700 / 2 };
	Vector2 size = { 50,50 };
	Color color = YELLOW;
	Vector2 speed = { map.boxSize, 0 };

	Vector2 enemyPosition = { 0 };
	Vector2 enemyDirection = { 1,0 };

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

