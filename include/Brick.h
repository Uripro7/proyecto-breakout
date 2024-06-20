#ifndef BRICK_H
#define BRICK_H

class Brick {
public:
    Brick();

    bool isActive() const;
    void deactivate();

private:
    bool active;
};

#endif
