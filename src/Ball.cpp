#include "Ball.h"

Ball::Ball(int x, int y) : x(x), y(y), dirX(1), dirY(-1) {}

void Ball::move() {
    x += dirX;
    y += dirY;
}

int Ball::getX() const { return x; }
int Ball::getY() const { return y; }
int Ball::getDirX() const { return dirX; }
int Ball::getDirY() const { return dirY; }
void Ball::setDirX(int dirX) { this->dirX = dirX; }
void Ball::setDirY(int dirY) { this->dirY = dirY; }
