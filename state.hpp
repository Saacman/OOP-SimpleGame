#ifndef STATE_HPP
#define STATE_HPP

#include "window.hpp"

class State {
public:
    virtual void init() = 0;
    // LLamado cuando se destruye un estados
    virtual void terminate() = 0;
    // Llamado cuando cambia al estado
    virtual void activate() {}
    // Llamado cuando cambia a otro estado
    virtual void deactivate() {}
    virtual void SetSwitchToState(unsigned int id) {}

    virtual void Update( float dTime) = 0;
    virtual void LateUpdate(float dTime) {}
    virtual void Draw(Window& window) = 0;

};

#endif
