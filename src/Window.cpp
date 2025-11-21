#include "Window.h"

void Window::TimeCounter()
{
	if (timeGame > 0.f) timeGame -= GetFrameTime();

	int actualTime = std::round(timeGame);

	DrawText(TextFormat("Time: %d", actualTime), 1200, 20, 20, GRAY);
}

void Window::StartWindow()
{
	DrawText("GHOST-CHASE", GetScreenWidth() / 2 - MeasureText("GHOST-CHASE", 75) / 2, GetScreenHeight() / 2 - 150, 75, WHITE);
	DrawText("PRESS", GetScreenWidth() / 2 - MeasureText("Press [ENTER] TO START", 20) / 2, GetScreenHeight() / 2, 20, GRAY);
	DrawText("[ENTER]", GetScreenWidth() / 2 - MeasureText("Press [ENTER] TO START", 20) / 2 + MeasureText("Press ", 20) + 5, GetScreenHeight() / 2, 20, RED);
	DrawText("TO START", GetScreenWidth() / 2 - MeasureText("Press [ENTER] TO START", 20) / 2 + MeasureText("Press [ENTER] ", 20), GetScreenHeight() / 2, 20, GRAY);

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

	DrawRectangle(250, 0, 50, 200, DARKBLUE);
	DrawRectangle(1100, 450, 50, 250, DARKBLUE);
	DrawRectangle(1000, 550, 100, 50, DARKBLUE);

	DrawRectangle(350, 300, 50, 50, PINK);
	DrawCircle(1025, 150, 25, YELLOW);

	DrawCircle(1075, 525, 5, GREEN);

	if (IsKeyPressed(KEY_ENTER))
	{
		player.gameStart = false; 
	}

}

void Window::GameWonWindow()
{
	DrawText("GAME WON", GetScreenWidth() / 2 - MeasureText("GAME WON", 50) / 2, GetScreenHeight() / 2 - 100, 50, GRAY);
	DrawText("PRESS", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2, GetScreenHeight() / 2, 20, GRAY);
	DrawText("[ENTER]", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2 + MeasureText("PRESS ", 20) + 5, GetScreenHeight() / 2, 20, RED);
	DrawText("TO PLAY AGAIN", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2 + MeasureText("PRESS [ENTER] ", 20), GetScreenHeight() / 2, 20, GRAY);

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

	if (IsKeyPressed(KEY_ENTER))
	{
		InitGame();
	}
}

void Window::GameOverWindow()
{
	DrawText("GAME OVER", GetScreenWidth() / 2 - MeasureText("GAME OVER", 50) / 2, GetScreenHeight() / 2 - 100, 50, GRAY);
	DrawText("PRESS", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2, GetScreenHeight() / 2, 20, GRAY);
	DrawText("[ENTER]", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2 + MeasureText("PRESS ", 20) + 5, GetScreenHeight() / 2, 20, RED);
	DrawText("TO PLAY AGAIN", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2 + MeasureText("PRESS [ENTER] ", 20), GetScreenHeight() / 2, 20, GRAY);

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

	if (IsKeyPressed(KEY_ENTER))
	{
		InitGame();
	}

}

void Window::GamePausedWindow()
{
	DrawText("GAME IS PAUSED", GetScreenWidth() / 2 - MeasureText("GAME IS PAUSED", 50) / 2, GetScreenHeight() / 2 - 100, 50, GRAY);
	DrawText("PRESS", GetScreenWidth() / 2 - MeasureText("Press [ENTER] TO START AGAIN", 20) / 2, GetScreenHeight() / 2, 20, GRAY);
	DrawText("[ENTER]", GetScreenWidth() / 2 - MeasureText("Press [ENTER] TO START AGAIN", 20) / 2 + MeasureText("Press ", 20) + 5, GetScreenHeight() / 2, 20, RED);
	DrawText("TO START AGAIN", GetScreenWidth() / 2 - MeasureText("Press [ENTER] TO START AGAIN", 20) / 2 + MeasureText("Press [ENTER] ", 20), GetScreenHeight() / 2, 20, GRAY);

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

	if (IsKeyPressed(KEY_ENTER))
	{
		player.gamePaused = false;
	}
}

