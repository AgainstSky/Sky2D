cmake_minimum_required(VERSION 3.22)
project(Sky2D
        VERSION 0.1.0
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# 默认构建类型
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()


include(FetchContent)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.5
)

FetchContent_MakeAvailable(raylib)



# 引擎
add_subdirectory(engine)

# 游戏
add_subdirectory(game)



#
#include(FetchContent)
#
#FetchContent_Declare(
#        raylib
#        GIT_REPOSITORY https://github.com/raysan5/raylib.git
#        GIT_TAG 5.5
#)
#
#FetchContent_MakeAvailable(raylib)
#
#add_executable(Sky2D
#        src/main.cpp
#)
#
#target_link_libraries(Sky2D PRIVATE raylib)