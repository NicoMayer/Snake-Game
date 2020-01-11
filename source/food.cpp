#include "food.hpp"

Food::Food(Point pos)
    : pos(pos) {
}


Point Food::get_pos() const {
    return pos;
}
