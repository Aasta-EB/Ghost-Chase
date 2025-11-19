#pragma once 
#include "Player.h"
#include "Enemy.h"


class Booster
{
public: 

	Enemy enemy;
	Player player;

	bool boosterExsits = false; 

	void DrawBooster();
	
	void ExpandPlayerVision();

	void ExposeEnemyPosition(Vector2d inPlayerPosition, Vector2d inEnemyPosition);

};