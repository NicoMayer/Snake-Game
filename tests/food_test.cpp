#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "food.hpp"

TEST_CASE("Create a new food", "[food]") {

    auto x = GENERATE(take(10, random(-10, 10)));
    auto y = GENERATE(take(10, random(-10, 10)));
    
    Food food(x, y);

    REQUIRE( x == food.X());
    REQUIRE( y == food.Y());

}
