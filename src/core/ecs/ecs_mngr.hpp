#pragma once

#include <entt.hpp>
#include "entity.hpp"
#include "system.hpp"
#include "base_types.hpp"

static bool SystemPtrCmp(const Ref<System>& ptr1, const Ref<System>& ptr2)
{
    return ptr1->GetOrder() < ptr2->GetOrder();
}

class EcsMngr
{
public:
    Entity CreateEntiry(const String& tag = "Default");
    void DestroyEntity(Entity entity);

    template<typename T>
    Ref<System> RegisterSystem(int order = 0)
    {
        CheckSystemType<T>();

        Ref<System> system_instance = CreateRef<T>();
        system_instance->SetOrder(order);
        system_instance->SetRegistryPtr(&m_registry);

        m_system_map.emplace(typeid(T).name(), system_instance);
        m_system_set.insert(system_instance);

        return system_instance;
    }

    template<typename T>
    T* GetSystemPtr()
    {
        CheckSystemType<T>();

        if (m_system_map.find(typeid(T).name()) == m_system_map.end())
        {
            return nullptr;
        }
        return dynamic_cast<T*>(m_system_map.find(typeid(T).name())->second.get());
    }

    void InitSystems();
    void UpdateSystems();
    void DestorySystems();

private:
    template<typename T>
    void CheckSystemType()
    {
        static_assert(
            std::is_base_of<System, T>::value,
            "This class does not inherit from System!");
    }

private:
    entt::registry m_registry;
    Map<const char*, Ref<System>> m_system_map;
    Set<Ref<System>, decltype(SystemPtrCmp)*> m_system_set;
};
