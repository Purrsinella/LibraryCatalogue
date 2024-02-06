#include "showBooks.h"
#include "mainMenu.h"

showBooks::showBooks() : highlight(0) {}

void showBooks::display() {
    demonstrate();
    for (int i = 0; i < vec.size(); i++) {
        if (i == highlight)
            wattron(_window.win, A_REVERSE);
        mvwprintw(_window.win, i + 1, 1, "%s", vec[i].c_str());
        wattroff(_window.win, A_REVERSE);
    }

}


void showBooks::handleInput(int key) {
    switch (key) {
        case KEY_UP:
            highlight--;
            if (highlight == -1)
                highlight = vec.size() - 1;
            break;
        case KEY_DOWN:
            highlight++;
            if (highlight == vec.size())
                highlight = 0;
            break;
        case KEY_ENTER:
        case '\n':
            if(highlight == 0)
                _engine->TransitionTo(std::make_unique<mainMenu>());
            break;
        default:
            break;
    }
}

void showBooks::demonstrate(){
    mvwprintw(_textWindow.win, 1,1, "I'll show you books");

}