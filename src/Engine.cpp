#include "Engine.h"
#include "ConcreteStateExit.h"


Engine::Engine(State *state, Window window, Window bigWnd) : _state(state), _window(window), _textWindow(bigWnd), _nextState(nullptr) {
    _state->setEngine(this, _window, _textWindow);
}

Engine::~Engine() {
    delete _state;
    delete _nextState;
}

void Engine::TransitionTo(State *state) {
    _nextState = state;
}

bool Engine::processTransition() {
    if (_nextState == nullptr)
        return true;

    delete _state;

    _state = _nextState;
    _nextState = nullptr;
    _state->setEngine(this, _window, _textWindow);

    if(dynamic_cast<ConcreteStateExit*>(_state) != nullptr){
        return false;
    }
    return true;
}


void Engine::display() {
    _window.clear();
    _textWindow.clear();
    _state->display();
    wrefresh(_window.win);
    wrefresh(_textWindow.win);
}

void Engine::handleInput(int key) {
    _state->handleInput(key);
}
