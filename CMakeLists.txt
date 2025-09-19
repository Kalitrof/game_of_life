cmake_minimum_required(VERSION 3.10)
project(game_of_life VERSION 0.1.0 LANGUAGES CXX)

# C++17 required
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# OpenMP (optional, if available)
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    message(STATUS "OpenMP found, enabling parallelism")
endif()

add_executable(game_of_life
    main.cpp
    Display.cpp
    Game.cpp
)

# Links
target_link_libraries(game_of_life PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
)

if(OpenMP_CXX_FOUND)
    target_link_libraries(game_of_life PRIVATE OpenMP::OpenMP_CXX)
endif()

# Default Release Optimization
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()
