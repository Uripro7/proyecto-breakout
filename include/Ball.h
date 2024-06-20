#ifndef BALL_H
#define BALL_H

class Ball {
public:
    Ball(int startX, int startY);

    int getX() const;
    int getY() const;
    int getDirX() const;
    int getDirY() const;

    void setDirX(int dirX);
    void setDirY(int dirY);
    void move();

private:
    int x, y;
    int dirX, dirY;
};

#endif
