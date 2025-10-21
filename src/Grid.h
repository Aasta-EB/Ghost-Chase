#pragma once
#include "raylib.h"
#include "Vector2d.h"

class Grid
{
public: 

	Vector2d rectangleSize = { 100, 100 };
	Color rectangleColor = ORANGE;

	void DrawRectangles(Vector2d inRectanglePosition);
};

