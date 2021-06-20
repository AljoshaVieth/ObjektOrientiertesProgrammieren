cmake_minimum_required(VERSION 3.17)
project(OOP)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_executable(07 07/main.cpp 07/Vector3D.cpp 07/Vector3D.h 07/Friends.cpp 07/Friends.h 09/main.cpp)
add_executable(08 08/main.cpp 08/Date.cpp 08/Date.h 08/ArrayList.cpp 08/ArrayList.h)
add_executable(09 09/main.cpp)
add_executable(10 10/main.cpp 10/Person.cpp 10/Person.h 10/Guest.cpp 10/Guest.h 10/Employee.cpp 10/Employee.h 10/Worker.cpp 10/Worker.h 10/Seller.cpp 10/Seller.h)
