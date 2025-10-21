#pragma once
#include <raylib.h>

class Player
{
public:

	// Player variables
	float playerSpeed = 10;
	float playerSize = 30;
	float playerPositionX;
	float playerPositionY;
	Color playerColor = PINK;

	// Player movement function
	void PlayerController();

	// Drawing player function
	void DrawPlayer(float playerPositionX, float playerPositionY);

};

