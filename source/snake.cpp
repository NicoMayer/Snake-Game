#include "snake.hpp"


Snake::Snake(Direction dir, std::initializer_list<Point> body) 
    : body(body), direction(dir) {
    
}

bool Snake::is_on_pos(Point pos) const {

    bool is_on_position = false;
   
    for(auto snake_cell_pos : body) {
        if (snake_cell_pos.equal(pos)) {
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
        return body.front();
    }
    else {
        return Point{0,0};
    }
}

void Snake::change_direction(Direction dir) {

    direction = dir;
}

bool Snake::move() {

    Point new_snake_head = body.front();

    switch(direction) {
        case Snake::UP:
            new_snake_head.add(0, -1);
            break;
        case Snake::DOWN:
            new_snake_head.add(0, 1);
            break;
        case Snake::LEFT:
            new_snake_head.add(-1, 0);
            break;
        case Snake::RIGHT:
            new_snake_head.add(1, 0);
            break;
    }

    if (!is_on_pos(new_snake_head)) {
        body.pop_back();
        body.push_front(new_snake_head);
        return true;
    }
    else {
        return false;
    }
}
         
    
