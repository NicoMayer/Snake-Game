#include <thread>
#include <chrono>
#include "colorgrid.hpp"

using namespace std::chrono_literals;

int main(){

    ColorGrid color_grid(16,16);

    color_grid.set_cell(0, 0, ColorGrid::GREEN);
    color_grid.set_cell(15, 0, ColorGrid::GREEN);
    color_grid.draw();
    std::this_thread::sleep_for(10s);
}
