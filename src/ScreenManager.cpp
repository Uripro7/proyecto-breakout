#include "ScreenManager.hpp"
#include <ncurses.h>

void ScreenManager::gotoxy(int x, int y) {
    move(y, x);
}
