#include "Enemy.h"

// Finds and stores the position of the hint ___________________________________________________________________________________________________________________________________________________________
void Enemy::GetHintPosition(Vector2d inPosition)
{
	enemyHintPosition = inPosition;
	enemyHintExsists = true;
}

// Enemy drops hint at its current position, player gets hint-points if collected _____________________________________________________________________________________________________________________
void Enemy::DrawDropHint(Vector2d inPlayerPosition)
{
	if (dropHintTimer > 0.f)
	{
		dropHintTimer -= GetFrameTime();
	}
	if (dropHintTimer < 0.f)
	{
		dropHintTimer = 4.f;
		if (!enemyHintExsists)
		{
			GetHintPosition(visualPosition);
		}
	}

	if (enemyHintExsists)
	{
		DrawCircle(enemyHintPosition.x, enemyHintPosition.y, 5, ORANGE);
	}

	if (enemyHintExsists == true)
	{
		if (enemyHintPosition.x == inPlayerPosition.x && enemyHintPosition.y == inPlayerPosition.y)
		{
			enemyHintExsists = false;
		}
	}
}

// Finds a random enemy direction ______________________________________________________________________________________________________________________________________________________________________
Vector2d Enemy::RandomEnemyDirection()
{
	srand(time(0));

	int chooseDirection = std::rand() % 4;

	Vector2d randomEnemyDirection = { 1 , 0 };

	switch (chooseDirection)
	{
	case 0:
		randomEnemyDirection = { 1 , 0 };
		break;
	case 1:
		randomEnemyDirection = { -1 , 0 };
		break;
	case 2:
		randomEnemyDirection = { 0 , 1 };
		break;
	case 3:
		randomEnemyDirection = { 0 , -1 };
		break;
	}

	return randomEnemyDirection;
}

// Finds a "random" enemy spawn point ______________________________________________________________________________________________________________________________________________________________________
Vector2d Enemy::RandomEnemyPosition()
{
	srand(time(0));

	int choosePosition = std::rand() % 5;
	Vector2d randomEnemyPosition = { 15 * map.boxSize, 10 * map.boxSize };

	switch (choosePosition)
	{
	case 0:
		randomEnemyPosition = { 15 * map.boxSize, 10 * map.boxSize };
		break;
	case 1:
		randomEnemyPosition = { 20 * map.boxSize, 3 * map.boxSize };
		break;
	case 2:
		randomEnemyPosition = { 9 * map.boxSize, 3 * map.boxSize };
		break;
	case 3:
		randomEnemyPosition = { 12 * map.boxSize, 9 * map.boxSize };
		break;
	case 4:
		randomEnemyPosition = { 4 * map.boxSize, 11 * map.boxSize };
		break;
	}

	return randomEnemyPosition;
}

