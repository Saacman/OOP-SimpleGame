#include "fsm.hpp"
// Constructor por defecto
FSM::FSM() : states(0), currentState(0) { }

// Llama a la función Update del estado activo para que utilizcé el tiempo delta
void FSM::Update( float dTime) {
    if(currentState) {
        currentState->Update(dTime);
    }
}

// Dibuja los dibujables del estado activo.
void FSM::Draw(Window& window) {
    if(currentState) {
        currentState->Draw(window);
    }
}

// Añadir estados a la FSM, retorna el id del estado insertado e inicializa el estado insertado
unsigned int FSM::Add(std::shared_ptr<State> state) {
    states.insert(std::make_pair(insertedStateID, state));
    state->init();
    return insertedStateID++;
}

// Cambiar a otro estado dentro del unordered_map dado el ID
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
        currentState->activate();
        states.erase(hold);
    }
}
