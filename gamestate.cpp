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
    walls.push_back(Box(sf::Vector2f(98.0f, 102.0f), sf::Vector2f(51.0f, 295.0f)));
    walls.push_back(Box(sf::Vector2f(98.0f, 102.0f), sf::Vector2f(182.0f, 295.0f)));
    walls.push_back(Box(sf::Vector2f(98.0f, 102.0f), sf::Vector2f(313.0f, 295.0f)));
    walls.push_back(Box(sf::Vector2f(227.0f, 102.0f), sf::Vector2f(116.5f, 57.0f)));
}

void GameState::terminate() { }

void GameState::SetSwitchToState(unsigned int id) {
	// Almacena el id del estado al que pasará al terminar
    switchToState = id;
}

void GameState::Update(float dTime) {
    enemy1.Update(dTime);
    if (player.GetPosition().x < 193.0f && player.GetPosition().x > 172.0f) {
        if (player.GetPosition().y < 345.0f && player.GetPosition().y > 316.0f) {
            fsm.SwitchTo(switchToState);
        }
    }
    if (player.GetPosition().x < 62.0f && player.GetPosition().x > 41.0f) {
        if (player.GetPosition().y < 345.0f && player.GetPosition().y > 316.0f) {
            fsm.SwitchTo(switchToState);
        }
    }
    if (player.GetPosition().x < 323.0f && player.GetPosition().x > 303.0f) {
        if (player.GetPosition().y < 345.0f && player.GetPosition().y > 316.0f) {
            fsm.SwitchTo(switchToState);
        }
    }
    player.CanMove();
    for( auto item = walls.begin(); item != walls.end(); item++ ) {
        if(player.GetBody().getGlobalBounds().intersects(item->GetBody().getGlobalBounds())) {
            for(unsigned int i = 0; i <= 3; i++) {
                if (player.GetDirection() == i)  player.CantMove(i);
            }
        }
    }

    player.Update(dTime);
}
void GameState::Draw(Window& window) {
    window.Draw(backSprite);
    for( auto item = walls.begin(); item != walls.end(); item++ ) item->Draw(window);
    player.Draw(window);
    enemy1.Draw(window);

}
