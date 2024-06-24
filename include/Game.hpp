#ifndef GAME_H
#define GAME_H

#include "Ball.hpp"
#include "Paddle.hpp"
#include "Brick.hpp"
#include "Life.hpp"
#include "ScreenManager.hpp"

const int WIDTH = 80;
const int HEIGHT = 24;
const int PADDLE_LENGTH = 10;

class Game {
public:
    Game();
    void run();
    void drawGame();
    void updateGame();
    void processInput();
    void initGame();
    void showMenu();

private:
    int score;
    int lives;
    Ball ball;
    Paddle paddle;
    Brick bricks[10][5];
    Life life;
    ScreenManager screenManager;
};

#endif // GAME_H
