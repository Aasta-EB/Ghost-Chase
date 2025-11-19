#include "Booster.h"

void Booster::DrawBooster()
{
}

void Booster::ExpandPlayerVision()
{
}

// A booster that exposes the enemys position and points in the direction
void Booster::ExposeEnemyPosition(Vector2d inPlayerPosition, Vector2d inEnemyPosition)
{
	// Finding and normalizing the vector between player and enemy
	Vector2d playerEnemyVector = inPlayerPosition.CalculateDistanceFromTarget(inEnemyPosition);
	Vector2d normalizedPlayerEnemyVector = playerEnemyVector.NormalizeVector();

	float normalizedPlayerEnemyVectorX = normalizedPlayerEnemyVector.x * 25.f;
	float normalizedPlayerEnemyVectorY = normalizedPlayerEnemyVector.y * 25.f;

	Vector2d normalizedPlayerEnemyVectorFullCalculated = { normalizedPlayerEnemyVector.x * 25.f ,normalizedPlayerEnemyVector.y * 25.f };

	Vector2d tangentVector = normalizedPlayerEnemyVectorFullCalculated.FindOrtognalVector();

	float arrowLine = normalizedPlayerEnemyVectorFullCalculated.CalculateDeltaVector();

	Vector2d arrowPoint = { inPlayerPosition.x + normalizedPlayerEnemyVectorFullCalculated.x, inPlayerPosition.y + normalizedPlayerEnemyVectorFullCalculated.y };

	float forhold = sinf(90) / 5; 

	float nyttForhold = sinf(45) / forhold; 

	float lastTangent = sqrt(5*5 - nyttForhold * nyttForhold); 

	float somethingX = normalizedPlayerEnemyVector.x * ( - lastTangent);
	float somethingY = normalizedPlayerEnemyVector.y * ( - lastTangent);

	float laX = somethingX + nyttForhold;
	float laY = somethingY + nyttForhold;

	float luX = somethingX - nyttForhold;
	float luY = somethingY - nyttForhold;


	Vector2d normalizedTangentVector = tangentVector.NormalizeVector();

	// Draws the line towards the enemy
	DrawLine(inPlayerPosition.x, inPlayerPosition.y, inPlayerPosition.x + normalizedPlayerEnemyVector.x * 25.f, inPlayerPosition.y + normalizedPlayerEnemyVector.y * 25.f, RED);
	DrawLine(arrowPoint.x, arrowPoint.y, arrowPoint.x - laX, arrowPoint.y - laY, RED);
	DrawLine(arrowPoint.x, arrowPoint.y, arrowPoint.x + luX, arrowPoint.y + luY, RED);
}