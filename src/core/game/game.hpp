#pragma once

#include "ecs/ecs_mngr.hpp"

class Game
{
public:
    void OnInitialized();
    void OnUpdate();
    void OnDestroy();

    bool IsEnd();

    EcsMngr ECS;
};
