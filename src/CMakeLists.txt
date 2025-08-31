cmake_minimum_required(VERSION 4.1.0)
project(${PROJECT_NAME})

include (FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
    SOURCE_DIR ${PROJECT_INSTALL_VENDOR_DIR}/raylib)
FetchContent_MakeAvailable(raylib)

set(HEADER_FILES
    Block.h
    ColorHandler.h
    Defaults.h
    Grid.h
    Position.h
    TetrisGame.h)

set(SOURCE_FILES
    main.cpp
    Application.cpp
    Block.cpp
    Grid.cpp
    TetrisGame.cpp
    Window.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} raylib)