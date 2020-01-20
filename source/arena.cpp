#include <cstdlib>
#include <ctime>

#include "arena.hpp"
#include "point.hpp"

Arena::Arena() 
    : snake(nullptr), width(0), height(0) {
}

Arena::Arena(const std::shared_ptr<Snake> &snake, size_t height, size_t width) 
    : height(height), width(width), snake(snake) {
    
    try_to_place_food();
}

bool Arena::move_snake(){

    if (snake == nullptr){
        return false;
    }

    if (snake->move() == false) {
        return false;
    }

    if (check_outside_snake() == true) {
        return false;
    }
    
 
    if (is_food_cell(snake->get_head_pos()) == true) {
        snake->grow();
        return try_to_place_food();
    }
    
    return true;
}

bool Arena::check_outside_snake() {
    
    if (snake == nullptr) {
        return false;
    }

    Point head_pos = snake->get_head_pos();

    if (head_pos.x < 0 or 
        head_pos.y < 0 or
        head_pos.y >= height or
        head_pos.x >= width) {
        
        return true;
    }
    return false;
}

bool Arena::try_to_place_food() {
    
    if (snake != nullptr && snake->get_length() >= height*width) {
        return false;
    }

    std::srand(std::time(nullptr));
    
    int x, y;
    
    do {
        x = std::rand() % width;
        y = std::rand() % height;
    } while (!is_empty_cell(Point{x,y}));

    food.set_pos(Point{x,y});

    return true;
}        

Point Arena::get_food_pos() const {

    return food.get_pos();
}

void Arena::set_food_pos(Point pos) {
    
    food.set_pos(pos);
}

bool Arena::is_food_cell(Point pos) const {

    return food.get_pos().equal(pos);
}

bool Arena::is_empty_cell(Point pos) const {
    
    if (is_food_cell(pos)) {
        return false;
    }

    if (snake != nullptr && snake->is_on_pos(pos)) {
        return false;
    }
    
    return true;
}

void Arena::paint(ColorGrid &color_grid) {
    
    for (int y; y < height; ++y) {
        for (int x; x < width; ++x) {

            color_grid.set_cell(x, y, ColorGrid::black);
        }
    }
    food.paint(color_grid);
} 
