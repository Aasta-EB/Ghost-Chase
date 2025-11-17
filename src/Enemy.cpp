#include "Enemy.h"

void Enemy::CollisionCheck()
{
	position = enemyPosition;
	int enemyPositionX = position.x / 50;
	int enemyPositionY = position.y / 50;

	if (enemyDirection.x == 1)
	{
		enemyPositionX = (position.x + 50) / 50;
		enemyPositionY = position.y / 50;

		if (map.map[enemyPositionY][enemyPositionX] == 1)
		{
			collisionRight = true;
			srand(time(0));
			int changeDirectionNumber = std::rand() % 3;
			std::cout << changeDirectionNumber;

			if (changeDirectionNumber == 0)
			{
				enemyDirection = { -1,0 };
			}
			else if (changeDirectionNumber == 1)
			{
				enemyDirection = { 0,1 };
			}
			else if (changeDirectionNumber == 2)
			{
				enemyDirection = { 0,-1 };
			}
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
			srand(time(0));
			int changeDirectionNumber = std::rand() % 3;
			std::cout << changeDirectionNumber;

			if (changeDirectionNumber == 0)
			{
				enemyDirection = { 1,0 };
			}
			else if (changeDirectionNumber == 1)
			{
				enemyDirection = { 0,1 };
			}
			else if (changeDirectionNumber == 2)
			{
				enemyDirection = { 0,-1 };
			}
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
			srand(time(0));
			int changeDirectionNumber = std::rand() % 3;
			std::cout << changeDirectionNumber;

			if (changeDirectionNumber == 0)
			{
				enemyDirection = { 0,1 };
			}
			else if (changeDirectionNumber == 1)
			{
				enemyDirection = { 1,0 };
			}
			else if (changeDirectionNumber == 2)
			{
				enemyDirection = { -1,0 };
			}
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
			srand(time(0));
			int changeDirectionNumber = std::rand() % 3;
			std::cout << changeDirectionNumber;

			if (changeDirectionNumber == 0)
			{
				enemyDirection = { 0,-1 };
			}
			else if (changeDirectionNumber == 1)
			{
				enemyDirection = { 1,0 };
			}
			else if (changeDirectionNumber == 2)
			{
				enemyDirection = { -1,0 };
			}
		}
		else
		{
			collisionDown = false;
		}
	}
}

void Enemy::EnemyMovement()
{
	for (int i = 0; i < 1; i++) enemyPosition = position;

	if ((framesCounter % 10) == 0)
	{
		for (int i = 0; i < 1; i++)
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
					speed = Vector2d{ map.boxSize, 0 };
					position.x += speed.x;
					position.y += speed.y;
				}
				else if (enemyDirection.x == -1 && collisionLeft == false)
				{
					speed = Vector2d{ -map.boxSize, 0 };
					position.x += speed.x;
					position.y += speed.y;
				}
				else if (enemyDirection.y == -1 && collisionUp == false)
				{
					speed = Vector2d{ 0, -map.boxSize };
					position.x += speed.x;
					position.y += speed.y;
				}
				else if (enemyDirection.y == 1 && collisionDown == false)
				{
					speed = Vector2d{ 0, map.boxSize };
					position.x += speed.x;
					position.y += speed.y;
				}
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
	Vector2 extraPosition = { position.x, position.y };
	Vector2 extraSize = { size.x, size.y };
	DrawRectangleV(extraPosition, extraSize, ORANGE);

	visualPosition = { position.x + 25, position.y + 25 };
	DrawCircle(visualPosition.x, visualPosition.y, 25, color);
}