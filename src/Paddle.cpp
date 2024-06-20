#include "Paddle.h"

Paddle::Paddle(float x, float y, const std::string& filename)
    : speed(5) {
    if (!texture.loadFromFile(filename)) {
        // Manejar el error si no se puede cargar la textura
    }
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}

void Paddle::moveLeft() {
    sprite.move(-speed, 0);
}

void Paddle::moveRight() {
    sprite.move(speed, 0);
}

void Paddle::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect Paddle::getBounds() const {
    return sprite.getGlobalBounds();
}
