cmake_minimum_required(VERSION 3.22)
project(SkyGameWork)

set(CMAKE_CXX_STANDARD 20)

#add_subdirectory(
#        "W://code/lib/raylib-master/raylib-master"
#        "${CMAKE_BINARY_DIR}/raylib"
#)


include(FetchContent)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.5
)

FetchContent_MakeAvailable(raylib)

add_executable(SkyGameWork
        src/main.cpp
)

target_link_libraries(SkyGameWork PRIVATE raylib)