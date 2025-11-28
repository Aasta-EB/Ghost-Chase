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
	Vector2d size = { 50,50 };
	Color color = YELLOW;
	Vector2d speed = { map.boxSize, 0 };
	Vector2d enemyPosition = { 0 }; // Do i realluy need this???
	Vector2d enemyDirection = { 1,0 };
	Vector2d visualPosition;
	bool collisionLeft = false;
	bool collisionRight = true;
	bool collisionUp = false;
	bool collisionDown = false;
	bool justChangedDirection = false;
	float distanceToPlayer = 100;
	int framesCounter = 0;

	// Enemy hint variables
	float dropHintTimer = 10.f;
	float enemyHintNumber = 0.5f;
	bool enemyHintExsists_1 = false;
	bool enemyHintExsists_2 = false;
	bool enemyHintExsists_3 = false;
	bool enemyHintExsists_4 = false;
	bool enemyHintExsists_5 = false;
	Vector2d enemyHintPos_1 = { 50, 50 };
	Vector2d enemyHintPos_2 = { 50, 50 };
	Vector2d enemyHintPos_3 = { 50, 50 };
	Vector2d enemyHintPos_4 = { 50, 50 };
	Vector2d enemyHintPos_5 = { 50, 50 };

	// Enemy functions
	void DrawDropHint();

	Vector2d RandomEnemyDirection();

	Vector2d RandomEnemyPosition();

	void CollisionCheck(Vector2d inPlayerPosition);

	void EnemyMovement(Vector2d inPlayerPosition);

	void DrawEnemy(Vector2d inPlayerPosition);
};
