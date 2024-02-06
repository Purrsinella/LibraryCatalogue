#ifndef STATE_MACHINE_ENGINE_H
#define STATE_MACHINE_ENGINE_H

#include <ncurses.h>
#include "Window.h"
#include "State.h"

class Engine {
private:
    State *_state;
    State *_nextState;
    Window _window;
    Window _textWindow;
public:

    //Engine(State *state, Window window);

    Engine(State *state, Window wnd, Window bigWnd);

    ~Engine();

    void TransitionTo(State *state);

    bool processTransition();

    void display();

    void handleInput(int key);
};


#endif //STATE_MACHINE_ENGINE_H
