#ifndef BRICK_H
#define BRICK_H

class Brick {
public:
    Brick();
    Brick(int x, int y);
    static const int WIDTH = 6;
    static const int HEIGHT = 4;
    void draw();
    bool isActive() const;
    void deactivate();
    int getX() const;
    int getY() const;

private:
    int x, y;
    bool active;
};

#endif // BRICK_H
