#ifndef STATE_MACHINE_MAINMENU_H
#define STATE_MACHINE_MAINMENU_H

#include <ncurses.h>
#include <vector>
#include <string>
#include "State.h"
#include "Engine.h"
class mainMenu : public State {
private:
    int highlight = 0;
    std::vector<std::string> vec = {"Show Books", "Exit"};
public:
    mainMenu();

    void display() override;

    void handleInput(int key);

    void demonstrate();
};

#endif //STATE_MACHINE_MAINMENU_H
