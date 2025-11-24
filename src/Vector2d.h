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

	// Calculates the tangent of aa triangle
	float CalculateTangent(float inHypotenuseLenght, float inOtherTangentLenght);

	// Calculates the vector from point to target point
	Vector2d CalculateVectorToTarget(Vector2d inTargetedVector);

	// Calculates the distance from point to target point
	float CalculateDeltatoTarget(Vector2d inVectorTarget);

	// Sums two vectors together
	Vector2d SumVectors(Vector2d inOtherVector);

	// Find triangle ratio
	float FindTriangleRatio(float inAngle, float inSideLenght);

	// Finds the side lenght using the triangle ratio
	float findTriangleSideLenght(float inAngle, float inTriangleRatio);

	// Finds the side lenght using the findtriangleratio and findtrianglesidelenght functions
	float CalculateSideLenght(float inFirstAngle, float inSideLenght, float inSecondAngle);

	// Finds the normalized ortognal vector of another vector
	Vector2d FindNormalizedOrtognalVector();

	// Calculates a cosine wave
	Vector2d CalculateCosineWave(float inAmplitude, float inFrequency, float inValueX);

	// Sets the offset to the vector
	/*Vector2d OffsetVector(Vector2d inVectorToAdd);*/

	// Scales the vector
	Vector2d MultiplyVector(float scale);

	// Normalizez the vector
	Vector2d NormalizeVector();;

	// Uses cosine to get movement
	//Vector2d CosineMovement(Vector2d inCenter, float inAmplitude, float inAngle);;

	//// Creates a circular motion
	//Vector2d CircularMotion(Vector2d inCenter, float inRadius, float inAngle);

	// Finding the dot product
	/*float DotProduct(Vector2d inOtherVector);*/

	// Finding the angle between two vectors
	/*float AngleBetweenVectors(Vector2d inOtherVector);*/

	// finds the cross product between two vectors (finds left or right)
	/*float CrossProduct(Vector2d inOtherVector);*/
};