// Enemy collision check ___________________________________________________________________________________________________________________________________________________________________________________
void Enemy::CollisionCheck(Vector2d inPlayerPosition)
{
	//position = enemyPosition;
	int enemyPositionX = position.x / 50;
	int enemyPositionY = position.y / 50;

	//std::cout << position.x << " , " << position.y << "\n";

	if (enemyDirection.x == 1 && enemyDirection.y == 0) // Moving right _________________________________________________________________________________________
	{
		enemyPositionX = (position.x + 50) / 50;
		enemyPositionY = position.y / 50;
		int changeDirectionNumber = 0;
		srand(time(0));

		if (inPlayerPosition.x == position.x + 100 && map.map[enemyPositionY][enemyPositionX] != 1)
		{
			/*	std::cout << enemyDirection.MultiplyVector(-1).x << " , " << enemyDirection.MultiplyVector(-1).y << "\n";
				enemyDirection.MultiplyVector(-1);*/
			enemyDirection.x *= -1;
		}
		else if (inPlayerPosition.x == position.x + 50 && map.map[enemyPositionY][enemyPositionX] != 1)
		{
			/*std::cout << enemyDirection.MultiplyVector(-1).x << " , " << enemyDirection.MultiplyVector(-1).y << "\n";
			enemyDirection.MultiplyVector(-1);*/
			enemyDirection.x *= -1;
		}
		else
		{
			if (map.map[enemyPositionY][enemyPositionX] == 1)
			{
				collisionRight = true;
				if (map.map[enemyPositionY - 1][enemyPositionX - 1] == 1)
				{
					collisionUp = true;
				}
				else
				{
					collisionUp = false;
				}
				if (map.map[enemyPositionY + 1][enemyPositionX - 1] == 1)
				{
					collisionDown = true;
				}
				else
				{
					collisionDown = false;
				}
				if (map.map[enemyPositionY][enemyPositionX - 1] == 1)
				{
					collisionLeft = true;
				}
				else
				{
					collisionLeft = false;
				}

				if (collisionUp == false && collisionDown == false && collisionLeft == false && collisionRight == true)
				{
					changeDirectionNumber = std::rand() % 2;
					if (changeDirectionNumber == 0)
					{
						enemyDirection = { 0,1 };
					}
					else if (changeDirectionNumber == 1)
					{
						enemyDirection = { 0,-1 };
					}
				}
				if (collisionUp == true && collisionDown == false && collisionLeft == false && collisionRight == true)
				{
					enemyDirection = { 0,1 };
				}
				if (collisionUp == false && collisionDown == true && collisionLeft == false && collisionRight == true)
				{
					enemyDirection = { 0,-1 };
				}
				if (collisionUp == false && collisionDown == false && collisionLeft == true && collisionRight == true)
				{
					changeDirectionNumber = std::rand() % 2;
					if (changeDirectionNumber == 0)
					{
						enemyDirection = { 0,1 };
					}
					else if (changeDirectionNumber == 1)
					{
						enemyDirection = { 0,-1 };
					}
				}
				if (collisionUp == false && collisionDown == true && collisionLeft == true && collisionRight == true)
				{
					enemyDirection = { 0, -1 };
				}
				if (collisionUp == true && collisionDown == false && collisionLeft == true && collisionRight == true)
				{
					enemyDirection = { 0, 1 };
				}
				if (collisionUp == true && collisionDown == true && collisionLeft == false && collisionRight == true)
				{
					enemyDirection = { -1 , 0 };
				}
			}
			else if (map.map[enemyPositionY][enemyPositionX] == 0)
			{
				collisionRight = false;
				enemyPositionX = position.x / 50;
				enemyPositionY = position.y / 50;
				int changeDirectionNumber = 0;
				srand(time(0));

				if (map.map[enemyPositionY + 1][enemyPositionX] == 0 && map.map[enemyPositionY - 1][enemyPositionX] == 1)
				{
					if (justChangedDirection == false)
					{
						changeDirectionNumber = std::rand() % 100;
						if (changeDirectionNumber >= 10 && changeDirectionNumber < 100)
						{
							enemyDirection = { 1,0 };
							//std::cout << "I continue this way \n";
						}
						else if (changeDirectionNumber >= 0 && changeDirectionNumber < 10)
						{
							enemyDirection = { 0,1 };
							//std::cout << "I am changing my direction \n";
						}
						justChangedDirection = true;
					}
					else if (justChangedDirection == true)
					{
						justChangedDirection = false;
					}
				}
				if (map.map[enemyPositionY - 1][enemyPositionX] == 0 && map.map[enemyPositionY + 1][enemyPositionX] == 1)
				{
					if (justChangedDirection == false)
					{
						changeDirectionNumber = std::rand() % 100;
						if (changeDirectionNumber >= 10 && changeDirectionNumber < 100)
						{
							enemyDirection = { 1,0 };
							//std::cout << "I continue this way \n";
						}
						else if (changeDirectionNumber >= 0 && changeDirectionNumber < 10)
						{
							enemyDirection = { 0,-1 };
							//std::cout << "I am changing my direction \n";
						}
						justChangedDirection = true;
					}
					else if (justChangedDirection == true)
					{
						justChangedDirection = false;
					}
				}
				if (map.map[enemyPositionY - 1][enemyPositionX] == 0 && map.map[enemyPositionY + 1][enemyPositionX] == 0)
				{
					if (justChangedDirection == false)
					{
						changeDirectionNumber = std::rand() % 100;
						if (changeDirectionNumber >= 20 && changeDirectionNumber < 100)
						{
							enemyDirection = { 1,0 };
							//std::cout << "I continue this way \n";
						}
						else if (changeDirectionNumber >= 0 && changeDirectionNumber < 10)
						{
							enemyDirection = { 0,1 };
							//std::cout << "I am changing my direction \n";
						}
						else if (changeDirectionNumber >= 10 && changeDirectionNumber < 20)
						{
							enemyDirection = { 0,-1 };
							//std::cout << "I am changing my direction \n";
						}
						justChangedDirection = true;
					}
					else if (justChangedDirection == true)
					{
						justChangedDirection = false;
					}
				}
			}
		}
		/*std::cout << enemyPositionY << " , " << enemyPositionX << "\n";*/
	}
	if (enemyDirection.x == -1 && enemyDirection.y == 0) // Moving left ______________________________________________________________________________________
	{
		enemyPositionX = (position.x - 50) / 50;
		enemyPositionY = position.y / 50;
		int changeDirectionNumber = 0;
		srand(time(0));

		if (inPlayerPosition.x == position.x - 100 && map.map[enemyPositionY][enemyPositionX] != 1)
		{
			/*std::cout << enemyDirection.MultiplyVector(-1).x << " , " << enemyDirection.MultiplyVector(-1).y << "\n";
			enemyDirection.MultiplyVector(-1);*/
			enemyDirection.x *= -1;
		}
		else if (inPlayerPosition.x == position.x - 50 && map.map[enemyPositionY][enemyPositionX] != 1)
		{
			/*std::cout << enemyDirection.MultiplyVector(-1).x << " , " << enemyDirection.MultiplyVector(-1).y << "\n";
			enemyDirection.MultiplyVector(-1);*/
			enemyDirection.x *= -1;
		}
		else
		{
			if (map.map[enemyPositionY][enemyPositionX] == 1)
			{
				collisionLeft = true;
				if (map.map[enemyPositionY - 1][enemyPositionX + 1] == 1)
				{
					collisionUp = true;
				}
				else
				{
					collisionUp = false;
				}
				if (map.map[enemyPositionY + 1][enemyPositionX + 1] == 1)
				{
					collisionDown = true;
				}
				else
				{
					collisionDown = false;
				}
				if (map.map[enemyPositionY][enemyPositionX + 1] == 1)
				{
					collisionRight = true;
				}
				else
				{
					collisionRight = false;
				}

				if (collisionUp == false && collisionDown == false && collisionRight == false && collisionLeft == true)
				{
					changeDirectionNumber = std::rand() % 2;
					if (changeDirectionNumber == 0)
					{
						enemyDirection = { 0,1 };
					}
					else if (changeDirectionNumber == 1)
					{
						enemyDirection = { 0,-1 };
					}
				}
				if (collisionUp == true && collisionDown == false && collisionRight == false && collisionLeft == true)
				{
					enemyDirection = { 0,1 };
				}
				if (collisionUp == false && collisionDown == true && collisionRight == false && collisionLeft == true)
				{
					enemyDirection = { 0,-1 };
				}
				if (collisionUp == false && collisionDown == false && collisionRight == true && collisionLeft == true)
				{
					changeDirectionNumber = std::rand() % 2;
					if (changeDirectionNumber == 0)
					{
						enemyDirection = { 0,1 };
					}
					else if (changeDirectionNumber == 1)
					{
						enemyDirection = { 0,-1 };
					}
				}
				if (collisionUp == false && collisionDown == true && collisionRight == true && collisionLeft == true)
				{
					enemyDirection = { 0, -1 };
				}
				if (collisionUp == true && collisionDown == false && collisionRight == true && collisionLeft == true)
				{
					enemyDirection = { 0, 1 };
				}
				if (collisionUp == true && collisionDown == true && collisionRight == false && collisionLeft == true)
				{
					enemyDirection = { 1 , 0 };
				}
			}
			else if (map.map[enemyPositionY][enemyPositionX] == 0)
			{
				collisionLeft = false;
				enemyPositionX = position.x / 50;
				enemyPositionY = position.y / 50;
				int changeDirectionNumber = 0;
				srand(time(0));

				if (map.map[enemyPositionY + 1][enemyPositionX] == 0 && map.map[enemyPositionY - 1][enemyPositionX] == 1)
				{
					if (justChangedDirection == false)
					{
						changeDirectionNumber = std::rand() % 100;
						if (changeDirectionNumber >= 10 && changeDirectionNumber < 100)
						{
							enemyDirection = { -1,0 };
							//std::cout << "I continue this way \n";
						}
						else if (changeDirectionNumber >= 0 && changeDirectionNumber < 10)
						{
							enemyDirection = { 0,1 };
							//std::cout << "I am changing my direction \n";
						}
						justChangedDirection = true;
					}
					else if (justChangedDirection == true)
					{
						justChangedDirection = false;
					}
				}
				if (map.map[enemyPositionY - 1][enemyPositionX] == 0 && map.map[enemyPositionY + 1][enemyPositionX] == 1)
				{
					if (justChangedDirection == false)
					{
						changeDirectionNumber = std::rand() % 100;
						if (changeDirectionNumber >= 10 && changeDirectionNumber < 100)
						{
							enemyDirection = { -1,0 };
							//std::cout << "I continue this way \n";
						}
						else if (changeDirectionNumber >= 0 && changeDirectionNumber < 10)
						{
							enemyDirection = { 0,-1 };
							//std::cout << "I am changing my direction \n";
						}
						justChangedDirection = true;
					}
					else if (justChangedDirection == true)
					{
						justChangedDirection = false;
					}
				}
				if (map.map[enemyPositionY - 1][enemyPositionX] == 0 && map.map[enemyPositionY + 1][enemyPositionX] == 0)
				{
					if (justChangedDirection == false)
					{
						changeDirectionNumber = std::rand() % 100;
						if (changeDirectionNumber >= 20 && changeDirectionNumber < 100)
						{
							enemyDirection = { -1,0 };
							//std::cout << "I continue this way \n";
						}
						else if (changeDirectionNumber >= 0 && changeDirectionNumber < 10)
						{
							enemyDirection = { 0,1 };
							//std::cout << "I am changing my direction \n";
						}
						else if (changeDirectionNumber >= 10 && changeDirectionNumber < 20)
						{
							enemyDirection = { 0,-1 };
							//std::cout << "I am changing my direction \n";
						}
						justChangedDirection = true;
					}
					else if (justChangedDirection == true)
					{
						justChangedDirection = false;
					}
				}
			}
		}
		/*std::cout << enemyPositionY << " , " << enemyPositionX << "\n";*/
	}
	if (enemyDirection.y == 1 && enemyDirection.x == 0) // Moving downwards __________________________________________________________________________________
	{
		enemyPositionX = position.x / 50;
		enemyPositionY = (position.y + 50) / 50;

		int changeDirectionNumber = 0;
		srand(time(0));

		if (inPlayerPosition.y == position.y + 100 && map.map[enemyPositionY][enemyPositionX] != 1)
		{
			/*std::cout << enemyDirection.MultiplyVector(-1).x << " , " << enemyDirection.MultiplyVector(-1).y << "\n";
			enemyDirection.MultiplyVector(-1);*/
			enemyDirection.y *= -1;
		}
		else if (inPlayerPosition.y == position.y + 50 && map.map[enemyPositionY][enemyPositionX] != 1)
		{
			/*std::cout << enemyDirection.MultiplyVector(-1).x << " , " << enemyDirection.MultiplyVector(-1).y << "\n";
			enemyDirection.MultiplyVector(-1);*/
			enemyDirection.y *= -1;
		}
		else
		{
			if (map.map[enemyPositionY][enemyPositionX] == 1)
			{
				collisionDown = true;
				if (map.map[enemyPositionY - 1][enemyPositionX - 1] == 1)
				{
					collisionUp = true;
				}
				else
				{
					collisionUp = false;
				}
				if (map.map[enemyPositionY - 1][enemyPositionX - 1] == 1)
				{
					collisionLeft = true;
				}
				else
				{
					collisionLeft = false;
				}
				if (map.map[enemyPositionY - 1][enemyPositionX + 1] == 1)
				{
					collisionRight = true;
				}
				else
				{
					collisionRight = false;
				}

				if (collisionUp == false && collisionLeft == false && collisionRight == false && collisionDown == true)
				{
					changeDirectionNumber = std::rand() % 2;
					if (changeDirectionNumber == 0)
					{
						enemyDirection = { 1,0 };
					}
					else if (changeDirectionNumber == 1)
					{
						enemyDirection = { -1,0 };
					}
				}
				if (collisionUp == true && collisionLeft == false && collisionRight == false && collisionDown == true)
				{
					changeDirectionNumber = std::rand() % 2;
					if (changeDirectionNumber == 0)
					{
						enemyDirection = { 1,0 };
					}
					else if (changeDirectionNumber == 1)
					{
						enemyDirection = { -1,0 };
					}
				}
				if (collisionUp == false && collisionLeft == true && collisionRight == false && collisionDown == true)
				{
					enemyDirection = { 1,0 };
				}
				if (collisionUp == false && collisionLeft == false && collisionRight == true && collisionDown == true)
				{
					enemyDirection = { -1,0 };
				}
				if (collisionUp == false && collisionLeft == true && collisionRight == true && collisionDown == true)
				{
					enemyDirection = { 0, -1 };
				}
				if (collisionUp == true && collisionLeft == false && collisionRight == true && collisionDown == true)
				{
					enemyDirection = { -1, 0 };
				}
				if (collisionUp == true && collisionLeft == true && collisionRight == false && collisionDown == true)
				{
					enemyDirection = { 1 , 0 };
				}
			}
			else if (map.map[enemyPositionY][enemyPositionX] == 0)
			{
				collisionDown = false;
				enemyPositionX = position.x / 50;
				enemyPositionY = position.y / 50;
				int changeDirectionNumber = 0;
				srand(time(0));

				if (map.map[enemyPositionY][enemyPositionX + 1] == 0 && map.map[enemyPositionY][enemyPositionX - 1] == 1)
				{
					if (justChangedDirection == false)
					{
						changeDirectionNumber = std::rand() % 100;
						if (changeDirectionNumber >= 10 && changeDirectionNumber < 100)
						{
							enemyDirection = { 0,1 };
							//std::cout << "I continue this way \n";
						}
						else if (changeDirectionNumber >= 0 && changeDirectionNumber < 10)
						{
							enemyDirection = { 1,0 };
							//std::cout << "I am changing my direction \n";
						}
						justChangedDirection = true;
					}
					else if (justChangedDirection == true)
					{
						justChangedDirection = false;
					}
				}
				if (map.map[enemyPositionY][enemyPositionX - 1] == 0 && map.map[enemyPositionY][enemyPositionX + 1] == 1)
				{
					if (justChangedDirection == false)
					{
						changeDirectionNumber = std::rand() % 100;
						if (changeDirectionNumber >= 10 && changeDirectionNumber < 100)
						{
							enemyDirection = { 0,1 };
							//std::cout << "I continue this way \n";
						}
						else if (changeDirectionNumber >= 0 && changeDirectionNumber < 10)
						{
							enemyDirection = { -1,0 };
							//std::cout << "I am changing my direction \n";
						}
						justChangedDirection = true;
					}
					else if (justChangedDirection == true)
					{
						justChangedDirection = false;
					}
				}
				if (map.map[enemyPositionY][enemyPositionX - 1] == 0 && map.map[enemyPositionY][enemyPositionX + 1] == 0)
				{
					if (justChangedDirection == false)
					{
						changeDirectionNumber = std::rand() % 100;
						if (changeDirectionNumber >= 20 && changeDirectionNumber < 100)
						{
							enemyDirection = { 0,1 };
							//std::cout << "I continue this way \n";
						}
						else if (changeDirectionNumber >= 0 && changeDirectionNumber < 10)
						{
							enemyDirection = { 1,0 };
							//std::cout << "I am changing my direction \n";
						}
						else if (changeDirectionNumber >= 10 && changeDirectionNumber < 20)
						{
							enemyDirection = { -1,0 };
							//std::cout << "I am changing my direction \n";
						}
						justChangedDirection = true;
					}
					else if (justChangedDirection == true)
					{
						justChangedDirection = false;
					}
				}
			}
		}
		/*std::cout << enemyPositionY << " , " << enemyPositionX << "\n";*/
		//std::cout << enemyDirection.x << " , " << enemyDirection.y << "\n";
	}
	if (enemyDirection.y == -1 && enemyDirection.x == 0) // Moving upwards __________________________________________________________________
	{
		enemyPositionX = position.x / 50;
		enemyPositionY = (position.y - 50) / 50;
		int changeDirectionNumber = 0;
		srand(time(0));

		if (inPlayerPosition.y == position.y - 100 && map.map[enemyPositionY][enemyPositionX] != 1)
		{
			/*std::cout << enemyDirection.MultiplyVector(-1).x << " , " << enemyDirection.MultiplyVector(-1).y << "\n";
			enemyDirection.MultiplyVector(-1);*/
			enemyDirection.y *= -1;
		}
		else if (inPlayerPosition.y == position.y - 50 && map.map[enemyPositionY][enemyPositionX] != 1)
		{
			/*std::cout << enemyDirection.MultiplyVector(-1).x << " , " << enemyDirection.MultiplyVector(-1).y << "\n";
			enemyDirection.MultiplyVector(-1);*/
			enemyDirection.y *= -1;
		}
		else
		{
			if (map.map[enemyPositionY][enemyPositionX] == 1)
			{
				collisionUp = true;
				if (map.map[enemyPositionY + 1][enemyPositionX + 1] == 1)
				{
					collisionDown = true;
				}
				else
				{
					collisionDown = false;
				}
				if (map.map[enemyPositionY + 1][enemyPositionX - 1] == 1)
				{
					collisionLeft = true;
				}
				else
				{
					collisionLeft = false;
				}
				if (map.map[enemyPositionY + 1][enemyPositionX + 1] == 1)
				{
					collisionRight = true;
				}
				else
				{
					collisionRight = false;
				}

				if (collisionDown == false && collisionLeft == false && collisionRight == false && collisionUp == true)
				{
					changeDirectionNumber = std::rand() % 2;
					if (changeDirectionNumber == 0)
					{
						enemyDirection = { 1,0 };
					}
					else if (changeDirectionNumber == 1)
					{
						enemyDirection = { -1,0 };
					}
				}
				if (collisionDown == true && collisionLeft == false && collisionRight == false && collisionUp == true)
				{
					changeDirectionNumber = std::rand() % 2;
					if (changeDirectionNumber == 0)
					{
						enemyDirection = { 1,0 };
					}
					else if (changeDirectionNumber == 1)
					{
						enemyDirection = { -1,0 };
					}
				}
				if (collisionDown == false && collisionLeft == true && collisionRight == false && collisionUp == true)
				{
					enemyDirection = { 1,0 };
				}
				if (collisionDown == false && collisionLeft == false && collisionRight == true && collisionUp == true)
				{
					enemyDirection = { -1,0 };
				}
				if (collisionDown == false && collisionLeft == true && collisionRight == true && collisionUp == true)
				{
					enemyDirection = { 0,  1 };
				}
				if (collisionDown == true && collisionLeft == false && collisionRight == true && collisionUp == true)
				{
					enemyDirection = { -1, 0 };
				}
				if (collisionDown == true && collisionLeft == true && collisionRight == false && collisionUp == true)
				{
					enemyDirection = { 1 , 0 };
				}
			}
			else if (map.map[enemyPositionY][enemyPositionX] == 0)
			{
				collisionUp = false;
				enemyPositionX = position.x / 50;
				enemyPositionY = position.y / 50;
				int changeDirectionNumber = 0;
				srand(time(0));

				if (map.map[enemyPositionY][enemyPositionX + 1] == 0 && map.map[enemyPositionY][enemyPositionX - 1] == 1)
				{
					if (justChangedDirection == false)
					{
						changeDirectionNumber = std::rand() % 100;
						if (changeDirectionNumber >= 10 && changeDirectionNumber < 100)
						{
							enemyDirection = { 0,-1 };
							//std::cout << "I continue this way \n";
						}
						else if (changeDirectionNumber >= 0 && changeDirectionNumber < 10)
						{
							enemyDirection = { 1,0 };
							//std::cout << "I am changing my direction \n";
						}
						justChangedDirection = true;
					}
					else if (justChangedDirection == true)
					{
						justChangedDirection = false;
					}
				}
				if (map.map[enemyPositionY][enemyPositionX - 1] == 0 && map.map[enemyPositionY][enemyPositionX + 1] == 1)
				{
					if (justChangedDirection == false)
					{
						changeDirectionNumber = std::rand() % 100;
						if (changeDirectionNumber >= 10 && changeDirectionNumber < 100)
						{
							enemyDirection = { 0,-1 };
							//std::cout << "I continue this way \n";
						}
						else if (changeDirectionNumber >= 0 && changeDirectionNumber < 10)
						{
							enemyDirection = { -1,0 };
							//std::cout << "I am changing my direction \n";
						}
						justChangedDirection = true;
					}
					else if (justChangedDirection == true)
					{
						justChangedDirection = false;
					}
				}
				if (map.map[enemyPositionY][enemyPositionX - 1] == 0 && map.map[enemyPositionY][enemyPositionX + 1] == 0)
				{
					if (justChangedDirection == false)
					{
						changeDirectionNumber = std::rand() % 100;
						if (changeDirectionNumber >= 20 && changeDirectionNumber < 100)
						{
							enemyDirection = { 0,-1 };
							//std::cout << "I continue this way \n";
						}
						else if (changeDirectionNumber >= 0 && changeDirectionNumber < 10)
						{
							enemyDirection = { 1,0 };
							//std::cout << "I am changing my direction \n";
						}
						else if (changeDirectionNumber >= 10 && changeDirectionNumber < 20)
						{
							enemyDirection = { -1,0 };
							//std::cout << "I am changing my direction \n";
						}
						justChangedDirection = true;
					}
					else if (justChangedDirection == true)
					{
						justChangedDirection = false;
					}
				}
			}
		}
		/*	std::cout << enemyPositionY << " , " << enemyPositionX << "\n";*/
	}
}

