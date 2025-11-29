#include "Window.h"

// Initiates (prepares) the game for playing ________________________________________________________________________________________________________________________________________________________________________
void Window::InitGame()
{
	// Sets enemy variables
	enemy.enemyDirection = { 0, -1 };
	enemy.enemyHintExsists_1 = false;
	enemy.enemyHintExsists_2 = false;
	enemy.enemyHintExsists_3 = false;
	enemy.enemyHintExsists_4 = false;
	enemy.enemyHintExsists_5 = false;
	enemy.dropHintTimer = 10.f;
	enemy.enemyHintNumber = 0.5f;
	enemy.collisionUp = false;
	enemy.collisionDown = false;
	enemy.collisionLeft = false;
	enemy.collisionRight = false;
	enemy.justChangedDirection = false;
	enemy.position = { enemy.RandomEnemyPosition().x, enemy.RandomEnemyPosition().y };
	enemy.visualPosition = { enemy.position.x + 25, enemy.position.y + 25 };
	enemy.enemyDirection = { enemy.RandomEnemyDirection().x, enemy.RandomEnemyDirection().y };

	// Sets player variables
	player.playerScore = 0;
	player.framesCounter = 0;
	player.position = { 13 * map.boxSize, 7 * map.boxSize };
	player.size = { map.boxSize, map.boxSize };
	player.speed = { map.boxSize, 0 };
	player.playerDirection = { 1 , 0 };
	player.playerPosition = { 0.0f, 0.0f }; // Do i really need this???

	// Sets booster variables
	booster.FindBoosterPosition();
	booster.boosterTime = 5.f;
	booster.collisionPlayerBooster = false;

	// Sets the game time
	timeGame = 60;

	// Sets the new game state 
	player.gameState = 2; // Game on
}

// Booster to expose the enemy's position ___________________________________________________________________________________________________________________________________________________
void Window::ExposeEnemyBooster()
{
	// Booster exsists after 30 seconds
	if (timeGame <= 30.f && timeGame >= 0.f && booster.collisionPlayerBooster == false && booster.boosterTime > 0)
	{
		booster.DrawBooster();
		booster.exsists = true;
	}
	else
	{
		booster.exsists = false;
	}

	// Collision between player and booster
	if (booster.exsists == true && player.centrePlayerPosition.x == booster.boosterPosition.x && player.centrePlayerPosition.y == booster.boosterPosition.y)
	{
		booster.collisionPlayerBooster = true;
	}
	if (booster.collisionPlayerBooster == true)
	{
		booster.BoosterTimer(player.centrePlayerPosition, enemy.visualPosition);
	}
}

// Enemy drops hint at its current position, player gets points if collected ________________________________________________________________________________________________________________
void Window::DropHint()
{
	enemy.DrawDropHint();

	// Collisioncheck between hint and player
	if (enemy.enemyHintExsists_1 == true)
	{
		if (player.centrePlayerPosition.x == enemy.enemyHintPos_1.x && player.centrePlayerPosition.y == enemy.enemyHintPos_1.y)
		{
			player.playerScore += 1;
			enemy.enemyHintExsists_1 = false;
		}
	}
	if (enemy.enemyHintExsists_2 == true)
	{
		if (player.centrePlayerPosition.x == enemy.enemyHintPos_2.x && player.centrePlayerPosition.y == enemy.enemyHintPos_2.y)
		{
			player.playerScore += 1;
			enemy.enemyHintExsists_2 = false;
		}
	}
	if (enemy.enemyHintExsists_3 == true)
	{
		if (player.centrePlayerPosition.x == enemy.enemyHintPos_3.x && player.centrePlayerPosition.y == enemy.enemyHintPos_3.y)
		{
			player.playerScore += 1;
			enemy.enemyHintExsists_3 = false;
		}
	}
	if (enemy.enemyHintExsists_4 == true)
	{
		if (player.centrePlayerPosition.x == enemy.enemyHintPos_4.x && player.centrePlayerPosition.y == enemy.enemyHintPos_4.y)
		{
			player.playerScore += 1;
			enemy.enemyHintExsists_4 = false;
		}
	}
	if (enemy.enemyHintExsists_5 == true)
	{
		if (player.centrePlayerPosition.x == enemy.enemyHintPos_4.x && player.centrePlayerPosition.y == enemy.enemyHintPos_4.y)
		{
			player.playerScore += 1;
			enemy.enemyHintExsists_5 = false;
		}
	}
}

