#include "Vector2d.h"

float Vector2d::CalculateDeltaVector()
{
	float lenghtOfVector = sqrt(x * x + y * y);

	return lenghtOfVector;
}

float Vector2d::CalculateTangent(float inHypotenuseLenght, float inOtherTangentLenght)
{
	float calculatedTangent = sqrt((inHypotenuseLenght * inHypotenuseLenght) - (inOtherTangentLenght * inOtherTangentLenght));

	return calculatedTangent;
}

Vector2d Vector2d::CalculateVectorToTarget(Vector2d inTargetedVector)
{
	float subtractVectorsX = inTargetedVector.x - x;
	float subtractVectorsY = inTargetedVector.y - y;

	Vector2d vectorBetweenTarget{ subtractVectorsX , subtractVectorsY };

	return vectorBetweenTarget;
}

float Vector2d::CalculateDeltatoTarget(Vector2d inVectorTarget)
{
	Vector2d vectorBetweenTarget = CalculateVectorToTarget(inVectorTarget);

	float findDelta = vectorBetweenTarget.CalculateDeltaVector();

	return findDelta;
}

Vector2d Vector2d::SumVectors(Vector2d inOtherVector)
{
	Vector2d summedVectors = { x + inOtherVector.x, y + inOtherVector.y };

	return summedVectors;
}

float Vector2d::FindTriangleRatio(float inAngle, float inSideLenght)
{
	float triangleRatio = sinf(inAngle) / inSideLenght;

	return triangleRatio;
}

float Vector2d::findTriangleSideLenght(float inAngle, float inTriangleRatio)
{
	float triangleSideLenght = sinf(inAngle) / inTriangleRatio;

	return triangleSideLenght;
}

float Vector2d::CalculateSideLenght(float inFirstAngle, float inSideLenght, float inSecondAngle)
{
	float triangleRatio = FindTriangleRatio(inFirstAngle, inSideLenght);
	float sideLenght = findTriangleSideLenght(inSecondAngle, triangleRatio);

	return sideLenght;
}

Vector2d Vector2d::FindNormalizedOrtognalVector()
{
	Vector2d ortognalVector = { -y,x };

	Vector2d normalizedOrtognalVector = ortognalVector.NormalizeVector();

	return normalizedOrtognalVector;
}

Vector2d Vector2d::CalculateCosineWave(float inAmplitude, float inFrequency, float inValueX)
{
	float valueY = inAmplitude * cosf(((2 * 3.14159) / inFrequency) * inValueX);

	Vector2d cosineWaveVector = { inValueX, valueY };

	return cosineWaveVector;
}

//Vector2d Vector2d::OffsetVector(Vector2d inVectorToAdd)
//{
//	float outVectorX = x + inVectorToAdd.x;
//	float outVectorY = y + inVectorToAdd.y;
//	return { outVectorX, outVectorY };
//}

// Scales the vector
Vector2d Vector2d::ScaleVector(float scale)
{
	float scaleVectorX = x * scale;
	float scaleVectorY = y * scale;

	return { scaleVectorX, scaleVectorY };
}

Vector2d Vector2d::NormalizeVector()
{
	if (CalculateDeltaVector() == 0)
	{
		return { 0, 0 };
	}

	// normalizing a the vector by taking its value divided by its magnitude(length)
	float normalizedVectorX = x / CalculateDeltaVector();
	float normalizedVectorY = y / CalculateDeltaVector();
	Vector2d normalizedVector{ normalizedVectorX,normalizedVectorY };

	return normalizedVector;
}
// Uses cosine to get movement
Vector2d Vector2d::CosineMovement(Vector2d inCenter, float inAmplitude, float inAngle)
{
	float x = inCenter.x + inAmplitude * cosf(inAngle);
	float y = inCenter.y;

	return { x, y };
}
//
//// Creates a circular motion
//Vector2d Vector2d::CircularMotion(Vector2d inCenter, float inRadius, float inAngle)
//{
//	float cosX = inCenter.x + inRadius * cosf(inAngle);
//	float sinY = inCenter.y + inRadius * sinf(inAngle);
//
//	return { cosX, sinY };
//}

// Finding the dot product
//float Vector2d::DotProduct(Vector2d inOtherVector)
//{
//	float xComponentMultiplied = x * inOtherVector.x;
//	float yComponentMultiplied = y * inOtherVector.y;
//
//	float dotProduct = xComponentMultiplied + yComponentMultiplied;
//
//	return 	dotProduct;
//}

// Finding the angle between two vectors
//float Vector2d::AngleBetweenVectors(Vector2d inOtherVector)
//{
//	float thisLenght = CalculateDeltaVector();
//	float otherLenght = inOtherVector.CalculateDeltaVector();
//
//	if (thisLenght == 0 || otherLenght == 0)
//	{
//		return 0.0f;
//	}
//
//	float dotProduct = DotProduct(inOtherVector);
//
//	float cosine = dotProduct / (thisLenght * otherLenght);
//
//	float degrees = acosf(cosine) * (180 / 3.14);
//	// Tells the program to find the cosine then multiplying it so it is shown in degrees and not radians
//
//	return degrees;
//}

//float Vector2d::CrossProduct(Vector2d inOtherVector)
//{
//	float aComponentMultiplied = x * inOtherVector.y;
//	float bComponentMultibplied = y * inOtherVector.x;
//
//	float crossProduct = aComponentMultiplied - bComponentMultibplied;
//
//	return crossProduct;
//}