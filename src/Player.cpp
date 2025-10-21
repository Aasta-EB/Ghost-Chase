#include "Player.h"


void Player::PlayerController()
{
	if (IsKeyDown(KEY_W))
	{
		
	}
	if (IsKeyDown(KEY_S))
	{
		
	}
	if (IsKeyDown(KEY_A))
	{
		
	}
	if (IsKeyDown(KEY_D))
	{
		
	}
}

void Player::DrawPlayer()
{
	playerPosition.x = 10;
	DrawCircle(playerPosition.x, playerPosition.y, playerSize, playerColor);
}
