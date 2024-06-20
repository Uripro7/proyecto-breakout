#include "Brick.h"

Brick::Brick() : active(true) {}

bool Brick::isActive() const {
    return active;
}

void Brick::deactivate() {
    active = false;
}
