#include "Grid.h"

void Grid::DrawRectangles(Vector2d inRectanglePosition)
{
	DrawRectangle(inRectanglePosition.x, inRectanglePosition.y, rectangleSize.x, rectangleSize.y, rectangleColor);
}
