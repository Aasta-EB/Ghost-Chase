#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Vector2d.h"

class Booster
{
public:

	Enemy enemy;
	Player player;
	Vector2d vector2d;

	// Boosters own position
	Vector2d boosterPosition;

	bool exsists = false;
	bool collisionPlayerBooster = false;
	float boosterTime = 5;

	Vector2d FindBoosterPosition();

	// Booster functions ___________________________________________________________________________________
	void DrawBooster();

	void ExpandPlayerVision();

	void ExposeEnemyPosition(Vector2d inPlayerPosition, Vector2d inEnemyPosition);

	void BoosterTimer(Vector2d inPlayerPosition, Vector2d inEnemyPosition);
};