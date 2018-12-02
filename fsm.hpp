#ifndef FSM_HPP
#define FSM_HPP

#include <memory>

#include "state.hpp"
#include "window.hpp"
#include <unordered_map>

class FSM {
public:
    FSM();

    virtual void ProcessInput();
    virtual void Update( float dTime);
    virtual void LateUpdate(float dTime);
    virtual void Draw(Window& window);

    // Añadir estados a la FSM, retorna el ID del estado insertado
    unsigned int Add(std::shared_ptr<State> state);

    // Cambiar al estado dado el id
    void SwitchTo(unsigned int id);

    // Remover estado de la FSM
    void Remove(unsigned int id);

private:
    // Todos los estados guardados en la FSM
    std::unordered_map<unsigned int, std::shared_ptr<State>> states;

	// Referencia al estado actual, usado para dibujar, actualizar
    std::shared_ptr<State> currentState;

	// ID del estado actual, se modifica cuando se añaden estados.
    unsigned int insertedStateID;
};

#endif
