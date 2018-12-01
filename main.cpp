#include "app.hpp"

int main() {
    //Crea el objeto "motor" para gestionar el juego
    App app;

    //Crea un ciclo con el cual se permitirá  llamar las funciones de app siempre y cuando este corriendo
    while (app.IsRunning()) {
        app.CaptureInput();
        app.Update();
        app.LateUpdate();
        app.Draw();
        app.GetdTime();
    }
    return 0;
}

