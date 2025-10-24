#include "Vector2d.h"

float Vector2d::CalculateLenghtOfVector()
{
    float lenghtOfVector = sqrt(x * x + y * y);

    return lenghtOfVector;
}

// Hopefully we can use this function to calculate the player box position, then we get some more math ;)
float Vector2d::CalculatePlayerPosition(Vector2d inPlayerPosition)
{
    
    return 0.0f;
}
