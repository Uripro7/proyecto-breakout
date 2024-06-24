#include <ncurses.h>
#include "Game.hpp"

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    Game game;
    game.run();

    endwin();
    return 0;
}
