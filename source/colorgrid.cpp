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
        cell = ColorGrid::black;
    }
}
void ColorGrid::init_screen(){
    
    initscr();
    cbreak();
    noecho();
} 

void ColorGrid::init_keyboard(){

    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
}

void ColorGrid::init_colors(){

    if(has_colors() == FALSE) {
        return;
    }
        start_color(); 
        init_pair(ColorGrid::green, COLOR_GREEN, COLOR_GREEN); 
        init_pair(ColorGrid::black, COLOR_BLACK, COLOR_BLACK);
        init_pair(ColorGrid::red, COLOR_RED, COLOR_RED); 
        init_pair(ColorGrid::white, COLOR_WHITE, COLOR_WHITE);
}

void ColorGrid::set_cell(int x, int y, ColorGrid::Color color){

    if (x < 0 || y < 0 || x >= width || y >= height) {
        return;
    } 

    color_grid[y*width + x] = color;

}
void ColorGrid::set_cell(Point pos, ColorGrid::Color color){

    if (pos.x < 0 || pos.y < 0 || pos.x >= width || pos.y >= height) {
        return;
    } 

    color_grid[pos.y*width + pos.x] = color;

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

ColorGrid::Key ColorGrid::poll_keyboard() {
    
    int ch = getch();

    switch(ch) {
        case KEY_LEFT:  return ColorGrid::key_left;
        case KEY_RIGHT: return ColorGrid::key_right;
        case KEY_DOWN:  return ColorGrid::key_down;
        case KEY_UP:    return ColorGrid::key_up;
    }
    return ColorGrid::no_key_pressed;
}
 

void ColorGrid::wait_ms(int ms) {
    
    napms(ms);
}
