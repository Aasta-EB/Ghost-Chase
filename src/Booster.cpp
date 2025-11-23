#include "Booster.h"

Vector2d Booster::FindBoosterPosition()
{
	srand(time(0));

	int boosterPlacementNumber = std::rand() % 5;

	if (boosterPlacementNumber == 0)
	{
		boosterPosition = { 12 * 50 + 25, 9 * 50 + 25 };
	}
	else if (boosterPlacementNumber == 1)
	{
		boosterPosition = { 25 * 50 + 25, 11 * 50 + 25 };
	}
	else if (boosterPlacementNumber == 2)
	{
		boosterPosition = { 7 * 50 + 25, 3 * 50 + 25 };
	}
	else if (boosterPlacementNumber == 3)
	{
		boosterPosition = { 9 * 50 + 25, 11 * 50 + 25 };
	}
	else if (boosterPlacementNumber == 4)
	{
		boosterPosition = { 21 * 50 + 25, 3 * 50 + 25 };
	}
	return boosterPosition;
}

void Booster::DrawBooster()
{
	DrawCircle(boosterPosition.x, boosterPosition.y, 5, GREEN);

}

void Booster::ExpandPlayerVision()
{
}

// A booster that exposes the enemys position and points in the direction
void Booster::ExposeEnemyPosition(Vector2d inPlayerPosition, Vector2d inEnemyPosition)
{
	if (inEnemyPosition.y <= inPlayerPosition.y && inEnemyPosition.y != inPlayerPosition.y) // On top arrow
	{
		Vector2d playerEnemyVector = inPlayerPosition.CalculateVectorToTarget({ inPlayerPosition.x , inPlayerPosition.y - 25 }); // Vector pointing "towards" the enemy
		Vector2d nmPlayerEnemyVector = playerEnemyVector.NormalizeVector(); // Normalizing the vector
		Vector2d scaledNmPlayerEnemyVector = nmPlayerEnemyVector.ScaleVector(25.f); // Scaling the vector by 25 as its the lenght i want the vector
		Vector2d playerEnemyVectorEnd = scaledNmPlayerEnemyVector.SumVectors(inPlayerPosition); // Finding the exact end position of the line we want to draw, is also the tip of the arrow

		// Drawing the line, 3 times for more visibility
		DrawLine(inPlayerPosition.x, inPlayerPosition.y, playerEnemyVectorEnd.x, playerEnemyVectorEnd.y, RED);
		DrawLine(inPlayerPosition.x - 1, inPlayerPosition.y, playerEnemyVectorEnd.x - 1, playerEnemyVectorEnd.y, RED);
		DrawLine(inPlayerPosition.x + 1, inPlayerPosition.y, playerEnemyVectorEnd.x + 1, playerEnemyVectorEnd.y, RED);

		// Calculating the points to the triangle
		float distanceToArrowEdgePoint = vector2d.CalculateSideLenght(90.f, 10.f, 45.f); // Finds the distance from the arrow line to the point we want to draw as the corner of the triangle
		float triangleHeight = vector2d.CalculateTangent(10, distanceToArrowEdgePoint); // Finds how far down on the arrow line we need to have the arrow edge be
		Vector2d vectorTriangleHeight = nmPlayerEnemyVector.ScaleVector(-triangleHeight); // Finds the vector of that lengt
		Vector2d vectorToArrowEdgePoint = vectorTriangleHeight.FindNormalizedOrtognalVector(); // Finds the vector out to the arrow edge
		Vector2d arrowEdgePoint = vectorTriangleHeight.SumVectors(vectorToArrowEdgePoint); // Adds the two vectors together to find the exact point we want to draw the arrow edge

		// Defining the points of the triangle
		Vector2d pointA = { playerEnemyVectorEnd.x, playerEnemyVectorEnd.y };
		Vector2d pointB = { pointA.x - distanceToArrowEdgePoint, pointA.y + triangleHeight *2 };
		Vector2d pointC = { pointB.x + distanceToArrowEdgePoint *2, pointB.y};

		// Drawing the triangle
		DrawTriangle({ pointA.x, pointA.y }, { pointB.x, pointB.y }, { pointC.x,pointC.y }, RED);
	}
	else if (inEnemyPosition.y >= inPlayerPosition.y && inEnemyPosition.y != inPlayerPosition.y) // Under arrow
	{
		Vector2d playerEnemyVector = inPlayerPosition.CalculateVectorToTarget({ inPlayerPosition.x , inPlayerPosition.y + 25 }); // Vector pointing "towards" the enemy
		Vector2d nmPlayerEnemyVector = playerEnemyVector.NormalizeVector(); // Normalizing the vector
		Vector2d scaledNmPlayerEnemyVector = nmPlayerEnemyVector.ScaleVector(25.f); // Scaling the vector by 25 as its the lenght i want the vector
		Vector2d playerEnemyVectorEnd = scaledNmPlayerEnemyVector.SumVectors(inPlayerPosition); // Finding the exact end position of the line we want to draw, is also the tip of the arrow

		// Drawing the line, 3 times for more visibility
		DrawLine(inPlayerPosition.x, inPlayerPosition.y, playerEnemyVectorEnd.x, playerEnemyVectorEnd.y, RED);
		DrawLine(inPlayerPosition.x - 1, inPlayerPosition.y, playerEnemyVectorEnd.x - 1, playerEnemyVectorEnd.y, RED);
		DrawLine(inPlayerPosition.x + 1, inPlayerPosition.y, playerEnemyVectorEnd.x + 1, playerEnemyVectorEnd.y, RED);

		// Calculating the points to the triangle
		float distanceToArrowEdgePoint = vector2d.CalculateSideLenght(90.f, 10.f, 45.f); // Finds the distance from the arrow line to the point we want to draw as the corner of the triangle
		float triangleHeight = vector2d.CalculateTangent(10, distanceToArrowEdgePoint); // Finds how far down on the arrow line we need to have the arrow edge be
		Vector2d vectorTriangleHeight = nmPlayerEnemyVector.ScaleVector(-triangleHeight); // Finds the vector of that lengt
		Vector2d vectorToArrowEdgePoint = vectorTriangleHeight.FindNormalizedOrtognalVector(); // Finds the vector out to the arrow edge
		Vector2d arrowEdgePoint = vectorTriangleHeight.SumVectors(vectorToArrowEdgePoint); // Adds the two vectors together to find the exact point we want to draw the arrow edge

		// Defining the points of the triangle
		Vector2d pointA = { playerEnemyVectorEnd.x, playerEnemyVectorEnd.y };
		Vector2d pointB = { pointA.x + distanceToArrowEdgePoint, pointA.y - triangleHeight * 2 };
		Vector2d pointC = { pointB.x - distanceToArrowEdgePoint * 2, pointB.y };

		// Drawing the triangle
		DrawTriangle({ pointA.x, pointA.y }, { pointB.x, pointB.y }, { pointC.x,pointC.y }, RED);

	}
	else if (inEnemyPosition.x <= inPlayerPosition.x) // Left arrow, enemy is to the left
	{
		Vector2d playerEnemyVector = inPlayerPosition.CalculateVectorToTarget({ inPlayerPosition.x - 25, inPlayerPosition.y });
		Vector2d nmPlayerEnemyVector = playerEnemyVector.NormalizeVector();
		Vector2d scaledNmPlayerEnemyVector = { inPlayerPosition.x + nmPlayerEnemyVector.x * 25.f ,inPlayerPosition.y + nmPlayerEnemyVector.y * 25.f };
		
		DrawLine(inPlayerPosition.x, inPlayerPosition.y, scaledNmPlayerEnemyVector.x, scaledNmPlayerEnemyVector.y, RED);
		DrawLine(inPlayerPosition.x, inPlayerPosition.y - 1, scaledNmPlayerEnemyVector.x, scaledNmPlayerEnemyVector.y - 1, RED);
		DrawLine(inPlayerPosition.x, inPlayerPosition.y + 1, scaledNmPlayerEnemyVector.x, scaledNmPlayerEnemyVector.y + 1, RED);

		float distanceToArrowEdgePoint = vector2d.CalculateSideLenght(90.f, 10.f, 45.f);

		float triangleHeight = vector2d.CalculateTangent(10, distanceToArrowEdgePoint);

		Vector2d vectorTriangleHeight = nmPlayerEnemyVector.ScaleVector(triangleHeight);

		Vector2d vectorToArrowEdgePoint = vectorTriangleHeight.FindNormalizedOrtognalVector();

		Vector2d actualVectorToArrowEdgePoint = vectorToArrowEdgePoint.ScaleVector(distanceToArrowEdgePoint);

		Vector2d arrowEdgePoint = vectorTriangleHeight.SumVectors(actualVectorToArrowEdgePoint);

		Vector2d pointA = { scaledNmPlayerEnemyVector.x, scaledNmPlayerEnemyVector.y };
		Vector2d pointB = { (scaledNmPlayerEnemyVector.x - arrowEdgePoint.x) + 5, scaledNmPlayerEnemyVector.y - arrowEdgePoint.y };
		Vector2d pointC = { pointB.x, pointB.y - (distanceToArrowEdgePoint * 2) };

		DrawTriangle({ pointA.x, pointA.y }, { pointB.x, pointB.y }, { pointC.x,pointC.y }, RED);
	}
	else if (inEnemyPosition.x > inPlayerPosition.x) // Right arrow
	{
		Vector2d playerEnemyVector = inPlayerPosition.CalculateVectorToTarget({ inPlayerPosition.x + 25, inPlayerPosition.y });
		Vector2d nmPlayerEnemyVector = playerEnemyVector.NormalizeVector();
		Vector2d scaledNmPlayerEnemyVector = { inPlayerPosition.x + nmPlayerEnemyVector.x * 25.f ,inPlayerPosition.y + nmPlayerEnemyVector.y * 25.f };

		DrawLine(inPlayerPosition.x, inPlayerPosition.y, scaledNmPlayerEnemyVector.x, scaledNmPlayerEnemyVector.y, RED);
		DrawLine(inPlayerPosition.x, inPlayerPosition.y - 1, scaledNmPlayerEnemyVector.x, scaledNmPlayerEnemyVector.y - 1, RED);
		DrawLine(inPlayerPosition.x, inPlayerPosition.y + 1, scaledNmPlayerEnemyVector.x, scaledNmPlayerEnemyVector.y + 1, RED);

		float distanceToArrowEdgePoint = vector2d.CalculateSideLenght(90.f, 10.f, 45.f);

		float triangleHeight = vector2d.CalculateTangent(10, distanceToArrowEdgePoint);

		Vector2d vectorTriangleHeight = nmPlayerEnemyVector.ScaleVector(-triangleHeight);

		Vector2d vectorToArrowEdgePoint = vectorTriangleHeight.FindNormalizedOrtognalVector();

		Vector2d actualVectorToArrowEdgePoint = vectorToArrowEdgePoint.ScaleVector(distanceToArrowEdgePoint);

		Vector2d arrowEdgePoint = vectorTriangleHeight.SumVectors(actualVectorToArrowEdgePoint);

		Vector2d pointA = { scaledNmPlayerEnemyVector.x, scaledNmPlayerEnemyVector.y };
		Vector2d pointC = { (scaledNmPlayerEnemyVector.x - arrowEdgePoint.x) - 10, scaledNmPlayerEnemyVector.y - arrowEdgePoint.y };
		Vector2d pointB = { pointC.x, pointC.y - (distanceToArrowEdgePoint * 2) };

		DrawTriangle({ pointA.x, pointA.y }, { pointB.x, pointB.y }, { pointC.x,pointC.y }, RED);
	}
}

void Booster::BoosterTimer(Vector2d inPlayerPosition, Vector2d inEnemyPosition)
{
	if (boosterTime > 0.f)
	{
		boosterTime -= GetFrameTime();
		ExposeEnemyPosition(inPlayerPosition, inEnemyPosition);
	}
	else
	{
		collisionPlayerBooster = false; 
	}

}
