#include "Enemy.h"

void Enemy::CollisionCheck()
{
	int enemyPositionX = position.x / 50;
	int enemyPositionY = position.y / 50;

	if (enemyDirection.x == 1)
	{
		enemyPositionX = (position.x + 50) / 50;
		enemyPositionY = position.y / 50;

		if (map.map[enemyPositionY][enemyPositionX] == 1)
		{
			collisionRight = true;
		}
		else
		{
			collisionRight = false;
		}
	}
	if (enemyDirection.x == -1)
	{
		enemyPositionX = (position.x - 50) / 50;
		enemyPositionY = position.y / 50;
		if (map.map[enemyPositionY][enemyPositionX] == 1)
		{
			collisionLeft = true;
		}
		else
		{
			collisionLeft = false;
		}
	}
	if (enemyDirection.y == -1)
	{
		enemyPositionX = position.x / 50;
		enemyPositionY = (position.y - 50) / 50;
		if (map.map[enemyPositionY][enemyPositionX] == 1)
		{
			collisionUp = true;
		}
		else
		{
			collisionUp = false;
		}
	}
	if (enemyDirection.y == 1)
	{
		enemyPositionX = position.x / 50;
		enemyPositionY = (position.y + 50) / 50;
		if (map.map[enemyPositionY][enemyPositionX] == 1)
		{
			collisionDown = true;
		}
		else
		{
			collisionDown = false;
		}
	}
}


void Enemy::EnemyMovement()
{
	for (int i = 0; i < counterTail; i++) enemyPosition = position;

	if ((framesCounter % 10) == 0)
	{
		for (int i = 0; i < counterTail; i++)
		{
			if (i == 0)
			{
				CollisionCheck();
				if (collisionRight == false && collisionLeft == false && collisionUp == false && collisionDown == false)
				{
					position.x += speed.x;
					position.y += speed.y;
				}
				else if (enemyDirection.x == 1 && collisionRight == false)
				{
					position.x += speed.x;
					position.y += speed.y;
				}
				else if (enemyDirection.x == -1 && collisionLeft == false)
				{
					position.x += speed.x;
					position.y += speed.y;
				}
				else if (enemyDirection.y == -1 && collisionUp == false)
				{
					position.x += speed.x;
					position.y += speed.y;
				}
				else if (enemyDirection.y == 1 && collisionDown == false)
				{
					position.x += speed.x;
					position.y += speed.y;
				}
				position.x += speed.x;
				position.y += speed.y;

			}
			else
			{
				position = enemyPosition;
			}
		}
	}
	framesCounter++;
}

void Enemy::DrawEnemy()
{
	EnemyMovement();
	for (int i = 0; i < 1; i++) DrawRectangleV(position, size, color);
}