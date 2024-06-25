#ifndef LIFE_HPP
#define LIFE_HPP

class Life {
public:
    Life(int initialLives = 3);  // Constructor predeterminado
    void loseLife();
    int getLives() const;

private:
    int lives;
};

#endif // LIFE_HPP
