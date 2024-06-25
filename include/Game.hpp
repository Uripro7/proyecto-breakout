#ifndef GAME_HPP
#define GAME_HPP

#include "config.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"
#include "Brick.hpp"
#include "Life.hpp"
#include "ScreenManager.hpp"

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

    Paddle paddle;
    Ball ball;
    Brick bricks;
    Life life;
    ScreenManager screenManager;
    int score;
    bool running;
};

#endif // GAME_HPP
