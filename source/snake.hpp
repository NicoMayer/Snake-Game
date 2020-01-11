#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <initializer_list>

struct Point {
    int x;
    int y;
};

class Snake {
public:
    enum Direction {
        UP,
        DOWN,
        RIGHT,
        LEFT
    };

    Snake(Snake::Direction dir, std::initializer_list<Point> body);
     

    
};

#endif //SNAKE_HPP
