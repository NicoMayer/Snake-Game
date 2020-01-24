#include "food.hpp"

Food::Food(Point pos)
    : pos(pos) {
}


Point Food::get_pos() const {
    return pos;
}

void Food::set_pos(Point pos) {
    this->pos = pos;
}

void Food::paint(ColorGrid &color_grid, Point offset) {

    color_grid.set_cell(pos + offset, ColorGrid::red);

}
