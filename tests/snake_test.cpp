#include "catch.hpp"
#include "snake.hpp"

TEST_CASE("Create a new snake", "[snake]") {

    Snake(Snake::UP, {{0, 0}, {1, 0}, {2, 0}});

}