// Counts the time left in game ___________________________________________________________________________________________________________________________________________________________________________
void Window::TimeCounter()
{
	if (timeGame > 0.f) timeGame -= GetFrameTime();

	// Rounding of number to have a whole number being printed
	int actualTime = std::round(timeGame);

	DrawText(TextFormat("TIME: %d", actualTime), 1250, 20, 20, GRAY);
}

// Draws the start window of the game ______________________________________________________________________________________________________________________________________________________________________
void Window::StartWindow()
{
	// Screen text
	DrawText("GHOST-CHASE", GetScreenWidth() / 2 - MeasureText("GHOST-CHASE", 75) / 2, GetScreenHeight() / 2 - 150, 75, WHITE);
	DrawText("PRESS", GetScreenWidth() / 2 - MeasureText("Press [ENTER] TO START", 20) / 2, GetScreenHeight() / 2, 20, GRAY);
	DrawText("[ENTER]", GetScreenWidth() / 2 - MeasureText("Press [ENTER] TO START", 20) / 2 + MeasureText("Press ", 20) + 5, GetScreenHeight() / 2, 20, RED);
	DrawText("TO START", GetScreenWidth() / 2 - MeasureText("Press [ENTER] TO START", 20) / 2 + MeasureText("Press [ENTER] ", 20), GetScreenHeight() / 2, 20, GRAY);

	// Draws waves using calculate cosine wave
	for (float x = 0; x < GetScreenHeight(); x++)
	{
		Vector2d wavePosition = vector2d.CalculateCosineWave(10.f, 50.f, x);
		DrawPixel(20 + wavePosition.y, wavePosition.x, YELLOW);
		DrawPixel(21 + wavePosition.y, wavePosition.x, YELLOW);
		DrawPixel(19 + wavePosition.y, wavePosition.x, YELLOW);

		DrawPixel(1380 + wavePosition.y, wavePosition.x, YELLOW);
		DrawPixel(1381 + wavePosition.y, wavePosition.x, YELLOW);
		DrawPixel(1379 + wavePosition.y, wavePosition.x, YELLOW);
	}

	// Draws visual
	DrawRectangle(250, 0, 50, 200, DARKBLUE);
	DrawRectangle(1100, 450, 50, 250, DARKBLUE);
	DrawRectangle(1000, 550, 100, 50, DARKBLUE);

	DrawRectangle(350, 300, 50, 50, PINK);
	DrawCircle(1025, 150, 25, YELLOW);

	DrawCircle(1075, 525, 5, GREEN);

	// Starts game after user input
	if (IsKeyPressed(KEY_ENTER))
	{
		InitGame();
		player.gameState = 2; // Game on
	}
}

// Draws the actual game is playing state __________________________________________________________________________________________________________________________________________________________________
void Window::GameOn()
{
	// Grid/map
	map.DrawMap();

	// Enemy related
	DropHint();
	enemy.DrawEnemy(player.playerPosition);

	// Player related
	player.DrawPlayer();
	ExposeEnemyBooster();

	// Booster Arrow tester
	//booster.ExposeEnemyPosition(player.centrePlayerPosition, enemy.visualPosition);

	// Limited vision related
	if (player.playerScore < 5)
	{
		fog.DrawFog({ player.playerPosition.x, player.playerPosition.y });
	}

	// Screen text
	DrawText("PRESS [P] TO PAUSE GAME", 50, 20, 20, GRAY);
	DrawText(TextFormat("HINTS COLLECTED: %d", player.playerScore), 1000, 20, 20, GRAY);
	TimeCounter();

	// Calculates distance between enemy
	float distanceToEnemy = player.centrePlayerPosition.CalculateMagnitudeToTarget(enemy.visualPosition);
	enemy.distanceToPlayer = distanceToEnemy;

	// Changes game state
	if (distanceToEnemy <= 45)
	{
		player.gameState = 4; // Game won
	}
	if (timeGame <= 0.f)
	{
		player.gameState = 5; // Game over
	}

	// Changes game state after user input
	if (IsKeyPressed(KEY_P))
	{
		player.gameState = 3; // Pause game
	}
}

