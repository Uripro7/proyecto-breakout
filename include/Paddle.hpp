#ifndef PADDLE_H
#define PADDLE_H

class Paddle {
public:
    Paddle(int x, int y, int length);
    void moveLeft();
    void moveRight();
    void draw();
    int getX() const;
    int getY() const;
    int getLength() const;

private:
    int x, y;
    int length;
};

#endif // PADDLE_H
