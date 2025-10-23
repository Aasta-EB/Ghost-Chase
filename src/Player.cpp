#include "Player.h"


void Player::FindPlayerTilePosition(Vector2d inPlayerPosition)
{
	int positionX = inPlayerPosition.x - 20;
	int positionY = inPlayerPosition.y - 20; 

	if (playerDirection.x == 1 && playerDirection.y == 0)
	{
		boxPositionX = std::round((positionX) / 50);
		boxPositionY = std::round((positionY) / 50)+1;
	}
	if (playerDirection.x == -1 && playerDirection.y == 0)
	{
		boxPositionX = std::round((positionX) / 50);
		boxPositionY = std::round((positionY) / 50);
	}
	if (playerDirection.x == 0 && playerDirection.y == -1)
	{
		boxPositionX = std::round((positionX) / 50)+1;
		boxPositionY = std::round((positionY) / 50);
	}
	if (playerDirection.x == 0 && playerDirection.y == 1)
	{
		boxPositionX = std::round((positionX) / 50);
		boxPositionY = std::round((positionY) / 50);
	}

	playerTileXPosition = boxPositionY;
	std::cout << "(" << playerTileXPosition << ", ";
	playerTileYPosition = boxPositionX;
	std::cout << playerTileYPosition << ")" << "\n";

	if (mapBoxes.map[boxPositionX][boxPositionY] == 1)
	{
		std::cout << "You've hit a wall, stop" << "\n";
		playerHitBox = true; 
	}
	else if (mapBoxes.map[boxPositionX][boxPositionY] == 0)
	{
		playerHitBox = false; 
	}
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
					//playerHitBox = true;
				}
				else
				{
					//playerHitBox = false;
				}
			}
		}
	}
}

void Player::PlayerController()
{
	if (IsKeyDown(KEY_W))
	{
		FindPlayerTilePosition({ playerYPosition, playerXPosition });

		if (playerDirection.y != -1 && playerHitBox == true)
		{
			playerDirection = { 0, -1 };
			playerYPosition -= playerSpeed * GetFrameTime();
		}
		else if (playerHitBox == false)
		{
			playerDirection = { 0, -1 };
			playerYPosition -= playerSpeed * GetFrameTime();
		}

	//	FindPlayerTilePosition({ playerYPosition, playerXPosition });

	///*	PlayerCheckCollisionWithBox({ playerYPosition, playerXPosition });*/
	//	if (playerHitBox == true)
	//	{
	//		std::cout << "I want to stop" << "\n";
	//	}
	//	else if (playerHitBox == false)
	//	{
	//		playerYPosition -= playerSpeed * GetFrameTime();
	//		playerDirection = { 0, 1 };
	//		//std::cout << playerYPosition << " " << playerXPosition << "\n";
	//		//PlayerCheckCollisionWithBox({ playerYPosition, playerXPosition });
	//	}
	}
	else if (IsKeyDown(KEY_S))
	{
		FindPlayerTilePosition({ playerYPosition, playerXPosition });

		if (playerDirection.y != 1 && playerHitBox == true)
		{
			playerDirection = { 0, 1 };
			playerYPosition += playerSpeed * GetFrameTime();
		}
		else if (playerHitBox == false)
		{
			playerDirection = { 0, 1 };
			playerYPosition += playerSpeed * GetFrameTime();
		}

		//std::cout << playerYPosition << " " << playerXPosition << "\n";
		///*PlayerCheckCollisionWithBox({ playerYPosition, playerXPosition });*/
		//FindPlayerTilePosition({ playerYPosition, playerXPosition });
		//if (playerHitBox == true)
		//{
		//	std::cout << "I want to stop" << "\n";
		//}
		//else if (playerHitBox == false)
		//{
		//	std::cout << playerYPosition << " " << playerXPosition << "\n";
		//	playerDirection = { 0, -1 };
		//	//std::cout << playerYPosition << " " << playerXPosition << "\n";
		//	//PlayerCheckCollisionWithBox({ playerYPosition, playerXPosition });
		//}
	}
	else if (IsKeyDown(KEY_A))
	{

		FindPlayerTilePosition({ playerYPosition, playerXPosition });

		if (playerDirection.x != -1 && playerHitBox == true)
		{
			playerDirection = { -1, 0 };
			playerXPosition -= playerSpeed * GetFrameTime();
		}
		else if (playerHitBox == false)
		{
			playerDirection = { -1, 0 };
			playerXPosition -= playerSpeed * GetFrameTime();
		}
		//std::cout << playerYPosition << " " << playerXPosition << "\n";
		//FindPlayerTilePosition({ playerYPosition, playerXPosition });
		//if (playerHitBox == true)
		//{
		//	std::cout << "I want to stop" << "\n";
		//}
		//else if (playerHitBox == false)
		//{
		//	playerXPosition -= playerSpeed * GetFrameTime();
		//	playerDirection = { 1, 0 };
		//	//std::cout << playerYPosition << " " << playerXPosition << "\n";
		//	//PlayerCheckCollisionWithBox({ playerYPosition, playerXPosition });
		//}
	}
	else if (IsKeyDown(KEY_D))
	{
		FindPlayerTilePosition({ playerYPosition, playerXPosition });

		if (playerDirection.x != 1 && playerHitBox == true)
		{
			playerDirection = { 1, 0 };
			playerXPosition += playerSpeed * GetFrameTime();
		}
		else if (playerHitBox == false)
		{
			playerDirection = { 1, 0 };
			playerXPosition += playerSpeed * GetFrameTime();
		}
		//std::cout << playerYPosition << " " << playerXPosition << "\n";
		//if (playerHitBox == true)
		//{
		//	std::cout << "I want to stop" << "\n";
		//}
		//else if (playerHitBox == false)
		//{
		//	playerXPosition += playerSpeed * GetFrameTime();
		//	playerDirection = { -1, 0 };
		//	//std::cout << playerYPosition << " " << playerXPosition << "\n";
		//	//PlayerCheckCollisionWithBox({ playerYPosition, playerXPosition });
		//}
	}
}

void Player::DrawPlayer()
{
	DrawRectangle(playerXPosition - 25, playerYPosition - 25, 50, 50, BLUE);
	DrawCircle(playerXPosition, playerYPosition, playerSize, playerColor);
}