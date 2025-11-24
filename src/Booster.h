#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Vector2d.h"

class Booster
{
public:

	// Initializes the classes
	Enemy enemy;
	Player player;
	Vector2d vector2d;


	// Boosters variables
	Vector2d boosterPosition;
	bool exsists = false;
	bool collisionPlayerBooster = false;
	float boosterTime = 5;

	// Selects a "random" position for the booster
	Vector2d FindBoosterPosition();

	// Draws the booster in it's chosen position
	void DrawBooster();

	// Expands player's vision (NOT IN USE)
	void ExpandPlayerVision();

	// Booster that exposes the enemys position and points in the direction
	void ExposeEnemyPosition(Vector2d inPlayerPosition, Vector2d inEnemyPosition);

	// Countdown timer for the duration of the booster
	void BoosterTimer(Vector2d inPlayerPosition, Vector2d inEnemyPosition);
};