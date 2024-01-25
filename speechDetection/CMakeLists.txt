cmake_minimum_required(VERSION 3.26)
project(speechDetection)

set(CMAKE_CXX_STANDARD 17)

add_executable(speechDetection fileIOs_wordPairs_main.cpp
        fileIOs_wordPairs.h
        fileIOs_wordPairs.cpp
        tain.cpp)
