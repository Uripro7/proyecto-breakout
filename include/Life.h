#ifndef LIFE_H
#define LIFE_H

class Life {
public:
    Life(int initialLives);
    int getLives() const;
    void loseLife();
    bool isGameOver() const;

private:
    int lives;
};

#endif
