#include <memory>
#include "catch.hpp"
#include "arena.hpp"
#include "snake.hpp"
#include "point.hpp"

TEST_CASE( "arena can move the snake", "[arena]"){

   
    SECTION( "move_snake without a snake return false" ) {
        Arena arena(nullptr, 16, 16);
        REQUIRE( arena.move_snake() == false);
    }

    SECTION( "move_snake returns false if the head leaves the arena" ) {
        
        auto snake = std::shared_ptr<Snake>(new Snake(Snake::UP, {{10, 0}, {10, 1}, {10, 2}}));
        
        Arena arena(snake, 16, 16);

        REQUIRE( arena.move_snake() == false);

    }

    SECTION( "move_snake returns true if the head leaves not the arena" ) {

        auto snake = std::shared_ptr<Snake>(new Snake(Snake::RIGHT, {{12, 10}, {11,10}}));

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

TEST_CASE( "arena can produce food and check the position of the food", "[arena]" ) {

    Arena arena(nullptr, 16, 16);
    
    Point food_cell_pos = arena.get_food_pos();
    REQUIRE( arena.is_food_cell(food_cell_pos) == true );

    food_cell_pos.add(-1,1);
    REQUIRE( arena.is_food_cell(food_cell_pos) == false );

} 

TEST_CASE( "arena can increase the length of snake", "[arena]" ) {
    
    auto snake = std::shared_ptr<Snake>(new Snake(Snake::RIGHT, {{10,10}}));
    
    Arena arena(snake, 16, 16);

    arena.set_food_pos(Point{11, 10});
    
    REQUIRE( arena.move_snake() == true );
    REQUIRE( snake->get_length() == 2 );
    
}    
    
    
    
