#ifndef GAME_H
#define GAME_H

#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"
#include "ScreenManager.h"
#include <vector>
#include <string> // Include string for std::string

class Game {
public:
    Game();
    void run();

private:
    static const int WIDTH = 60;
    static const int HEIGHT = 20;
    static const int PADDLE_LENGTH = 10;
    static const int PADDLE_SPEED = 5;
    static const int FRAME_DELAY = 50000; // Adjust this value to change the game speed

    Ball ball;
    Paddle paddle;
    std::vector<std::vector<Brick>> bricks;
    int score;
    int lives;
    ScreenManager screenManager;

    void showMenu();
    void initGame();
    void drawGame();
    void updateGame();
    void processInput();
};

#endif
