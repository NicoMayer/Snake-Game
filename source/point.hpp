#ifndef POINT_HPP
#define POINT_HPP

struct Point {
    int x;
    int y;
    
    bool equal(const Point& point) const; 
    void add(int x, int y);    
    Point operator+ (Point point);
};

#endif //POINT_HPP
