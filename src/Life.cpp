#include "Life.hpp"

Life::Life(int initialLives) : lives(initialLives) {}

void Life::loseLife() {
    if (lives > 0) {
        lives--;
    }
}

int Life::getLives() const {
    return lives;
}
