#pragma once
#include "Player.h"
#include "Grid.h"
#include "Enemy.h"
#include "Fog.h"
#include "Booster.h"

class Window
{
public:

	// Game objects
	Player player;
	Grid map;
	Enemy enemy;
	Fog fov;
	Booster booster;
	Vector2d vector2d;

	// Game difficulty 
	int gameDifficulty = 1; // 0 = Easy, 1 = Medium, 2 = Hard, 3 = Difficult

	// Game time
	float timeGame;
	
	// Initiates (prepares) the game for playing
	void InitGame();

	// Booster to expose the enemy's position
	void ExposeEnemyBooster();

	// Enemy drops hint at its current position, player gets points if collected
	void DropHint();

	// Makes the player able to set the game difficulty
	void SetGameDifficulty();

	// Counts the time left in game
	void TimeCounter();

	// Draws the start window of the game
	void StartWindow();

	// Draws the actual game is playing state
	void GameOn();

	// Draws the win screen
	void GameWonWindow();

	// Draws the game over screen
	void GameOverWindow();

	// Draws the game paused screen
	void GamePausedWindow();

	// Draws the entire game
	void DrawGame();

	// Updates each frame
	void UpdateDrawFrame();
};
