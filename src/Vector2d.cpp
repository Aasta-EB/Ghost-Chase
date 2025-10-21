#include "Vector2d.h"

float Vector2d::CalculateLenghtOfVector()
{
    float lenghtOfVector = sqrt(x * x + y * y);

    return lenghtOfVector;
}
