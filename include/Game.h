#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <ncurses.h>
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"

class Game {
public:
    Game();
    void run();

private:
    const int WIDTH = 60;
    const int HEIGHT = 20;
    const int PADDLE_LENGTH = 10;
    const int PADDLE_SPEED = 5;

    Ball ball;
    Paddle paddle;
    std::vector<std::vector<Brick>> bricks;
    int score;
    int lives;
    char screen[20][61];

    void showMenu();
    void initGame();
    void drawGame();
    void updateGame();
    void processInput();
    void loadResources();
};

#endif
