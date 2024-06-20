#ifndef BRICK_H
#define BRICK_H

class Brick {
public:
    Brick();

    void activate();
    void deactivate();
    bool isActive() const;

private:
    bool active;
};

#endif
