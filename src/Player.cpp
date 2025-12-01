#include "Player.h"

// The players collision check ______________________________________________________________________________________________________________________________________________________________________________________
void Player::CollisionCheck()
{
	int playerPositionX = position.x / 50;
	int playerPositionY = position.y / 50;

	// Player moving right ____________________________________________________________________
	if (playerDirection.x == 1)
	{
		// Checks collision with the box infront of the player
		playerPositionX = (position.x + 50) / 50;
		playerPositionY = position.y / 50;

		if (map.map[playerPositionY][playerPositionX] == 1)
		{
			collisionRight = true;

			// Checks for collisions on the sides of the player
			if (map.map[playerPositionY - 1][playerPositionX - 1] == 1)
			{
				collisionUp = true;
			}
			else
			{
				collisionUp = false;
			}
			if (map.map[playerPositionY][playerPositionX - 2] == 1)
			{
				collisionLeft = true;
			}
			else
			{
				collisionLeft = false;
			}
			if (map.map[playerPositionY + 1][playerPositionX - 1] == 1)
			{
				collisionDown = true;
			}
			else
			{
				collisionDown = false;
			}
		}
		else if (map.map[playerPositionY][playerPositionX] == 0)
		{
			collisionRight = false;

			// Checks for collision on the sides of the player
			if (map.map[playerPositionY - 1][playerPositionX - 1] == 1)
			{
				collisionUp = true;
			}
			else
			{
				collisionUp = false;
			}
			if (map.map[playerPositionY + 1][playerPositionX - 1] == 1)
			{
				collisionDown = true;
			}
			else
			{
				collisionDown = false;
			}
		}
	}

	// Player moving left ________________________________________________________________________
	if (playerDirection.x == -1)
	{
		// Checks collision with the box infront of the player
		playerPositionX = (position.x - 50) / 50;
		playerPositionY = position.y / 50;

		if (map.map[playerPositionY][playerPositionX] == 1)
		{
			collisionLeft = true;

			// Checks for collisions on the sides of the player
			if (map.map[playerPositionY - 1][playerPositionX + 1] == 1)
			{
				collisionUp = true;
			}
			else
			{
				collisionUp = false;
			}
			if (map.map[playerPositionY][playerPositionX + 2] == 1)
			{
				collisionRight = true;
			}
			else
			{
				collisionRight = false;
			}
			if (map.map[playerPositionY + 1][playerPositionX + 1] == 1)
			{
				collisionDown = true;
			}
			else
			{
				collisionDown = false;
			}
		}
		else if (map.map[playerPositionY][playerPositionX] == 0)
		{
			collisionLeft = false;

			// Checks for collision on the sides of the player
			if (map.map[playerPositionY - 1][playerPositionX + 1] == 1)
			{
				collisionUp = true;
			}
			else
			{
				collisionUp = false;
			}
			if (map.map[playerPositionY + 1][playerPositionX + 1] == 1)
			{
				collisionDown = true;
			}
			else
			{
				collisionDown = false;
			}
		}
	}

	// Player moving up ______________________________________________________________________
	if (playerDirection.y == -1)
	{
		// Checks collision with the box infront of the player
		playerPositionX = position.x / 50;
		playerPositionY = (position.y - 50) / 50;

		if (map.map[playerPositionY][playerPositionX] == 1)
		{
			collisionUp = true;

			// Checks for collisions on the sides of the player
			if (map.map[playerPositionY + 1][playerPositionX - 1] == 1)
			{
				collisionLeft = true;
			}
			else
			{
				collisionLeft = false;
			}
			if (map.map[playerPositionY + 1][playerPositionX + 1] == 1)
			{
				collisionRight = true;
			}
			else
			{
				collisionRight = false;
			}
			if (map.map[playerPositionY + 2][playerPositionX] == 1)
			{
				collisionDown = true;
			}
			else
			{
				collisionDown = false;
			}
		}
		else if (map.map[playerPositionY][playerPositionX] == 0)
		{
			collisionUp = false;

			// Checks for collision on the sides of the player
			if (map.map[playerPositionY + 1][playerPositionX - 1] == 1)
			{
				collisionLeft = true;
			}
			else
			{
				collisionLeft = false;
			}
			if (map.map[playerPositionY + 1][playerPositionX + 1] == 1)
			{
				collisionRight = true;
			}
			else
			{
				collisionRight = false;
			}
		}
	}

	// Player moving down ____________________________________________________________________
	if (playerDirection.y == 1)
	{
		// Checks collision with the box infront of the player
		playerPositionX = position.x / 50;
		playerPositionY = (position.y + 50) / 50;

		if (map.map[playerPositionY][playerPositionX] == 1)
		{
			collisionDown = true;

			// Checks for collisions on the sides of the player
			if (map.map[playerPositionY - 1][playerPositionX - 1] == 1)
			{
				collisionLeft = true;
			}
			else
			{
				collisionLeft = false;
			}
			if (map.map[playerPositionY - 1][playerPositionX + 1] == 1)
			{
				collisionRight = true;
			}
			else
			{
				collisionRight = false;
			}
			if (map.map[playerPositionY - 2][playerPositionX] == 1)
			{
				collisionUp = true;
			}
			else
			{
				collisionUp = false;
			}
		}
		else if (map.map[playerPositionY][playerPositionX] == 0)
		{
			collisionDown = false;

			// Checks for collision on the sides of the player
			if (map.map[playerPositionY - 1][playerPositionX - 1] == 1)
			{
				collisionLeft = true;
			}
			else
			{
				collisionLeft = false;
			}
			if (map.map[playerPositionY - 1][playerPositionX + 1] == 1)
			{
				collisionRight = true;
			}
			else
			{
				collisionRight = false;
			}
		}
	}
	//std::cout << playerPositionX << " , " << playerPositionY << "\n";
}

