#include "Vector2d.h"

// Calculating the vector between two points _______________________________________________________________________________________________________________________
// (Coskun, P.K.S, personal communication, October 2025) 
Vector2d Vector2d::CalculateVectorToTarget(Vector2d inTargetedVector)
{
	float subtractVectorsX = inTargetedVector.x - x;
	float subtractVectorsY = inTargetedVector.y - y;

	Vector2d vectorBetweenTarget{ subtractVectorsX , subtractVectorsY };

	return vectorBetweenTarget;
}

// Calculating the lenght(magnitude) of a vector ____________________________________________________________________________________________________________________
// (Coskun, P.K.S, personal communication, October 2025)
float Vector2d::CalulateMagnitudeOfDelta() 
{
	float magnitudeOfVector = sqrt(x * x + y * y);

	return magnitudeOfVector;
}

// Calculates the lenght between two points _________________________________________________________________________________________________________________________
// (Coskun, P.K.S, personal communication, October 2025)
float Vector2d::CalculateMagnitudeToTarget(Vector2d inVectorTarget)
{
	Vector2d vectorBetweenTarget = CalculateVectorToTarget(inVectorTarget);

	float findDelta = vectorBetweenTarget.CalulateMagnitudeOfDelta();

	return findDelta;
}

// Calculates the sum of two vectors (vector offset) ________________________________________________________________________________________________________________
// (Coskun, P.K.S, personal communication, October 2025) 
Vector2d Vector2d::SumVectors(Vector2d inOtherVector)
{
	Vector2d summedVectors = { x + inOtherVector.x, y + inOtherVector.y };

	return summedVectors;
}

// Calculates the tangent of a triangle _____________________________________________________________________________________________________________________________
float Vector2d::CalculateTangent(float inHypotenuseLenght, float inOtherTangentLenght)
{
	float calculatedTangent = sqrt((inHypotenuseLenght * inHypotenuseLenght) - (inOtherTangentLenght * inOtherTangentLenght));

	return calculatedTangent;
}

// Calculates the ratio of a triangle ________________________________________________________________________________________________________________________________
float Vector2d::FindTriangleRatio(float inAngle, float inSideLenght)
{
	float triangleRatio = sinf(inAngle) / inSideLenght;

	return triangleRatio;
}

// Calculate side of triangle using triangle ratio ___________________________________________________________________________________________________________________
float Vector2d::FindTriangleSideLenght(float inAngle, float inTriangleRatio)
{
	float triangleSideLenght = sinf(inAngle) / inTriangleRatio;

	return triangleSideLenght;
}

// Calculates side of triangle _______________________________________________________________________________________________________________________________________
float Vector2d::CalculateSideLenght(float inFirstAngle, float inSideLenght, float inSecondAngle)
{
	float triangleRatio = FindTriangleRatio(inFirstAngle, inSideLenght);
	float sideLenght = FindTriangleSideLenght(inSecondAngle, triangleRatio);

	return sideLenght;
}

// Normalizing vector (finding directional vector) ____________________________________________________________________________________________________________________
// (Coskun, P.K.S, personal communication, October 2025)
Vector2d Vector2d::NormalizeVector()
{
	// Checking if the magnitude is 0 as dividing by 0 is not good 
	if (CalulateMagnitudeOfDelta() == 0)
	{
		return { 0, 0 };
	}

	float normalizedX = x / CalulateMagnitudeOfDelta();
	float normalizedY = y / CalulateMagnitudeOfDelta();

	return { normalizedX , normalizedY };
}

// Calculates the orthogonal vector and normalizes it __________________________________________________________________________________________________________________
Vector2d Vector2d::FindNormalizedOrthogonalVector()
{
	Vector2d ortognalVector = { -y,x };

	Vector2d normalizedOrtognalVector = ortognalVector.NormalizeVector();

	return normalizedOrtognalVector;
}

// Multiplying the vector (scaling vector) _____________________________________________________________________________________________________________________________
// (Coskun, P.K.S, personal communication, October 2025)
Vector2d Vector2d::MultiplyVector(float scale)
{
	float scaledVectorX = x * scale;
	float scaledVectorY = y * scale;

	return { scaledVectorX, scaledVectorY };
}

// Calculates a cosine wave _____________________________________________________________________________________________________________________________________________
Vector2d Vector2d::CalculateCosineWave(float inAmplitude, float inFrequency, float inValueX)
{
	float valueY = inAmplitude * cosf(((2 * 3.14159) / inFrequency) * inValueX);

	Vector2d cosineWaveVector = { inValueX, valueY };

	return cosineWaveVector;
}