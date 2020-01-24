#include <thread>
#include <chrono>
#include <memory>
#include "colorgrid.hpp"
#include "game.hpp"

int main(){

    std::shared_ptr<ColorGrid> color_grid = std::make_shared<ColorGrid>(20,20);
    
    Game game(color_grid, 16, 16);

    while (true) {

        if (game.update() == false) {
           break; 
        }

        game.draw();
    }        
}
