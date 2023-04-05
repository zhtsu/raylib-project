#include <raylib.h>
#include "ecs/ecs_mngr.hpp"
#include "ecs/entity.hpp"
#include "ecs/components.hpp"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);


    int entity_count = 0;
    EcsMngr ecs_mngr;

    while (!WindowShouldClose())
    {
        Entity entity;

        if (IsKeyDown('C'))
        {
            entity = ecs_mngr.CreateEntiry();
            entity_count++;
            entity.AddComponent<NameComponent>(std::to_string(entity_count));
        }

        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            if (entity && entity.HasComponent<NameComponent>())
            {
                DrawText(entity.GetComponent<NameComponent>().name.c_str(), 190, 240, 20, LIGHTGRAY);
            }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

