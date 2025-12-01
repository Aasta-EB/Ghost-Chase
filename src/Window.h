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
	int gameDifficulty = 1; // 0 = Easy, 1 = Medium, 2 = Hard

	// Game time
	float timeGame;
	
	// Initiates (prepares) the game for playing
	void InitGame();

	// Counts the time left in game
	void TimeCounter();

	// Booster to expose the enemy's position
	void ActivateBooster();

	// Makes the player able to set the game difficulty
	void SetGameDifficulty();

	// Draws the actual game is playing state
	void GameOn();

	// Draws the start window of the game
	void StartWindow();

	// Draws the win screen
	void GameWonWindow();

	// Draws the game over screen
	void GameOverWindow();

	// Draws the game paused screen
	void GamePausedWindow();

	// Draws the help screen
	void HelpWindow();

	// Draws the entire game
	void DrawGame();

	// Updates each frame
	void UpdateDrawFrame();
};
