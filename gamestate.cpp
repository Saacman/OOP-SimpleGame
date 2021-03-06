#include "gamestate.hpp"
#include <vector>
#include <iostream>

GameState::GameState(ResourcePath& Path, FSM& fsm) : path(Path), fsm(fsm), switchToState(0) { }

// Iniializa el estado
void GameState::init() {
    // Iniciando al jugador
    playerTexture.loadFromFile(path.Get() + "player.png");
    player = Player(&playerTexture, sf::Vector2u(4, 4), 0.1f, 100.0f);

    backTexture.loadFromFile(path.Get() + "background.png");
    backSprite.setTexture(backTexture);
    // Definiendo el vector de paredes
    walls.push_back(Box(sf::Vector2f(800.0f, 20.0f), sf::Vector2f(0.0f, -20.0f)));
    walls.push_back(Box(sf::Vector2f(800.0f, 20.0f), sf::Vector2f(0.0f, 600.0f)));
    walls.push_back(Box(sf::Vector2f(10.0f, 600.0f), sf::Vector2f(-10.0f, 0.0f)));
    walls.push_back(Box(sf::Vector2f(10.0f, 600.0f), sf::Vector2f(800.0f, 0.0f)));
    walls.push_back(Box(sf::Vector2f(373.0f, 307.0f), sf::Vector2f(427.0f, 74.0f)));
    walls.push_back(Box(sf::Vector2f(291.0f, 74.0f), sf::Vector2f(509.0f, 0.0f)));
    walls.push_back(Box(sf::Vector2f(65.0f, 68.0f), sf::Vector2f(2.0f, 482.0f)));
    walls.push_back(Box(sf::Vector2f(65.0f, 68.0f), sf::Vector2f(296.5f, 482.0f)));
    walls.push_back(Box(sf::Vector2f(373.0f, 118.0f), sf::Vector2f(427.0f, 482.0f)));
    walls.push_back(Box(sf::Vector2f(98.0f, 102.0f), sf::Vector2f(2.0f, 244.0f)));
    walls.push_back(Box(sf::Vector2f(98.0f, 102.0f), sf::Vector2f(133.0f, 244.0f)));
    walls.push_back(Box(sf::Vector2f(98.0f, 102.0f), sf::Vector2f(264.0f, 244.0f)));
    walls.push_back(Box(sf::Vector2f(227.0f, 102.0f), sf::Vector2f(3.0f, 6.0f)));

    // Definiendo las cajas de cambio de estado
    switchBox.push_back(Box(sf::Vector2f(21.0f, 1.0f), sf::Vector2f(182.5f, 345.5f)));
    switchBox.push_back(Box(sf::Vector2f(21.0f, 1.0f), sf::Vector2f(51.5f, 345.5f)));
    switchBox.push_back(Box(sf::Vector2f(21.0f, 1.0f), sf::Vector2f(313.5f, 345.5f)));
}

// Asgina el estado al que pasará el activo
void GameState::SetSwitchToState(unsigned int id) {
    switchToState = id;
}

// Actualizar la lógica según dTime
void GameState::Update(float dTime) {

    player.CanMove();
    // A través de un iterador revisa las coliciones con las paredes
    for( auto item = walls.begin(); item != walls.end(); item++ ) {
        if(player.GetBody().getGlobalBounds().intersects(item->GetBody().getGlobalBounds())) {
            for(unsigned int i = 0; i <= 3; i++) if (player.GetDirection() == i)  player.CantMove(i);
        }
    }
    // A través de un iterador revisa el cambio de estado.
    for( auto item = switchBox.begin(); item != switchBox.end(); item++ ) {
        if(player.GetBody().getGlobalBounds().intersects(item->GetBody().getGlobalBounds()) && player.Action()) {
            fsm.SwitchTo(switchToState);
            player.GetBody().move(0, 20);
        }
    }
    player.Update(dTime);
}
void GameState::Draw(Window& window) {
    window.Draw(backSprite);
    //for( auto item = switchBox.begin(); item != switchBox.end(); item++ ) item->Draw(window);
    player.Draw(window);
    

}
