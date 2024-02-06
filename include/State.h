#ifndef STATE_MACHINE_STATE_H
#define STATE_MACHINE_STATE_H
#include "Window.h"

class Engine;

class State {
protected:
    Engine *_engine;
    Window _window;
    Window _textWindow;
public:
    virtual ~State() = default;

    void setEngine(Engine *engine, Window window, Window bigWnd) {
        _engine = engine;
        _window = window;
        _textWindow = bigWnd;
    }

    virtual void handleInput(int key) = 0;
    virtual void display() = 0;
};




#endif //STATE_MACHINE_STATE_H
