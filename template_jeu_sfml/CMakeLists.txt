cmake_minimum_required(VERSION 3.16)

project(R5A12 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(SFML_DIR "/home/dragon-de-rage/SFML-3.1.0-linux-gcc-64-bit/SFML-3.1.0/lib/cmake/SFML/")
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

include_directories(".")

# Linux: install libsfml-dev package.
#list(APPEND CMAKE_MODULE_PATH "/home/dragon-de-rage/SFML-3.1.0-linux-gcc-64-bit/SFML-3.1.0/lib/cmake")
#find_package(SFML 3.1 REQUIRED COMPONENTS Graphics Window System)

add_executable(R5A12 main.cpp GameWindow.cpp GameWindow.h)
target_link_libraries(R5A12 sfml-graphics sfml-window sfml-system)


