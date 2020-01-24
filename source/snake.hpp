#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <deque>
#include <initializer_list>
#include <cstddef>
#include "point.hpp"
#include "colorgrid.hpp"


class Snake {
public:

    enum Direction {
        UP,
        DOWN,
        RIGHT,
        LEFT 
    };

    Snake(Direction dir, std::initializer_list<Point> body);
     
    bool is_on_pos(Point pos) const;
    void change_direction(Direction dir);

    bool move();
    void grow();

    Snake::Direction get_direction() const;
    Point get_head_pos() const;
    size_t get_length() const; 
    
    void paint(ColorGrid &color_grid, Point offset);        
private:
    size_t length;  
    
    std::deque<Point> body;
    Direction direction; 
};

#endif //SNAKE_HPP
