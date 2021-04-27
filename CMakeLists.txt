cmake_minimum_required(VERSION 3.17)
project(OOP)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_executable(05 05/main.cpp 05/Friends.cpp 05/Date.cpp 05/Person.cpp 05/Friends.h 05/Person.h 05/Date.h)