// Updates player each frame ____________________________________________________________________________________________________________________________________________________________________________
void Player::UpdatePlayer()
{
	if (gameState == 2)
	{
		// Player input _______________________________________________________________________________________
		if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))
		{
			// Checks for collision 
			CollisionCheck();

			// Changes player direction to right
			playerDirection = { 1,0 };
			if (playerDirection.x == 0 || playerDirection.x == -1 && collisionRight == false)
			{
				speed = Vector2d{ map.boxSize, 0 };
				playerDirection = { 1,0 };
			}
			else if (playerDirection.x == 1 && collisionRight == false)
			{
				speed = Vector2d{ map.boxSize, 0 };
				playerDirection = { 1,0 };
			}
		}
		if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A))
		{
			// Checks for collision 
			CollisionCheck();

			// Changes player direction to left
			playerDirection = { -1,0 };
			if (playerDirection.x == 0 || playerDirection.x == 1 && collisionLeft == false)
			{
				speed = Vector2d{ -map.boxSize, 0 };
				playerDirection = { -1,0 };
			}
			else if (playerDirection.x == -1 && collisionLeft == false)
			{
				speed = Vector2d{ -map.boxSize, 0 };
				playerDirection = { -1,0 };
			}
		}
		if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W))
		{
			// Checks for collision 
			CollisionCheck();

			// Changes player direction to up
			playerDirection = { 0,-1 };
			if (playerDirection.y == 0 || playerDirection.y == -1 && collisionUp == false)
			{
				speed = Vector2d{ 0, -map.boxSize };
				playerDirection = { 0,-1 };
			}
			else if (playerDirection.y == -1 && collisionUp == false)
			{
				speed = Vector2d{ 0, -map.boxSize };
				playerDirection = { 0,-1 };
			}
		}
		if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S))
		{
			// Checks for collision 
			CollisionCheck();

			// Changes player direction to down
			playerDirection = { 0,1 };
			if (playerDirection.y == 0 || playerDirection.y == 1 && collisionDown == false)
			{
				speed = Vector2d{ 0, map.boxSize };
				playerDirection = { 0,1 };
			}
			else if (playerDirection.y == 1 && collisionDown == false)
			{
				speed = Vector2d{ 0, map.boxSize };
				playerDirection = { 0,1 };
			}
		}

		// Continuos player movement _____________________________________________________________________
		if ((framesCounter % 10) == 0)
		{
			// Checks for collision before moving
			CollisionCheck();
			if (playerDirection.x == 1 && collisionRight == false)
			{
				position.x += speed.x;
				position.y += speed.y;
			}
			if (playerDirection.x == -1 && collisionLeft == false)
			{
				position.x += speed.x;
				position.y += speed.y;
			}
			if (playerDirection.y == -1 && collisionUp == false)
			{
				position.x += speed.x;
				position.y += speed.y;
			}
			if (playerDirection.y == 1 && collisionDown == false)
			{
				position.x += speed.x;
				position.y += speed.y;
			}
		}
		framesCounter++;
	}
}

// Drawing of player _______________________________________________________________________________________________________________________________________________________________________________
void Player::DrawPlayer()
{
	DrawRectangleV({ position.x, position.y }, { size.x, size.y }, color);

	centrePlayerPosition = { position.x + 25, position.y + 25 };
}