// Draws the win screen ___________________________________________________________________________________________________________________________________________________________________________
void Window::GameWonWindow()
{
	// Screen text
	DrawText("GAME WON", GetScreenWidth() / 2 - MeasureText("GAME WON", 50) / 2, GetScreenHeight() / 2 - 100, 50, GRAY);
	DrawText("PRESS", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2, GetScreenHeight() / 2, 20, GRAY);
	DrawText("[ENTER]", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2 + MeasureText("PRESS ", 20) + 5, GetScreenHeight() / 2, 20, RED);
	DrawText("TO PLAY AGAIN", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2 + MeasureText("PRESS [ENTER] ", 20), GetScreenHeight() / 2, 20, GRAY);

	DrawText("PRESS", GetScreenWidth() / 2 - MeasureText("PRESS [M] TO GO BACK TO MAIN SCREEN", 20) / 2, GetScreenHeight() / 2 - 25, 20, GRAY);
	DrawText("[M]", GetScreenWidth() / 2 - MeasureText("PRESS [M] TO GO BACK TO MAIN SCREEN", 20) / 2 + MeasureText("PRESS ", 20), GetScreenHeight() / 2 - 25, 20, GREEN);
	DrawText("TO GO BACK TO MAIN SCREEN", GetScreenWidth() / 2 - MeasureText("PRESS [M] TO GO BACK TO MAIN SCREEN", 20) / 2 + MeasureText("PRESS [M] ", 20), GetScreenHeight() / 2 - 25, 20, GRAY);

	// Draws waves using calculate cosine wave
	for (float x = 0; x < GetScreenHeight(); x++)
	{
		Vector2d wavePosition = vector2d.CalculateCosineWave(10.f, 50.f, x);
		DrawPixel(20 + wavePosition.y, wavePosition.x, YELLOW);
		DrawPixel(21 + wavePosition.y, wavePosition.x, YELLOW);
		DrawPixel(19 + wavePosition.y, wavePosition.x, YELLOW);

		DrawPixel(1380 + wavePosition.y, wavePosition.x, YELLOW);
		DrawPixel(1381 + wavePosition.y, wavePosition.x, YELLOW);
		DrawPixel(1379 + wavePosition.y, wavePosition.x, YELLOW);
	}

	// Changes game state after user input
	if (IsKeyPressed(KEY_ENTER))
	{
		InitGame(); // Starts the game again
	}
	if (IsKeyPressed(KEY_M))
	{
		player.gameState = 1; // Back to main menu
	}
}

// Draws the game over screen ___________________________________________________________________________________________________________________________________________________________________________
void Window::GameOverWindow()
{
	// Screen text
	DrawText("GAME OVER", GetScreenWidth() / 2 - MeasureText("GAME OVER", 50) / 2, GetScreenHeight() / 2 - 100, 50, GRAY);
	DrawText("PRESS", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2, GetScreenHeight() / 2, 20, GRAY);
	DrawText("[ENTER]", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2 + MeasureText("PRESS ", 20) + 5, GetScreenHeight() / 2, 20, RED);
	DrawText("TO PLAY AGAIN", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2 + MeasureText("PRESS [ENTER] ", 20), GetScreenHeight() / 2, 20, GRAY);

	DrawText("PRESS", GetScreenWidth() / 2 - MeasureText("PRESS [M] TO GO BACK TO MAIN SCREEN", 20) / 2, GetScreenHeight() / 2 - 25, 20, GRAY);
	DrawText("[M]", GetScreenWidth() / 2 - MeasureText("PRESS [M] TO GO BACK TO MAIN SCREEN", 20) / 2 + MeasureText("PRESS ", 20), GetScreenHeight() / 2 - 25, 20, GREEN);
	DrawText("TO GO BACK TO MAIN SCREEN", GetScreenWidth() / 2 - MeasureText("PRESS [M] TO GO BACK TO MAIN SCREEN", 20) / 2 + MeasureText("PRESS [M] ", 20), GetScreenHeight() / 2 - 25, 20, GRAY);

	// Draws waves using calculate cosine wave
	for (float x = 0; x < GetScreenHeight(); x++)
	{
		Vector2d wavePosition = vector2d.CalculateCosineWave(10.f, 50.f, x);
		DrawPixel(20 + wavePosition.y, wavePosition.x, YELLOW);
		DrawPixel(21 + wavePosition.y, wavePosition.x, YELLOW);
		DrawPixel(19 + wavePosition.y, wavePosition.x, YELLOW);

		DrawPixel(1380 + wavePosition.y, wavePosition.x, YELLOW);
		DrawPixel(1381 + wavePosition.y, wavePosition.x, YELLOW);
		DrawPixel(1379 + wavePosition.y, wavePosition.x, YELLOW);
	}

	// Changes game state after user input
	if (IsKeyPressed(KEY_ENTER))
	{
		InitGame(); // Starts the game again
	}
	if (IsKeyPressed(KEY_M))
	{
		player.gameState = 1; // Back to main menu

	}
}

