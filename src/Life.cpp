#include "Life.h"

Life::Life(int initialLives) : lives(initialLives) {}

int Life::getLives() const {
    return lives;
}

void Life::loseLife() {
    lives--;
}

bool Life::isGameOver() const {
    return lives <= 0;
}
