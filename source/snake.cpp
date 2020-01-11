#include "snake.hpp"


Snake::Snake(Snake::Direction dir, std::initializer_list<Point> body) 
    : body(body), direction(dir) {
    
}

bool Snake::is_on_pos(Point pos) const {

    bool is_on_position = false;
   
    for(auto snake_cell : body) {
        if (pos == snake_cell) {
            is_on_position = true;
        }
    } 
    return is_on_position;
}

Snake::Direction Snake::get_direction() const {
    return direction;
}

Point Snake::get_head_pos() const {
    if (body.size() > 0) {
        return body[0];
    }
    else {
        return Point{0,0};
    }
}
