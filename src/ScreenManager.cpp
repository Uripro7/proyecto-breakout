#include "ScreenManager.h"
#include <iostream>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

ScreenManager::ScreenManager() {}

void ScreenManager::clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

void ScreenManager::drawText(int x, int y, const std::string &text) {
    std::cout << "\033[" << y + 1 << ";" << x + 1 << "H" << text;
}

void ScreenManager::refreshScreen() {
    std::cout << std::flush;
}

bool ScreenManager::kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF) {
        ungetc(ch, stdin);
        return true;
    }

    return false;
}
