#include "food.hpp"

Food::Food(int x, int y)
    : x(x), y(y) {}

int Food::X() const {
    return x;
}

int Food::Y() const {
    return y;
}
