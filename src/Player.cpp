#include "Player.h"

// Finds the players position compared to the boxes position, 
void Player::FindPlayerTilePosition(Vector2d inPlayerPosition)
{
	// Calculates (almost, the players position, it has to be changed as it is dependent on the driection of player movement
	int positionX = inPlayerPosition.x - 20;
	int positionY = inPlayerPosition.y - 20; 

	// Checks the player direction and calculates the box the player is in
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
		boxPositionX = std::round((positionX) / 50);
		boxPositionY = std::round((positionY) / 50);
	}
	if (playerDirection.x == 0 && playerDirection.y == 1)
	{
		boxPositionX = std::round((positionX) / 50) + 1;
		boxPositionY = std::round((positionY) / 50);
	}

	/*playerTileXPosition = boxPositionY;
	std::cout << "(" << playerTileXPosition << ", ";
	playerTileYPosition = boxPositionX;
	std::cout << playerTileYPosition << ")" << "\n"; */

	// Checks the actual player box position and the boxes position to see if the player hits any
	if (mapBoxes.map[boxPositionX][boxPositionY] == 1)
	{
		//std::cout << "You've hit a wall, stop" << "\n";
		playerHitBox = true; 
	}
	else if (mapBoxes.map[boxPositionX][boxPositionY] == 0)
	{
		playerHitBox = false; 
	}
}

// Original hitbox ckeck for collision, does not work and is therefore not used, at least as of now
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

// Player movement function
// This movement needs to be updated as we want continuos movement
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

			for (int i = 0; playerHitBox == false; i = 0)
			{
				playerYPosition -= playerSpeed * GetFrameTime();
			}
		}
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
	}
}

// Draw player function, could probably be updated to better the code
void Player::DrawPlayer()
{
	// DrawRectangle(playerXPosition - 25, playerYPosition - 25, 50, 50, BLUE);
	DrawCircle(playerXPosition, playerYPosition, playerSize, playerColor);
}