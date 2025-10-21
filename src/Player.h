#pragma once
#include <raylib.h>
#include "Vector2d.h"
#include "Grid.h"

class Player
{
public:

	// Player variables
	Vector2d playerPosition;
	float playerXPosition;
	float playerYPosition;
	float playerSpeed = 100;
	float playerSize = 30;
	Color playerColor = PINK;

	// Player movement function
	void PlayerController();

	// Drawing player function
	void DrawPlayer();

};

