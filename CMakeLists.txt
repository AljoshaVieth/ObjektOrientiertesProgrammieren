cmake_minimum_required(VERSION 3.17)
project(OOP)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_executable(06 06/main.cpp 06/Friends.cpp 06/Friends.h)
