project(snake_game_tests)

add_executable(snake_game_tests 
                food_test.cpp
                snake_test.cpp
                arena_test.cpp)

target_link_libraries(snake_game_tests PRIVATE snake_game_lib catch)

add_test(NAME Tests COMMAND snake_game_tests)
