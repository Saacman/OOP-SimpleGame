#include "roomstate.hpp"

RoomState::RoomState(ResourcePath& Path, FSM& fsm) : path(Path), fsm(fsm), switchToState(0){ }


void RoomState::init() {
    playerTexture.loadFromFile(path.Get() + "player.png");
    player = Player(&playerTexture, sf::Vector2u(4, 4), 0.1f, 100.0f);


    backTexture.loadFromFile(path.Get() + "indoor.png");
    backSprite.setTexture(backTexture);
    backSprite.setPosition(160,60);
}

void RoomState::terminate() { }

void RoomState::SetSwitchToState(unsigned int id) {
	// Almacena el id del estado al que pasará al terminar
    switchToState = id;
}

void RoomState::Update(float dTime) {
    player.Update(dTime);
    if (player.GetPosition().x < 420.0f && player.GetPosition().x > 380.0f) {
        if (player.GetPosition().y < 540.0f && player.GetPosition().y > 509.0f) {
            fsm.SwitchTo(switchToState);
        }
    }


}
void RoomState::Draw(Window& window) {
    window.Draw(backSprite);
    player.Draw(window);
}
