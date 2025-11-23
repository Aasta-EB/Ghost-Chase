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
	Fog fog;
	Booster booster;
	Vector2d vector2d;

	float timeGame;

	void ExposeEnemyBooster();

	void DropHint();

	void TimeCounter();

	void StartWindow();

	void GameOn();

	void GameWonWindow();

	void GameOverWindow();

	void GamePausedWindow();

	// Initiates game ____________________________________________________________________________________________________________________________________________________________
	void InitGame();

	void DrawGame();

	void UpdateDrawFrame();
};
