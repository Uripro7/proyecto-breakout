#include "Paddle.hpp"

Paddle::Paddle() : x(WIDTH / 2) {}

void Paddle::moveLeft() {
    if (x > 0) x -= PADDLE_SPEED;
}

void Paddle::moveRight() {
    if (x < WIDTH - PADDLE_LENGTH) x += PADDLE_SPEED;
}

void Paddle::draw(char screen[HEIGHT][WIDTH + 1]) {
    for (int i = 0; i < PADDLE_LENGTH; ++i) {
        screen[HEIGHT - 1][x + i] = PADDLE;
    }
}

int Paddle::getX() const {
    return x;
}
