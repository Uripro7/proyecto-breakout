#ifndef BALL_H
#define BALL_H

class Ball {
public:
    Ball(int x, int y, int dirX, int dirY);
    void move();
    void draw();
    int getX() const;
    int getY() const;
    void changeDirectionY();
    void changeDirectionX();

private:
    int x, y;
    int dirX, dirY;
};

#endif // BALL_H
