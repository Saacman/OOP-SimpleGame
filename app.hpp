#ifndef APP_HPP
#define APP_HPP

#include "window.hpp"
#include "r_path.hpp"
#include "fsm.hpp"
#include "splashscreen.hpp"
#include "gamestate.hpp"
#include "roomstate.hpp"

// La aplicación de juego inicializa la maquina de estados, engloba el proceso de dibujo,
// y administra el reloj.

class App {
public:
    App();
    void Update();
    void Draw();
    bool IsRunning() const;
    void GetdTime();

private:
    Window window;
    sf::Clock clock;
    float dTime;
    ResourcePath path;
    FSM fsm;
};
#endif
