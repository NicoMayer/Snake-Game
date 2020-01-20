#ifndef COLORGRID_HPP
#define COLORGRID_HPP

#include <vector>
#include <cstddef>
#include <ncurses.h>
#include "point.hpp"

class ColorGrid {
public:

    enum Color {
        green = 1,
        black = 2,
        red = 3,
        white = 4
    };

    enum Key {
        key_left,
        key_right,
        key_down,
        key_up,
        no_key_pressed
    };

    ColorGrid(size_t width, size_t height);
    ~ColorGrid();

    void set_cell(int x, int y, ColorGrid::Color color);
    void set_cell(Point pos, ColorGrid::Color color);
    void draw();

    ColorGrid::Key poll_keyboard();
    void wait_ms(int ms);

private:    
    std::vector<ColorGrid::Color> color_grid;

    const size_t width;
    const size_t height;

    void init_screen();
    void init_keyboard();
    void init_colors();
    void init_color_grid();
};
    

#endif //COLORGRID_HPP
