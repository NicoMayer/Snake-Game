#include "arena.hpp"

Arena::Arena(const std::shared_ptr<Snake> &snake, size_t height, size_t width) 
    : height(height), width(width), snake(snake) {

}


bool Arena::move_snake(){

    if (snake != nullptr) {
    
        return snake->move();
    }
}
