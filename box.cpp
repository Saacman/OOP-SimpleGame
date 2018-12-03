#include "box.hpp"

Box::Box() { }

Box::Box(sf::Vector2f size, sf::Vector2f position) {
    body.setSize(size);
    body.setOrigin(size/2.0f);
    //body.setTexture(texture);
    //body.setFillColor(color);
    body.setPosition(position);

}
Box::~Box() {

}

void Box::Draw(Window& window) {
    window.Draw(body);
}

// Collider Box::GetCollider() {
//     return Collider(body);
// }
