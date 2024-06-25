#ifndef BALL_HPP
#define BALL_HPP

#include "config.hpp"

class Ball {
public:
    Ball();  // Constructor por defecto
    void move();
    void checkCollisionWithWalls();
    void checkCollisionWithPaddle(int paddleX);
    bool checkCollisionWithBrick(bool bricks[WIDTH / 6][HEIGHT / 4], int& score);
    void draw(char screen[HEIGHT][WIDTH + 1]);

    int getY() const;  // Método getY

private:
    int x, y;
    int dirX, dirY;
};

#endif // BALL_HPP
