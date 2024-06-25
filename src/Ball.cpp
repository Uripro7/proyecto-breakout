#include "Ball.hpp"

Ball::Ball() : x(WIDTH / 2), y(HEIGHT / 2), dirX(1), dirY(1) {}

void Ball::move() {
    x += dirX;
    y += dirY;
}

void Ball::checkCollisionWithWalls() {
    if (x <= 0 || x >= WIDTH - 1) dirX = -dirX;
    if (y <= 0) dirY = -dirY;
}

void Ball::checkCollisionWithPaddle(int paddleX) {
    if (y == HEIGHT - 2 && x >= paddleX && x < paddleX + PADDLE_LENGTH) {
        dirY = -dirY;
    }
}

bool Ball::checkCollisionWithBrick(bool bricks[WIDTH / 6][HEIGHT / 4], int& score) {
    int brickX = x / (WIDTH / 6);
    int brickY = y / (HEIGHT / 4);
    if (bricks[brickX][brickY]) {
        bricks[brickX][brickY] = false;
        dirY = -dirY;
        score += 10;
        return true;
    }
    return false;
}

void Ball::draw(char screen[HEIGHT][WIDTH + 1]) {
    screen[y][x] = BALL;
}

int Ball::getY() const {
    return 0;
}
