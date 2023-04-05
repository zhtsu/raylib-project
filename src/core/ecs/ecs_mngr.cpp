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

void EcsMngr::InitSystems()
{
    for (auto system : m_system_set)
    {
        system->OnInitialized();
    }
}

void EcsMngr::UpdateSystems()
{
    for (auto system : m_system_set)
    {
        system->OnUpdate();
    }
}

void EcsMngr::DestorySystems()
{
    for (auto system : m_system_set)
    {
        system->OnDestroy();
    }
}
