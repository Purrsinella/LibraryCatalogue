#include "Window.h"

Window::Window() {
    win = newwin(25, 80, 0, 0);
    height = 25;
    box(win, 0, 0);
    refresh();
    wrefresh(win);
}

Window::Window(int ht) {
    height = ht;
    win = newwin(height+2, 80, 0, 0);
    box(win, 0, 0);
    refresh();
    wrefresh(win);
}

Window::Window(int ht, int oX) {
    height = ht;
    win = newwin(height+2, 80, oX, 0);
    box(win, 0, 0);
    refresh();
    wrefresh(win);
}

void Window::clear() const {
    wclear(win);
    box(win, 0, 0);
    wrefresh(win);
}
