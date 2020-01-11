#ifndef FOOD_HPP
#define FOOD_HPP

#include "point.hpp"

class Food {
    
    const Point pos;

public:
    Food(Point pos);
    Point get_pos() const;
};

#endif //FOOD_HPP
