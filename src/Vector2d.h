#pragma once
#include <math.h>

class Vector2d
{
public:
	// Vector class variables
	float x;
	float y;

	// Calculates lenght of vector (magnitude)
	float CalculateDeltaVector();

	Vector2d CalculateDistanceFromTarget(Vector2d inTargetedVector);

	float CalculateDeltatoTarget(Vector2d inVectorTarget);

};
