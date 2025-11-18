#pragma once
#include "Player.h"
#include "Grid.h"
#include "Enemy.h"

class Window
{
public:

	Player player;
	Grid map;
	Enemy enemy;

	// Initiates game ____________________________________________________________________________________________________________________________________________________________
	void InitGame();

	void DrawGame();

	void UpdateDrawFrame();
};
