cmake_minimum_required(VERSION 4.1.0)
project(${PROJECT_NAME})

include (FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5)
FetchContent_MakeAvailable(raylib)

set(SOURCE_FILES
    main.cpp
    Block.h
    Block.cpp
    Constants.h
    Grid.h
    Grid.cpp
    TetrisGame.h
    TetrisGame.cpp
    ColorHandler.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} raylib)

install(TARGETS ${PROJECT_NAME} 
        DESTINATION ${PROJECT_INSTALL_BIN_DIR})