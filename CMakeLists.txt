
cmake_minimum_required (VERSION 2.6)
project(PONGZ)
set(SOURCE src/main.cpp src/Game.cpp src/Ball.cpp src/Player.cpp)
set(HEADERS src/Tickable.h src/Game.h src/Ball.h src/Player.h)
add_executable(pongz ${SOURCE} ${HEADERS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
target_link_libraries(pongz sfml-graphics sfml-window sfml-system)
target_compile_definitions(pongz PRIVATE WINDOW_WIDTH=800 WINDOW_HEIGHT=600 WINDOW_TITLE="pongz")