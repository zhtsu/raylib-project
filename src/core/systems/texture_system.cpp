#include "texture_system.hpp"
#include "ecs/components.hpp"
#include <raylib.h>

void TextureSystem::OnInitialized()
{
}

void TextureSystem::OnUpdate()
{
    for (Entity entity : GetEntityList<TextureComponent, TransformComponent>())
    {
        if (entity.HasComponent<TextureComponent>() && entity.GetComponent<TextureComponent>().texture)
        {
            Texture2D tex = *entity.GetComponent<TextureComponent>().texture;
            Transform trans = entity.GetComponent<TransformComponent>().transform;
            DrawTexture(tex, trans.translation.x, trans.translation.y, WHITE);
        }
    }
}

void TextureSystem::OnDestroy()
{
}
