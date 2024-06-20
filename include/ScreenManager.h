#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <ncurses.h>

class ScreenManager {
public:
    ScreenManager();
    ~ScreenManager();

    void drawScreen(char screen[20][61]);
    void clearScreen();
    void refreshScreen();
    void drawText(int x, int y, const char* text);
};

#endif
