#include <raylib.h>
#include "ecs/ecs_mngr.hpp"
#include "ecs/entity.hpp"
#include "ecs/components.hpp"

#include <iostream>

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);


    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(RAYWHITE);
           
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

