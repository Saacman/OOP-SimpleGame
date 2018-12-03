#include "gamestate.hpp"

GameState::GameState(ResourcePath& Path) : path(Path){ }


void GameState::init() {
    playerTexture.loadFromFile(path.Get() + "player.png");
    player = Player(&playerTexture, sf::Vector2u(4, 4), 0.1f, 100.0f);

    backTexture.loadFromFile(path.Get() + "background.png");
    backSprite.setTexture(backTexture);
    // platform1 = Platform(sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f));
    // platform2 = Platform(sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));
}

void GameState::terminate() { }


void GameState::Update(float dTime) {

    player.Update(dTime);
    // platform1.GetCollider().CheckCollider(player.GetCollider(),1.0f);
    // platform2.GetCollider().CheckCollider(player.GetCollider(),1.0f); // Valores entre 0 y 1
}
void GameState::Draw(Window& window) {

    window.Draw(backSprite);
    // platform1.Draw(window);
    // platform2.Draw(window);
    player.Draw(window);

}
