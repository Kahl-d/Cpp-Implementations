cmake_minimum_required(VERSION 3.26)
project(Zy_books_speech_Code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Zy_books_speech_Code
        designDoc.h
        fileIOs_wordPairs.cpp
        fileIOs_wordPairs.h
        fileIOs_wordPairs_main.cpp)
