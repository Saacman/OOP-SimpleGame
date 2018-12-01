#include "fsm.hpp"
// Constructor por defecto
FSM::FSM() : states(0), currentState(0) { }

void FSM::ProcessInput() {
    if(currentState) {
        currentState->ProcessInput();
    }
}
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
    //auto inserted = states.insert(std::make_pair(insertedStateID, state));
    states.insert(std::make_pair(insertedStateID, state));
    //inserted.first->second->init();
    state->init();
    return insertedStateID++;
}

// Cambiar al estado dado el id
void FSM::SwitchTo(unsigned int id) {
    auto hold = states.find(id);
    if(hold != states.end()) {

        if(currentState) currentState->deactivate();//Si nosotros tenemos un estado actual,
                                                    //nosotros llamaremos el metodo deactive

        currentState = hold->second;//COnfigur el estado actual asegurando que es cargado y dibujado

        currentState->activate();
    }
}

// Remover estado de la FSM
void FSM::Remove(unsigned int id) {
    auto hold = states.find(id);
    if(hold != states.end()) {

        if(currentState == hold->second) currentState = nullptr;//Si el estado no esta siendo removido se llama el estado actual
                  //Tambien queremos posicionar un puntero null para un estado
                  //este no es mas largo que update.

        //Nos aseguramos de llamar al metodo terminate del estado que estamos removiendo
        hold -> second -> terminate();

        currentState->activate();
        states.erase(hold);//Borra definitivamente el estado actual
    }
}
