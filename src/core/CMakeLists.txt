cmake_minimum_required(VERSION 3.16.0)

set(SRC_LIST
    ecs/ecs_mngr.cpp
    game/game.cpp
    systems/texture_system.cpp
)

add_library(core STATIC ${SRC_LIST})

target_link_libraries(core entt raylib)

set_target_properties(core PROPERTIES OUTPUT_NAME "project-core")