#include "fsm.hpp"
// Constructor por defecto
FSM::FSM() : states(0), currentState(0) { }

void FSM::Update( float dTime) {
    if(currentState) {
        currentState->Update(dTime);
    }
}
void FSM::LateUpdate(float dTime) {
    if(currentState) {
        currentState->LateUpdate(dTime);
    }
}
void FSM::Draw(Window& window) {
    if(currentState) {
        currentState->Draw(window);
    }
}

// Añadir estados a la FSM, retorna el id del estado insertado
unsigned int FSM::Add(std::shared_ptr<State> state) {
    states.insert(std::make_pair(insertedStateID, state));
    state->init();
    return insertedStateID++;
}

// Cambiar al estado dado el id
void FSM::SwitchTo(unsigned int id) {
    auto hold = states.find(id);
    if(hold != states.end()) {

        if(currentState) currentState->deactivate();
        currentState = hold->second;
        currentState->activate();
    }
}

// Remover estado de la FSM
void FSM::Remove(unsigned int id) {
    auto hold = states.find(id);
    if(hold != states.end()) {

        if(currentState == hold->second) currentState = nullptr;
        hold -> second -> terminate();
        currentState->activate();
        states.erase(hold);
    }
}
