#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>

class Ball {
public:
    Ball(float x, float y, const std::string& filename);
    void move();
    void draw(sf::RenderWindow& window);
    void setDirection(float dx, float dy);
    sf::FloatRect getBounds() const;

private:
    sf::Texture texture;
    sf::Sprite sprite;
    float dx, dy;
};

#endif
