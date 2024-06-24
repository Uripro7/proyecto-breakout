#ifndef GAME_H
#define GAME_H

#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"
#include "ScreenManager.h"
#include "Life.h"
#include <vector>

class Game {
public:
    Game();
    void run();

private:
    void showMenu();
    void initGame();
    void drawGame();
    void updateGame();
    void processInput();

    Ball ball;
    Paddle paddle;
    std::vector<std::vector<Brick>> bricks;
    ScreenManager screenManager;
    Life life;
    int score;
    static const int WIDTH = 60;
    static const int HEIGHT = 20;
    static const int PADDLE_LENGTH = 10;
    static const int PADDLE_SPEED = 5;
    static const int FRAME_DELAY = 50000; // Adjust to slow down the ball
};

#endif
