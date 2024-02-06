#ifndef STATE_MACHINE_CONCRETESTATEEXIT_H
#define STATE_MACHINE_CONCRETESTATEEXIT_H
#include "State.h"
#include <vector>
#include <string>

class ConcreteStateExit : public State{
public:
    ConcreteStateExit() = default;

    void display() override {}

    void handleInput(int key) {}

    void demonstrate() {}
};


#endif //STATE_MACHINE_CONCRETESTATEEXIT_H
