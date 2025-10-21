#pragma once
#include <raylib.h>
#include "Vector2d.h"

class Player
{
public:

	// Player variables
	Vector2d playerPosition;
	float playerSpeed = 10;
	float playerSize = 30;
	float playerPositionX;
	float playerPositionY;
	Color playerColor = PINK;

	// Player movement function
	void PlayerController();

	// Drawing player function
	void DrawPlayer();

};

