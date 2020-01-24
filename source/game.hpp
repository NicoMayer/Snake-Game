#ifndef GAME_H
#define GAME_H

#include <memory>
#include "snake.hpp"
#include "arena.hpp"

class Game {
public:

    Game(const std::shared_ptr<ColorGrid> &color_grid, int  height, int width);
    
    void retry();
    bool update();
    void draw();
private:
    void init_game();
    int calc_gamespeed();
   
    std::shared_ptr<ColorGrid> color_grid;

    std::shared_ptr<Snake> snake;
    Arena arena;
    
    int height;
    int width;
};
#endif //GAME_H
