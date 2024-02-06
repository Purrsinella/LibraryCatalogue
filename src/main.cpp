#include <SQLiteCpp/Database.h>
#include <string>
#include <ncurses.h>
#include <Window.h>
#include <Engine.h>
#include <mainMenu.h>


int main() {
    initscr();

    bool isRunning = true;

    auto bigWindow = Window{};

    auto window = Window(6,bigWindow.height);
    refresh();
    curs_set(0);
    wrefresh(window.win);

    Engine fsm(std::make_unique<mainMenu>(), window, bigWindow);

    keypad(window.win, true);
    while (isRunning) {
        fsm.display();
        auto key = wgetch(window.win);
        fsm.handleInput(key);
        isRunning = fsm.processTransition();
    }

    endwin();
}
