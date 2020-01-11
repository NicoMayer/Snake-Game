project(Snake_Game_Run)

add_library(snake_game_lib STATIC 
            food.hpp 
            food.cpp
            snake.hpp
            snake.cpp)
 
target_include_directories(snake_game_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


#add_executable(Snake_Game main.cpp)
#target_link_libraries(Snake_Game snake_game_lib ${CURSES_LIBRARIES})

