#include "Brick.h"

Brick::Brick() : active(true) {}

bool Brick::isActive() const {
    return active;
}

void Brick::activate(bool state) {
    active = state;
}
