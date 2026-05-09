cmake_minimum_required(VERSION 3.31)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        student.cpp
        bank.cpp
        games.cpp
        utilities.cpp
        admin.cpp
        functions.h)
