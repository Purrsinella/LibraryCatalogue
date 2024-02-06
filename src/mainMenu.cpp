#include "mainMenu.h"
#include "showBooks.h"
#include "ConcreteStateExit.h"

mainMenu::mainMenu() : highlight(0) {}

void mainMenu::display() {
    demonstrate();

    for (int i = 0; i < vec.size(); i++) {
        if (i == highlight)
            wattron(_window.win, A_REVERSE);
        mvwprintw(_window.win, i + 1, 1, "%s", vec[i].c_str());
        wattroff(_window.win, A_REVERSE);
    }

}


void mainMenu::handleInput(int key) {
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
                _engine->TransitionTo(std::make_unique<showBooks>());
            else if(highlight == 1)
                _engine->TransitionTo(std::make_unique<ConcreteStateExit>());
            break;
        default:
            break;
    }
}

void mainMenu::demonstrate(){
    mvwprintw(_textWindow.win, 1, 1, "It's main menu");
}