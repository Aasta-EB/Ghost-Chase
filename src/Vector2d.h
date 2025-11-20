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

	Vector2d CalculateVectorToTarget(Vector2d inTargetedVector);

	float CalculateDeltatoTarget(Vector2d inVectorTarget);

	Vector2d FindOrtognalVector();

	// Functions from class NEEDS TO BE CHANGED
	// Normalizes the Vector
	// Sets the offset to the vector
	Vector2d OffsetVector(Vector2d inVectorToAdd);

	// Scales the vector
	Vector2d ScaleVector(float scale);

	// Normalizez the vector
	Vector2d NormalizeVector();;

	// Uses cosine to get movement
	Vector2d CosineMovement(Vector2d inCenter, float inAmplitude, float inAngle);;

	// Creates a circular motion
	Vector2d CircularMotion(Vector2d inCenter, float inRadius, float inAngle);

	// Finding the dot product
	float DotProduct(Vector2d inOtherVector);

	// Finding the angle between two vectors
	float AngleBetweenVectors(Vector2d inOtherVector);

	// finds the cross product between two vectors (finds left or right)
	float CrossProduct(Vector2d inOtherVector);
};
