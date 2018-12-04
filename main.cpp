#include "app.hpp"
#include <SFML/Audio.hpp>

#include <iostream>

int main() {
    //Crea el objeto "motor" para gestionar el juego
    App app;
    sf::Music music;
    if (!music.openFromFile("Resources/prueba1.Ogg")) {
        return EXIT_FAILURE;
    }

    // Iniciar musica
    music.play();
    //Crea un ciclo con el cual se permitirá  llamar las funciones de app siempre y cuando este corriendo
    while (app.IsRunning()) {
        app.Update();
        app.LateUpdate();
        app.Draw();
        app.GetdTime();
    }
    return 0;
}
