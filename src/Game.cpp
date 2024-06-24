#include "Game.hpp"
#include <ncurses.h>
#include <unistd.h>

Game::Game() : score(0), lives(3), ball(WIDTH / 2, HEIGHT - 3, 1, -1), paddle(WIDTH / 2 - PADDLE_LENGTH / 2, HEIGHT - 1, PADDLE_LENGTH) {
    initGame();
}

void Game::initGame() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            bricks[i][j] = Brick(i * Brick::WIDTH, j * Brick::HEIGHT);
        }
    }
}

void Game::run() {
    showMenu();
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
            if (bricks[i][j].isActive()) {
                bricks[i][j].draw();
            }
        }
    }
    life.draw(lives);
    mvprintw(HEIGHT + 1, 0, "Score: %d", score);
    screenManager.refreshScreen();
}

void Game::updateGame() {
    ball.move();

    // Check collision with paddle
    if (ball.getY() == HEIGHT - 1 && ball.getX() >= paddle.getX() && ball.getX() < paddle.getX() + paddle.getLength()) {
        ball.changeDirectionY();
        // Adjust ball's direction based on where it hits the paddle
        int paddleCenter = paddle.getX() + paddle.getLength() / 2;
        int ballPosition = ball.getX();
        if (ballPosition < paddleCenter) {
            ball.changeDirectionX();
        } else if (ballPosition > paddleCenter) {
            ball.changeDirectionX();
        }
    }

    // Check collision with bricks
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (bricks[i][j].isActive() && ball.getX() >= bricks[i][j].getX() && ball.getX() < bricks[i][j].getX() + Brick::WIDTH &&
                ball.getY() >= bricks[i][j].getY() && ball.getY() < bricks[i][j].getY() + Brick::HEIGHT) {
                bricks[i][j].deactivate();
                ball.changeDirectionY();
                score += 10;
            }
        }
    }

    // Check if ball hits top wall
    if (ball.getY() <= 0) {
        ball.changeDirectionY();
    }

    // Check if ball hits side walls
    if (ball.getX() <= 0 || ball.getX() >= WIDTH - 1) {
        ball.changeDirectionX();
    }

    // Check if ball misses paddle and loses a life
    if (ball.getY() >= HEIGHT) {
        --lives;
        ball = Ball(WIDTH / 2, HEIGHT - 3, 1, -1); // Reset ball position
        paddle = Paddle(WIDTH / 2 - PADDLE_LENGTH / 2, HEIGHT - 1, PADDLE_LENGTH); // Reset paddle position
    }
}

void Game::processInput() {
    int ch = getch();
    switch (ch) {
        case KEY_LEFT:
            paddle.moveLeft();
            break;
        case KEY_RIGHT:
            paddle.moveRight();
            break;
        case 'q':
            lives = 0; // Quit game
            break;
        default:
            break;
    }
}

void Game::showMenu() {
    screenManager.clearScreen();
    mvprintw(HEIGHT / 2 - 2, WIDTH / 2 - 10, "Press any key to start...");
    screenManager.refreshScreen();
    getch(); // Wait for user input to start game
    screenManager.clearScreen();
}
