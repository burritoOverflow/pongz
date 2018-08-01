
cmake_minimum_required (VERSION 2.6)
project(PONGZ)
add_executable(pongz main.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
target_link_libraries(pongz sfml-graphics sfml-window sfml-system)