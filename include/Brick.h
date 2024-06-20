#ifndef BRICK_H
#define BRICK_H

#include <SFML/Graphics.hpp>

class Brick {
public:
    Brick(float x, float y, const std::string& filename);
    void draw(sf::RenderWindow& window) const;
    sf::FloatRect getBounds() const;
    bool isActive() const;
    void deactivate();

private:
    sf::Texture texture;
    sf::Sprite sprite;
    bool active;
};

#endif
