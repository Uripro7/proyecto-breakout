#include "ScreenManager.h"

ScreenManager::ScreenManager() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    timeout(0); // Non-blocking input
}

ScreenManager::~ScreenManager() {
    endwin();
}

void ScreenManager::drawScreen(char screen[20][61]) {
    for (int y = 0; y < 20; ++y) {
        for (int x = 0; x < 61; ++x) {
            mvaddch(y, x, screen[y][x]);
        }
    }
}

void ScreenManager::clearScreen() {
    clear();
}

void ScreenManager::refreshScreen() {
    refresh();
}

void ScreenManager::drawText(int x, int y, const char* text) {
    mvprintw(y, x, "%s", text);
}
