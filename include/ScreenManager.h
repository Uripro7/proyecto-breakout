#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <string>

class ScreenManager {
public:
    void clearScreen();
    void drawText(int x, int y, const std::string &text);
    void refreshScreen();
    bool kbhit();
};

#endif
