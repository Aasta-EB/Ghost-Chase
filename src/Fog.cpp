#include "Fog.h"


void Fog::DrawFog(Vector2d inPlayerPosition)
{
	DrawRectangle(inPlayerPosition.x - (50 * 22 + 50 * 2.5), inPlayerPosition.y - (50 * 8 + 50 * 2.5), GetScreenWidth()*2, 50 * 8, BLACK);
	DrawRectangle(inPlayerPosition.x - (50 * 22 + 50 * 2.5), inPlayerPosition.y + 50 * 2.5, GetScreenWidth() * 2, 50 * 9, BLACK);
	DrawRectangle(inPlayerPosition.x - (50 * 22 + 50 * 2.5), inPlayerPosition.y - 50 * 2.5, 50 * 22, 50 * 5, BLACK); 
	DrawRectangle(inPlayerPosition.x + 50 * 2.5, inPlayerPosition.y - 50 * 2.5, 50 * 23, 50 * 5, BLACK); 
}