#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <string>
#include <vector>

class ScreenManager {
public:
    ScreenManager();
    void clearScreen();
    void drawText(int x, int y, const std::string &text);
    void refreshScreen();
    bool kbhit(); // Check if a key is pressed
};

#endif
