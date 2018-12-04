#ifndef STATE_HPP
#define STATE_HPP

#include "window.hpp"

//Clase abstracta de la que se derivan los estads los juegos. No debe instanciarse
// Algunos métodos no fueron implementados por la simplicidad del demo.
class State {
public:
    virtual void init() = 0;

    // Llamado cuando cambia al estado
    virtual void activate() {}
    // Llamado cuando cambia a otro estado
    virtual void deactivate() {}
    virtual void SetSwitchToState(unsigned int id) {}

    virtual void Update( float dTime) = 0;
    virtual void Draw(Window& window) = 0;

};

#endif
