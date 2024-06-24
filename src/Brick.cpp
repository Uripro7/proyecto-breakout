#include "Brick.hpp"
#include <ncurses.h>

Brick::Brick() : x(0), y(0), active(true) {}

Brick::Brick(int x, int y) : x(x), y(y), active(true) {}

void Brick::draw() {
    if (active) {
        mvaddch(y, x, '#');
    }
}

bool Brick::isActive() const {
    return active;
}

void Brick::deactivate() {
    active = false;
}

int Brick::getX() const {
    return x;
}

int Brick::getY() const {
    return y;
}
