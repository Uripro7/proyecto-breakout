#ifndef PADDLE_HPP
#define PADDLE_HPP

#include "config.hpp"

class Paddle {
public:
    Paddle();  // Constructor por defecto
    void moveLeft();
    void moveRight();
    void draw(char screen[HEIGHT][WIDTH + 1]);  // Método draw

    int getX() const;  // Método getX

private:
    int x;
};

#endif // PADDLE_HPP
