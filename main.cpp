#include <iostream>
#include "SQLiteCpp/Database.h"
#include <string>
#include <ncurses.h>


int main() {
    initscr();
    printw("Hello, World!");
    refresh();
    getch();
    endwin();
    return 0;
}
