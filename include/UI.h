#ifndef LIBRARYCATALOGUE_UI_H
#define LIBRARYCATALOGUE_UI_H

#include <ncurses.h>
#include <vector>
#include <string>

class UI {
public:
    void menu();
private:
    WINDOW * shape();
    int options(std::vector<std::string> &vec, WINDOW *menu_win);
    void cleanScreen(WINDOW *menu_win);
};


#endif //LIBRARYCATALOGUE_UI_H
