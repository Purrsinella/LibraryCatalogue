#ifndef LIBRARYCATALOGUE_UI_H
#define LIBRARYCATALOGUE_UI_H

#include <ncurses.h>
#include <vector>
#include <string>

class UI {
public:
    void menu();
private:
    WINDOW * shape(int height);
    int options(std::vector<std::string> &vec, WINDOW *menuWin);
    void cleanWin(WINDOW *menuWin);
};


#endif //LIBRARYCATALOGUE_UI_H
