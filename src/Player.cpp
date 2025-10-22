#include "Player.h"


void Player::FindPlayerTilePosition(Vector2d inPlayerPosition)
{
	playerXPosition = inPlayerPosition.x;
	playerYPosition = inPlayerPosition.y; 

	float playerTileXPosition = std::round(playerXPosition/50);
	std::cout << playerTileXPosition << "\n";
	int playerTileYPosition; 
}

void Player::PlayerCheckCollisionWithBox(Vector2d inPlayerPosition)
{
	for (int i = 0; i < 14; i++ && playerHitBox == false)
	{
		//std::cout << "\n";
		for (int j = 0; j < 28; j++ && playerHitBox == false)
		{
			/*	std::cout << map[i][j];*/
			if (mapBoxes.map[i][j] == 1)
			{
				//std::cout << map[i][j];
				/*std::cout << "1, ";*/
				int positionY = i * 50;
				int positionX = j * 50;

				Rectangle boxPos = { positionY, positionX, mapBoxes.boxSize, mapBoxes.boxSize };
				Vector2 playerPos = { (float)inPlayerPosition.x, (float)inPlayerPosition.y };

				if (CheckCollisionCircleRec(playerPos, 22.f, boxPos))
				{
					std::cout << "Oh no, collision with wall!" << "\n";
					playerHitBox = true;
				}
				else
				{
					playerHitBox = false;
				}
			}
		}
	}
}

void Player::PlayerController()
{
	if (IsKeyDown(KEY_W))
	{
		PlayerCheckCollisionWithBox({ playerYPosition, playerXPosition });
		if (playerHitBox == true)
		{
			playerYPosition += playerSpeed * GetFrameTime();
		}
		else if (playerHitBox == false)
		{
			playerYPosition -= playerSpeed * GetFrameTime();
			//std::cout << playerYPosition << " " << playerXPosition << "\n";
			PlayerCheckCollisionWithBox({ playerYPosition, playerXPosition });
		}
		FindPlayerTilePosition({ playerYPosition, playerXPosition });
	}
	else if (IsKeyDown(KEY_S))
	{
		playerYPosition += playerSpeed * GetFrameTime();
		//std::cout << playerYPosition << " " << playerXPosition << "\n";
		PlayerCheckCollisionWithBox({ playerYPosition, playerXPosition });
		FindPlayerTilePosition({ playerYPosition, playerXPosition });
	}
	else if (IsKeyDown(KEY_A))
	{
		playerXPosition -= playerSpeed * GetFrameTime();
		//std::cout << playerYPosition << " " << playerXPosition << "\n";
		PlayerCheckCollisionWithBox({ playerYPosition, playerXPosition });
		FindPlayerTilePosition({ playerYPosition, playerXPosition });
	}
	else if (IsKeyDown(KEY_D))
	{
		playerXPosition += playerSpeed * GetFrameTime();
		//std::cout << playerYPosition << " " << playerXPosition << "\n";
		PlayerCheckCollisionWithBox({ playerYPosition, playerXPosition });
		FindPlayerTilePosition({ playerYPosition, playerXPosition });
	}
}

void Player::DrawPlayer()
{
	DrawRectangle(playerXPosition - 25, playerYPosition - 25, 50, 50, BLUE);
	DrawCircle(playerXPosition, playerYPosition, playerSize, playerColor);
}