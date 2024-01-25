cmake_minimum_required(VERSION 3.26)
project(Graph)

set(CMAKE_CXX_STANDARD 17)

add_executable(Graph main.cpp
        graph.h
        graph.cpp)
