#include "Paddle.hpp"
#include <ncurses.h>

Paddle::Paddle(int x, int y, int length) : x(x), y(y), length(length) {}

void Paddle::moveLeft() {
    x--;
}

void Paddle::moveRight() {
    x++;
}

void Paddle::draw() {
    for (int i = 0; i < length; ++i) {
        mvaddch(y, x + i, '=');
    }
}

int Paddle::getX() const {
    return x;
}

int Paddle::getY() const {
    return y;
}

int Paddle::getLength() const {
    return length;
}
