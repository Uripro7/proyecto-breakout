#ifndef BRICK_H
#define BRICK_H

class Brick {
public:
    Brick();
    Brick(int x, int y);
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
