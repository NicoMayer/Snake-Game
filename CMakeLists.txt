cmake_minimum_required(VERSION 3.10)
project(Snake_Game)

set(CMAKE_CXX_STANDARD 14)

enable_testing()
include_directories(include)

add_subdirectory(source)
add_subdirectory(tests)

