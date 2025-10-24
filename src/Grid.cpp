#include "Grid.h"

void Grid::DrawMap()
{
	// A for loop to find the boxes position
	for (int i = 0; i < 14; i++)
	{
		//std::cout << "\n";
		for (int j = 0; j < 28; j++)
		{
			//std::cout << map[i][j];
			if (map[i][j] == 0 )
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
				// ^ This calculation needs to be put into a math class

				// Draws the rectangle at the correct position
				DrawRectangle(positionX, positionY, boxSize, boxSize, boxColor);
			}
		}
	}
}
