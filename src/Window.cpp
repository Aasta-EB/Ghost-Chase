#include "Window.h"

void Window::TimeCounter()
{
	if (timeGame > 0.f) timeGame -= GetFrameTime();

	int actualTime = std::round(timeGame);

	DrawText(TextFormat("Time: %d", actualTime), 1200, 20, 20, GRAY);
}

void Window::InitGame()
{
	player.framesCounter = 0;
	player.gameOver = true;

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

	if (player.gameOver == false && player.gamePaused == false)
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
			player.gameOver = true;
		}

	}
	else if (player.gameOver = true)
	{
		InitGame();
		DrawText("GAME OVER", GetScreenWidth() / 2 - MeasureText("GAME OVER", 20) / 2, GetScreenHeight() / 2 - 50, 20, GRAY);
		DrawText("PRESS [ENTER] TO START", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO START", 20) / 2, GetScreenHeight() / 2, 20, GRAY);

		if (IsKeyPressed(KEY_ENTER))
		{
			player.gameOver = false;
		}
	}
	else if (player.gamePaused = true)
	{
		DrawText("PRESS [ENTER] TO START AGAIN", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO START AGAIN", 20) / 2, GetScreenHeight() / 2, 20, GRAY);

		if (IsKeyPressed(KEY_ENTER))
		{
			player.gamePaused = false;
		}
	}

	EndDrawing();
}

// Updates each frame ________________________________________________________________________________________________________________________________________________________
void Window::UpdateDrawFrame()
{
	player.UpdatePlayer();
	DrawGame();
}