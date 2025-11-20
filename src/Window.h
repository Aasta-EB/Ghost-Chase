#pragma once
#include "Player.h"
#include "Grid.h"
#include "Enemy.h"
#include "Fog.h"
#include "Booster.h"

class Window
{
public:

	Player player;
	Grid map;
	Enemy enemy;
	Fog fog = { 0 };
	Booster booster;

	float timeGame; 

	void TimeCounter();

	// Initiates game ____________________________________________________________________________________________________________________________________________________________
	void InitGame();

	void DrawGame();

	void UpdateDrawFrame();
};
