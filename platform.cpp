#include "platform.hpp"

Platform::Platform() { }

Platform::Platform(sf::Vector2f size, sf::Vector2f position) {
    body.setSize(size);
    body.setOrigin(size/2.0f);
    //body.setTexture(texture);
    //body.setFillColor(color);
    body.setPosition(position);

}
Platform::~Platform() {

}

void Platform::Draw(Window& window) {
    window.Draw(body);
}

Collider Platform::GetCollider() {
    return Collider(body);
}
