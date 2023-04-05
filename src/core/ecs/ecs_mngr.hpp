#pragma once

#include <entt.hpp>
#include "entity.hpp"

class EcsMngr
{
public:
    Entity CreateEntiry(const std::string& name = std::string());
    void DestroyEntity(Entity entity);

private:
    entt::registry m_registry;
};
