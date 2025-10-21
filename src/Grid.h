#pragma once
#include "raylib.h"
#include "Vector2d.h"
#include <iostream>
#include <vector>

class Grid
{
public:

	float boxWidth = 50;
	float boxHeight = 50;

	int gridRows = 14;
	int gridColumns = 28;
	Vector2d rectangleSize = { 50, 50 };
	Color boxColor = ORANGE;

	std::vector<int> boxPositionX;
	std::vector<int> boxPositionY;

	void DrawMap();
};
