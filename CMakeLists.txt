cmake_minimum_required(VERSION 3.31)
project(hello)

set(CMAKE_CXX_STANDARD 20)

add_executable(hello main.cpp
        game.cpp
        game.h)
