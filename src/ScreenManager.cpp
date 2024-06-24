#include "ScreenManager.h"
#include <ncurses.h>
#include <unistd.h>

void ScreenManager::clearScreen() {
    clear();
}

void ScreenManager::drawText(int x, int y, const std::string &text) {
    mvprintw(y, x, "%s", text.c_str());
}

void ScreenManager::refreshScreen() {
    refresh();
}

bool ScreenManager::kbhit() {
    timeout(0);
    int ch = getch();
    if (ch != ERR) {
        ungetch(ch);
        return true;
    }
    return false;
}
