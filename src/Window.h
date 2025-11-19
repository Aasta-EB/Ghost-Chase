#pragma once
#include "Player.h"
#include "Grid.h"
#include "Enemy.h"
#include "Fog.h"

class Window
{
public:

	Player player;
	Grid map;
	Enemy enemy;
	Fog fog = { 0 };

	// Initiates game ____________________________________________________________________________________________________________________________________________________________
	void InitGame();

	void DrawGame();

	void UpdateDrawFrame();
};
