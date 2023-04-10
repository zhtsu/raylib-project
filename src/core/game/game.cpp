#include "game.hpp"
#include "systems/texture_system.hpp"

void Game::OnInitialized()
{
    ECS.RegisterSystem<TextureSystem>()->OnInitialized();
}

void Game::OnUpdate()
{
    if (ECS.GetSystemPtr<TextureSystem>())
    {
        ECS.GetSystemPtr<TextureSystem>()->OnUpdate();
    }
    
}

void Game::OnDestroy()
{
    if (ECS.GetSystemPtr<TextureSystem>())
    {
        ECS.GetSystemPtr<TextureSystem>()->OnDestroy();
    }
}

bool Game::IsEnd()
{
    return false;
}
