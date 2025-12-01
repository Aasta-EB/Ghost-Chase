#include "Window.h"

// Initiates (prepares) the game for playing ________________________________________________________________________________________________________________________________________________________________________
void Window::InitGame()
{
	// Sets enemy variables
	enemy.enemyDirection = { 0, -1 };
	enemy.enemyHintExsists = false;
	enemy.dropHintTimer = 4.f;
	enemy.collisionUp = false;
	enemy.collisionDown = false;
	enemy.collisionLeft = false;
	enemy.collisionRight = false;
	enemy.justChangedDirection = false;
	enemy.position = { enemy.RandomEnemyPosition().x, enemy.RandomEnemyPosition().y };
	enemy.visualPosition = { enemy.position.x + 25, enemy.position.y + 25 };
	enemy.enemyDirection = { enemy.RandomEnemyDirection().x, enemy.RandomEnemyDirection().y };
	
	// Sets the enemy speed based on the game difficulty
	if (gameDifficulty == 0) enemy.framesCounterDivider = 15; // Easy
	else if (gameDifficulty == 1) enemy.framesCounterDivider = 10; // Medium
	else if (gameDifficulty == 2) enemy.framesCounterDivider = 5; // Hard


	// Sets player variables
	player.hintsCollected = 0;
	player.framesCounter = 0;
	player.position = { 13 * map.boxSize, 7 * map.boxSize };
	player.speed = { map.boxSize, 0 };
	player.playerDirection = { 1 , 0 };

	// Sets booster variables
	booster.FindBoosterPosition();
	booster.boosterTime = 5.f;
	booster.collisionPlayerBooster = false;

	// Sets the game time
	timeGame = 60;

	// Sets the new game state 
	player.gameState = 2; // Game on
}

// Counts the time left in game ___________________________________________________________________________________________________________________________________________________________________________
void Window::TimeCounter()
{
	if (timeGame > 0.f) timeGame -= GetFrameTime();

	// Rounding of number to have a whole number being printed
	int actualTime = std::round(timeGame);

	// Draws the time left, changes to red when less than 10 seconds left
	if (actualTime > 10)
	{
		DrawText(TextFormat("TIME: %d", actualTime), 1250, 20, 20, GRAY);
	}
	else
	{
		DrawText("TIME: ", 1250, 20, 20, GRAY);
		DrawText(TextFormat("%d", actualTime), 1250 + MeasureText("TIME: ", 20), 20, 20, RED);
	}
}

// Booster to expose the enemy's position ___________________________________________________________________________________________________________________________________________________
void Window::ActivateBooster()
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

// Makes the player able to set the game difficulty _________________________________________________________________________________________________________________________________________________________
void Window::SetGameDifficulty()
{
	DrawText("PRESS", GetScreenWidth() / 2 - MeasureText("PRESS [ARROWS] TO CHANGE DIFFICULTY", 20) / 2, GetScreenHeight() / 2 + 25, 20, GRAY);
	DrawText("[ARROWS]", GetScreenWidth() / 2 - MeasureText("PRESS [ARROWS] TO CHANGE DIFFICULTY", 20) / 2 + MeasureText("PRESS ", 20) + 5, GetScreenHeight() / 2 + 25, 20, YELLOW);
	DrawText("TO CHANGE DIFFICULTY", GetScreenWidth() / 2 - MeasureText("PRESS [ARROWS] TO CHANGE DIFFICULTY", 20) / 2 + MeasureText("PRESS [ARROWS] ", 20), GetScreenHeight() / 2 + 25, 20, GRAY);

	if (IsKeyPressed(KEY_UP))
	{
		gameDifficulty++;
		if (gameDifficulty > 2)
		{
			gameDifficulty = 0;
		}
	}
	if (IsKeyPressed(KEY_DOWN))
	{
		gameDifficulty--;
		if (gameDifficulty < 0)
		{
			gameDifficulty = 2;
		}
	}

	// Draws the current difficulty
	switch (gameDifficulty)
	{
	case 0:
		DrawText("DIFFICULTY: ", GetScreenWidth() / 2 - MeasureText("DIFFICULTY: MEDIUM", 35) / 2, 600, 35, GRAY);
		DrawText("EASY", GetScreenWidth() / 2 + 50, 600, 35, GREEN);
		break;
	case 1:
		DrawText("DIFFICULTY: ", GetScreenWidth() / 2 - MeasureText("DIFFICULTY: MEDIUM", 35) / 2, 600, 35, GRAY);
		DrawText("MEDIUM", GetScreenWidth() / 2 + 50, 600, 35, YELLOW);
		break;
	case 2:
		DrawText("DIFFICULTY: ", GetScreenWidth() / 2 - MeasureText("DIFFICULTY: MEDIUM", 35) / 2, 600, 35, GRAY);
		DrawText("HARD", GetScreenWidth() / 2 + 50, 600, 35, RED);
		break;
	}

}

