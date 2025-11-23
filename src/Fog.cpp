#include "Fog.h"


void Fog::ReadyFog(Vector2d inPlayerPosition)
{
//	int playerPositionX = inPlayerPosition.x;
//	int playerPositionY = inPlayerPosition.y;
// 
//
//	std::cout << inPlayerPosition.x << " , " << inPlayerPosition.y << "\n";
//
//	for (int i = 0; i < 14; i++)
//	{
//		for (int j = 0; j < 28; j++)
//		{
//			//std::cout << fog[i][j];
//			if (fog[i][j] == 1)
//			{
//				//std::cout << "1, ";
//				fog[i][j] = 0;
//			}
//		}
//	}
//  playerVision = 2; 
//	fog[playerPositionY][playerPositionX] = 1;
	//std::cout << fog[playerPositionY][playerPositionX] << "\n";
	/*for (int i = 1; i <= playerVision; i++)
	{
		fog[playerPositionY + i][playerPositionX] = 1;
		fog[playerPositionY - i][playerPositionX] = 1;
		fog[playerPositionY][playerPositionX + i] = 1;
		fog[playerPositionY][playerPositionX - i] = 1;

		fog[playerPositionY + i][playerPositionX + i] = 1;
		fog[playerPositionY - i][playerPositionX - i] = 1;
		fog[playerPositionY + i][playerPositionX - i] = 1;
		fog[playerPositionY - i][playerPositionX + i] = 1;
	}*/
}

void Fog::DrawFog(Vector2d inPlayerPosition)
{
	//ReadyFog(inPlayerPosition);

	//for (int i = 0; i < 14; i++)
	//{
	//	for (int j = 0; j < 28; j++)
	//	{
	//		if (fog[i][j] == 1)
	//		{
	//			std::cout << i << " , " << j << "\n";
	//			//std::cout << fog[i][j] << "\n";
	//		}
	//		if (fog[i][j] == 0)
	//		{
	//			int positionY = i * 50;
	//			int positionX = j * 50;
	//			DrawRectangle(positionX, positionY, 50, 50, BLACK);
	//		}
	//	}
	//}
}
