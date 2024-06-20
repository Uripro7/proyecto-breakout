#include "Ball.h"

Ball::Ball(float x, float y, const std::string& filename)
    : dx(1), dy(-1) {
    if (!texture.loadFromFile(filename)) {
        // Manejar el error si no se puede cargar la textura
    }
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}

void Ball::move() {
    sprite.move(dx, dy);
}

void Ball::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Ball::setDirection(float dx, float dy) {
    this->dx = dx;
    this->dy = dy;
}

sf::FloatRect Ball::getBounds() const {
    return sprite.getGlobalBounds();
}
