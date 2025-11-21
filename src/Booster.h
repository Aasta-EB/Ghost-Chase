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

	int timeGame = 0;

	bool boosterExsits = false; 

	void DrawBooster();
	
	void ExpandPlayerVision();

	void ExposeEnemyPosition(Vector2d inPlayerPosition, Vector2d inEnemyPosition);

};