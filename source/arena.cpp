#include "arena.hpp"
#include "point.hpp"

Arena::Arena(const std::shared_ptr<Snake> &snake, size_t height, size_t width) 
    : height(height), width(width), snake(snake) {

}

bool Arena::move_snake(){

    if (snake == nullptr){
        return false;
    }

    if (snake->move() == false) {
        return false;
    }

    if (check_outside_snake() == true) {
        return false;
    }
    
    return true;
}

bool Arena::check_outside_snake() {
    
    if (snake == nullptr) {
        return false;
    }

    Point head_pos = snake->get_head_pos();

    if (head_pos.x < 0 or 
        head_pos.y < 0 or
        head_pos.y >= height or
        head_pos.x >= width) {
        
        return true;
    }
    return false;
}
