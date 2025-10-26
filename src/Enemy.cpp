#include "Enemy.h"

void Enemy::FindEnemyBoxPosition(Vector2d inEnemyPosition)
{
	// Calculates (almost, the players position, it has to be changed as it is dependent on the driection of player movement
	int positionX = inEnemyPosition.x - 20;
	int positionY = inEnemyPosition.y - 20;

	// Checks the player direction and calculates the box the player is in
	if (enemyDirection.x == 1 && enemyDirection.y == 0)
	{
		enemyBoxPositionX = std::round((positionX) / 50);
		enemyBoxPositionY = std::round((positionY) / 50) + 1;
	}
	if (enemyDirection.x == -1 && enemyDirection.y == 0)
	{
		enemyBoxPositionX = std::round((positionX) / 50);
		enemyBoxPositionY = std::round((positionY) / 50);
	}
	if (enemyDirection.x == 0 && enemyDirection.y == -1)
	{
		enemyBoxPositionX = std::round((positionX) / 50);
		enemyBoxPositionY = std::round((positionY) / 50);
	}
	if (enemyDirection.x == 0 && enemyDirection.y == 1)
	{
		enemyBoxPositionX = std::round((positionX) / 50) + 1;
		enemyBoxPositionY = std::round((positionY) / 50);
	}

	// Checks the actual player box position and the boxes position to see if the player hits any
	if (box.map[enemyBoxPositionX][enemyBoxPositionY] == 1)
	{
		//std::cout << "You've hit a wall, stop" << "\n";
		enemyHitBox = true;
	}
	else if (box.map[enemyBoxPositionX][enemyBoxPositionY] == 0)
	{
		enemyHitBox = false;
	}
}

void Enemy::EnemyMovement(Vector2d inEnemyPosition)
{
	for (enemyHitBox == false)
	{
		int randomMovementX = rand() % 50;
		inEnemyPosition += randomMovementX;
	}
}


void Enemy::DrawEnemy()
{
    DrawCircle(enemyPositionX, enemyPositionY, enemySize, enemyColor);
}
