#ifndef COLORGRID_HPP
#define COLORGRID_HPP

#include <vector>
#include <cstddef>
#include <ncurses.h>

class ColorGrid {
public:

    enum Color {
        GREEN = 1,
        BLACK = 2,
        RED = 3
    };

    ColorGrid(size_t width, size_t height);
    ~ColorGrid();

    void set_cell(size_t x, size_t y, ColorGrid::Color color);
    void draw();

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
