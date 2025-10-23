#pragma once
#include <math.h>

class Vector2d
{
public: 
	// Vector class variables
	float x;
	float y; 

	// Calculates lenght of vector (magnitude)
	float CalculateLenghtOfVector();

	float CalculatePlayerPosition(Vector2d inPlayerPosition);



};

