cmake_minimum_required(VERSION 3.16.0)

project(ray-lib)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/bin)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_subdirectory(${PROJECT_SOURCE_DIR}/3rdparty/raylib)

add_executable(
    raylib-project
    ${PROJECT_SOURCE_DIR}/src/main.c
)

target_link_libraries(
    raylib-project
    raylib
)
