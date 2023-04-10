#pragma once

#include <entt.hpp>
#include "entity.hpp"
#include "base_types.hpp"

class System
{
public:
    virtual void OnInitialized() = 0;
    virtual void OnUpdate() = 0;
    virtual void OnDestroy() = 0;

    inline void SetRegistryPtr(entt::registry* register_ptr) { m_registry_ptr = register_ptr; }
    // Set the larger order to get system sooner executed
    inline void SetOrder(int order) { m_order = order; }
    inline int GetOrder() { return 0; }

    template<typename... Types>
    List<Entity>& GetEntityList()
    {
        if (!m_registry_ptr)
        {
            return m_entity_list;
        }

        m_entity_list.clear();

        auto&& view = m_registry_ptr->view<Types...>();
        for (const auto& entity : view)
        {
            m_entity_list.push_back(Entity(entity, m_registry_ptr));
        }

        return m_entity_list;
    }

private:
    entt::registry* m_registry_ptr = nullptr;
    List<Entity> m_entity_list;
    int m_order = 0;
};
