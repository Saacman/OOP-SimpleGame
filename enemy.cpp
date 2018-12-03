#include "enemy.hpp"

Enemy::Enemy() : speed(0.0f) {}

Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed)
: speed(speed){
// 40x60
    body.setSize(sf::Vector2f(40.0f,60.0f));
    body.setOrigin(body.getSize()/2.0f);
    body.setPosition(230.0f, 150.0f);
    body.setTexture(texture);
}
Enemy::~Enemy() {}

void Enemy::Update(float deltaTime) {
    sf::Vector2f movement(0.0f, 0.0f);
    if (body.getPosition().x <= 394.0f && body.getPosition().y == 10.0f) {
        movement.x = speed * deltaTime;
    }
    if (body.getPosition().x >= 230.0f && body.getPosition().y == 176.0f) {
        movement.x = -speed * deltaTime;
    }
    if (body.getPosition().y <= 176.0f && body.getPosition().x == 394.0f) {
        movement.x = speed * deltaTime;
    }
    if (body.getPosition().y >= 10.0f && body.getPosition().x == 230.0f) {
        movement.x = -speed * deltaTime;
    }


    body.move(movement);
}

void Enemy::Draw(Window& window) {
    window.Draw(body);
}

sf::Vector2f Enemy::GetPosition() {
    return body.getPosition();
}
//
// Collider Enemy::GetCollider() {
//     return collider;
// }
