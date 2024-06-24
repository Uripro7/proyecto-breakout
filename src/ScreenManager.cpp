#include "ScreenManager.hpp"
#include <ncurses.h>

void ScreenManager::clearScreen() {
    clear();
}

void ScreenManager::refreshScreen() {
    refresh();
}
