#ifndef POINT_HPP
#define POINT_HPP

struct Point {
    int x;
    int y;
    
    bool equal(const Point& point) const; 
    void add(int x, int y);    
};

#endif //POINT_HPP
