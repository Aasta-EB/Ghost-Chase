#include <raylib.h>
#include <stdlib.h>                 // Required for: calloc(), free()

#include "Player.h"
#include "Grid.h"
#include "Enemy.h"
#include "Vector2d.h"
#include "Window.h"


// Acsessing classes _________________________________________________________________________________________________________________________________________________________
static Player player = { 0 };
Grid map;
Window window;
Fog fog;


int main()
{
	// Starting game window
	InitWindow(map.windowWidth, map.windowHeight, "Ghost-Chase");

	window.InitGame();
	fog.InitFog();

	SetTargetFPS(60);

	// Draws map
	map.DrawMap();

	// Game while loop
	while (!WindowShouldClose())
	{

		window.UpdateDrawFrame();
	}

	free(fog.tileIds);      // Free allocated map tile ids
	free(fog.tileFog);      // Free allocated map tile fog state

	UnloadRenderTexture(fog.fogOfWar);  // Unload render texture


	CloseWindow();

	return 0;
}