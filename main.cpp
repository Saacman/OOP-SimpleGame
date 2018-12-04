#include "app.hpp"
#include <SFML/Audio.hpp>

#include <iostream>

int main() {
    //Crea el objeto "motor" para gestionar el juego
    App app;
    // Carga la música
    sf::Music music;
    if (!music.openFromFile("Resources/prueba1.Ogg")) {
        return EXIT_FAILURE;
    }
    // Iniciar musica
    music.play();
    //Cicl de Juego
    while (app.IsRunning()) {
        app.Update();
        app.Draw();
        app.GetdTime();
    }
    return 0;
}
