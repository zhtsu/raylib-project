#pragma once

#include <entt.hpp>
#include "base_types.hpp"

class Entity
{
public:
    Entity() = default;
    Entity(entt::entity handle, entt::registry* registry_ptr)
        : m_handle(handle), m_registry_ptr(registry_ptr) {}

    template<typename T>
    bool HasComponent()
    {
        return m_registry_ptr->all_of<T>(m_handle);
    }

    template<typename T>
    T& GetComponent()
    {
        return m_registry_ptr->get<T>(m_handle);
    }

    template<typename T, typename... Args>
    T& AddComponent(Args&&... args)
    {
        if (HasComponent<T>())
        {
            return GetComponent<T>();
        }
        T& component = m_registry_ptr->emplace<T>(m_handle, std::forward<Args>(args)...);
        return component;
    }

    template<typename T, typename... Args>
    T& AddOrReplaceComponent(Args&&... args)
    {
        T& component = m_registry_ptr->emplace_or_replace<T>(m_handle, std::forward<Args>(args)...);
        return component;
    }

    template<typename T>
    void RemoveComponent()
    {
        if (!HasComponent<T>())
        {
            return;
        }
        m_registry_ptr->remove<T>(m_handle);
    }

    bool operator==(const Entity& other) const
    {
        return m_handle == other.m_handle && m_registry_ptr == other.m_registry_ptr;
    }

    bool operator!=(const Entity& other) const
    {
        return !(*this == other);
    }

    operator bool() const { return m_handle != entt::null; }
    operator uint32() const { return (uint32)m_handle; }
    operator entt::entity() const { return m_handle; } 

private:
    entt::entity m_handle = entt::null;
    entt::registry* m_registry_ptr = nullptr;
};
