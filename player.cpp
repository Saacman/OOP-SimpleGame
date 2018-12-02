#include "player.hpp"

Player::Player() : row(0), speed(0.0f) {}

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed)
: animation(texture, imageCount, switchTime), speed(speed) {

    body.setSize(sf::Vector2f(40.0f,60.0f));
    body.setOrigin(body.getSize()/2.0f);
    body.setPosition(400.0f, 300.0f);
    body.setTexture(texture);

}
Player::~Player() {}

void Player::Update(float deltaTime) {
    row = 0;
    sf::Vector2f movement(0.0f, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        movement.y = speed * deltaTime;
        row = 0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        movement.y = -(speed * deltaTime);
        row = 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        movement.x = -(speed * deltaTime);
        row = 2;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        movement.x = speed * deltaTime;
        row = 3;
    }
    animation.Update(row, deltaTime);
    body.setTextureRect(animation.getRect());
    body.move(movement);
}

void Player::Draw(Window& window) {
    window.Draw(body);
}

sf::Vector2f Player::GetPosition() {
    return body.getPosition();
}

// Collision Player::GetCollider() {
//     return Collision(body);
// }
