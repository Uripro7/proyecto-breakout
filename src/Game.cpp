#include "Game.h"
#include <unistd.h> // For usleep function
#include <sstream> // Include sstream for std::ostringstream
#include <string> // Include string for std::string

Game::Game() 
    : ball(WIDTH / 2, HEIGHT - 3), 
      paddle(WIDTH / 2 - PADDLE_LENGTH / 2, PADDLE_LENGTH, PADDLE_SPEED), 
      bricks(WIDTH / 6, std::vector<Brick>(HEIGHT / 4)), // Initialize bricks vector
      screenManager() {
    initGame();
}

void Game::run() {
    showMenu();
    while (true) {
        drawGame();
        processInput();
        updateGame();
        screenManager.refreshScreen();
        usleep(FRAME_DELAY); // Sleep for the frame delay time (adjusted to slow down the ball)
    }
}

void Game::showMenu() {
    screenManager.clearScreen();
    screenManager.drawText(20, 5, "==============================");
    screenManager.drawText(20, 6, "  Do you think you are fast?  ");
    screenManager.drawText(20, 7, "          Prove it B)         ");
    screenManager.drawText(20, 8, "      Welcome to breakout     ");
    screenManager.drawText(20, 9, "==============================");
    screenManager.drawText(20, 11, "Press any key to start...");
    screenManager.refreshScreen();
    getchar(); // Wait for a key press
    screenManager.clearScreen();
}

void Game::initGame() {
    for (int i = 0; i < WIDTH / 6; ++i) {
        for (int j = 0; j < HEIGHT / 4; ++j) {
            bricks[i][j].activate();
        }
    }
    score = 0;
    lives = 3;
}

void Game::drawGame() {
    screenManager.clearScreen();

    // Draw bricks
    for (int j = 0; j < HEIGHT / 4; ++j) {
        for (int i = 0; i < WIDTH / 6; ++i) {
            if (bricks[i][j].isActive()) {
                screenManager.drawText(i * 6, j, "#");
            }
        }
    }

    // Draw ball
    screenManager.drawText(ball.getX(), ball.getY(), "o");

    // Draw paddle
    for (int i = 0; i < paddle.getLength(); ++i) {
        screenManager.drawText(paddle.getX() + i, HEIGHT - 1, "=");
    }

    // Show score and lives
    std::ostringstream scoreLivesText;
    scoreLivesText << "Puntuacion: " << score << "  Vidas: " << lives;
    screenManager.drawText(0, HEIGHT, scoreLivesText.str().c_str()); // Convert std::string to const char*
    screenManager.refreshScreen();
}

void Game::updateGame() {
    ball.move();

    // Bounce the ball off the edges
    if (ball.getX() <= 0 || ball.getX() >= WIDTH - 1) {
        ball.setDirX(-ball.getDirX());
    }
    if (ball.getY() <= 0) {
        ball.setDirY(-ball.getDirY());
    }

    // Detect collision with paddle
    if (ball.getY() == HEIGHT - 2 && ball.getX() >= paddle.getX() && ball.getX() < paddle.getX() + paddle.getLength()) {
        ball.setDirY(-ball.getDirY());

        int hitPos = ball.getX() - paddle.getX();
        ball.setDirX(hitPos < paddle.getLength() / 2 ? -1 : 1);
    }

    // Detect collision with bricks
    int brickX = ball.getX() / 6;
    int brickY = ball.getY() / 1;
    if (brickX >= 0 && brickX < WIDTH / 6 && brickY >= 0 && brickY < HEIGHT / 4 && bricks[brickX][brickY].isActive()) {
        bricks[brickX][brickY].deactivate();
        score += 10;
        ball.setDirY(-ball.getDirY());
    }

    // Check end-of-game condition
    if (ball.getY() >= HEIGHT) {
        --lives;
        if (lives <= 0) {
            screenManager.clearScreen();
            screenManager.drawText(20, 10, "Game Over!");
            std::ostringstream finalScoreText;
            finalScoreText << "Final score: " << score;
            screenManager.drawText(20, 12, finalScoreText.str().c_str()); // Convert std::string to const char*
            screenManager.drawText(20, 14, "Press 'r' to reboot or 'q' to quit.");
            screenManager.refreshScreen();

            // Wait for the player to choose to restart or exit
            while (true) {
                char key = getchar();
                if (key == 'r') {
                    initGame();
                    break;
                } else if (key == 'q') {
                    exit(0);
                }
            }
        } else {
            // Reset ball and paddle
            ball = Ball(WIDTH / 2, HEIGHT - 3);
            paddle = Paddle(WIDTH / 2 - PADDLE_LENGTH / 2, PADDLE_LENGTH, PADDLE_SPEED);
        }
    }
}

void Game::processInput() {
    if (screenManager.kbhit()) { // Use the custom kbhit method from ScreenManager
        int ch = getchar();
        if (ch == 'a' && paddle.getX() > 0) {
            paddle.moveLeft();
        }
        if (ch == 'd' && paddle.getX() < WIDTH - paddle.getLength()) {
            paddle.moveRight();
        }
    }
}
