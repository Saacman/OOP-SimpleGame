#include "app.hpp"

App::App() : window(" Proyecto Final ") {
    // Creamos dos estados
    //Pasamos en la localización de la textura nuestro splashScreen
    std::shared_ptr<SplashScreen> splashScreen = std::make_shared<SplashScreen>(path, fsm, window, textureAllocator);
    //Pasamos nuestra localidad de textura a nuestra app
    std::shared_ptr<GameState> gameState = std::make_shared<GameState>(path, textureAllocator);
    //Los añadimos a la FSM
    unsigned int splashScreenID = fsm.Add(splashScreen);//Esto retorna el ID de estados dentro de la FSM
    unsigned int gameStateID = fsm.Add(gameState);
    //Configuramos la splash
    splashScreen->SetSwitchToState(gameStateID);
    fsm.SwitchTo(splashScreenID);//queremos que el juego comience despues de nuestro splash
                                 //tenemos una transición a nuestro estado usando el id
    dTime = clock.restart().asSeconds();
}

void App::Update() {
    window.Update(); // Linea importante, sin ella la ventana no responde
    fsm.Update(dTime);
}
void App::LateUpdate() {
    fsm.LateUpdate(dTime);
}

void App::Draw() {//Dibuja principalmente los sprite
    window.BeginDraw();

    fsm.Draw(window);

    window.EndDraw();
}

bool App::IsRunning() const {
    return window.IsOpen();
}

void App::GetdTime() {//linea importante debido a que pone la velocidad de ejecución en
                      //función de un reloj general y no del procesador
    dTime = clock.restart().asSeconds();
}
void App::CaptureInput()
{
    fsm.ProcessInput();
}
