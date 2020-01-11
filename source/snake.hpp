#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>
#include <initializer_list>

#include "point.hpp"


class Snake {
public:
    enum Direction {
        UP,
        DOWN,
        RIGHT,
        LEFT
    };

    Snake(Snake::Direction dir, std::initializer_list<Point> body);
     
    bool is_on_pos(Point pos) const;

    Snake::Direction get_direction() const;
    Point get_head_pos() const;
    
private:
    
    std::vector<Point> body;
    Snake::Direction direction; 
};

#endif //SNAKE_HPP
