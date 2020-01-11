#ifndef POINT_HPP
#define POINT_HPP

struct Point {
    unsigned int x;
    unsigned int y;
    
    bool operator == (const Point& point) const {
        return point.x == x and point.y == y;
    }

};

#endif //POINT_HPP
