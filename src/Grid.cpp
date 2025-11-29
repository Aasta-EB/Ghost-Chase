#include "Grid.h"

// Draw map (grid/the labyrinth) function
void Grid::DrawMap()
{
	// Loop to find the boxes position
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 28; j++)
		{
			if (map[i][j] == 0)
			{
				//std::cout << map[i][j];
				//std::cout << "0, ";
			}
			if (map[i][j] == 1)
			{
				//std::cout << map[i][j];
				//std::cout << "1, ";
				int positionY = i * 50;
				int positionX = j * 50;

				// Draws the rectangle at the correct position
				DrawRectangle(positionX, positionY, boxSize, boxSize, boxColor);
			}
		}
	}
};