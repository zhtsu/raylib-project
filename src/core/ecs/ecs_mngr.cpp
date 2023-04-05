#include "ecs_mngr.hpp"

Entity EcsMngr::CreateEntiry(const std::string& name)
{
    Entity entity(m_registry.create(), &m_registry);
    return entity;
}

void EcsMngr::DestroyEntity(Entity entity)
{
    m_registry.destroy(entity);
}
