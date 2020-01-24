#ifndef FOOD_HPP
#define FOOD_HPP

#include "colorgrid.hpp"
#include "point.hpp"

class Food {
    
    Point pos;

public:
    Food(Point pos = {0,0});

    void set_pos(Point pos);
    Point get_pos() const;
    void paint(ColorGrid &color_grid, Point offset);
};

#endif //FOOD_HPP
