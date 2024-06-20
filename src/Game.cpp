#include "Game.h"

Game::Game() : ball(WIDTH / 2, HEIGHT - 3), paddle(WIDTH / 2 - PADDLE_LENGTH / 2, PADDLE_LENGTH, PADDLE_SPEED), score(0), lives(3) {
    for (int i = 0; i < WIDTH / 6; ++i) {
        std::vector<Brick> row;
        for (int j = 0; j < HEIGHT / 4; ++j) {
            row.push_back(Brick());
        }
        bricks.push_back(row);
    }
}

void Game::showMenu() {
    clear();
    mvprintw(0, 0, "==============================");
    mvprintw(1, 0, "  Do you think you are fast?");
    mvprintw(2, 0, "          Prove it B)");
    mvprintw(3, 0, "      Welcome to breakout");
    mvprintw(4, 0, "==============================");
    mvprintw(6, 0, "Press any key to start...");
    refresh();
    getch();
    clear();
}

void Game::initGame() {
    ball = Ball(WIDTH / 2, HEIGHT - 3);
    paddle = Paddle(WIDTH / 2 - PADDLE_LENGTH / 2, PADDLE_LENGTH, PADDLE_SPEED);
    score = 0;
    lives = 3;

    for (int i = 0; i < WIDTH / 6; ++i) {
        for (int j = 0; j < HEIGHT / 4; ++j) {
            bricks[i][j] = Brick();
        }
    }

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            screen[y][x] = ' ';
        }
        screen[y][WIDTH] = '\0';
    }
}

void Game::drawGame() {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            screen[y][x] = ' ';
        }
    }

    for (int j = 0; j < HEIGHT / 4; ++j) {
        for (int i = 0; i < WIDTH / 6; ++i) {
            if (bricks[i][j].isActive()) {
                screen[j][i * 6] = '#';
            }
        }
    }

    screen[ball.getY()][ball.getX()] = 'o';

    for (int i = 0; i < PADDLE_LENGTH; ++i) {
        screen[HEIGHT - 1][paddle.getX() + i] = '=';
    }

    clear();
    for (int y = 0; y < HEIGHT; ++y) {
        mvprintw(y, 0, "%s", screen[y]);
    }
    mvprintw(HEIGHT, 0, "Puntuacion: %d  Vidas: %d", score, lives);
    refresh();
}

void Game::updateGame() {
    ball.move();

    if (ball.getX() <= 0 || ball.getX() >= WIDTH - 1) {
        ball.setDirX(-ball.getDirX());
    }
    if (ball.getY() <= 0) {
        ball.setDirY(-ball.getDirY());
    }

    if (ball.getY() == HEIGHT - 2 && ball.getX() >= paddle.getX() && ball.getX() < paddle.getX() + PADDLE_LENGTH) {
        ball.setDirY(-ball.getDirY());
        int hitPos = ball.getX() - paddle.getX();
        if (hitPos < PADDLE_LENGTH / 2) {
            ball.setDirX(-1);
        } else {
            ball.setDirX(1);
        }
    }

    int brickX = ball.getX() / 6;
    int brickY = ball.getY();
    if (brickX >= 0 && brickX < WIDTH / 6 && brickY >= 0 && brickY < HEIGHT / 4 && bricks[brickX][brickY].isActive()) {
        bricks[brickX][brickY].deactivate();
        score += 10;
        ball.setDirY(-ball.getDirY());
    }

    if (ball.getY() >= HEIGHT) {
        --lives;
        if (lives <= 0) {
            clear();
            mvprintw(HEIGHT / 2, WIDTH / 2 - 5, "Game Over!");
            mvprintw(HEIGHT / 2 + 1, WIDTH / 2 - 5, "Final score: %d", score);
            mvprintw(HEIGHT / 2 + 2, WIDTH / 2 - 5, "Press 'r' to reboot or 'q' to get out.");
            refresh();

            while (true) {
                char key = getch();
                if (key == 'r') {
                    initGame();
                    break;
                } else if (key == 'q') {
                    endwin();
                    exit(0);
                }
            }
        } else {
            ball = Ball(WIDTH / 2, HEIGHT - 3);
            paddle = Paddle(WIDTH / 2 - PADDLE_LENGTH / 2, PADDLE_LENGTH, PADDLE_SPEED);
        }
    }
}

void Game::processInput() {
    nodelay(stdscr, TRUE);
    int key = getch();
    if (key == 'a') {
        paddle.moveLeft();
    }
    if (key == 'd') {
        paddle.moveRight();
    }
}

void Game::run() {
    initscr();
    noecho();
    curs_set(FALSE);

    showMenu();
    initGame();

    while (true) {
        drawGame();
        processInput();
        updateGame();
        napms(20);
    }

    endwin();
}

void Game::loadResources() {
    // Function to load images or other resources
}

