#include "game.hpp"

Game::Game(const std::shared_ptr<ColorGrid> &color_grid, int height, int width) 
   : color_grid(color_grid), height(height), width(width) {
    init_game();
}

void Game::init_game() {

    Point first_element = {width / 2, height / 2};
    Point second_element = {width / 2 - 1, height / 2};
    Point thrid_element = {width / 2 - 2, height / 2};

    snake = std::shared_ptr<Snake>(new Snake(Snake::RIGHT, {first_element, second_element, thrid_element}));
    
    arena = Arena(snake, height , width);
}

bool Game::update() {

    color_grid->wait_ms(500);

    ColorGrid::Key key;
    key = color_grid->poll_keyboard();
    
    if (key == ColorGrid::key_up) {
        snake->change_direction(Snake::UP);
    }
    else if (key == ColorGrid::key_down) {
        snake->change_direction(Snake::DOWN);
    }
    else if (key == ColorGrid::key_left) {
        snake->change_direction(Snake::LEFT);
    }
    else if (key == ColorGrid::key_right) {
        snake->change_direction(Snake::RIGHT);
    }

    return arena.move_snake();
}

void Game::draw() {
    
    arena.paint(*color_grid, Point{2,2});

    color_grid->draw();
} 

void Game::retry() {

    init_game();
}
