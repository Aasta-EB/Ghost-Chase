#include <raylib.h>

#include "Player.h"
#include "Grid.h"
#include "Enemy.h"
#include "Vector2d.h"

// Acsessing classes _________________________________________________________________________________________________________________________________________________________
static Player player = { 0 };
Grid map;

// Updates each frame ________________________________________________________________________________________________________________________________________________________
void UpdateDrawFrame()
{
	player.UpdateGame();
	player.DrawGame();
}

int main()
{
	// Starting game window
	InitWindow(map.windowWidth, map.windowHeight, "Ghost-Chase");

	player.InitGame();

	SetTargetFPS(60);

	// Draws map
	map.DrawMap();

	// Game while loop
	while (!WindowShouldClose())
	{
		UpdateDrawFrame();
	}
	CloseWindow();

	return 0;
}