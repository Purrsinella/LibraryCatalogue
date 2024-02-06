#ifndef STATE_MACHINE_SHOWBOOKS_H
#define STATE_MACHINE_SHOWBOOKS_H


#include <ncurses.h>
#include <vector>
#include <string>
#include "State.h"
#include "Engine.h"
#include "mainMenu.h"
class showBooks : public State {
private:
    int highlight = 0;
    std::vector<std::string> vec = {"Back to main menu"};
public:
    showBooks();

    void display() override;

    void handleInput(int key);

    void demonstrate();
};

#endif //STATE_MACHINE_SHOWBOOKS_H
