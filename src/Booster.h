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
	Vector2d boosterPosition;

	bool exsists = false; 

	bool collisionPlayerBooster = false; 

	int timeGame = 0;

	bool boosterExsits = false; 

	Vector2d FindBoosterPosition();

	void DrawBooster();
	
	void ExpandPlayerVision();

	void ExposeEnemyPosition(Vector2d inPlayerPosition, Vector2d inEnemyPosition);

};