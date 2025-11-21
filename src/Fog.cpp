#include "Fog.h"

void Fog::InitFog()
{
	//  -------------------------------------------------
	tilesX = 140;
	tilesY = 70;

	// NOTE: We can have up to 256 values for tile ids and for tile fog state,
	// probably we don't need that many values for fog state, it can be optimized
	// to use only 2 bits per fog state (reducing size by 4) but logic will be a bit more complex
	tileIds = (char*)calloc(tilesX * tilesY, sizeof(char));
	tileFog = (char*)calloc(tilesX * tilesY, sizeof(char));

	// Player position on the screen (pixel coordinates, not tile coordinates
	playerTileX = 0;
	playerTileY = 0;

	// Render texture to render fog of war
	// NOTE: To get an automatic smooth-fog effect we use a render texture to render fog
	// at a smaller size (one pixel per tile) and scale it on drawing with bilinear filtering
	RenderTexture2D fogOfWar = LoadRenderTexture(tilesX, tilesY);
	SetTextureFilter(fogOfWar.texture, TEXTURE_FILTER_BILINEAR);
}

void Fog::ReadyFog()
{
	// Previous visited tiles are set to partial fog
	for (unsigned int i = 0; i < tilesX * tilesY; i++) if (tileFog[i] == 1) tileFog[i] = 0;

	// Get current tile position from player pixel position
	playerTileX = (int)((player.position.x + mapTileSize / 2) / mapTileSize);
	playerTileY = (int)((player.position.y + mapTileSize / 2) / mapTileSize);

	// Check visibility and update fog
	// NOTE: We check tilemap limits to avoid processing tiles out-of-array-bounds (it could crash program)
	for (int y = (playerTileY - playerTileViasbility); y < (playerTileY + playerTileViasbility); y++)
		for (int x = (playerTileX - playerTileViasbility); x < (playerTileX + playerTileViasbility); x++)
			if ((x >= 0) && (x < (int)tilesX) && (y >= 0) && (y < (int)tilesY)) tileFog[y * tilesX + x] = 1;

	// Draw
	// Draw fog of war to a small render texture for automatic smoothing on scaling
	BeginTextureMode(fogOfWar);
	ClearBackground(BLANK);
	for (unsigned int y = 0; y < tilesY; y++)
		for (unsigned int x = 0; x < tilesX; x++)
			if (tileFog[y * tilesX + x] == 0) DrawRectangle(x, y, 1, 1, BLACK);
	EndTextureMode();
}

void Fog::DrawFog()
{
	// Draw fog of war (scaled to full map, bilinear filtering)
	DrawTexturePro(fogOfWar.texture, Rectangle{ 0, 0, (float)fogOfWar.texture.width, (float)-fogOfWar.texture.height },
		Rectangle{
		0, 0, (float)tilesX * mapTileSize, (float)tilesY * mapTileSize
		},
		Vector2{
		0, 0
		}, 0.0f, WHITE);
}
