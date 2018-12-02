#include "gamestate.hpp"

GameState::GameState(ResourcePath& path) : path(path) { }

void GameState::init() {
    playerTexture.loadFromFile(path.Get() + "player.png");
    player = Player(&playerTexture, sf::Vector2u(4, 4), 0.1f, 100.0f);


    backTexture.loadFromFile(path.Get() + "background.png");
    backSprite.setTexture(backTexture);


    //Platform platform1(nullptr, sf::Vector2f(400.of, 200.0f), sf::Vector2f(500.0f, 200.0f));
}

void GameState::terminate() { }

void GameState::ProcessInput() {
    //input.Update();
}

void GameState::Update(float dTime) {
    // const int speed = 150;
    // float frameMove = speed * dTime;
    // int xMove = 0;
    // int yMove = 0;
    // if (input.isKPressed(Input::Key::Up))  yMove = -frameMove;
    // if (input.isKPressed(Input::Key::Down)) yMove = frameMove;
    // if (input.isKPressed(Input::Key::Right)) xMove = frameMove;
    // if (input.isKPressed(Input::Key::Left)) xMove = -frameMove;
    // playerSprite.move(xMove, yMove);

    player.Update(dTime);
    //platform1.GetCollider().CheckCollision(player.GetCollider(),1.0f); // Valores entre 0 y 1
}
void GameState::Draw(Window& window) {
    //platform1.Draw(window);
    window.Draw(backSprite);
    player.Draw(window);

}
