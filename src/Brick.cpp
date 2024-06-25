#include "Brick.hpp"

Brick::Brick() {
    initialize();
}

void Brick::initialize() {
    for (int i = 0; i < WIDTH / 6; ++i) {
        for (int j = 0; j < HEIGHT / 4; ++j) {
            bricks[i][j] = true;
        }
    }
}

void Brick::draw(char screen[HEIGHT][WIDTH + 1]) {
    for (int i = 0; i < WIDTH / 6; ++i) {
        for (int j = 0; j < HEIGHT / 4; ++j) {
            if (bricks[i][j]) {
                for (int x = i * 6; x < (i + 1) * 6; ++x) {
                    for (int y = j * 4; y < (j + 1) * 4; ++y) {
                        screen[y][x] = BRICK;
                    }
                }
            }
        }
    }
}

bool (*Brick::getBricks())[WIDTH / 6] {
    return 0;
}
