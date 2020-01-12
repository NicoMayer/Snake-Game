#ifndef ARENA_HPP
#define ARENA_HPP

#include <memory>
#include "snake.hpp"

class Arena {
public:
    
    Arena(const std::shared_ptr<Snake> &snake, size_t height, size_t width);

    bool move_snake();
    
private:

    std::shared_ptr<Snake> snake;

    const size_t height;
    const size_t width;
}; 

#endif //ARENA_HPP
