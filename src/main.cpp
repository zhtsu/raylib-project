#include <raylib.h>

#include "game/game.hpp"

#include <iostream>

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    Ref<Game> game = CreateRef<Game>();

    game->OnInitialized();
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        game->OnUpdate();

        EndDrawing();
    }
    game->OnDestroy();

    CloseWindow();

    return 0;
}

