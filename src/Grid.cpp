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
			if (map[i][j] == 1)
			{
				//std::cout << map[i][j];
				/*std::cout << "1, ";*/
				int positionY = i * 50;
				int positionX = j * 50;

				DrawRectangle(positionX, positionY, boxSize, boxSize, boxColor);

				// Not important as of now
				//boxCoordinates.push_back({saveBoxPosition});
				//boxPositionY.push_back(positionY);
				//Vector2d boxPosition = { positionX, positionY };
				//std::cout << boxPosition.x << " " << boxPosition.y << "\n";

			}
		}
	}
}
