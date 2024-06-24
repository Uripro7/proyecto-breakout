#include "Paddle.h"

Paddle::Paddle(int x, int length, int speed) : x(x), length(length), speed(speed) {}

int Paddle::getX() const {
    return x;
}

void Paddle::moveLeft() {
    x -= speed;
    if (x < 0) x = 0;
}

void Paddle::moveRight() {
    x += speed;
}
