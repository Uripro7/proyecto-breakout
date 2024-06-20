#ifndef PADDLE_H
#define PADDLE_H

class Paddle {
public:
    Paddle(int startX, int width, int speed);

    int getX() const;
    void moveLeft();
    void moveRight();
    int getLength() const;

private:
    int x;
    int length;
    int speed;
};

#endif
