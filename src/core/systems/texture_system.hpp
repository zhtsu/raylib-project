#pragma once

#include "ecs/system.hpp"

class TextureSystem : public System
{
public:
    void OnInitialized() override;
    void OnUpdate() override;
    void OnDestroy() override;
};
