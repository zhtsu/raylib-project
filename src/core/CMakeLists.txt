cmake_minimum_required(VERSION 3.16.0)

set(SRC_LIST
    ecs/ecs_mngr.cpp
)

add_library(core STATIC ${SRC_LIST})

target_link_libraries(core entt)

set_target_properties(core PROPERTIES OUTPUT_NAME "project-core")