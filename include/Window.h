#ifndef STATE_MACHINE_WINDOW_H
#define STATE_MACHINE_WINDOW_H

#include <ncurses.h>

class Window {
public:
    WINDOW *win;

    int height;

    Window();

    explicit Window(int ht);

    Window(int ht, int oX);

    void clear() const;
};


#endif //STATE_MACHINE_WINDOW_H
