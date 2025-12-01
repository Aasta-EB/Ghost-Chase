#include <raylib.h>

#include "Grid.h"
#include "Window.h"

// Acsessing classes _________________________________________________________________________________________________________________________________________________________
Grid map;
Window window;

// Main game function ________________________________________________________________________________________________________________________________________________________
int main()
{
	// Starting game window
	InitWindow(map.windowWidth, map.windowHeight, "Ghost-Chase");

	// Sets the target FPS
	SetTargetFPS(60);

	// Game while loop
	while (!WindowShouldClose())
	{
		// Draws each frame
		window.UpdateDrawFrame();
	}

	CloseWindow();

	return 0;
}