cmake_minimum_required (VERSION 3.25)
project(basic_pong)

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS HEADERS src/*.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(basic_pong ${SOURCES} ${HEADERS})

target_link_libraries(basic_pong sfml-graphics sfml-window sfml-system)
target_compile_definitions(basic_pong PRIVATE WINDOW_WIDTH=1920 WINDOW_HEIGHT=1080 WINDOW_TITLE="Basic Pong")