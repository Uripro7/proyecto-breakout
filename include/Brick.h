#ifndef BRICK_H
#define BRICK_H

class Brick {
public:
    Brick();
    bool isActive() const;
    void activate(bool state);

private:
    bool active;
};

#endif
