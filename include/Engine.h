#ifndef STATE_MACHINE_ENGINE_H
#define STATE_MACHINE_ENGINE_H

#include <ncurses.h>
#include "Window.h"
#include "State.h"
#include <memory>

class Engine {
private:
    std::unique_ptr<State> _state;
    std::unique_ptr<State> _nextState;
    Window _window;
    Window _textWindow;
public:

    Engine(std::unique_ptr<State> state, Window wnd, Window bigWnd);

    ~Engine();

    void TransitionTo(std::unique_ptr<State> state);

    bool processTransition();

    void display();

    void handleInput(int key);
};


#endif //STATE_MACHINE_ENGINE_H
