cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
project(Snake_Game)

enable_testing()
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_subdirectory(externals/catch2)
add_subdirectory(source)
add_subdirectory(tests)
