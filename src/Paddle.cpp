#include "Paddle.h"

Paddle::Paddle(int startX, int width, int speed) : x(startX), length(width), speed(speed) {}

int Paddle::getX() const {
    return x;
}

void Paddle::moveLeft() {
    x -= speed;
    if (x < 0) {
        x = 0;
    }
}

void Paddle::moveRight() {
    x += speed;
    if (x > 60 - length) {
        x = 60 - length;
    }
}

int Paddle::getLength() const {
    return length;
}
