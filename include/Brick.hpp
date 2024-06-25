#ifndef BRICK_HPP
#define BRICK_HPP

#include "config.hpp"

class Brick {
public:
    Brick();  // Constructor por defecto
    void initialize();
    void draw(char screen[HEIGHT][WIDTH + 1]);

    bool (*getBricks())[WIDTH / 6];  // Método getBricks

private:
    bool bricks[WIDTH / 6][HEIGHT / 4];
};

#endif // BRICK_HPP
