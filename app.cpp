#include "app.hpp"

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

void App::Update() {
    window.Update(); // Linea importante, sin ella la ventana no responde
    fsm.Update(dTime);
}
void App::LateUpdate() {
    fsm.LateUpdate(dTime);
}

void App::Draw() {
    window.BeginDraw();

    fsm.Draw(window);

    window.EndDraw();
}

bool App::IsRunning() const {
    return window.IsOpen();
}

void App::GetdTime() {
    dTime = clock.restart().asSeconds();
}
