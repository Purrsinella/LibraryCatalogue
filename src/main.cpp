#include <iostream>
#include "SQLiteCpp/Database.h"
#include <string>
#include <ncurses.h>
#include <UI.h>

int main() {
    initscr();
    refresh();
    UI ui;
    ui.menu();
    getch();
    endwin();
    return 0;
}
