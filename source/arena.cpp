#include "arena.hpp"
#include "point.hpp"

Arena::Arena(const std::shared_ptr<Snake> &snake, size_t height, size_t width) 
    : height(height), width(width), snake(snake) {

}


bool Arena::move_snake(){

    bool is_ok = true;

    if (snake == nullptr) {
        return false; 
    }
    
    is_ok = snake->move();
    is_ok = is_ok and not check_outside_snake();
    
    return is_ok;
}

bool Arena::check_outside_snake() {
    
    Point head_pos = snake->get_head_pos();

    if (head_pos.x < 0 or 
        head_pos.y < 0 or
        head_pos.y >= height or
        head_pos.x >= width) {
        
        return true;
    }
    return false;
}
