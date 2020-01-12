#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <deque>
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

    void change_direction(Snake::Direction dir);

    bool move();

    Snake::Direction get_direction() const;
    Point get_head_pos() const;
    
private:
    
    std::deque<Point> body;
    Snake::Direction direction; 
};

#endif //SNAKE_HPP
