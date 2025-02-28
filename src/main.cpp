#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

#include "Game/Game.hpp"
#include "Player/Player.hpp"

Game game;

void UpdateDrawFrame();

int main(void)
{
	InitWindow(game.WIDTH, game.HEIGHT, "raylib [core] example - basic window");
	game.Init();

	Player plr;
	plr.position = Vector2 { (float)game.WIDTH / 2, (float)game.HEIGHT / 2 };
	plr.Init();

	for (int i = 0; i < 25; i++)
	{
		game.obstacles.push_back({
			(float)GetRandomValue(0, 800), (float)GetRandomValue(0, 800),
			(float)GetRandomValue(30, 100), (float)GetRandomValue(30, 100)
		});
	}

	#if defined(PLATFORM_WEB)
    	emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
	#else
		SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
		//--------------------------------------------------------------------------------------

		// Main game loop
		while (!WindowShouldClose())    // Detect window close button or ESC key
		{
			UpdateDrawFrame();
		}
	#endif

	CloseWindow();

	return 0;
}

void UpdateDrawFrame()
{
	game.Update();
	BeginDrawing();
	
	ClearBackground(RAYWHITE);

	game.Draw();

	EndDrawing();
}