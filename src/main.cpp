#include <raylib.h>
#include "ecs/ecs_mngr.hpp"
#include "ecs/entity.hpp"
#include "ecs/components.hpp"
#include "ecs/system.hpp"

#include <iostream>

class TestSystem : public System
{
public:
    void OnInitialized() override { }

    void OnUpdate() override
    {
        for (auto& entity : GetEntityList<NameComponent>())
        {
            std::cout << entity.GetComponent<NameComponent>().name << std::endl;
        }
    }

    void OnDestroy() override { }
};

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);


    int entity_count = 0;
    EcsMngr ecs_mngr;

    ecs_mngr.RegisterSystem<TestSystem>();

    while (!WindowShouldClose())
    {
        Entity entity;

        ecs_mngr.UpdateSystems();

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

