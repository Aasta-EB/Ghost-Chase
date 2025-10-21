#include "Grid.h"

void Grid::DrawMap()
{

	for (int i = 0; i < 14; i++)
	{
		//std::cout << "\n";
		for (int j = 0; j < 28; j++)
		{
		/*	std::cout << map[i][j];*/
			if (map[i][j] == 0 )
			{
				//std::cout << map[i][j];
			/*	std::cout << "0, ";*/
			}
			if (map[i][j] == 1 )
			{
				//std::cout << map[i][j];
				/*std::cout << "1, ";*/
				int positionY = i * 50;
				int positionX = j * 50;

				DrawRectangle(positionX, positionY, boxWidth, boxHeight, boxColor);
				boxPositionX.push_back(positionX);
				boxPositionY.push_back(positionY);

			}
		}
	}
}
