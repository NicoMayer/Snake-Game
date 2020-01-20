#ifndef ARENA_HPP
#define ARENA_HPP

#include <memory>
#include "snake.hpp"
#include "point.hpp"
#include "food.hpp"
#include "colorgrid.hpp"

class Arena {
public:
    Arena();    
    Arena(const std::shared_ptr<Snake> &snake, size_t height, size_t width);

    bool move_snake();
    
    Point get_food_pos() const;
    void set_food_pos(Point pos);
    
    bool is_food_cell(Point pos) const;
    bool is_empty_cell(Point pos) const;    
    
    void paint(ColorGrid &color_grid);
private:

    bool check_outside_snake();
    bool try_to_place_food();

    std::shared_ptr<Snake> snake;
    Food food;

    size_t height;
    size_t width;
}; 

#endif //ARENA_HPP
