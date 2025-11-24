#pragma once
#include <math.h>

class Vector2d
{
public:
	// Vector class variables
	float x;
	float y;

	// Calculating the vector between two points 
	// (Coskun, P.K.S, personal communication, October 2025) 
	Vector2d CalculateVectorToTarget(Vector2d inTargetedVector);

	// Calculating the lenght(magnitude) of a vector 
	// (Coskun, P.K.S, personal communication, October 2025)
	float CalulateMagnitudeOfDelta();

	// Calculates the lenght between two points 
	// (Coskun, P.K.S, personal communication, October 2025)
	float CalculateMagnitudeToTarget(Vector2d inVectorTarget);

	// Calculates the sum of two vectors (vector offset) 
	// (Coskun, P.K.S, personal communication, October 2025) 
	Vector2d SumVectors(Vector2d inOtherVector);

	// Calculates the tangent of a triangle
	float CalculateTangent(float inHypotenuseLenght, float inOtherTangentLenght);

	// Calculates the ratio of a triangle
	float FindTriangleRatio(float inAngle, float inSideLenght);

	// Calculate side of triangle using triangle ratio
	float FindTriangleSideLenght(float inAngle, float inTriangleRatio);

	// Calculates side of triangle
	float CalculateSideLenght(float inFirstAngle, float inSideLenght, float inSecondAngle);

	// Normalizing vector (finding directional vector) 
	// (Coskun, P.K.S, personal communication, October 2025)
	Vector2d NormalizeVector();

	// Calculates the orthogonal vector and normalizes it
	Vector2d FindNormalizedOrthogonalVector();

	// Multiplying the vector (scaling vector) 
	// (Coskun, P.K.S, personal communication, October 2025)
	Vector2d MultiplyVector(float scale);

	// Calculates a cosine wave
	Vector2d CalculateCosineWave(float inAmplitude, float inFrequency, float inValueX);	
};
