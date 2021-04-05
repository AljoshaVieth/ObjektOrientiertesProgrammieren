cmake_minimum_required(VERSION 3.17)
project(OOP)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
add_executable(01 01/main.cpp)
add_executable(02 02/main.cpp)
add_executable(03 03/main.cpp 03/Date.cpp 03/Person.cpp)