void Window::InitGame()
{
	player.framesCounter = 0;

	player.gameWon = false;
	player.gameOver = false; 
	player.gamePaused = false;

	player.allowMove = false;

	map.offset.x = map.windowWidth % int(map.boxSize);
	map.offset.y = map.windowHeight % int(map.boxSize);

	player.position = Vector2d{ 1400 / 2, 700 / 2 };
	player.size = Vector2d{ map.boxSize, map.boxSize };
	player.speed = Vector2d{ map.boxSize, 0 };

	player.playerPosition = Vector2d{ 0.0f, 0.0f };

	enemy.position = { 15 * 50,10 * 50 };
	enemy.visualPosition = { enemy.position.x + 25, enemy.position.y + 25 };

	timeGame = 60;
}

// Draws the entire game ___________________________________________________________________________________________________________________________________________________________________________
void Window::DrawGame()
{
	BeginDrawing();

	ClearBackground(BLACK);

	if (player.gameOver == false && player.gamePaused == false && player.gameWon == false && player.gameStart == false)
	{
		// Draw grid lines
		/*for (int i = 0; i < map.windowWidth / map.boxSize + 1; i++)
		{
			DrawLineV(Vector2{ map.boxSize * i + map.offset.x / 2, map.offset.y / 2 }, Vector2{ map.boxSize * i + map.offset.x / 2, map.windowHeight - map.offset.y / 2 }, LIGHTGRAY);
		}*/

		/*for (int i = 0; i < map.windowHeight / map.boxSize + 1; i++)
		{
			DrawLineV(Vector2{ map.offset.x / 2, map.boxSize * i + map.offset.y / 2 }, Vector2{ map.windowWidth - map.offset.x / 2, map.boxSize * i + map.offset.y / 2 }, LIGHTGRAY);
		}*/

		map.DrawMap();

		enemy.DrawEnemy(player.playerPosition);

		// Draw Player
		player.DrawPlayer();

		DrawText("PRESS [P] TO PAUSE GAME", 50, 20, 20, GRAY);

		if (IsKeyPressed(KEY_P))
		{
			player.gamePaused = true;
		}

		float distanceToEnemy = player.centrePlayerPosition.CalculateDeltatoTarget(enemy.visualPosition);
		enemy.distanceToPlayer = distanceToEnemy;
		TimeCounter();
		//std::cout << distanceToEnemy << "\n";
		//DrawLine(player.centrePlayerPosition.x, player.centrePlayerPosition.y, enemy.visualPosition.x, enemy.visualPosition.y, RED);

		//booster.ExposeEnemyPosition(player.centrePlayerPosition, enemy.visualPosition);
		booster.DrawBooster();

		if (distanceToEnemy <= 25)
		{
			player.gameWon = true;
		}
		if (timeGame <= 0.f)
		{
			player.gameOver = true; 
		}
	}
	else if (player.gameOver = true && !player.gamePaused && !player.gameStart && !player.gameWon)
	{
		GameOverWindow();
	}
	else if (player.gamePaused = true && !player.gameStart && !player.gameWon && !player.gameOver)
	{
		GamePausedWindow();
	}
	else if (player.gameWon = true && !player.gamePaused && !player.gameStart && !player.gameOver)
	{
		GameWonWindow();
	}
	else if (player.gameStart = true && !player.gamePaused)
	{
		InitGame();
		StartWindow();
	}

	EndDrawing();
}

// Updates each frame ________________________________________________________________________________________________________________________________________________________
void Window::UpdateDrawFrame()
{
	player.UpdatePlayer();
	DrawGame();
}