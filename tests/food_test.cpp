#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "food.hpp"

TEST_CASE("Create a new food", "[food]") {

    auto x = GENERATE(take(10, random(0u, 1000u)));
    auto y = GENERATE(take(10, random(0u, 1000u)));
    
    Food food({x, y});

    REQUIRE(food.get_pos() == Point{x, y}); 
}
