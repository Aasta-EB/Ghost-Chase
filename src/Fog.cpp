#include "Fog.h"

void Fog::InitFog()
{
	int playerPositionX = player.position.x;
	int playerPositionY = player.position.y;

	fog[playerPositionY][playerPositionX] = 1; 
	for (int i = 1; i < playerVision; i++)
	{
		fog[playerPositionY+i][playerPositionX] = 1;
		fog[playerPositionY-i][playerPositionX] = 1;
		fog[playerPositionY][playerPositionX+i] = 1;
		fog[playerPositionY][playerPositionX-i] = 1;

		fog[playerPositionY + i][playerPositionX + i] = 1;
		fog[playerPositionY - i][playerPositionX - i] = 1;
		fog[playerPositionY + i][playerPositionX + i] = 1;
		fog[playerPositionY - i][playerPositionX - i] = 1;
	}
	
}

void Fog::ReadyFog()
{
	
}

void Fog::DrawFog()
{
	
}
