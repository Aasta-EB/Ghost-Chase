#include "Player.h"


void Player::PlayerController()
{
	Grid box; 

	if (IsKeyDown(KEY_W))
	{
		playerYPosition -= playerSpeed * GetFrameTime();
	}
	else if (IsKeyDown(KEY_S))
	{
		playerYPosition += playerSpeed * GetFrameTime();
	}
	else if (IsKeyDown(KEY_A))
	{
		playerXPosition -= playerSpeed * GetFrameTime();
	}
	else if (IsKeyDown(KEY_D))
	{
		playerXPosition += playerSpeed * GetFrameTime();
	}
}

void Player::DrawPlayer()
{
	DrawCircle(playerXPosition, playerYPosition, playerSize, playerColor);
}
