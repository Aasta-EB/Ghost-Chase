#pragma once
#include "Player.h"
class Fog
{
public: 

	Player player;

	RenderTexture2D fogOfWar;

	int mapTileSize = 10; // Tiles size 32x32 pixels
	int playerTileViasbility = 10;  // Player can see 2 tiles around its position

	unsigned int tilesX;            // Number of tiles in X axis
	unsigned int tilesY;            // Number of tiles in Y axis
	char* tileIds;         // Tile ids (tilesX*tilesY), defines type of tile to draw
	char* tileFog;         // Tile fog state (tilesX*tilesY), defines if a tile has fog or half-fog

	int playerTileX = 0;
	int playerTileY = 0;

	void InitFog();

	void ReadyFog();

	void DrawFog();
};

