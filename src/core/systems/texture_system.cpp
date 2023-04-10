#include "texture_system.hpp"
#include "ecs/components.hpp"

//////////////////////// Test
#include <iostream>

void TextureSystem::OnInitialized()
{
}

void TextureSystem::OnUpdate()
{
    for (Entity entity : GetEntityList<Texture2D>())
    {
        Texture2D tex = entity.GetComponent<Texture2D>();
        Transform trans = entity.GetComponent<Transform>();
        DrawTexture(tex, trans.translation.x, trans.translation.y, WHITE);

        /////////////////////////// Test
        std::cout << entity.GetComponent<TagComponent>().tag << std::endl;
    }
}

void TextureSystem::OnDestroy()
{
}
