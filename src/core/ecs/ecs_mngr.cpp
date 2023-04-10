#include "ecs_mngr.hpp"
#include "components.hpp"

Entity EcsMngr::CreateEntiry(const String& tag)
{
    Entity entity(m_registry.create(), &m_registry);
    entity.AddComponent<TagComponent>(tag);
    entity.AddComponent<Transform>();
    
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
