#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>
#include <initializer_list>

struct Point {
    unsigned int x;
    unsigned int y;
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
     
    bool is_on_pos(unsigned int x, unsigned int y) const;

    Snake::Direction get_direction() const;
private:
    
    std::vector<Point> body;
    Snake::Direction direction; 
};

#endif //SNAKE_HPP
