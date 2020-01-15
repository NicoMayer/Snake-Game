#include "catch.hpp"
#include "snake.hpp"
#include "point.hpp"

TEST_CASE( "snake can be created", "[snake]" ) {

    Snake snake(Snake::UP, {{x:0, y:0}, {x:1, y:0}, {x:2, y:0}});

    REQUIRE( snake.is_on_pos(Point{x:0, y:0}) );
    REQUIRE( snake.is_on_pos(Point{x:1, y:0}) );
    REQUIRE( snake.is_on_pos(Point{x:2, y:0}) );

    REQUIRE( snake.get_head_pos().equal(Point{x:0, y:0}) );

    
    REQUIRE( snake.get_direction() == Snake::UP );
}

TEST_CASE( "snake can be move", "[snake]" ) {

    Snake snake(Snake::UP, {{x:10, y:10}});

    REQUIRE( snake.is_on_pos(Point{x:10, y:10}) );

    SECTION( "snake can be move up") {

        snake.change_direction(Snake::UP);
        REQUIRE( snake.move() == true );            
        REQUIRE( snake.is_on_pos(Point{x:10, y:9}) );

    }

    SECTION( "snake can be move down" ) {

        snake.change_direction(Snake::DOWN);
        REQUIRE( snake.move() == true );
        REQUIRE( snake.is_on_pos(Point{x:10, y:11}) );

    }

    SECTION( "snake can be move right" ) {

        snake.change_direction(Snake::RIGHT);
        REQUIRE( snake.move() == true );
        REQUIRE( snake.is_on_pos(Point{x:11, y:10}) );

    }

    SECTION( "snake can be move left" ) {
        
        snake.change_direction(Snake::LEFT);
        REQUIRE( snake.move() == true );
        REQUIRE( snake.is_on_pos(Point{x:9, y:10}) );
    }

}

TEST_CASE( "snake can be handle a invalid direction", "[snake]") {
    
    Snake snake(-1, {{x:0, y:0}});

    REQUIRE( snake.move() == false );
    REQUIRE( snake.is_on_pos(Point{x:0, y:0}) );
}
