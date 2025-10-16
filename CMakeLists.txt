cmake_minimum_required(VERSION 4.0)
project(Engin)

set(CMAKE_CXX_STANDARD 20)

add_executable(Engin main.cpp
        src/Engine.cpp
        include/Engine.h
        src/Renderer.cpp
        include/Renderer.h
        include/utils/Vector2.h)

# include sdl2 headers and link libraries
include_directories(/usr/include/SDL2)
target_link_libraries(Engin SDL2 SDL2main SDL2_image SDL2_ttf SDL2_mixer)
