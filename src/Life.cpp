#include "Life.hpp"
#include <ncurses.h>

Life::Life() : lives(3) {}

void Life::draw(int lives) {
    mvprintw(0, 0, "Lives: %d", lives);
}
