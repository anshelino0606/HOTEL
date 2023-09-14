cmake_minimum_required(VERSION 3.26)
project(HOTEL)

set(CMAKE_CXX_STANDARD 17)

add_executable(HOTEL main.cpp
        Room.cpp
        Date.cpp)
