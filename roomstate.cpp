#include "roomstate.hpp"

RoomState::RoomState(ResourcePath& Path, FSM& fsm) : path(Path), fsm(fsm), switchToState(0){ }


void RoomState::init() {
    playerTexture.loadFromFile(path.Get() + "player.png");
    player = Player(&playerTexture, sf::Vector2u(4, 4), 0.1f, 100.0f);

    backTexture.loadFromFile(path.Get() + "indoor.png");
    backSprite.setTexture(backTexture);
    backSprite.setPosition(160,60);

    // Vector de paredes
    walls.push_back(Box(sf::Vector2f(160.00f, 600.0f), sf::Vector2f(12.0f, 0.0f)));
    walls.push_back(Box(sf::Vector2f(160.00f, 600.0f), sf::Vector2f(632.0f, 0.0f)));
    walls.push_back(Box(sf::Vector2f(480.00f, 94.0f), sf::Vector2f(160.0f, 0.0f)));
    walls.push_back(Box(sf::Vector2f(480.00f, 60.0f), sf::Vector2f(160.0f, 540.0f)));
    walls.push_back(Box(sf::Vector2f(208.00f, 31.0f), sf::Vector2f(160.0f, 509.0f)));
    walls.push_back(Box(sf::Vector2f(212.00f, 31.0f), sf::Vector2f(420.0f, 509.0f)));
    // Caja de cambio
    switchBox.push_back(Box(Box(sf::Vector2f(40.0f, 1.0f), sf::Vector2f(380.0f, 539.0f))));
}

void RoomState::terminate() { }

void RoomState::SetSwitchToState(unsigned int id) {

	// Almacena el id del estado al que pasará al terminar
    switchToState = id;
}

void RoomState::Update(float dTime) {
    player.CanMove();
    for( auto item = walls.begin(); item != walls.end(); item++ ) {
        if(player.GetBody().getGlobalBounds().intersects(item->GetBody().getGlobalBounds())) {
            for(unsigned int i = 0; i <= 3; i++) if (player.GetDirection() == i)  player.CantMove(i);
        }
    }
    for( auto item = switchBox.begin(); item != switchBox.end(); item++ ) {
        if(player.GetBody().getGlobalBounds().intersects(item->GetBody().getGlobalBounds()) && player.Action()) {
            fsm.SwitchTo(switchToState);
            // Movemos al jugador 10px arriba de la caja de estado
            player.GetBody().move(0, -20);
        }
    }
    player.Update(dTime);

}

void RoomState::Draw(Window& window) {
    window.Draw(backSprite);
    //for( auto item = switchBox.begin(); item != switchBox.end(); item++ ) item->Draw(window);
    //for( auto item = walls.begin(); item != walls.end(); item++ ) item->Draw(window);
    player.Draw(window);
}
