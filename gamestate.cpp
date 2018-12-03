#include "gamestate.hpp"
#include <vector>
#include <iostream>

GameState::GameState(ResourcePath& Path, FSM& fsm) : path(Path), fsm(fsm), switchToState(0) { }


void GameState::init() {
    playerTexture.loadFromFile(path.Get() + "player.png");
    player = Player(&playerTexture, sf::Vector2u(4, 4), 0.1f, 100.0f);
    enemy1 = Enemy(nullptr, sf::Vector2u(4, 4), 0.1f, 100.0f);

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

void GameState::terminate() { }

void GameState::SetSwitchToState(unsigned int id) {

	// Almacena el id del estado al que pasará al terminar

    switchToState = id;
}

void GameState::Update(float dTime) {
    enemy1.Update(dTime);

    player.CanMove();
    for( auto item = walls.begin(); item != walls.end(); item++ ) {
        if(player.GetBody().getGlobalBounds().intersects(item->GetBody().getGlobalBounds())) {
            for(unsigned int i = 0; i <= 3; i++) if (player.GetDirection() == i)  player.CantMove(i);
        }
    }
    for( auto item = switchBox.begin(); item != switchBox.end(); item++ ) {
        if(player.GetBody().getGlobalBounds().intersects(item->GetBody().getGlobalBounds())) {
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
    //enemy1.Draw(window);

}
