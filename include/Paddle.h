#ifndef PADDLE_H
#define PADDLE_H

class Paddle {
public:
    Paddle(int x, int length, int speed);
    int getX() const;
    void moveLeft();
    void moveRight();

private:
    int x;
    int length;
    int speed;
};

#endif
