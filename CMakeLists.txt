cmake_minimum_required(VERSION 3.17)
project(OOP)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_executable(08 08/main.cpp 08/Date.cpp 08/Date.h 08/ArrayList.cpp 08/ArrayList.h)
