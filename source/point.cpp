#include "point.hpp"

bool Point::equal(const Point& point) const {
    return (point.x == x and point.y == y);
}

void Point::add(int x, int y) {
    this->x += x;
    this->y += y;
}

Point Point::operator+ (Point point) {
    
    Point result = *this;
    
    result.add(point.x, point.y);

    return result;
}
