#pragma once

#include <entt.hpp>
#include "entity.hpp"
#include "system.hpp"

class EcsMngr
{
public:
    Entity CreateEntiry(const std::string& name = std::string());
    void DestroyEntity(Entity entity);

    template<typename T>
    void RegisterSystem()
    {
        static_assert(
            std::is_base_of<System, T>::value,
            "This class does not inherit from System!");
        m_system_map.insert(typeid(T).name(), std::make_shared<T>());
    }

    template<typename T>
    void DisableSystem()
    {
        if (m_system_map.find(typeid(T).name()) == m_system_map.end())
        {
            return;
        }
        m_system_map[typeid(T).name()]->Disable();
    }

    template<typename T>
    void EnableSystem()
    {
        if (m_system_map.find(typeid(T).name()) == m_system_map.end())
        {
            return;
        }
        m_system_map[typeid(T).name()]->Enable();
    }

    template<typename T>
    void SetSystemOrder()
    {
        // TODO
    }

    void UpdateSystems();

private:
    entt::registry m_registry;
    std::map<const char*, std::shared_ptr<System>> m_system_map;
};
