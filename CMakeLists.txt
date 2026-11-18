cmake_minimum_required(VERSION 3.20)

project(raylib_template)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug) #如果使用CLion或Visual Studio，请注释掉这一行

include(FetchContent)
FetchContent_Declare(raylib GIT_REPOSITORY
        http://47.95.246.101:3000/xinyun/raylib6_2.git # 课程库镜像，下载速度更快
        GIT_TAG trimmed-6.2 # 使用raylib的版本
        )
FetchContent_MakeAvailable(raylib)

add_executable(game 
        main.cpp
        maze.h
        maze.cpp
        player.h
        player.cpp
        pathfind.h
        pathfind.cpp
)

target_link_libraries(game raylib)

