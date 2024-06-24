#include "Ball.hpp"
#include <ncurses.h>

Ball::Ball(int x, int y, int dirX, int dirY) : x(x), y(y), dirX(dirX), dirY(dirY) {}

void Ball::move() {
    x += dirX;
    y += dirY;
}

void Ball::draw() {
    mvaddch(y, x, 'O');
}

int Ball::getX() const {
    return x;
}

int Ball::getY() const {
    return y;
}

void Ball::changeDirectionY() {
    dirY = -dirY;
}

void Ball::changeDirectionX() {
    dirX = -dirX;
}
