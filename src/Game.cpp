#include "Game.h"
#include <iostream>
#include <sstream>
#include <unistd.h> // For usleep

Game::Game() : ball(WIDTH / 2, HEIGHT - 3), paddle(WIDTH / 2 - PADDLE_LENGTH / 2, PADDLE_LENGTH, PADDLE_SPEED), life(3), score(0) {
    bricks.resize(WIDTH / 6, std::vector<Brick>(HEIGHT / 4));
}

void Game::showMenu() {
    screenManager.clearScreen();
    screenManager.drawText(0, 0, "==============================");
    screenManager.drawText(0, 1, "  Do you think you are fast?  ");
    screenManager.drawText(0, 2, "          Prove it B)         ");
    screenManager.drawText(0, 3, "      Welcome to breakout     ");
    screenManager.drawText(0, 4, "==============================");
    screenManager.drawText(0, 6, "Press any key to start...");

    screenManager.refreshScreen();
    getchar(); // Wait for the user to press a key to continue
}

void Game::initGame() {
    ball = Ball(WIDTH / 2, HEIGHT - 3);
    paddle = Paddle(WIDTH / 2 - PADDLE_LENGTH / 2, PADDLE_LENGTH, PADDLE_SPEED);
    life = Life(3);
    score = 0;

    for (int i = 0; i < WIDTH / 6; ++i) {
        for (int j = 0; j < HEIGHT / 4; ++j) {
            bricks[i][j] = Brick();
        }
    }
}

void Game::drawGame() {
    screenManager.clearScreen();

    for (int j = 0; j < HEIGHT / 4; ++j) {
        for (int i = 0; i < WIDTH / 6; ++i) {
            if (bricks[i][j].isActive()) {
                screenManager.drawText(i * 6, j, "#");
            }
        }
    }

    screenManager.drawText(ball.getX(), ball.getY(), "o");

    for (int i = 0; i < PADDLE_LENGTH; ++i) {
        screenManager.drawText(paddle.getX() + i, HEIGHT - 1, "=");
    }

    screenManager.drawText(0, HEIGHT, "Puntuacion: " + std::to_string(score) + "  Vidas: " + std::to_string(life.getLives()));

    screenManager.refreshScreen();
}

void Game::updateGame() {
    ball.move();

    // Check collision with walls
    if (ball.getX() <= 0 || ball.getX() >= WIDTH - 1) {
        ball.setDirX(-ball.getDirX());
    }
    if (ball.getY() <= 0) {
        ball.setDirY(-ball.getDirY());
    }

    // Check collision with paddle
    if (ball.getY() == HEIGHT - 2 && ball.getX() >= paddle.getX() && ball.getX() < paddle.getX() + PADDLE_LENGTH) {
        ball.setDirY(-ball.getDirY());
    }

    // Check collision with bricks
    int brickX = ball.getX() / 6;
    int brickY = ball.getY() / 1;
    if (brickX >= 0 && brickX < WIDTH / 6 && brickY >= 0 && brickY < HEIGHT / 4 && bricks[brickX][brickY].isActive()) {
        bricks[brickX][brickY].activate(false);
        score += 10;
        ball.setDirY(-ball.getDirY());
    }

    // Check if ball falls off the screen
    if (ball.getY() >= HEIGHT) {
        life.loseLife();
        if (life.isGameOver()) {
            screenManager.clearScreen();
            screenManager.drawText(0, 0, "Game Over!");
            screenManager.drawText(0, 1, "Final score: " + std::to_string(score));
            screenManager.drawText(0, 2, "Press 'r' to restart or 'q' to quit...");

            screenManager.refreshScreen();

            while (true) {
                if (screenManager.kbhit()) {
                    char key = getchar();
                    if (key == 'r') {
                        initGame();
                        break;
                    } else if (key == 'q') {
                        return;
                    }
                }
            }
        } else {
            // Reset ball position
            ball = Ball(WIDTH / 2, HEIGHT - 3);
        }
    }
}

void Game::processInput() {
    if (screenManager.kbhit()) {
        char key = getchar();
        if (key == 'a') {
            paddle.moveLeft();
        } else if (key == 'd') {
            paddle.moveRight();
        }
    }
}

void Game::run() {
    showMenu();
    initGame();

    while (true) {
        drawGame();
        processInput();
        updateGame();

        // Adjust frame delay to control ball speed
        usleep(FRAME_DELAY);
    }
}

int main() {
    Game game;
    game.run();

    return 0;
}

