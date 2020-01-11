#include "catch.hpp"
#include "snake.hpp"

TEST_CASE("Create a new snake", "[snake]") {

    Snake snake(Snake::UP, {{0, 0}, {1, 0}, {2, 0}});

    REQUIRE(snake.is_on_pos(0,0));
    REQUIRE(snake.is_on_pos(1,0));
    REQUIRE(snake.is_on_pos(2,0));
    REQUIRE(snake.get_head_pos() == {0, 0});
    
    REQUIRE(snake.get_direction() == Snake::UP);
}
