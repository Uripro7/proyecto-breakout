#include "Game.hpp"
#include <ncurses.h>
#include <unistd.h>

Game::Game() : score(0), lives(3), ball(WIDTH / 2, HEIGHT - 3, 1, -1), paddle(WIDTH / 2 - PADDLE_LENGTH / 2, HEIGHT - 1, PADDLE_LENGTH) {
    initGame();
}

void Game::initGame() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            bricks[i][j] = Brick(i * 8, j * 2);
        }
    }
}

void Game::run() {
    while (lives > 0) {
        drawGame();
        processInput();
        updateGame();
        usleep(100000); // Reduce speed of the game loop
    }
}

void Game::drawGame() {
    screenManager.clearScreen();
    ball.draw();
    paddle.draw();
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            bricks[i][j].draw();
        }
    }
    life.draw(lives);
    screenManager.refreshScreen();
}

void Game::updateGame() {
    ball.move();
    if (ball.getY() == HEIGHT - 1 && ball.getX() >= paddle.getX() && ball.getX() < paddle.getX() + paddle.getLength()) {
        ball.changeDirectionY();
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (bricks[i][j].isActive() && ball.getX() == bricks[i][j].getX() && ball.getY() == bricks[i][j].getY()) {
                bricks[i][j].deactivate();
                ball.changeDirectionY();
                score += 10;
            }
        }
    }
    if (ball.getY() >= HEIGHT) {
        --lives;
        ball = Ball(WIDTH / 2, HEIGHT - 3, 1, -1);
        paddle = Paddle(WIDTH / 2 - PADDLE_LENGTH / 2, HEIGHT - 1, PADDLE_LENGTH);
    }
}

void Game::processInput() {
    int ch = getch();
    if (ch == KEY_LEFT && paddle.getX() > 0) {
        paddle.moveLeft();
    } else if (ch == KEY_RIGHT && paddle.getX() < WIDTH - paddle.getLength()) {
        paddle.moveRight();
    }
}

void Game::showMenu() {
    screenManager.clearScreen();
    mvprintw(0, 0, "================================");
    mvprintw(1, 0, "  Do you think you are fast?");
    mvprintw(2, 0, "          Prove it B)");
    mvprintw(3, 0, "      Welcome to breakout");
    mvprintw(4, 0, "================================");
    mvprintw(6, 0, "Press any key to start...");
    screenManager.refreshScreen();
    getch();
    screenManager.clearScreen();
}
