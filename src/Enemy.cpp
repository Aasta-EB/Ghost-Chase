#include "Enemy.h"

void Enemy::DrawDropHint()
{
	if (dropHintTimer > 0.f)
	{
		dropHintTimer -= GetFrameTime();
	}
	if (dropHintTimer < 0.f)
	{
		enemyHintNumber += 0.5f;
		std::cout << enemyHintNumber << "\n";
		dropHintTimer = 10.f;
	}

	if (enemyHintNumber == 1)
	{
		enemyHintExsists_1 = true;
		enemyHintPos_1 = visualPosition; 
		enemyHintNumber += 0.5; 
	}
	if (enemyHintNumber == 2)
	{
		enemyHintExsists_2 = true;
		enemyHintPos_2 = visualPosition;
		enemyHintNumber += 0.5;
	}
	if (enemyHintNumber == 3)
	{
		enemyHintExsists_3 = true;
		enemyHintPos_3 = visualPosition;
		enemyHintNumber += 0.5;
	}
	if (enemyHintNumber == 4)
	{
		enemyHintExsists_4 = true;
		enemyHintPos_4 = visualPosition;
		enemyHintNumber += 0.5;
	}

	if (enemyHintExsists_1 == true)
	{
		DrawCircle(enemyHintPos_1.x, enemyHintPos_1.y, 5, ORANGE);
	}
	if (enemyHintExsists_2 == true)
	{
		DrawCircle(enemyHintPos_2.x, enemyHintPos_2.y, 5, ORANGE);
	}
	if (enemyHintExsists_3 == true)
	{
		DrawCircle(enemyHintPos_3.x, enemyHintPos_3.y, 5, ORANGE);
	}
	if (enemyHintExsists_4 == true)
	{
		DrawCircle(enemyHintPos_4.x, enemyHintPos_4.y, 5, ORANGE);
	}

}

void Enemy::EnemyEscape(Vector2d inPlayerPosition)
{
	if (distanceToPlayer <= 300)
	{
		if (inPlayerPosition.x <= position.x)
		{
			runLeft = true;
		}
		if (inPlayerPosition.x >= position.x)
		{
			runRight = true;
		}
		if (inPlayerPosition.y <= position.y)
		{
			runDown = true; 
		}
		if (inPlayerPosition.y >= position.y)
		{
			runUp = true;
		}
	}
	else
	{
		runRight = false;
		runLeft = false;
		runDown = false;
		runUp = false;
	}

	//std::cout << distanceToPlayer << "\n";
}


void Enemy::CollisionCheck(Vector2d inPlayerPosition)
{
	position = enemyPosition;
	int enemyPositionX = position.x / 50;
	int enemyPositionY = position.y / 50;

	if (enemyDirection.x == 1)
	{
		enemyPositionX = (position.x + 50) / 50;
		enemyPositionY = position.y / 50;

		EnemyEscape(inPlayerPosition);

		if (map.map[enemyPositionY][enemyPositionX] == 1 || runLeft == true)
		{
			int changeDirectionNumber;
			collisionRight = true;
			srand(time(0));
			if (runLeft == true && map.map[enemyPositionY][enemyPositionX] != 1)
			{
				changeDirectionNumber = 0; 
			}
			else
			{
				changeDirectionNumber = std::rand() % 3;
			}
			//std::cout << changeDirectionNumber;

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
			runLeft = false; 
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

		EnemyEscape(inPlayerPosition);

		if (map.map[enemyPositionY][enemyPositionX] == 1 || runRight == true)
		{
			int changeDirectionNumber;

			srand(time(0));
			if (runRight == true && map.map[enemyPositionY][enemyPositionX] != 1)
			{
				changeDirectionNumber = 0;
			}
			else
			{
				collisionLeft = true;
				changeDirectionNumber = std::rand() % 3;
			}
			
			//std::cout << changeDirectionNumber;

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
			runRight = false;
		}
		else
		{
			collisionLeft = false;
		}
	}
	if (enemyDirection.y == -1)
	{
		EnemyEscape(inPlayerPosition);

		enemyPositionX = position.x / 50;
		enemyPositionY = (position.y - 50) / 50;
		if (map.map[enemyPositionY][enemyPositionX] == 1 || runDown == true)
		{
			int changeDirectionNumber;

			srand(time(0));
			if (runDown == true && map.map[enemyPositionY][enemyPositionX] != 1)
			{
				changeDirectionNumber = 0;
			}
			else
			{
				collisionUp = true;
				changeDirectionNumber = std::rand() % 3;
			}
			//std::cout << changeDirectionNumber;

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
			runDown = false; 
		}
		else
		{
			collisionUp = false;
		}
	}
	if (enemyDirection.y == 1)
	{
		EnemyEscape(inPlayerPosition);

		enemyPositionX = position.x / 50;
		enemyPositionY = (position.y + 50) / 50;
		if (map.map[enemyPositionY][enemyPositionX] == 1 || runUp == true)
		{
			int changeDirectionNumber;
			srand(time(0));
			
			if (runUp == true && map.map[enemyPositionY][enemyPositionX] != 1)
			{
				changeDirectionNumber = 0;
			}
			else
			{
				collisionDown = true;
				changeDirectionNumber = std::rand() % 3;
			}
			//std::cout << changeDirectionNumber;

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
			runUp = false; 
		}
		else
		{
			collisionDown = false;
		}
	}
}

void Enemy::EnemyMovement(Vector2d inPlayerPosition)
{
	for (int i = 0; i < 1; i++) enemyPosition = position;

	if ((framesCounter % 10) == 0)
	{
		for (int i = 0; i < 1; i++)
		{
			if (i == 0)
			{
				CollisionCheck(inPlayerPosition);
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

void Enemy::DrawEnemy(Vector2d inPlayerPosition)
{
	EnemyMovement(inPlayerPosition);
	//DrawRectangleV({ position.x, position.y }, { size.x, size.y }, ORANGE);

	visualPosition = { position.x + 25, position.y + 25 };
	DrawCircle(visualPosition.x, visualPosition.y, 25, color);
}