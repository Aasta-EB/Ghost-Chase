#pragma once
#include <raylib.h>
#include "Vector2d.h"
#include "Grid.h"

class Player
{
public:

	// Player variables
	Vector2d playerPosition = { playerYPosition, playerXPosition };
	float playerXPosition;
	float playerYPosition;
	float playerSpeed = 100;
	float playerSize = 20;
	Color playerColor = PINK;
	Grid mapBoxes;
	int playerTileXPosition;
	float playerTileYPosition;

	bool playerHitBox;

	void FindPlayerTilePosition(Vector2d inPlayerPosition);

	void PlayerCheckCollisionWithBox(Vector2d inPlayerPosition);

	// Player movement function
	void PlayerController();

	// Drawing player function
	void DrawPlayer();

};

