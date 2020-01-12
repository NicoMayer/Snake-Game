#include <memory>
#include "catch.hpp"
#include "arena.hpp"
#include "snake.hpp"

TEST_CASE( "arena can move the snake", "[arena]"){

   
    SECTION( "move_snake without a snake return false" ) {
        Arena arena(nullptr, 16, 16);
        REQUIRE( arena.move_snake() == false);
    }

    SECTION( "move_snake returns false if the head leaves the arena" ) {
        
        auto snake = std::shared_ptr<Snake>(new Snake(Snake::UP, {{10, 1}, {10, 2}, {10, 3}}));
        
        Arena arena(snake, 16, 16);

        REQUIRE( arena.move_snake() == false);

    }

    SECTION( "move_snake returns false if the head leaves not the arena" ) {

        auto snake = std::shared_ptr<Snake>(new Snake(Snake::RIGHT, {{10, 10}, {11,10}}));

        Arena arena(snake, 16, 16);

        REQUIRE( arena.move_snake() == true);

    }

    SECTION( "move_snake returns false if snake collides with itself" ) {

        auto snake = std::shared_ptr<Snake>
                        (new Snake(Snake::DOWN, {{10, 5}, {9, 5}, {9, 6}, {10, 6}, {11, 6}})); 

        Arena arena(snake, 16, 16);

        REQUIRE( arena.move_snake() == false);
    }
}
