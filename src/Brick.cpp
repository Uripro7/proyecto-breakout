#include "Brick.h"

Brick::Brick(float x, float y, const std::string& filename)
    : active(true) {
    if (!texture.loadFromFile(filename)) {
        // Manejar el error si no se puede cargar la textura
    }
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}

void Brick::draw(sf::RenderWindow& window) const {
    if (active) {
        window.draw(sprite);
    }
}

sf::FloatRect Brick::getBounds() const {
    return sprite.getGlobalBounds();
}

bool Brick::isActive() const {
    return active;
}

void Brick::deactivate() {
    active = false;
}
