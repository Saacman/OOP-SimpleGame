#include "app.hpp"

// Constructor por defecto. Inicializa la maquina de estados con punteros compartidos a los estados de juego.
App::App() : window(" Proyecto Final ") {
    // Creamos los estados
    std::shared_ptr<SplashScreen> splashScreen = std::make_shared<SplashScreen>(path, fsm, window);
    std::shared_ptr<GameState> gameState = std::make_shared<GameState>(path, fsm);
    std::shared_ptr<RoomState> roomState = std::make_shared<RoomState>(path, fsm);
    //Los añadimos a la FSM
    unsigned int splashScreenID = fsm.Add(splashScreen);
    unsigned int gameStateID = fsm.Add(gameState);
    unsigned int roomStateID = fsm.Add(roomState);
    //Configuramos los estados a cambiar
    splashScreen->SetSwitchToState(gameStateID);
    gameState->SetSwitchToState(roomStateID);
    roomState->SetSwitchToState(gameStateID);
    fsm.SwitchTo(splashScreenID);
    dTime = clock.restart().asSeconds();
}

// Actualiza los eventos de la ventana y pasa el tiempo delta a la fsm
void App::Update() {
    window.Update(); // Linea importante, sin ella la ventana no responde
    fsm.Update(dTime);
}

// El proceso de dibujo. Limpia la venta, dibuja los elementos a mostrar y los coloca en la ventana
void App::Draw() {
    window.BeginDraw();
    fsm.Draw(window);
    window.EndDraw();
}

// Verifica que la venta se encuentre abierta
bool App::IsRunning() const {
    return window.IsOpen();
}

// Obtiene el tiempo transcurrido entre cada ciclo.
void App::GetdTime() {
    dTime = clock.restart().asSeconds();
}