// Draws the game paused screen ___________________________________________________________________________________________________________________________________________________________________________
void Window::GamePausedWindow()
{
	// Screen text
	DrawText("GAME IS PAUSED", GetScreenWidth() / 2 - MeasureText("GAME IS PAUSED", 50) / 2, GetScreenHeight() / 2 - 100, 50, GRAY);
	DrawText("PRESS", GetScreenWidth() / 2 - MeasureText("Press [ENTER] TO START AGAIN", 20) / 2, GetScreenHeight() / 2, 20, GRAY);
	DrawText("[ENTER]", GetScreenWidth() / 2 - MeasureText("Press [ENTER] TO START AGAIN", 20) / 2 + MeasureText("Press ", 20) + 5, GetScreenHeight() / 2, 20, RED);
	DrawText("TO START AGAIN", GetScreenWidth() / 2 - MeasureText("Press [ENTER] TO START AGAIN", 20) / 2 + MeasureText("Press [ENTER] ", 20), GetScreenHeight() / 2, 20, GRAY);

	DrawText("PRESS", GetScreenWidth() / 2 - MeasureText("PRESS [M] TO GO BACK TO MAIN SCREEN", 20) / 2, GetScreenHeight() / 2 - 25, 20, GRAY);
	DrawText("[M]", GetScreenWidth() / 2 - MeasureText("PRESS [M] TO GO BACK TO MAIN SCREEN", 20) / 2 + MeasureText("PRESS ", 20), GetScreenHeight() / 2 - 25, 20, GREEN);
	DrawText("TO GO BACK TO MAIN SCREEN", GetScreenWidth() / 2 - MeasureText("PRESS [M] TO GO BACK TO MAIN SCREEN", 20) / 2 + MeasureText("PRESS [M] ", 20), GetScreenHeight() / 2 - 25, 20, GRAY);

	// Draws waves using calculate cosine wave
	for (float x = 0; x < GetScreenHeight(); x++)
	{
		Vector2d wavePosition = vector2d.CalculateCosineWave(10.f, 50.f, x);
		DrawPixel(20 + wavePosition.y, wavePosition.x, YELLOW);
		DrawPixel(21 + wavePosition.y, wavePosition.x, YELLOW);
		DrawPixel(19 + wavePosition.y, wavePosition.x, YELLOW);

		DrawPixel(1380 + wavePosition.y, wavePosition.x, YELLOW);
		DrawPixel(1381 + wavePosition.y, wavePosition.x, YELLOW);
		DrawPixel(1379 + wavePosition.y, wavePosition.x, YELLOW);
	}

	// Changes game state after user input
	if (IsKeyPressed(KEY_ENTER))
	{
		player.gameState = 2; // Back to playing the game
	}
	if (IsKeyPressed(KEY_M))
	{
		player.gameState = 1; // Back to main menu
	}
}

// Draws the entire game ___________________________________________________________________________________________________________________________________________________________________________
void Window::DrawGame()
{
	BeginDrawing();

	ClearBackground(BLACK);

	switch (player.gameState){
	
		// Game states , 1 = Start window, 2 = Game on, 3 = Game Paused, 4 = Game Won, 5 = Game Over
		case 1:
			//InitGame();
			StartWindow();
			break;

		case 2:
			GameOn();
			break;

		case 3:
			GamePausedWindow();
			break;

		case 4:
			GameWonWindow();
			break;

		case 5:
			GameOverWindow();
			break;

	}

	EndDrawing();
}

// Updates each frame ________________________________________________________________________________________________________________________________________________________
void Window::UpdateDrawFrame()
{
	player.UpdatePlayer();
	DrawGame();
}