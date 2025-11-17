#include "Vector2d.h"

float Vector2d::CalculateDeltaVector()
{
	float lenghtOfVector = sqrt(x * x + y * y);

	return lenghtOfVector;
}

Vector2d Vector2d::CalculateDistanceFromTarget(Vector2d inTargetedVector)
{
	float subtractVectorsX = inTargetedVector.x - x;
	float subtractVectorsY = inTargetedVector.y - y;

	Vector2d vectorBetweenTarget{ subtractVectorsX , subtractVectorsY };

	return vectorBetweenTarget;
}

float Vector2d::CalculateDeltatoTarget(Vector2d inVectorTarget)
{
	Vector2d vectorBetweenTarget = CalculateDistanceFromTarget(inVectorTarget);

	float findDelta = vectorBetweenTarget.CalculateDeltaVector();

	return findDelta;
}
