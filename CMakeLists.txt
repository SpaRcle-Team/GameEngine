cmake_minimum_required(VERSION 3.16)
project(Game)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Framework/Helper)
add_executable(Game Run/src/main.cpp)

target_link_libraries(Game Helper)