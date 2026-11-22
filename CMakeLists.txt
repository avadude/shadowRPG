cmake_minimum_required(VERSION 3.22)
project(shadowRPG C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Download Raylib at one fixed version, same for everyone
include(FetchContent)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_Declare(raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(raylib)

# Pick up every .c file in src/ automatically (nobody edits this file to add code)
file(GLOB_RECURSE GAME_SRC CONFIGURE_DEPENDS src/*.c)
add_executable(game ${GAME_SRC})
target_include_directories(game PRIVATE include)
target_link_libraries(game PRIVATE raylib)
if(UNIX)
    target_link_libraries(game PRIVATE m)
endif()

# Strict rules apply to OUR code only, not to Raylib
target_compile_options(game PRIVATE -Wall -Wextra -Werror)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(game PRIVATE -g -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(game PRIVATE -fsanitize=address,undefined)
endif()