// Draws the actual game is playing state __________________________________________________________________________________________________________________________________________________________________
void Window::GameOn()
{
	// Grid/map
	map.DrawMap();

	// Enemy related
	if (player.hintsCollected < 10)
	{
		enemy.DrawDropHint(player.centrePlayerPosition);
	}
	enemy.DrawEnemy(player.position);

	// Player related
	player.DrawPlayer();
	ActivateBooster();

	// Booster Arrow tester
	//booster.ExposeEnemyPosition(player.centrePlayerPosition, enemy.visualPosition);

	// Limited vision related
	if (player.hintsCollected < 10)
	{
		fov.DrawFOV({ player.position.x, player.position.y });
	}

	// Screen text
	DrawText("PRESS [P] TO PAUSE GAME", 50, 20, 20, GRAY);
	DrawText(TextFormat("HINTS COLLECTED: %d", player.hintsCollected), 1000, 20, 20, GRAY);
	TimeCounter();

	if (enemy.enemyHintExsists == true)
	{
		if (enemy.enemyHintPosition.x == player.centrePlayerPosition.x && enemy.enemyHintPosition.y == player.centrePlayerPosition.y)
		{
			player.hintsCollected += 1;
		}
	}

	// Calculates distance between enemy
	float distanceToEnemy = player.centrePlayerPosition.CalculateMagnitudeToTarget(enemy.visualPosition);

	// Changes game state
	if (distanceToEnemy < 50)
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

// Draws the start window of the game ______________________________________________________________________________________________________________________________________________________________________
void Window::StartWindow()
{
	// Screen text
	DrawText("GHOST-CHASE", GetScreenWidth() / 2 - MeasureText("GHOST-CHASE", 75) / 2, GetScreenHeight() / 2 - 150, 75, WHITE);
	DrawText("PRESS", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO START", 20) / 2, GetScreenHeight() / 2, 20, GRAY);
	DrawText("[ENTER]", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO START", 20) / 2 + MeasureText("PRESS ", 20) + 5, GetScreenHeight() / 2, 20, RED);
	DrawText("TO START", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO START", 20) / 2 + MeasureText("PRESS [ENTER] ", 20), GetScreenHeight() / 2, 20, GRAY);

	DrawText("PRESS", GetScreenWidth() / 2 - MeasureText("PRESS [SPACE] FOR HELP", 20) / 2, GetScreenHeight() / 2 + 50, 20, GRAY);
	DrawText("[SPACE]", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] FOR HELP", 20) / 2 + MeasureText("PRESS ", 20), GetScreenHeight() / 2 + 50, 20, DARKBLUE);
	DrawText("FOR HELP", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] FOR HELP", 20) / 2 + MeasureText("PRESS [SPACE] ", 20), GetScreenHeight() / 2 + 50, 20, GRAY);

	// Sets game difficulty
	SetGameDifficulty();

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

	// Goes to help screen after user input
	if (IsKeyPressed(KEY_SPACE))
	{
		player.gameState = 6; // Pause screen
	}

	// Starts game after user input
	if (IsKeyPressed(KEY_ENTER))
	{
		InitGame();
		player.gameState = 2; // Game on
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

	// Sets game difficulty
	SetGameDifficulty();

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
	
	// Sets game difficulty
	SetGameDifficulty();

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

// Draws the help window _________________________________________________________________________________________________________________________________________________________________________
void Window::HelpWindow()
{
	// Screen text
	DrawText("HELP", GetScreenWidth() / 2 - MeasureText("HELP", 50) / 2, 25, 50, GRAY);
	
	DrawText("MOVING: ", 50, 100, 20, YELLOW);
	DrawText("TO MOVE AROUND, USE WASD OR THE ARROW-KEYS", 50, 120, 20, GRAY);

	DrawText("DIFFICULTIES: ", 50, 150, 20, RED);
	DrawText("EASY: ENEMY IS SLOWER THAN PLAYER", 50, 170, 20, GRAY);
	DrawText("MEDIUM: ENEMY AND PLAYER HAS EQUAL SPEED", 50, 190, 20, GRAY);
	DrawText("HARD: ENEMY IS FASTER THAN PLAYER", 50, 210, 20, GRAY);

	DrawText("ENEMY HINTS: ", 50, 240, 20, ORANGE);
	DrawText("IS IT A LITTLE TOO DARK? COLLECT 10 ENEMY HINTS TO HAVE THE FEILD OF VIEW DISSAPEAR", 50, 260, 20, GRAY);

	DrawText("BOOSTER: ", 50, 290, 20, GREEN);
	DrawText("AFTER 30 SECONDS A BOOSTER WILL SPAWN", 50, 310, 20, GRAY);
	DrawText("COLLECT IT TO GET AN INDICATION ON THE ENEMY'S POSITION FOR 5 SECONDS", 50, 330, 20, GRAY);

	DrawText("TIMER: ", 50, 360, 20, DARKBLUE);
	DrawText("YOU HAVE 60 SECONDS TO CATCH THE ENEMY, IF THE TIME RUNS OUT YOU LOSE", 50, 380, 20, GRAY);

	DrawText("PRESS", GetScreenWidth() / 2 - MeasureText("PRESS [M] TO GO BACK TO MAIN SCREEN", 20) / 2, 650, 20, GRAY);
	DrawText("[M]", GetScreenWidth() / 2 - MeasureText("PRESS [M] TO GO BACK TO MAIN SCREEN", 20) / 2 + MeasureText("PRESS ", 20), 650, 20, GREEN);
	DrawText("TO GO BACK TO MAIN SCREEN", GetScreenWidth() / 2 - MeasureText("PRESS [M] TO GO BACK TO MAIN SCREEN", 20) / 2 + MeasureText("PRESS [M] ", 20), 650, 20, GRAY);

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
	DrawRectangle(1100, 450, 50, 250, DARKBLUE);
	DrawRectangle(1000, 550, 100, 50, DARKBLUE);

	DrawCircle(1075, 525, 5, GREEN);
	
	// Changes game state after user input
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
	
		// Game states , 1 = Start window, 2 = Game on, 3 = Game Paused, 4 = Game Won, 5 = Game Over, 6 = Help screen
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

		case 6:
			HelpWindow();
			break;

	}

	EndDrawing();
}

// Updates each frame _________________________________________________________________________________________________________________________________________________________________________________
void Window::UpdateDrawFrame()
{
	player.UpdatePlayer();
	DrawGame();
}