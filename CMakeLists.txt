cmake_minimum_required(VERSION 3.16.0)

project(raylib-project CXX)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/bin)

include_directories(${PROJECT_SOURCE_DIR}/src/core)

# 3rdparty
add_subdirectory(${PROJECT_SOURCE_DIR}/3rdparty/raylib)
add_subdirectory(${PROJECT_SOURCE_DIR}/3rdparty/entt)
add_subdirectory(${PROJECT_SOURCE_DIR}/3rdparty/box2d)
# customized
add_subdirectory(${PROJECT_SOURCE_DIR}/src/core)

add_executable(
    raylib-project
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

target_link_libraries(
    raylib-project
    raylib
    entt
    box2d
    core
)