// Continuos enemy movement ______________________________________________________________________________________________________________________________________________
void Enemy::EnemyMovement(Vector2d inPlayerPosition)
{
	if ((framesCounter % framesCounterDivider) == 0)
	{
		CollisionCheck(inPlayerPosition);
		if (enemyDirection.x == 1 && collisionRight == false)
		{
			speed = Vector2d{ map.boxSize, 0 };
			position.x += speed.x;
			position.y += speed.y;
		}
		if (enemyDirection.x == -1 && collisionLeft == false)
		{
			speed = Vector2d{ -map.boxSize, 0 };
			position.x += speed.x;
			position.y += speed.y;
		}
		if (enemyDirection.y == -1 && collisionUp == false)
		{
			speed = Vector2d{ 0, -map.boxSize };
			position.x += speed.x;
			position.y += speed.y;
		}
		if (enemyDirection.y == 1 && collisionDown == false)
		{
			speed = Vector2d{ 0, map.boxSize };
			position.x += speed.x;
			position.y += speed.y;
		}
	}
	framesCounter++;
}

// Draw enemy function _________________________________________________________________________________________________________________________________________________________________
void Enemy::DrawEnemy(Vector2d inPlayerPosition)
{
	EnemyMovement(inPlayerPosition);

	visualPosition = { position.x + 25, position.y + 25 };
	DrawCircle(visualPosition.x, visualPosition.y, 25, color);
}

