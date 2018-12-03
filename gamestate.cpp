#include "gamestate.hpp"

GameState::GameState(ResourcePath& Path) : path(Path){ }


void GameState::init() {
    playerTexture.loadFromFile(path.Get() + "player.png");
    player = Player(&playerTexture, sf::Vector2u(4, 4), 0.1f, 100.0f);

    backTexture.loadFromFile(path.Get() + "background.png");
    backSprite.setTexture(backTexture);
    house1 = Box(sf::Vector2f(98.0f, 102.0f), sf::Vector2f(51.0f, 295.0f));
    house2 = Box(sf::Vector2f(98.0f, 102.0f), sf::Vector2f(182.0f, 295.0f));
    house3 = Box(sf::Vector2f(98.0f, 102.0f), sf::Vector2f(313.0f, 295.0f));
    house4 = Box(sf::Vector2f(227.0f, 102.0f), sf::Vector2f(116.5f, 57.0f));
}

void GameState::terminate() { }


void GameState::Update(float dTime) {

    player.Update(dTime);
    // platform1.GetCollider().CheckCollider(player.GetCollider(),1.0f);
    // platform2.GetCollider().CheckCollider(player.GetCollider(),1.0f); // Valores entre 0 y 1
}
void GameState::Draw(Window& window) {
    window.Draw(backSprite);
    house1.Draw(window);
    house2.Draw(window);
    house3.Draw(window);
    house4.Draw(window);
    player.Draw(window);

}
