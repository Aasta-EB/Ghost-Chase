#include "Fog.h"

// Draw limited view function ___________________________________________________________________________________________________________________________________________________________________
void Fog::DrawFOV(Vector2d inPlayerPosition)
{
	// Draws all four rectangles in relation to the player position (or general input position)
	DrawRectangle(inPlayerPosition.x - (50 * 22 + 50 * 2.5), inPlayerPosition.y - (50 * 8 + 50 * 2.5), GetScreenWidth() * 2, 50 * 8, BLACK);
	DrawRectangle(inPlayerPosition.x - (50 * 22 + 50 * 2.5), inPlayerPosition.y + 50 * 2.5, GetScreenWidth() * 2, 50 * 9, BLACK);
	DrawRectangle(inPlayerPosition.x - (50 * 22 + 50 * 2.5), inPlayerPosition.y - 50 * 2.5, 50 * 22, 50 * 5, BLACK);
	DrawRectangle(inPlayerPosition.x + 50 * 2.5, inPlayerPosition.y - 50 * 2.5, 50 * 23, 50 * 5, BLACK);
}