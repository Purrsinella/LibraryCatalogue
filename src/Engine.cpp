#include "Engine.h"
#include "ConcreteStateExit.h"


Engine::Engine(std::unique_ptr<State> state, Window window, Window bigWnd) : _state(std::move(state)), _window(window), _textWindow(bigWnd), _nextState(nullptr) {
    _state->setEngine(this, _window, _textWindow);
}

Engine::~Engine() = default;

void Engine::TransitionTo(std::unique_ptr<State> state) {
    _nextState = std::move(state);
}

bool Engine::processTransition() {
    if (_nextState == nullptr)
        return true;

    _state = std::move(_nextState);
    _nextState = nullptr;
    _state->setEngine(this, _window, _textWindow);

    if(dynamic_cast<ConcreteStateExit*>(_state.get()) != nullptr){
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
