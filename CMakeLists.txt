cmake_minimum_required(VERSION 4.1.0)
project(Tetris-Project)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(PROJECT_INSTALL_VENDOR_DIR ${CMAKE_INSTALL_PREFIX}/vendor)

include_directories(${PROJECT_INSTALL_VENDOR_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src)

add_subdirectory(src)