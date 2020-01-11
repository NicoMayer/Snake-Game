#include <colorgrid.hpp>

ColorGrid::ColorGrid(size_t width, size_t height)
    : width(width), height(height) {

    init_color_grid();
    init_screen();    
    init_keyboard();
    init_colors();
}

ColorGrid::~ColorGrid(){
    endwin();
}

void ColorGrid::init_color_grid(){
    
    color_grid.reserve(width*height); 
    
    for (auto cell : color_grid){
        cell = ColorGrid::BLACK;
    }
}
void ColorGrid::init_screen(){
    
    initscr();
    cbreak();
    noecho();
} 

void ColorGrid::init_keyboard(){

    keypad(stdscr, TRUE);
}

void ColorGrid::init_colors(){

    if(has_colors() == FALSE) {
        return;
    }
        start_color(); 
        init_pair(ColorGrid::GREEN, COLOR_GREEN, COLOR_GREEN); 
        init_pair(ColorGrid::BLACK, COLOR_BLACK, COLOR_BLACK);
        init_pair(ColorGrid::RED, COLOR_RED, COLOR_RED); 
}

void ColorGrid::set_cell(size_t x, size_t y, ColorGrid::Color color){

    if (x >= width or y >= height) {
        return;
    } 

    color_grid[y*width + x] = color;

}

void ColorGrid::draw(){
    
    if (has_colors() == FALSE) {
        return;
    } 
        
    for (size_t y=0; y < height; ++y) {
        for (size_t x=0; x < width; ++x) {

            ColorGrid::Color cell_color = color_grid[y*width + x];
            mvaddch(y, x, ' ' | COLOR_PAIR(cell_color));
        }
    }

    refresh();
}
