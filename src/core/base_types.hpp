#pragma once

#include <memory>
#include <map>
#include <set>
#include <array>
#include <string>

using int32 = int32_t;
using uint32 = uint32_t;
using String = std::string;

template<typename T>
using Ref = std::shared_ptr<T>;

template<typename T>
using List = std::list<T>;

template<typename KeyType, typename ValType>
using Map = std::map<KeyType, ValType>;

template<typename T, typename... Args>
using Set = std::set<T, Args...>;

template<typename T, typename... Args>
constexpr Ref<T> CreateRef(Args&&... args)
{
    return std::make_shared<T>(std::forward<Args>(args)...);
}
