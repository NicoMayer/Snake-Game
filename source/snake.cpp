#include "snake.hpp"


Snake::Snake(Snake::Direction dir, std::initializer_list<Point> body) 
    : body(body), direction(dir) {
    
}

bool Snake::is_on_pos(unsigned int x, unsigned int y) const {

    bool is_on_position = false;
   
    for(auto snake_cell : body) {
        if (snake_cell.x == x and snake_cell.y == y) {
            is_on_position = true;
        }
    } 
    return is_on_position;
}

Snake::Direction Snake::get_direction() const {
    return direction;
}


