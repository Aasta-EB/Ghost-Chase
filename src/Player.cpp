#include "Player.h"

void Player::PlayerController()
{
	if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
	{
		playerPositionX -= 1 * GetFrameTime();
	}
	if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
	{
		playerPositionX += 1 * GetFrameTime();
	}
	if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
	{
		playerPositionY -= 1 * GetFrameTime();
	}
	if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
	{
		playerPositionX += 1 * GetFrameTime();
	}
}

void Player::DrawPlayer(float playerPositionX, float playerPositionY)
{
	DrawCircle(playerPositionX, playerPositionY, playerSize, playerColor);
}
