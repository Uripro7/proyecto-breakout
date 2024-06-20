#include "Brick.h"

Brick::Brick() : active(false) {}

void Brick::activate() {
    active = true;
}

void Brick::deactivate() {
    active = false;
}

bool Brick::isActive() const {
    return active;
}
