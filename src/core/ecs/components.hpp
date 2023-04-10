#pragma once

#include <raylib.h>
#include "base_types.hpp"

struct TagComponent
{
    String tag;
};

struct TransformComponent
{
    Transform transform;
};

struct TextureComponent
{
    Ref<Texture2D> texture;
};
