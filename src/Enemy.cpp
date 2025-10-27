#include "Enemy.h"

void Enemy::EnemyMovement()
{
	if (GetRandomValue(0, 100) < 5)
	{
		enemyDirection = GetRandomValue(0, 3);
		int i = 0; 
		while (i < 10)
		{
			switch (enemyDirection)
			{
				// Venstre
			case 0:
				enemyPosition.x -= enemySpeed * GetFrameTime();
				break;

				//Høyre
			case 1:
				enemyPosition.x += enemySpeed * GetFrameTime();
				break;

				// Opp
			case 2:
				enemyPosition.y -= enemySpeed * GetFrameTime();
				break;

				// Ned
			case 3:
				enemyPosition.y += enemySpeed * GetFrameTime();
				break;

			default:
				break;
			}
			i += 1;
		}
		
	}
}

void Enemy::DrawEnemy()
{
	EnemyMovement();
	DrawCircle(enemyPosition.x, enemyPosition.y, enemySize, enemyColor);
}
