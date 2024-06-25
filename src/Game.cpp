#include "Game.hpp"
#include <ncurses.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <Brick.hpp>

Game::Game() : score(0), running(true), paddle(), ball(), bricks(), life(3) {}

void Game::showMenu() {
    clear();
    mvprintw(0, 0, "==============================");
    mvprintw(1, 0, "  Do you think you are fast?  ");
    mvprintw(2, 0, "          Prove it B)         ");
    mvprintw(3, 0, "      Welcome to breakout     ");
    mvprintw(4, 0, "==============================");
    mvprintw(6, 0, "Press any key to start...");
    refresh();
    getch();
    clear();
}

void Game::initGame() {
    ball = Ball();
    paddle = Paddle();
    bricks = Brick();
    life = Life(3);
    bricks.initialize();
    score = 0;
}

void Game::drawGame() {
    clear();
    char screen[HEIGHT][WIDTH + 1] = {0};
    bricks.draw(screen);
    paddle.draw(screen);
    ball.draw(screen);
    mvprintw(HEIGHT, 0, "Score: %d  Lives: %d", score, life.getLives());
    for (int y = 0; y < HEIGHT; ++y) {
        mvprintw(y, 0, screen[y]);
    }
    refresh();
}

void Game::updateGame() {
    ball.move();
    ball.checkCollisionWithWalls();
    ball.checkCollisionWithPaddle(paddle.getX());
    if (ball.checkCollisionWithBrick(bricks.getBricks(), score)) {
        score += 10;
    }
    if (ball.getY() >= HEIGHT) {
        life.loseLife();
        if (life.getLives() <= 0) {
            running = false;
            mvprintw(HEIGHT / 2, WIDTH / 2 - 5, "Game Over!");
            refresh();
            std::this_thread::sleep_for(std::chrono::seconds(3));
        } else {
            ball = Ball();
        }
    }
}

void Game::processInput() {
    int ch = getch();
    switch (ch) {
        case 'a':
            paddle.moveLeft();
            break;
        case 'd':
            paddle.moveRight();
            break;
    }
}

void Game::run() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    showMenu();
    initGame();

    while (running) {
        processInput();
        updateGame();
        drawGame();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    endwin();
}
