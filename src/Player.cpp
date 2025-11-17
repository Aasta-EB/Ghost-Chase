#include "Player.h"

// The players collision check __________________________________________________________________________________________________________________________________
void Player::CollisionCheck()
{
	int playerPositionX = position.x / 50;
	int playerPositionY = position.y / 50;

	if (playerDirection.x == 1)
	{
		playerPositionX = (position.x + 50) / 50;
		playerPositionY = position.y / 50;

		if (map.map[playerPositionY][playerPositionX] == 1)
		{
			collisionRight = true;
		}
		else
		{
			collisionRight = false;
		}
	}
	if (playerDirection.x == -1)
	{
		playerPositionX = (position.x - 50) / 50;
		playerPositionY = position.y / 50;
		if (map.map[playerPositionY][playerPositionX] == 1)
		{
			collisionLeft = true;
		}
		else
		{
			collisionLeft = false;
		}
	}
	if (playerDirection.y == -1)
	{
		playerPositionX = position.x / 50;
		playerPositionY = (position.y - 50) / 50;
		if (map.map[playerPositionY][playerPositionX] == 1)
		{
			collisionUp = true;
		}
		else
		{
			collisionUp = false;
		}
	}
	if (playerDirection.y == 1)
	{
		playerPositionX = position.x / 50;
		playerPositionY = (position.y + 50) / 50;
		if (map.map[playerPositionY][playerPositionX] == 1)
		{
			collisionDown = true;
		}
		else
		{
			collisionDown = false;
		}
	}
	//std::cout << playerPositionX << " , " << playerPositionY << "\n";
}

// Update of the game (happens each frame) also player movement __________________________________________________________________________________________________
void Player::UpdateGame()
{
	if (!gameOver)
	{
		// Player control

		if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D) && allowMove)
		{
			CollisionCheck();
			if (playerDirection.x == 0 || playerDirection.x == -1 && collisionRight == false)
			{
				speed = Vector2d{ map.boxSize, 0 };
				allowMove = false;
				playerDirection = { 1,0 };
			}
			else if (playerDirection.x == 1 && collisionRight == false)
			{
				speed = Vector2d{ map.boxSize, 0 };
				allowMove = false;
				playerDirection = { 1,0 };
			}
		}
		if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A) && allowMove)
		{
			CollisionCheck();
			if (playerDirection.x == 0 || playerDirection.x == 1 && collisionLeft == false)
			{
				speed = Vector2d{ -map.boxSize, 0 };
				allowMove = false;
				playerDirection = { -1,0 };
			}
			else if (playerDirection.x == -1 && collisionLeft == false)
			{
				speed = Vector2d{ -map.boxSize, 0 };
				allowMove = false;
				playerDirection = { -1,0 };
			}
		}
		if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W) && allowMove)
		{
			CollisionCheck();
			if (playerDirection.y == 0 || playerDirection.y == -1 && collisionUp == false)
			{
				speed = Vector2d{ 0, -map.boxSize };
				allowMove = false;
				playerDirection = { 0,-1 };
			}
			else if (playerDirection.y == -1 && collisionUp == false)
			{
				speed = Vector2d{ 0, -map.boxSize };
				allowMove = false;
				playerDirection = { 0,-1 };
			}
		}
		if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S) && allowMove)
		{
			CollisionCheck();
			if (playerDirection.y == 0 || playerDirection.y == 1 && collisionDown == false)
			{
				speed = Vector2d{ 0, map.boxSize };
				allowMove = false;
				playerDirection = { 0,1 };
			}
			else if (playerDirection.y == 1 && collisionDown == false)
			{
				speed = Vector2d{ 0, map.boxSize };
				allowMove = false;
				playerDirection = { 0,1 };
			}
		}

		// Player movement
		for (int i = 0; i < counterTail; i++) playerPosition = position;

		if ((framesCounter % 10) == 0)
		{
			for (int i = 0; i < counterTail; i++)
			{
				if (i == 0)
				{
					CollisionCheck();
					if (collisionRight == false && collisionLeft == false && collisionUp == false && collisionDown == false)
					{
						position.x += speed.x;
						position.y += speed.y;
						allowMove = true;
					}
					else if (playerDirection.x == 1 && collisionRight == false)
					{
						position.x += speed.x;
						position.y += speed.y;
						allowMove = true;
					}
					else if (playerDirection.x == -1 && collisionLeft == false)
					{
						position.x += speed.x;
						position.y += speed.y;
						allowMove = true;
					}
					else if (playerDirection.y == -1 && collisionUp == false)
					{
						position.x += speed.x;
						position.y += speed.y;
						allowMove = true;
					}
					else if (playerDirection.y == 1 && collisionDown == false)
					{
						position.x += speed.x;
						position.y += speed.y;
						allowMove = true;
					}
				}
				else
				{
					position = playerPosition;
				}
			}
		}

		framesCounter++;
	}
}

// Drawing of player _______________________________________________________________________________________________________________________________________________________________________________
void Player::DrawPlayer()
{
	Vector2 extraPosition = { position.x, position.y };
	Vector2 extraSize = { size.x, size.y };
	for (int i = 0; i < counterTail; i++) DrawRectangleV(extraPosition, extraSize, color);

	centrePlayerPosition = { position.x + 25, position.y + 25 };
	//std::cout << centrePlayerPosition.x << " " << centrePlayerPosition.y << "\n";

	//float distanceToEnemy = centrePlayerPosition.CalculateDeltatoTarget(enemy.visualPosition);
	////std::cout << distanceToEnemy << "\n";
	//DrawLine(centrePlayerPosition.x, centrePlayerPosition.y, enemy.visualPosition.x, enemy.visualPosition.y, RED);

	//if (distanceToEnemy <= 25)
	//{
	//	gameOver = true;
	//}
}