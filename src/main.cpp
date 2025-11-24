#include <raylib.h>
#include <stdlib.h>                 // Required for: calloc(), free()

#include "Grid.h"
#include "Window.h"

// Acsessing classes _________________________________________________________________________________________________________________________________________________________
Grid map;
Window window;

int main()
{
	// Starting game window
	InitWindow(map.windowWidth, map.windowHeight, "Ghost-Chase");

	// Initiates the game the first time
	window.InitGame();

	// Sets the target FPS
	SetTargetFPS(60);

	// Draws map
	map.DrawMap();

	// Game while loop
	while (!WindowShouldClose())
	{
		// Draws each frame
		window.UpdateDrawFrame();
	}

	CloseWindow();

	return 0;
}