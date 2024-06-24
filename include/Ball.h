#ifndef BALL_H
#define BALL_H

class Ball {
public:
    Ball(int x, int y);
    void move();
    int getX() const;
    int getY() const;
    int getDirX() const;
    int getDirY() const;
    void setDirX(int dirX);
    void setDirY(int dirY);

private:
    int x, y;
    int dirX, dirY;
};

#endif
