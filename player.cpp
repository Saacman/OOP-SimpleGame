#include "player.hpp"
#include <iostream>
Player::Player() : row(0), speed(0.0f), direction(0) {}

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed)
: animation(texture, imageCount, switchTime), speed(speed), direction(0) {
// 40x60
    body.setSize(sf::Vector2f(25.0f, 37.5f));
    body.setOrigin(body.getSize()/2.0f);
    body.setPosition(400.0f, 430.0f);
    body.setTexture(texture);
    action = false;
}
Player::~Player() {}

void Player::Update(float deltaTime) {
    row = direction;
    moving = false;
    action = false;
    sf::Vector2f movement(0.0f, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if(!canMove.getBit(0)) {
            movement.y = speed * deltaTime;
            row = 0;
            moving = true;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if(!canMove.getBit(1)) {
            movement.y = -(speed * deltaTime);
            row = 1;
            moving = true;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if(!canMove.getBit(2)){
            movement.x = -(speed * deltaTime);
            row = 2;
            moving = true;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if(!canMove.getBit(3)){
            movement.x = speed * deltaTime;
            row = 3;
            moving = true;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
        action = true;
        std::cout << "pew pew" << std::endl;
    }
    direction = row;
    animation.Update(row, deltaTime, moving);
    body.setTextureRect(animation.getRect());
    body.move(movement);
}

void Player::Draw(Window& window) {
    window.Draw(body);
}

sf::Vector2f Player::GetPosition() {
    return body.getPosition();
}

sf::RectangleShape Player::GetBody() {
    return body;
}

unsigned int Player::GetDirection(){
    return direction;
}
void Player::CantMove(int index) {
    canMove.setBit(index);
}
void Player::CanMove() {
    canMove.Clear();
}

bool Player::Action() {
    return action;
}
//
// Collider Player::GetCollider() {
//     return collider;
// }
